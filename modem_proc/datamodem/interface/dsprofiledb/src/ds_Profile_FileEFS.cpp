/*===========================================================================
  @file ds_Profile_FileEFS.cpp

  This file implements EFS File class which is wrapper for various file 
  operations with the profile done on the EFS

                Copyright (c) 2013 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary
===========================================================================*/

/*===========================================================================
  EDIT HISTORY FOR MODULE

  Please notice that the changes are listed in reverse chronological order.

  when       who what, where, why
  ---------- --- ------------------------------------------------------------
  2013-04-14 am Created module

===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE


===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include <string.h>

extern "C"
{
#include "fs_public.h"
#include "fs_sys_types.h"
#include "fs_errno.h"
}

#include "ds_profile_db.h"
#include "ds_Profile_Profile.h"
#include "ds_Profile_File.h"
#include "ds_Profile_FileEFS.h"
#include "ds_Profile_DBMgr.h"

#include "ds_Profile_Log.h"
#include "ps_system_heap.h"

#include <stringl/stringl.h>

using namespace ds::Profile;
/*===========================================================================

                      INTERNAL DEFINITIONS

===========================================================================*/
static const char PROFILE_DIR[] = "/Data_Profiles/";
static const char PROFILE_FILENAME_BASE[] = "Profile";
static const char PROFILE_NAME_FMT_STRING[] = "/Data_Profiles/Profile%u%1s";
static const int  MAX_PATH_LEN = 128;
static const int  TECH_FIELD_SIZE = 1;
static const int  STRUCT_SIZE_FIELD_SIZE = sizeof(size_t);
static uint32 ds_profile_error_read_operation = 0;
mcfg_fs_e_type FileEFS::file_type = MCFG_FS_TYPE_EFS;
/*===========================================================================

                      INTERNAL FUNCTIONS

===========================================================================*/
static int FlagTypeToEFSflag(File::FlagType flag)
{
  switch (flag)
  {
    case File::F_CREATE:
      return MCFG_FS_O_CREAT | MCFG_FS_O_TRUNC | MCFG_FS_O_RDWR | MCFG_FS_O_EXCL;
    case File::F_CREATE_OVERWRITE:
      return MCFG_FS_O_CREAT | MCFG_FS_O_TRUNC | MCFG_FS_O_RDWR;
    case File::F_READ:
      return MCFG_FS_O_RDONLY;
    case File::F_WRITE:
      return MCFG_FS_O_WRONLY | MCFG_FS_O_TRUNC; /* file is always truncated to 0 when written, TODO revisit in Phase 2 */
    case File::F_WRITE_CREATE:
      return MCFG_FS_O_WRONLY | MCFG_FS_O_CREAT | MCFG_FS_O_TRUNC; /* file is always truncated to 0 when written, TODO revisit in Phase 2 */
    case File::F_RW:
      #ifdef FEATURE_USER_CONFIGURE_EFS
      return MCFG_FS_O_RDWR | MCFG_FS_O_CREAT | MCFG_FS_O_TRUNC;
      #else
      return MCFG_FS_O_RDWR;
      #endif
    default:
      return -1;
  }
}

static ds_profile_db_result_type ParseFileName(const char* file_name, 
                                               ds_profile_db_profile_num_type* profile_num) 
{  
  if (!profile_num) {
    return DB_RESULT_ERR_INVAL;
  }

  char tmp_str[3];
  unsigned int tmp_profile_num = 0;
  int ret = sscanf(file_name, PROFILE_NAME_FMT_STRING, &tmp_profile_num, tmp_str );

  /* we should read ProfileX - where X is some number and 
     sscanf returns number of entry read */
  if (1 != ret) {
    PROFILE_DB_LOG_ERROR("ParseFileName(): error in sscanf");
    return DB_RESULT_ERR_INVAL;
  }

  *profile_num = tmp_profile_num;

  return DB_RESULT_SUCCESS;
}

static ds_profile_db_result_type BuildFileName(ds_profile_db_profile_num_type profile_num,
                                               char* file_name) 
{  
  ds_profile_db_result_type res = Profile::ValidateProfileNum(profile_num);
  if (DB_RESULT_SUCCESS != res) {
    return res;
  }

  char file_path[MAX_PATH_LEN] = {};

  if (strlcpy(file_path,  PROFILE_DIR, sizeof(file_path)) >= sizeof(file_path))
  {
    PROFILE_DB_LOG_ERROR("BuildFileName(): error in strlcpy");
    return DB_RESULT_ERR_INVAL;
  }

  int ret = snprintf(file_name, MAX_PATH_LEN, "%s%s%u", file_path, PROFILE_FILENAME_BASE, profile_num );

  if (!ret)
  {
    PROFILE_DB_LOG_ERROR("BuildFileName(): error in snprintf");
    return DB_RESULT_FAIL;
  }

  return DB_RESULT_SUCCESS;
}

static ds_profile_db_result_type CheckAndCreateDirectory()
{
  ds_profile_db_result_type res = DB_RESULT_SUCCESS;
  mcfg_fs_status_e_type efs_res;
  fs_stat dont_care;
  mcfg_fs_sub_id_e_type mcfg_subs_id = MCFG_FS_SUBID_NONE;

  efs_res = mcfg_fs_stat(PROFILE_DIR, &dont_care, FileEFS::file_type, mcfg_subs_id);
  if (efs_res != MCFG_FS_STATUS_OK)
  {
    if (-1 == mcfg_mkdir(PROFILE_DIR, MCFG_FS_ALLPERMS, FileEFS::file_type))
    {
      PROFILE_DB_LOG_ERROR("CheckandCreateDirectory(): Could not create profiles directory");
      return res;
    }
  }
  return res;
}

#ifdef FEATURE_USER_CONFIGURE_EFS
ds_profile_db_result_type CheckEFSFileSize(uint32 offset,
                                           uint16 tech_mask)
{
  ds_profile_db_result_type result_type = DB_RESULT_SUCCESS;

  if (tech_mask == DB_TECH_TO_TECHMASK(DB_TECH_3GPP))
  {
    if (offset > MAX_3GPP_PROFILE_SIZE)
    {
      result_type = DB_RESULT_ERR_OUT_OF_MEMORY;
      return result_type;
    }
  } 
  else if (tech_mask == DB_TECH_TO_TECHMASK(DB_TECH_3GPP2))
  {
    if (offset > MAX_3GPP2_PROFILE_SIZE)
    {
      result_type = DB_RESULT_ERR_OUT_OF_MEMORY;
      return result_type;
    }
  } 
  else if (tech_mask == (ds_profile_db_supported_tech_mask)EPC_TECH_MASK)
  {
    if (offset > MAX_TLV_SIZE)
    {
      result_type = DB_RESULT_ERR_OUT_OF_MEMORY;

      return result_type;
    }
  }
  return result_type;
}
#endif

/*===========================================================================

                      PUBLIC FUNCTIONS

===========================================================================*/

FileEFS::FileEFS(ds_profile_db_profile_num_type num, ds_profile_db_subs_type subs, FlagType flag  /* = F_RW */) :
  fs_handle(-1), profile_num(-1), is_new(false)
{
  Open(num, flag, subs);
}

ds_profile_db_result_type FileEFS::Open(ds_profile_db_profile_num_type num, 
                                        FlagType flag /* = F_RW */,
                                        ds_profile_db_subs_type subs /*= DB_PROFILE_ACTIVE_SUBSCRIPTION_1*/)
{
  ds_profile_db_result_type res;
  mcfg_fs_sub_id_e_type mcfg_subs_id = MCFG_FS_SUBID_NONE;
  int efs_flag = FlagTypeToEFSflag(flag);
  if (-1 == efs_flag)
  {
    PROFILE_DB_LOG_ERROR_1("Open(): invalid efs_flag %d", efs_flag);
    return DB_RESULT_ERR_INVAL_OP;
  }
  
  mcfg_subs_id = ds_profile_db_convert_ds_to_mcfg_subs(subs);

  char file_name[MAX_PATH_LEN] = {};
  if (DB_RESULT_SUCCESS != (res = (BuildFileName(num, file_name))))
  {
    PROFILE_DB_LOG_ERROR("Build File Name failure during read all");  
    return res;
  }
  
  if (-1 != fs_handle)
  {
    PROFILE_DB_LOG_ERROR("Fs handle already present");
    Close();
  }
  
  if (DB_RESULT_SUCCESS != (res = CheckAndCreateDirectory()))
  {
    return res;
  }
  if (efs_flag & MCFG_FS_O_CREAT)
  {
    fs_handle = mcfg_fopen(file_name, efs_flag, MCFG_FS_DEFFILEMODE, file_type, mcfg_subs_id);
    is_new = true;
  } else
  {
    fs_handle = mcfg_fopen(file_name, efs_flag, MCFG_FS_ALLPERMS, file_type, mcfg_subs_id);
    is_new = false;
  }

  if (-1 == fs_handle)
  {
    PROFILE_DB_LOG_ERROR_1("Open(): could not open file, error %d", mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  profile_num = num;

  return DB_RESULT_SUCCESS;
}

ds_profile_db_result_type FileEFS::Close(void)
{
  ds_profile_db_result_type res = DB_RESULT_SUCCESS;
  profile_num = -1;

  if (-1 == fs_handle)
  {
    PROFILE_DB_LOG_ERROR("Close(): invalid fs_handle");
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  if (0 != mcfg_fclose(fs_handle, file_type))
  {
    PROFILE_DB_LOG_ERROR_1("Close(): could not close file, error %d", mcfg_fs_errno( file_type ));
    res = DB_RESULT_ERR_FILE_ACCESS;
  }
  fs_handle = -1;

  return res;
}

bool FileEFS::IsOpen(void) const
{ 
  return (-1 != fs_handle);
} 

FileEFS::~FileEFS(void)
{
  if (-1 != fs_handle)
{
    Close();
  }  
}
#ifdef FEATURE_USER_CONFIGURE_EFS
ds_profile_db_result_type FileEFS::Write(const Profile *profile,
                                         bool is_reset_event,
                                         bool reset_profile,
                                         bool is_create,
                                         bool is_3gpp2_default_profile)
{
  if (!profile)
  {
    PROFILE_DB_LOG_ERROR("Write(): profile pointer is NULL");
    return DB_RESULT_ERR_INVAL;
  }

  return Create(profile, is_reset_event, reset_profile, is_create, is_3gpp2_default_profile);
}

ds_profile_db_result_type FileEFS::Read(Profile **profile) const
{
  Profile *tmpProf = NULL;
  ds_profile_db_efs_header efs_header = { 0 };
  char *offset_ptr = NULL;
  ds_profile_db_info_type param_info = { 0 };
  char data[MAX_DATA_SIZE] = { 0 };
  ds_profile_db_ident_type ident = INVALID_PROFILE_PARAM;
  uint16 ident_val = 0;
  uint32 read_tlvs = 0;
  uint32 num_bytes = 0;
  void *heapMemForFile = ds_profile_db_get_heap_mem_for_file();
  ds_profile_db_gen_params_type gen_params = { 0 };
  void *tech_param = NULL;
  ds_profile_db_result_type res = DB_RESULT_SUCCESS;


  /*Create a default PRofile 
    1.) Finish Reading the TLV from the read
    2.) Use the same heapMEmfor File
    3.) SetParam on the tmp Profile
    4.) After everything passes just set the profile
  */
  /* first technology should be general */

  memset(heapMemForFile, 0, MAX_TLV_SIZE);
  num_bytes = mcfg_fread(fs_handle, heapMemForFile, MAX_TLV_SIZE, file_type);
  /* we reached the end */
  PROFILE_DB_LOG_HIGH_1("READTLV(): number of bytes Read %d", num_bytes);

  if (0 == num_bytes)
  {
    res = DB_RESULT_ERR_EOF;
    goto bail;
  }

  READ_FROM_INDEX(heapMemForFile, ds_profile_db_efs_header, efs_header);
  gen_params.profile_number = efs_header.num;
  gen_params.tech_mask = efs_header.tech_mask;
  gen_params.persistent = 1;
  if (efs_header.magic_number != DS_PROFILE_DB_MAGIC_EFS_NUM)
  {
    res = DB_RESULT_FAIL;
    goto bail;
  }
  //size for efs_header + efs_header.size
  if (num_bytes != (efs_header.size + sizeof(ds_profile_db_efs_header)))
  {
    res = DB_RESULT_FAIL;
    goto bail;
  }
  /*Check if EPC is supported or not and if the read profile is EPC, then ignore and dont cache*/
  if ((!DBMgr::Instance()->GetEPCSupportVal()) && 
      (EPC_TECH_MASK == efs_header.tech_mask))
  {
    res = DB_RESULT_FAIL;
    goto bail;
  }

  if ((res = Profile::ValidateProfileNumPerTech(efs_header.num, 
                                                efs_header.tech_mask)) 
      != DB_RESULT_SUCCESS)
  {
    goto bail;
  }

  if (efs_header.size > MAX_TLV_SIZE)
  {
    res = DB_RESULT_FAIL;
    goto bail;
  }
  DB_FOR_EVERY_TECH_IN_MASK_DO_START(efs_header.tech_mask, tech)
  if (!tmpProf)
  {
    PS_SYSTEM_HEAP_MEM_ALLOC(tech_param, Profile::GetCStructSize(tech), void*);
    Profile::GetDefaultCParams(tech, tech_param);
    tmpProf = Profile::CreateInstance(tech, tech_param, &gen_params);
    PS_SYSTEM_HEAP_MEM_FREE(tech_param);
    if (NULL == tmpProf)
    {
      PROFILE_DB_LOG_ERROR_2("Read(): could not create profile num %d from tech part %d"
                             "or from general params read from EFS",
                             tech, gen_params.profile_number);
      res = DB_RESULT_ERR_INVAL;
      goto bail;
    }
  } 
  else
  {
    PS_SYSTEM_HEAP_MEM_ALLOC(tech_param, Profile::GetCStructSize(tech), void*);
    Profile::GetDefaultCParams(tech, tech_param);
    if (DB_RESULT_SUCCESS != tmpProf->AddSupportedTech(tech, tech_param))
    {
      PROFILE_DB_LOG_ERROR_2("Read(): could not create profile num %d from tech part %"
                             "read from EFS",
                             tech, gen_params.profile_number);
      res = DB_RESULT_ERR_INVAL;
      goto bail;
    }
    PS_SYSTEM_HEAP_MEM_FREE(tech_param);
  }
  DB_FOR_EVERY_TECH_IN_MASK_DO_END
    offset_ptr = (char *)heapMemForFile + EFS_HEADER_SIZE;

  while (read_tlvs < efs_header.num_tlvs)
  {
    memset(data, 0, sizeof(data));
    param_info.len = 0;
    param_info.buf = data;
    READ_FROM_INDEX(offset_ptr, TLV_LEN, ident_val);
    ident = (ds_profile_db_ident_type)ident_val;
    offset_ptr += DS_PROFILE_DB_IDENT_SIZE;
    READ_FROM_INDEX(offset_ptr, TLV_LEN, param_info.len);
    offset_ptr += DS_PROFILE_DB_PARAM_LEN_SIZE;
    memscpy(data, MAX_DATA_SIZE, offset_ptr, param_info.len);
    offset_ptr += param_info.len;
    if (tmpProf)
    {
      if (DB_RESULT_SUCCESS != (res = tmpProf->SetParam(ident, &param_info)))
      {
        if (res != DB_RESULT_ERR_SET_IDENT_NOT_SUPPORTED)
        {
          res = DB_RESULT_FAIL;
          goto bail;
        }
      }
    }

    read_tlvs++;
  }
  if (tmpProf)
  {
    tmpProf->SetReadTime(time_get_secs());
  }


bail:
  mcfg_fclose(fs_handle, file_type);
  *profile = tmpProf;
  return res;
}

#else

ds_profile_db_result_type FileEFS::Write(const Profile *profile) const
{
  if (!profile)
  {
    PROFILE_DB_LOG_ERROR("Write(): profile pointer is NULL");
    return DB_RESULT_ERR_INVAL;
  }

  return Create(profile);
}

ds_profile_db_result_type FileEFS::Read(Profile **profile) const
{
  ds_profile_db_result_type res;
  ds_profile_db_gen_params_type gen_params;
  ds_profile_db_tech_type tech;
  Profile* tmpProf = NULL;
  void *tech_params = NULL;

  if (!profile)
  {
    PROFILE_DB_LOG_ERROR("Read(): profile pointer is NULL");
    return DB_RESULT_ERR_INVAL;
  }

  /* use goto bail after this point !!! */
  PS_SYSTEM_HEAP_MEM_ALLOC(tech_params, Profile::GetMaxCStructSize(),
                           void*);
  if (!tech_params)
  {
    return DB_RESULT_ERR_OUT_OF_MEMORY;
  }


  /* first technology should be general */
  if (DB_RESULT_SUCCESS != (res = ReadParams(&gen_params, &tech, true)))
  {
    goto bail;
  }

  if (gen_params.profile_number != profile_num)
  {
    res = DB_RESULT_ERR_INVAL_PROFILE_NUM;
    goto bail;
  }

  /* there should be at least one more technology */
  if (DB_RESULT_SUCCESS != (res = ReadParams(tech_params, &tech)))
  {
    goto bail;
  }

  tmpProf = Profile::CreateInstance(tech, tech_params, &gen_params);
  if (NULL == tmpProf)
  {
    PROFILE_DB_LOG_ERROR_2("Read(): could not create profile num %d from tech part %d"
                           "or from general params read from EFS",
                           tech, gen_params.profile_number);
    res = DB_RESULT_ERR_INVAL;
    goto bail;
  }

  while (true)
  {
    res = ReadParams(tech_params, &tech);
    if (DB_RESULT_SUCCESS != res)
    {
      if (DB_RESULT_ERR_EOF == res)
      {
        break;
      } else
      {
        goto bail;
      }
    }

    if (DB_RESULT_SUCCESS != (res = tmpProf->AddSupportedTech(tech, tech_params)))
    {
      PROFILE_DB_LOG_ERROR_2("Read(): could not create profile num %d from tech part %"
                             "read from EFS",
                             tech, gen_params.profile_number);
      goto bail;
    }
  }

  *profile = tmpProf;

  if (tech_params)
  {
    PS_SYSTEM_HEAP_MEM_FREE(tech_params);
  }

  return DB_RESULT_SUCCESS;


bail :

  if (tech_params)
  {
    PS_SYSTEM_HEAP_MEM_FREE(tech_params);
  }

  if (tmpProf)
  {
    delete tmpProf;
    tmpProf = NULL;
  }

  if (0 != mcfg_fclose(fs_handle, file_type))
  {
    PROFILE_DB_LOG_ERROR_1("Close(): could not close file, error %d", mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  PROFILE_DB_LOG_ERROR_ON_EXIT(res);

  return res;
}
#endif
ds_profile_db_result_type FileEFS::Delete(ds_profile_db_profile_num_type num,
                                          ds_profile_db_subs_type subs)
{
  ds_profile_db_result_type res;
  char file_name[MAX_PATH_LEN] = { };
  mcfg_fs_sub_id_e_type mcfg_subs_id = MCFG_FS_SUBID_NONE;
  if (DB_RESULT_SUCCESS != (res = (BuildFileName(num, file_name))))
  {
    return res;
  }

  if (-1 != fs_handle)
  {
    Close();
  }

  mcfg_subs_id = ds_profile_db_convert_ds_to_mcfg_subs(subs);

  if (MCFG_FS_STATUS_OK != mcfg_fs_delete(file_name, file_type, mcfg_subs_id))
  {
    PROFILE_DB_LOG_ERROR_1("Delete(): could not delete file, error %d", mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  return DB_RESULT_SUCCESS;
}


/*===========================================================================

                      PRIVATE FUNCTIONS

===========================================================================*/
ds_profile_db_result_type FileEFS::Open(const char *file_name, 
                                        FlagType flag /* = F_RW */, 
                                        ds_profile_db_subs_type subs /* = DB_PROFILE_ACTIVE_SUBSCRIPTION_1*/)
{
  ds_profile_db_profile_num_type _profile_num = 0;
  ds_profile_db_result_type res = ParseFileName(file_name, &_profile_num);
  if (DB_RESULT_SUCCESS != res)
  {
    PROFILE_DB_LOG_ERROR("Error during ParseFileName");
    return res;
  }

  return Open(_profile_num, flag, subs);
}

#ifdef FEATURE_USER_CONFIGURE_EFS
ds_profile_db_result_type FileEFS::Create(const Profile *profile,
                                          bool is_reset_event,
                                          bool reset_profile,
                                          bool is_create,
                                          bool is_3gpp2_default_profile)
{
  ds_profile_db_result_type result_type = DB_RESULT_FAIL;
  uint32 read_num_tlvs = 0;
  ds_profile_db_efs_header efs_header = { 0 };
  uint32 offset = 0;
  void *heapMemForFile = ds_profile_db_get_heap_mem_for_file();
  int size_to_write = 0;
  uint32 num_bytes = 0;
  uint16 tech_mask = 0;


  if (!profile)
  {
    PROFILE_DB_LOG_ERROR("Create in EFS(): profile pointer is NULL");
    return DB_RESULT_ERR_INVAL;
  }

  tech_mask = profile->GetSupportedTechMask();
  /* 

    1.)Get the changed Ident List along with Set and Reset
    2.)Read the File from EFS
    3.)Switch case to find if it is static or dynamic memory (ex : apn name)
    4.)See if the TLV already exists and overwrite the memory with other stuff.
    5.)Then copy over the changed idents.
    6.)Write the dynamic memory at the end.

  */
  //This file was never written. Write it with the header
  if (reset_profile || is_create)
  {
    efs_header.tech_mask = profile->GetSupportedTechMask();
    efs_header.num =  profile->GetNum();
    efs_header.size = 0;
    efs_header.magic_number = DS_PROFILE_DB_MAGIC_EFS_NUM;
    if (is_create)
    {
      efs_header.time_created = time_get_secs();
    } 
    else
    {
      efs_header.last_modified_time = time_get_secs();
    }
    efs_header.last_read_time = profile->GetReadTime();
    num_bytes = mcfg_fwrite(fs_handle, &efs_header, sizeof(efs_header), file_type);
    PROFILE_DB_LOG_HIGH_1("Create in EFS: Writing a new or resetting profile to "
                          "default size_to_write %d",
                          num_bytes);
    result_type = DB_RESULT_SUCCESS;
    goto bail;
  }
  if (!is_3gpp2_default_profile)
  {
    READ_FROM_INDEX(heapMemForFile, ds_profile_db_efs_header, efs_header);
    read_num_tlvs =  efs_header.num_tlvs;
    if (DS_PROFILE_DB_MAGIC_EFS_NUM != efs_header.magic_number)
    {
      result_type = DB_RESULT_FAIL;
      goto bail;
    }
    offset = EFS_HEADER_SIZE + efs_header.size;


    result_type = CheckEFSFileSize(offset, efs_header.tech_mask);
    if (DB_RESULT_SUCCESS != result_type)
    {
      PROFILE_DB_LOG_ERROR_1("Wrong size in the profile efs_header.size = %d", 
                              efs_header.size);
      goto bail;
    }
  }
  else
  {
    offset = EFS_HEADER_SIZE;
	  efs_header.tech_mask = profile->GetSupportedTechMask();
    efs_header.num =  profile->GetNum();
    efs_header.magic_number = DS_PROFILE_DB_MAGIC_EFS_NUM;
  }

  DB_FOR_EVERY_TECH_IN_MASK_DO_START(tech_mask, tech)
    result_type = GetIdentToUpdateEFS(profile,
                                    DB_TECH_TO_TECHMASK(tech),
                                      &offset, &efs_header,
                                      &read_num_tlvs,
                                      is_reset_event,
                                      true);
    if (DB_RESULT_SUCCESS != result_type)
    {
      goto bail;
    }
  DB_FOR_EVERY_TECH_IN_MASK_DO_END

  //Now write everything to file
  //1.) Update the header with the num tlv
  //2.) Update the size and write everything to EFS

  efs_header.size = (offset - sizeof(efs_header));
  efs_header.last_modified_time = time_get_secs();

  result_type = CheckEFSFileSize(offset, efs_header.tech_mask);
  if (DB_RESULT_SUCCESS != result_type)
    {
    PROFILE_DB_LOG_ERROR_1("Wrong size in the profile efs_header.size = %d", 
                            efs_header.size);
      goto bail;
    }

  memscpy(heapMemForFile, (MAX_TLV_SIZE), &efs_header, sizeof(efs_header));
  size_to_write = efs_header.size + sizeof(efs_header);
  if (size_to_write != mcfg_fwrite(fs_handle, heapMemForFile, size_to_write, file_type))
  {
    PROFILE_DB_LOG_ERROR_2("WriteParams(): wrong number of bytes written %d or error %d", size_to_write, mcfg_fs_errno( file_type ));
    result_type = DB_RESULT_ERR_FILE_ACCESS;
    goto bail;
  }

bail:
  PROFILE_DB_LOG_HIGH_3("Create in EFS: status %d, size_to_write %d, size stored in header %d",
                        result_type, size_to_write, efs_header.size);
  Close();
  return result_type;
}
#else
ds_profile_db_result_type FileEFS::Create(const Profile *profile) const
{
  ds_profile_db_result_type res;

  /* First, write the general params */
  /**********************************/

  /* validate the profile number */
  if (profile_num != profile->GetNum())
  {
    return DB_RESULT_ERR_INVAL_PROFILE_NUM;
  }
  res = WriteParams(profile, DB_TECH_MAX);
  if (DB_RESULT_SUCCESS != res)
  {
    return res;
  }


  /* Second, write all the tech params blocks */
  /**********************************/
  for (int tech = DB_TECH_MIN; tech < DB_TECH_MAX; tech++)
  {
    res = WriteParams(profile, (ds_profile_db_tech_type)tech);
    if (DB_RESULT_SUCCESS != res && DB_RESULT_ERR_INVAL_PROFILE_TYPE != res)
    {
      return res;
    }
  }

  return DB_RESULT_SUCCESS;
}
#endif
ds_profile_db_result_type FileEFS::Update(const Profile *profile) const
{
  return DB_RESULT_SUCCESS;
}


ds_profile_db_result_type FileEFS::WriteParams(const Profile *profile,
                                               ds_profile_db_tech_type tech) const
{
#ifdef FEATURE_USER_CONFIGURE_EFS
  return DB_RESULT_SUCCESS;
#else
  fs_ssize_t num_bytes = 0;

  const void *params = GetProfileCParamsPtr(profile, tech);
  if (!params)
  {
    return DB_RESULT_ERR_INVAL_PROFILE_TYPE;
  }

  /* write technology */
  num_bytes = mcfg_fwrite(fs_handle, &tech, TECH_FIELD_SIZE, file_type);
  if (TECH_FIELD_SIZE != num_bytes)
  {
    PROFILE_DB_LOG_ERROR_2("WriteParams(): wrong number of bytes written %d or error %d", num_bytes, mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  /* write struct size */
  size_t struct_size = Profile::GetCStructSize(tech);
  num_bytes = mcfg_fwrite(fs_handle, &struct_size, STRUCT_SIZE_FIELD_SIZE, file_type);
  if (STRUCT_SIZE_FIELD_SIZE != num_bytes)
  {
    PROFILE_DB_LOG_ERROR_2("WriteParams(): wrong number of bytes written %d or error %d", num_bytes, mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  /* write the struct itself */
  num_bytes = mcfg_fwrite(fs_handle, params, struct_size, file_type);
  if (struct_size != num_bytes)
  {
    PROFILE_DB_LOG_ERROR_2("WriteParams(): wrong number of bytes written %d or error %d", num_bytes, mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  return DB_RESULT_SUCCESS;
#endif
}

ds_profile_db_result_type FileEFS::ReadParams(void *c_params,
                                              ds_profile_db_tech_type *tech,
                                              bool read_gen_params /* = false */) const
{
#ifdef FEATURE_USER_CONFIGURE_EFS
  return DB_RESULT_SUCCESS;
#else
  ds_profile_db_result_type res;
  size_t struct_size_in_file = 0;
  fs_ssize_t num_bytes = 0;


  /* read tech */
  *tech = DB_TECH_MIN;
  num_bytes = mcfg_fread(fs_handle, tech, TECH_FIELD_SIZE, file_type);
  /* we reached the end */
  if (0 == num_bytes)
  {
    return DB_RESULT_ERR_EOF;
  }

  if (TECH_FIELD_SIZE != num_bytes)
  {
    PROFILE_DB_LOG_ERROR_2("ReadParams(): wrong number of bytes read %d or error %d", num_bytes, mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  /* if we are reading gen params, technology should be DB_TECH_MAX, 
     otherwise it can be any valid technology */
  if (read_gen_params)
  {
    if (DB_TECH_MAX != *tech)
    {
      PROFILE_DB_LOG_ERROR_2("ReadParams(): expected to read DB_TECH_MAX(%d) technology, got %d instead",
                             DB_TECH_MAX, *tech);
      return DB_RESULT_ERR_INVAL_PROFILE_TYPE;
    }
  } else
  {
    if (DB_RESULT_SUCCESS != (res = Profile::ValidateTech(*tech)))
    {
      return res;
    }
  }

  /* read struct size */
  num_bytes = mcfg_fread(fs_handle, &struct_size_in_file, STRUCT_SIZE_FIELD_SIZE, file_type);
  if (STRUCT_SIZE_FIELD_SIZE != num_bytes)
  {
    PROFILE_DB_LOG_ERROR_2("ReadParams(): wrong number of bytes read %d or error %d", num_bytes, mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  /* read tech params */
  /* if we need to read more than it was actually written, it means that
     our current profile version is newer than the one saved. We need to
     fill the missing params with default values */
  size_t real_struct_size = Profile::GetCStructSize(*tech);
  if (real_struct_size > struct_size_in_file)
  {
    if (DB_RESULT_SUCCESS != (res = Profile::GetDefaultCParams(*tech, c_params)))
    {
      return res;
    }
  }

  num_bytes = mcfg_fread(fs_handle, c_params, struct_size_in_file, file_type);
  if (struct_size_in_file != num_bytes)
  {
    PROFILE_DB_LOG_ERROR_2("ReadParams(): wrong number of bytes read %d or error %d", num_bytes, mcfg_fs_errno( file_type ));
    return DB_RESULT_ERR_FILE_ACCESS;
  }

  return DB_RESULT_SUCCESS;
#endif
}

ds_profile_db_result_type FileEFS::Init(void)
{
  struct fs_stat dont_care;
  int            efs_res;

  efs_res = mcfg_fs_stat((char *)PROFILE_DIR,
                         &dont_care,
                         file_type,
                         MCFG_FS_SUBID_NONE);

  if (efs_res != MCFG_FS_STATUS_OK)
  {
    /*-----------------------------------------------------------------------
       ENOENT means no such file or directory
    -----------------------------------------------------------------------*/
    if (mcfg_fs_errno( file_type ) == ENOENT)
    {
      /*-----------------------------------------------------------------------
        If directory is not already present, create the directory first
      -----------------------------------------------------------------------*/
      if (mcfg_mkdir(PROFILE_DIR,
                     MCFG_FS_ALLPERMS,
                     file_type) == -1)
      {
        PROFILE_DB_LOG_ERROR_1("Init(): error %d while creating profiles directory",
                               mcfg_fs_errno( file_type ));
        return DB_RESULT_ERR_FILE_ACCESS;
      }
    } 
    else
    {
      PROFILE_DB_LOG_ERROR_1("Init(): error %d while invoking efs_stat", mcfg_fs_errno( file_type ));
      return DB_RESULT_ERR_FILE_ACCESS;
    }
  }

  return DB_RESULT_SUCCESS;
}

ds_profile_db_result_type FileEFS::ReadAll(Profile **profiles, unsigned int *count,
                                           ds_profile_db_subs_type subs /*= DB_PROFILE_ACTIVE_SUBSCRIPTION_1*/)
{
  fs_dirent      *dirent = NULL;
  char   file_path[MAX_PATH_LEN] = { };
  uint32                 fmode = 0;
  fs_stat         efs_file_info;
  ds_profile_db_result_type res = DB_RESULT_SUCCESS;
  unsigned int new_count = 0;
  mcfg_fs_sub_id_e_type mcfg_subs_id = MCFG_FS_SUBID_NONE;

  EFSDIR* dirp = mcfg_fs_opendir( PROFILE_DIR, file_type );
  /* ENOENT stands for No such file or directory */
  if( (dirp == NULL) || (EFSDIR*)-1 == dirp) {   
      PROFILE_DB_LOG_HIGH_STR_1("ReadAll(): Could not open profiles directory: %s", PROFILE_DIR);
      PROFILE_DB_LOG_HIGH("ReadAll(): Will try to create it");
    if (-1 == mcfg_mkdir(PROFILE_DIR, MCFG_FS_ALLPERMS, file_type))
      {
        PROFILE_DB_LOG_ERROR("ReadAll(): Could not create profiles directory");
        ds_profile_error_read_operation |= ERR_DIR_CREATE;
        return DB_RESULT_FAIL;
      }
    dirp = mcfg_fs_opendir(PROFILE_DIR, file_type);  //Open after creating dir
    if ((dirp == NULL) || (EFSDIR *)-1 == dirp)
    {
      PROFILE_DB_LOG_ERROR("ReadAll(): Could not open profiles directory");
      ds_profile_error_read_operation |= ERR_DIR_ACCESS;
      return DB_RESULT_FAIL;
    }
  }

  mcfg_subs_id = ds_profile_db_convert_ds_to_mcfg_subs(subs);
  while ((dirent = mcfg_fs_readdir_subid(dirp, file_type, mcfg_subs_id)) != 0)
  {
    memset(file_path, 0, sizeof(file_path));

    if (strlcpy(file_path,  PROFILE_DIR, sizeof(file_path)) >= sizeof(file_path)) 
    {
      res = DB_RESULT_ERR_INVAL;
      PROFILE_DB_LOG_ERROR("Error during strlcpy");
      ds_profile_error_read_operation |= ERR_STRING_FAIL;
      continue;
    }

    if (strlcat(file_path,  dirent->d_name, sizeof(file_path)) >= sizeof(file_path))
    {
      res = DB_RESULT_ERR_INVAL;
      PROFILE_DB_LOG_ERROR("Error during strlcat");
      ds_profile_error_read_operation |= ERR_STRING_FAIL;
      continue;
    }

    /* Check if mode is returned; otherwise call stat to get mode. */
    if (FS_MASK_CHECK(dirent->d_stats_present, FS_DIRENT_HAS_ST_MODE))
    {
      fmode = dirent->d_stat.st_mode;
    } 
    else
    {
      if (mcfg_fs_stat(file_path, &efs_file_info, file_type, mcfg_subs_id) != MCFG_FS_STATUS_OK)
      {
        res = DB_RESULT_ERR_FILE_ACCESS;
        PROFILE_DB_LOG_ERROR("EFS stat for File access failure");
        ds_profile_error_read_operation |= ERR_FILE_ACCESS;
        continue;
      }
      fmode = efs_file_info.st_mode;
    }

    /* This is a file*/
    if (S_ISREG(fmode) || S_ISITM(fmode))
    {
      /* this should set profile_num field */
      if (DB_RESULT_SUCCESS != (res = Open(file_path, F_READ, subs)))
      {
        PROFILE_DB_LOG_ERROR("Writing res for Open Failure");
        ds_profile_error_read_operation |= ERR_PARSE_FILENAME;
        PROFILE_DB_LOG_ERROR_1("ReadAll(): error while reading profile number %d, deleting it", profile_num);
        if (mcfg_fs_delete(file_path, file_type, mcfg_subs_id) != MCFG_FS_STATUS_OK)
        {
          PROFILE_DB_LOG_ERROR_1("ReadAll(): could not delete file, error %d", mcfg_fs_errno( file_type ));
        }
        continue;
      }

      if (DB_RESULT_SUCCESS != (res = Read(&(profiles[new_count]))))
      {
        PROFILE_DB_LOG_ERROR_1("ReadAll(): error while reading profile number %d, deleting it", profile_num);
        if (mcfg_fs_delete(file_path, file_type, mcfg_subs_id) != MCFG_FS_STATUS_OK)
        {
          PROFILE_DB_LOG_ERROR_1("ReadAll(): could not delete file, error %d", mcfg_fs_errno( file_type ));
        }
         if (profiles[new_count])
        {
          delete profiles[new_count];
          profiles[new_count] = NULL;
        }
        continue;
      }
      profiles[new_count]->SetSubscriptionId(subs, false);
      new_count++;
      if (new_count >= DS_PROFILE_DB_MAX_PERS_PROFILE_COUNT)
      {
        res = DB_RESULT_ERR_OUT_OF_PROFILES;
        *count = new_count;
        goto bail;
      }
      if (new_count > *count)
      {
        PROFILE_DB_LOG_ERROR("Writing res for out_of_profiles");
        res = DB_RESULT_ERR_OUT_OF_PROFILES;
        goto bail;
      }
    }
  } /* while */

  *count = new_count;
  /* fall through */

  res =  DB_RESULT_SUCCESS;

bail:
  if (dirp)
  {
    mcfg_fs_closedir(dirp, file_type);
  }

  if (res != DB_RESULT_SUCCESS)
  {
    PROFILE_DB_LOG_ERROR_2("ReadAll(): error occurred %d, mcfg_fs_errno( file_type ) %d", res, mcfg_fs_errno( file_type ));
  }

  return res;
}

#ifdef FEATURE_USER_CONFIGURE_EFS
bool FileEFS::CheckIdentExistsHelper
(
  ds_profile_db_ident_type ident,
  uint32 read_tlv,
  uint32 *offset
  ) const
{
  char *prev_offset_ptr = NULL;
  char *offset_ptr = NULL;
  uint16 len;
  char *end_ptr = NULL;
  uint32 num_tlvs = 0;
  uint32 local_size = *offset;
  uint32 dest_size = 0;
  uint32 size_to_copy = 0;
  uint32 written_size = 0;
  void *heapMemForFile = ds_profile_db_get_heap_mem_for_file();
  ds_profile_db_ident_type read_ident = INVALID_PROFILE_PARAM;
  uint16 read_ident_val = 0;

  offset_ptr = (char *)heapMemForFile + EFS_HEADER_SIZE;
  end_ptr = (char *)heapMemForFile + local_size;
  while ((offset_ptr <= (offset_ptr + MAX_TLV_SIZE)) && (num_tlvs < read_tlv))
  {
    num_tlvs++;
    READ_FROM_INDEX(offset_ptr, TLV_LEN, read_ident_val);
    read_ident = (ds_profile_db_ident_type)read_ident_val;
    if (ident == (read_ident))
    {
      PROFILE_DB_LOG_HIGH_1("CheckIdent(): Found ident %d ", read_ident);
      prev_offset_ptr = offset_ptr;
      offset_ptr += DS_PROFILE_DB_IDENT_SIZE;
      *offset -= DS_PROFILE_DB_IDENT_SIZE;
      READ_FROM_INDEX(offset_ptr, TLV_LEN, len);
      offset_ptr += len + DS_PROFILE_DB_PARAM_LEN_SIZE;
      *offset -= (len + DS_PROFILE_DB_PARAM_LEN_SIZE);
      dest_size = (end_ptr - prev_offset_ptr);
      size_to_copy = (end_ptr - offset_ptr);

      written_size = memsmove((void *)prev_offset_ptr, dest_size, (void *)offset_ptr, size_to_copy);

      if (written_size != size_to_copy)
      {
        PROFILE_DB_LOG_HIGH("Memsmove failure");
      }

      return true;
    } 
    else
    {
      //Go forward by the len and ident
      offset_ptr += DS_PROFILE_DB_IDENT_SIZE;
      READ_FROM_INDEX(offset_ptr, TLV_LEN, len);
      offset_ptr += len + DS_PROFILE_DB_PARAM_LEN_SIZE;
    }
  }
  return false;
}

ds_profile_db_result_type FileEFS::ReadTLV(void)
{
  uint32 num_bytes = 0;
  void *heapMemForFile = ds_profile_db_get_heap_mem_for_file();
  memset(heapMemForFile, 0, MAX_TLV_SIZE);
  num_bytes = mcfg_fread(fs_handle, heapMemForFile, MAX_TLV_SIZE, file_type);
  /* we reached the end */
  PROFILE_DB_LOG_HIGH_1("READTLV(): number of bytes Read %d or error %d", num_bytes);

  if (0 == num_bytes)
  {
    return DB_RESULT_ERR_EOF;
  }
  if (num_bytes >= MAX_TLV_SIZE)
  {
    return DB_RESULT_FAIL;
  }
  Close();
  return DB_RESULT_SUCCESS;
}

ds_profile_db_result_type FileEFS::GetIdentToUpdateEFS(const Profile *profile,
                                                       ds_profile_db_supported_tech_mask tech_mask,
                                                       uint32 *offset,
                                                       ds_profile_db_efs_header *efs_header,
                                                       uint32 *read_num_tlvs,
                                                       boolean is_reset_event,
                                                       boolean update_gen_ident) const
{
  ds_profile_db_result_type result_type;
  uint16 gen_ident_count = 0;
  uint16 ident_count = 0;
  char *offset_ptr = NULL;
  ds_profile_db_info_type param_info = { 0 };
  char data[MAX_DATA_SIZE] = { 0 };
  ds_profile_db_ident_type *ident_ptr = NULL;
  ds_profile_db_ident_type *gen_ident_ptr = NULL;
  void *heapMemForFile = ds_profile_db_get_heap_mem_for_file();

  if (!profile)
  {
    PROFILE_DB_LOG_ERROR("Read(): profile pointer is NULL");
    return DB_RESULT_ERR_INVAL;
  }

  memset(data, 0, sizeof(data));
  result_type = ds_profile_db_get_changed_idents((ds_profile_db_profile_managed_type *)profile,
                                                 tech_mask, &ident_ptr,
                                                 &ident_count, &gen_ident_ptr, &gen_ident_count);

  if (result_type != DB_RESULT_SUCCESS)
  {
    goto bail;
  }

  /*1.) GO over changed idents 
    2.) Check if it already exists from the read buffer
    3.) If yes overwrite starting from next TLV
    4.) append the current changed TLV at end
  */

  if (update_gen_ident)
  {
    for (int iter = 0; iter < gen_ident_count; iter++)
    {
      if (gen_ident_ptr)
      {
        param_info.buf = data;
        param_info.len = MAX_DATA_SIZE;
        //Check if the ident exists and remove from the memory
        if (CheckIdentExistsHelper(gen_ident_ptr[iter], *read_num_tlvs, offset))
        {
          if (*read_num_tlvs != 0)
          {
            *read_num_tlvs = *read_num_tlvs - 1;
          }
          if (efs_header->num_tlvs)
          {
            efs_header->num_tlvs--;
          }
        }

        if (!is_reset_event)
        {
          if (DB_RESULT_SUCCESS == (result_type = profile->GetParam(gen_ident_ptr[iter], &param_info)))
          {
            offset_ptr = (char *)heapMemForFile + *offset;
            memscpy(offset_ptr, (MAX_TLV_SIZE - (*offset)), &(gen_ident_ptr[iter]), DS_PROFILE_DB_IDENT_SIZE);
            *offset += DS_PROFILE_DB_IDENT_SIZE;
            offset_ptr += DS_PROFILE_DB_IDENT_SIZE;
            memscpy(offset_ptr, (MAX_TLV_SIZE - (*offset)), &(param_info.len), DS_PROFILE_DB_PARAM_LEN_SIZE);
            *offset += DS_PROFILE_DB_PARAM_LEN_SIZE;
            offset_ptr += DS_PROFILE_DB_PARAM_LEN_SIZE;
            memscpy(offset_ptr, (MAX_TLV_SIZE - (*offset)), param_info.buf, param_info.len);
            *offset += param_info.len;
            offset_ptr += param_info.len;
          } else
          {
            PROFILE_DB_LOG_ERROR_1("Get Param failed . Status %d", result_type);
            goto bail;
          }
          efs_header->num_tlvs++;
        }
      }
    }
  }

  for (int iter = 0; iter < ident_count; iter++)
  {
    if (ident_ptr)
    {
      param_info.buf = data;
      param_info.len = MAX_DATA_SIZE;
      if (CheckIdentExistsHelper(ident_ptr[iter], *read_num_tlvs, offset))
      {
        if (*read_num_tlvs != 0)
        {
          *read_num_tlvs = *read_num_tlvs - 1;
        }
        if (efs_header->num_tlvs)
        {
          efs_header->num_tlvs--;
        }
      }
      if (!is_reset_event)
      {
        if (DB_RESULT_SUCCESS == (result_type = profile->GetParam(ident_ptr[iter], &param_info)))
        {
          offset_ptr = (char *)heapMemForFile + *offset;
          if (DS_PROFILE_DB_IDENT_SIZE !=
                memscpy(offset_ptr, (MAX_TLV_SIZE - (*offset)), &(ident_ptr[iter]), DS_PROFILE_DB_IDENT_SIZE))
          {
            PROFILE_DB_LOG_ERROR("Error writing Ident to memory");
            result_type = DB_RESULT_FAIL;
            goto bail;
          }
          *offset += DS_PROFILE_DB_IDENT_SIZE;
          offset_ptr += DS_PROFILE_DB_IDENT_SIZE;
          memscpy(offset_ptr, (MAX_TLV_SIZE - (*offset)), &(param_info.len), DS_PROFILE_DB_PARAM_LEN_SIZE);
          *offset += DS_PROFILE_DB_PARAM_LEN_SIZE;
          offset_ptr += DS_PROFILE_DB_PARAM_LEN_SIZE;
          memscpy(offset_ptr, (MAX_TLV_SIZE - (*offset)), param_info.buf, param_info.len);
          *offset += param_info.len;
          offset_ptr += param_info.len;
        } else
        {
          PROFILE_DB_LOG_ERROR_1("Get Param failed . Status %d", result_type);
          goto bail;
        }
        efs_header->num_tlvs++;
      }
    }
  }

bail:
  if (ident_ptr)
  {
    ds_profile_db_free_idents(ident_ptr);
    ident_ptr = NULL;
  }
  if (gen_ident_ptr)
  {
    ds_profile_db_free_idents(gen_ident_ptr);
    gen_ident_ptr = NULL;
  }
  return result_type;
}

#endif