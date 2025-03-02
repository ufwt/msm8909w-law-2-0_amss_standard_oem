/*============================================================================
@file ULogDiag.c

ULog Diagnostic Interface to support reading and controlling ULog logs
via DIAG commands.

Copyright (c) 2003-2013, 2015-2016 Qualcomm Technologies Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary

$Header: //components/rel/core.mpss/3.5.c12.3/power/ulog/src/ULogDiag.c#1 $
============================================================================*/
#include "ULogBuildFeatures.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ULog.h"
#ifndef DEFEATURE_ULOG_DIAG
#include <stddef.h>
#include "comdef.h"
#include "diagcmd.h"
#include "diagpkt.h"
#include "DALSys.h"
#include "ULogDiagFormat.h"
#include "ULogFront.h"


typedef struct external_ulog_handle
{
  struct external_ulog_handle * next;
  ULogHandle internalHandle;
  ULogHandle externalHandle;
} external_ulog_handle;

static external_ulog_handle * ulogDiagExtHeadPtr = NULL;

typedef struct ulog_diag_plugin_handle
{
  struct ulog_diag_plugin_handle * next;
  uint32 plugin_id; 
  int (*plugin_fcn) (uint32 msg_to_plugin);
  int (*plugin_fcn_ext) (void* msg_to_plugin, unsigned long int msg_size);
} ulog_diag_plugin_handle;

static ulog_diag_plugin_handle * ulogDiagPluginHeadPtr = NULL;


/**
 * <!-- GetExternalHandle -->
 *
 * @brief Given an internal handle, create a new handle if we haven't created one already.
 *
 * @return an external handle that we can share with diag and use to validate 
 * future diag requests.
 */
static ULogHandle GetExternalHandle(ULogHandle handle)
{
  external_ulog_handle * idxHandle = ulogDiagExtHeadPtr;
  external_ulog_handle * prevHandle;
  external_ulog_handle * newHandle;

  if (ulogDiagExtHeadPtr == NULL)   //no preexisting list of handles, start one
  {
    DALSYS_Malloc( sizeof(external_ulog_handle), (void **)&newHandle );
    if (newHandle != NULL)
    {
      newHandle->next = NULL;
      newHandle->internalHandle = handle;
      newHandle->externalHandle = (ULogHandle)1;
      ulogDiagExtHeadPtr = newHandle;
      return(newHandle->externalHandle);
    }
  }
  else                      //a list exists, search for a match, create a new handle if match not found
  {
    prevHandle = ulogDiagExtHeadPtr;
    while (idxHandle != NULL)
    {
      if (idxHandle->internalHandle == handle)
      {
        // We found a matching handle.
        return(idxHandle->externalHandle);
      }

      prevHandle = idxHandle;
      idxHandle = idxHandle->next;
    }

    //no matching handle found, create one
	DALSYS_Malloc( sizeof(external_ulog_handle), (void **)&newHandle );
	if (newHandle != NULL)
    {
      newHandle->next = NULL;
      newHandle->internalHandle = handle;
      newHandle->externalHandle = (ULogHandle)((int)prevHandle->externalHandle+1);
      prevHandle->next = newHandle;
      return(newHandle->externalHandle);
    }
  }

  return(NULL);
}


/**
 * <!-- GetInternalHandle -->
 * 
 * @brief Given an external handle, find the corresponding internal handle and return it.
 *
 * @return An internal handle or NULL if the handle was not found. 
 */
static ULogHandle GetInternalHandle(ULogHandle handle)
{
  external_ulog_handle * idxHandle = ulogDiagExtHeadPtr;

  if (handle != NULL)
  {
    while (idxHandle != NULL)
    {
      if (idxHandle->externalHandle == handle)
      {
        return(idxHandle->internalHandle);
      }
      idxHandle = idxHandle->next;
    }
  }
  return(NULL);
}


/**
 * <!-- ULogDiag_RunPlugin -->
 *
 * @brief See if we have a registered plugin for the requested id, run it. 
 *
 * Plugins should mostly return DAL_SUCCESS, or DAL_ERROR.
 * For more complicated return values, values 10000 to 20000 
 * should remain unused by normal ULog return values and 
 * can be returned. The PC application uses ULOG_ERR_NOTCONNECTED
 * to indicate an ID has no plugin attached to it. 							
 *
 * @return the return value, usually DAL_SUCCESS, or ULOG_ERR_NOTCONNECTED
 */
static int ULogDiag_RunPluginInternal
(
  uint32 selected_plugin_id, 
  void *msg_to_plugin, 
  unsigned long int msg_size, 
  int is_ext
)
{
  ulog_diag_plugin_handle * idxHandle = ulogDiagPluginHeadPtr;

  if (ulogDiagPluginHeadPtr == NULL)   
  {
    return ULOG_ERR_NOTCONNECTED;
  }

  while (idxHandle != NULL)
  {
    if (idxHandle->plugin_id == selected_plugin_id)  
    {
      // found the id, run the plugin function
      if (is_ext)
      {
        return idxHandle->plugin_fcn_ext(msg_to_plugin, msg_size);
      }
      else
      {
        return idxHandle->plugin_fcn((uint32)msg_to_plugin);
      }
    }
    idxHandle = idxHandle->next;
  }

  return ULOG_ERR_NOTCONNECTED;
}

int ULogDiag_RunPlugin(uint32 selected_plugin_id, uint32 msg_to_plugin)
{
  return ULogDiag_RunPluginInternal(selected_plugin_id, 
                                    (void*)msg_to_plugin, sizeof(uint32), 0);
}

int ULogDiag_RunPluginExt
(
  uint32 selected_plugin_id,
  void* msg_to_plugin,
  unsigned long int msg_size
)
{
  if (msg_size > MAX_PLUGIN_EXT_SIZE)
  {
    return ULOG_ERR_OVERRUN;
  }
  return ULogDiag_RunPluginInternal(selected_plugin_id, 
                                      msg_to_plugin, msg_size, 1);
}

/**
 * <!-- ULogDiagAddPlugin -->
 *
 * @brief Setup and enable a ULog Diag plugin.
 * 
 * When the PC based ULogDiagPluginLauncher.exe is run, the plugin with a 
 * matching plugin_id will be run with a 32 bit int passed as an argument 
 * to the plugin. These plugins can be used to create useful analysis tools.
 * For example: when the PC ULogDiagPluginLauncher is run:
 *     ULogDiagPluginLauncher.exe COM12 Modem 1 0
 * The plugin that the NPA team provides as 
 *     ULogDiagAddPlugin(npa_generate_dump_log, ULOG_DIAG_PLUGIN_ID_NPADUMP); 
 * will create a new ULog called "NPA Dump Log" that can be read out with
 * the ULogDiagReader tool.  
 *
 * Plugins should mostly return DAL_SUCCESS, or DAL_ERROR.
 * For more complicated return values, values 10000 to 20000 
 * should remain unused by normal ULog return values and 
 * can be returned. The PC application uses ULOG_ERR_NOTCONNECTED
 * to indicate an ID has no plugin attached to it. 							
 *
 * @param new_pluginfcn : A function pointer to a plugin.  The plugin accepts 
 *                        a uint32 as an input and returns an integer.
 * @param new_plugin_id : A uint32 id that the plugin will be registered with.  
 *
 * @return DAL_SUCCESS if the plugin is registered successfully, an error code if it isn't. 
 */
static ULogResult ULogDiagAddPluginInternal
(
  uint32 new_plugin_id,
  int(*new_pluginfcn)(uint32), 
  int(*new_pluginfcnext)(void*, unsigned long int),
  int is_ext
)
{
  ulog_diag_plugin_handle * idxHandle = ulogDiagPluginHeadPtr;
  ulog_diag_plugin_handle * prevHandle;
  ulog_diag_plugin_handle * newHandle;
  
  if ((new_pluginfcn==NULL) && (!is_ext))
  {
    return ULOG_ERR_INVALIDPARAMETER;
  }

  if ((new_pluginfcnext==NULL) && (is_ext))
  {
    return ULOG_ERR_INVALIDPARAMETER;
  }

  if (ulogDiagPluginHeadPtr == NULL)   //no preexisting list of handles, start one
  {
    DALSYS_Malloc(sizeof(ulog_diag_plugin_handle), (void **)&newHandle);
    if (newHandle != NULL)
    {
      newHandle->next = NULL;
      newHandle->plugin_id = new_plugin_id;
      if (is_ext)
      {
        newHandle->plugin_fcn_ext = new_pluginfcnext;
        newHandle->plugin_fcn = NULL;
      }
      else
      {
      newHandle->plugin_fcn = new_pluginfcn;
        newHandle->plugin_fcn_ext = NULL;
      }
      ulogDiagPluginHeadPtr = newHandle;
      return(DAL_SUCCESS);
    }
  }
  else                      //a list exists, search for a match, create a new handle if match not found
  {
    prevHandle = ulogDiagPluginHeadPtr;
    while (idxHandle != NULL)
    {
      if (idxHandle->plugin_id == new_plugin_id)  
      {
        // The id is already taken.  Return an error.
        return ULOG_ERR_ALREADYCONNECTED;
      }

      prevHandle = idxHandle;
      idxHandle = idxHandle->next;
    }

    //no matching handle found, create one
    DALSYS_Malloc(sizeof(ulog_diag_plugin_handle), (void **)&newHandle);
    if (newHandle != NULL)
    {
      newHandle->next = NULL;
      newHandle->plugin_id = new_plugin_id;
      if (is_ext)
      {
        newHandle->plugin_fcn_ext = new_pluginfcnext;
        newHandle->plugin_fcn = NULL;
      }
      else
      {
      newHandle->plugin_fcn = new_pluginfcn;
        newHandle->plugin_fcn_ext = NULL;
      }
      prevHandle->next = newHandle;
      return DAL_SUCCESS;
    }
  }
   return DAL_SUCCESS;
}

ULogResult ULogDiagAddPlugin(int(*new_pluginfcn)(uint32), uint32 new_plugin_id)
{
  return ULogDiagAddPluginInternal(new_plugin_id, new_pluginfcn, NULL, 0);
}

ULogResult ULogDiagAddPluginExt
(
  int(*new_pluginfcnext)(void*, unsigned long int),
  uint32 new_plugin_id
)
{
  return ULogDiagAddPluginInternal(new_plugin_id, NULL, new_pluginfcnext, 1);
}
/**
 * <!-- ULogDiagFormatPayload -->
 *
 * @brief Formats a payload suitable for a diag response or log packet
 *
 * @param handle : Pointer to ULog handle to read from
 * @param format_req : Format of payload to generate (ASCII, BINARY)
 * @param format_rsp : Format of payload generated
                       (will contain OVERRUN information if needed)
 * @param buf_size : size of payload_buf
 * @param payload_buf : pointer to payload buffer where output will be written
 * @param bytes_written: set to number of bytes written to payload_buf
 *                       upon exitting this function. A value of 0 can
 *                       indicate an empty ULog, or that a rewind has occurred.
 *
 * @return DAL_SUCCESS if successful. (bytes_written value of 0 with DAL_SUCCESS indicates an empty ULog)
 *         Error are definded in the ULOG_ERRORS enum.
 *         ULOG_ERR_MISC in this case represents that the ULog was rewound while trying to read from it.
 *      
 */
ULogResult ULogDiagFormatPayload(ULogHandle handle, int format_req, unsigned long int *format_rsp, int buf_size, char * payload_buf, unsigned long int *bytes_written)
{
  ULogResult rval = ULOG_ERR_INVALIDPARAMETER;
  
  if((handle==NULL) || (bytes_written==NULL) || (format_rsp==NULL))
  {
    return ULOG_ERR_INVALIDPARAMETER;
  }

  if(format_req == ULOGDIAG_FORMAT_BINARY)
  {
    *format_rsp = ULOGDIAG_FORMAT_BINARY;
    if(ULOG_ERR_OVERRUN == 
      ULogCore_Read (handle, buf_size, payload_buf, bytes_written))
    {
      *format_rsp = ULOGDIAG_FORMAT_BINARY_OVERRUN_DETECTED;
    }
    rval = DAL_SUCCESS;
  }
  else if(format_req == ULOGDIAG_FORMAT_ASCII)
  { 
    char * stringStart = (char *)payload_buf;
    uint32 outputMsgIndex = 0;
    uint32 msgConsumed;
    uint32 oneMsgBuffer[256];
    uint32 readOutputLength = 0;
    uint32 readFlags;
    
    // Null terminate the output buffer.
    *bytes_written = 0;
    payload_buf[0] = 0;

    ULogCore_Query(handle,
      ULOG_VALUE_LOG_READFLAGS,
      &readFlags);

    if (readFlags & ULOG_RD_FLAG_REWIND)
    {
      // We just had a log rewind.  Return a zero length payload and set ERR code to MISC
      rval = ULOG_ERR_MISC;
    }
    else 
    {
      // While the log is has messages in it, or the output buffer
      // is not full, continue reading from the log
      while (1)
      {
        *format_rsp = ULOGDIAG_FORMAT_ASCII;
        
        if(ULOG_ERR_OVERRUN == 
          ULogCore_ReadEx (handle,  
            sizeof(oneMsgBuffer),  
            (char *)oneMsgBuffer,  
            &readOutputLength,
            1))
        {
          *format_rsp	= ULOGDIAG_FORMAT_ASCII_OVERRUN_DETECTED;
        }
		
        // Read one message from the log
        if (readOutputLength > 4)
        {
          
          // Convert it and put it in the output buffer.
          ULogCore_MsgFormat (handle,
            (char *)&oneMsgBuffer[1],  // Skip the status
            &stringStart[outputMsgIndex], 
            buf_size - outputMsgIndex, 
            &msgConsumed);
          
          // Now how full is our output buffer
          outputMsgIndex = strlen(stringStart);
          
          *bytes_written = outputMsgIndex;
          
          // If we have filled enough of the output buffer,
          // call it good and return.
          if ((buf_size - outputMsgIndex) < 255)
          {
            rval = DAL_SUCCESS;
            break; // break from while loop
          }
        }
        else
        {
          // The log has no data.  This may cause the rewind flag to be set, so
          // let's make sure it is cleared.
          
          if (*bytes_written == 0)
          {
            ULogCore_Query(handle, ULOG_VALUE_LOG_READFLAGS, &readFlags);
          }
          rval = DAL_SUCCESS;            
          break; // break from while loop
        }
      } // while loop
    }
  }
  
  return rval;
}


/**
 * <!-- ULogDiagReadAndFormat -->
 * 
 * @brief Read and format messages until the output buffer is full enough.
 *
 * @return A pointer to response packet.
 */
static PACKED void * ULogDiagReadAndFormat(ulogdiag_cmd_type_read * readCmd)
{
  ulogdiag_cmd_rsp_type_read * readRsp;
  ULogHandle localHandle;
  unsigned baseOffsetBytes = offsetof(ulogdiag_cmd_rsp_type_read, response);  
  ULogResult rval;
  
  // If we are outputting in binary format, then the data is read
  // directly to the output buffer.
  // If we are outputting in ascii format, then the data is read to
  // a temporary buffer, and then formatted to the output buffer.
  readRsp = (ulogdiag_cmd_rsp_type_read *) diagpkt_subsys_alloc (DIAG_SUBSYS_ULOG,
                                    (uint16) readCmd->header.subsysCmdCode, 
                                    sizeof(ulogdiag_cmd_rsp_type_read));
  if(readRsp == NULL)
  {
    return (readRsp);
  }

  localHandle = GetInternalHandle(readCmd->handle);
  if (localHandle == NULL)
  {
    return(NULL);
  }

  rval = ULogDiagFormatPayload(localHandle, readCmd->outputFormat, &readRsp->outputFormat,
    sizeof(readRsp->response), readRsp->response, &readRsp->outputLength);

  if(rval != DAL_SUCCESS)
  {
    // An error occurred while reading from the ULog. Ensure response packet fields are set correctly.
    readRsp->outputFormat = readCmd->outputFormat;
    readRsp->outputLength = 0;
  }
      
  if(readRsp->outputLength == 0)
  {
    diagpkt_shorten (readRsp, (baseOffsetBytes + 1));
  }
  else if(readRsp->outputLength < sizeof(readRsp->response))
  {
    diagpkt_shorten (readRsp, (baseOffsetBytes + readRsp->outputLength + 1));
  }

  return (readRsp);
}


/**
 * <!-- ulogdiag_handler -->
 *
 * @brief Performs the command specified in the request packet.
 *
 * @param req : Pointer to request packet
 * @param pkt_len : Length of request packet
 *
 * @return a pointer to response packet.
 */
static PACKED void * ulogdiag_handler( PACKED void *req,  
                                       word pkt_len )
{
  ulogdiag_cmd_rsp_type_version * versionRsp;

  ulogdiag_cmd_type_connect * connectCmd;
  ulogdiag_cmd_rsp_type_connect * connectRsp;

  ulogdiag_cmd_type_allocate * allocateCmd;
  ulogdiag_cmd_rsp_type_allocate * allocateRsp;

  ulogdiag_cmd_type_enable * enableCmd;
  ulogdiag_cmd_rsp_type_enable * enableRsp;

  ulogdiag_cmd_type_list * listCmd;
  ulogdiag_cmd_rsp_type_list * listRsp;

  ulogdiag_cmd_type_read * readCmd;

  ulogdiag_cmd_type_header_read * headerReadCmd;
  ulogdiag_cmd_rsp_type_header_read * headerReadRsp;

  ulogdiag_cmd_type_disable * disableCmd;
  ulogdiag_cmd_rsp_type_disable * disableRsp;

  ulogdiag_cmd_type_settransport * settransportCmd;
  ulogdiag_cmd_rsp_type_settransport *settransportRsp;

  ulogdiag_cmd_type_plugin * pluginCmd;
  ulogdiag_cmd_type_plugin_ext * pluginExtCmd;
  ulogdiag_cmd_rsp_type_plugin_cmd * pluginRsp;

  ulogdiag_msg_header * hdr = (ulogdiag_msg_header *)req;
  unsigned baseOffsetBytes;
  ULogHandle tempLog;
  PACKED void * rsp  = NULL;

  ULOGDIAG_CommandsType command_code = ULOGDIAG_CONNECT;

  if (req)
  {
    // Read the command code, and limit it to one byte.
    command_code = (ULOGDIAG_CommandsType) (hdr->subsysCmdCode & 0xFF);

    /*  Verify that the command code is valid */
    {
      switch (command_code)
      {
        case ULOGDIAG_VERSION:
          versionRsp = (ulogdiag_cmd_rsp_type_version *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                           (uint16) hdr->subsysCmdCode, 
                                           sizeof(ulogdiag_cmd_rsp_type_version));
          if (versionRsp == NULL)
          {
            return(NULL);
          }
          versionRsp->majorVersion = 1;
          versionRsp->minorVersion = 0;

          rsp = (void *)versionRsp;
          break;

        case ULOGDIAG_SETTRANSPORT_RAM:
          settransportCmd = (ulogdiag_cmd_type_settransport *)req;
          settransportRsp = (ulogdiag_cmd_rsp_type_settransport *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                           (uint16) hdr->subsysCmdCode, 
                                           sizeof(ulogdiag_cmd_rsp_type_settransport));

          if(NULL == settransportRsp )
          {
            return(NULL);
          }
          settransportRsp->result = ULogCore_SetTransportToRAM(GetInternalHandle(settransportCmd->handle));
          rsp = (void *)settransportRsp;
        break;
		

        case ULOGDIAG_SETTRANSPORT_STM:
          settransportCmd = (ulogdiag_cmd_type_settransport *)req;
          settransportRsp = (ulogdiag_cmd_rsp_type_settransport *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_settransport));

          if(NULL == settransportRsp )
          {
            return(NULL);
          }
          settransportRsp->result = ULogCore_SetTransportToStm(GetInternalHandle(settransportCmd->handle),
                                                               settransportCmd->protocol_num);
          rsp = (void *)settransportRsp;
        break;

        case ULOGDIAG_SETTRANSPORT_STMASCII:
          settransportCmd = (ulogdiag_cmd_type_settransport *)req;
          settransportRsp = (ulogdiag_cmd_rsp_type_settransport *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_settransport));

          if(NULL == settransportRsp )
          {
            return(NULL);
          }
          settransportRsp->result = ULogCore_SetTransportToStmAscii(GetInternalHandle(settransportCmd->handle),
                                                                    settransportCmd->protocol_num);
          rsp = (void *)settransportRsp;
        break;


        case ULOGDIAG_CONNECT:
          connectCmd = (ulogdiag_cmd_type_connect *)req;
          connectRsp = (ulogdiag_cmd_rsp_type_connect *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_connect));
          if (connectRsp == NULL)
          {
             return(NULL);
          }

          // Try to find the matching log.
          tempLog = ULogCore_HandleGet((char*)connectCmd->logName);

          if (tempLog!=NULL){
            // Found the log, get the external handle for it. 
            connectRsp->handle = GetExternalHandle(tempLog);

            if (connectRsp->handle!=NULL){

              // Make sure the ULOG_STATUS_LOG_SW_READ_STARTED hasn't been set so that this 
              // new read session doesn't immediately send an ULOG_ERROR_OVERRUN. 
              ULogCore_ReadSessionComplete(tempLog);

              // Return success, we found the log and have an external handle for them to use. 
              connectRsp->result = DAL_SUCCESS;                 
            }
            else
            {
              // This should be almost impossible unless a malloc getting an external handle fails. 
              connectRsp->result = ULOG_ERR_MISC;
            }
          }
          else
          {
            // Didn't find the log.  Return the correct error code. 
            connectRsp->handle = NULL;
            connectRsp->result = ULOG_ERR_NAMENOTFOUND;
          }
          rsp = (void *)connectRsp;
          break;

        case ULOGDIAG_ALLOCATE:
          allocateCmd = (ulogdiag_cmd_type_allocate *)req;
          allocateRsp = (ulogdiag_cmd_rsp_type_allocate *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_allocate));
          if (allocateRsp == NULL)
          {
            return(NULL);
          }
          allocateRsp->result = ULogCore_Allocate(GetInternalHandle(allocateCmd->handle),
                                                  allocateCmd->bufferSize);
          rsp = (void *)allocateRsp;
          break;

        case ULOGDIAG_ENABLE:
          enableCmd = (ulogdiag_cmd_type_enable *)req;
          enableRsp = (ulogdiag_cmd_rsp_type_enable *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_enable));
          if (enableRsp == NULL)
          {
            return(NULL);
          }
          enableRsp->result = ULogCore_Enable(GetInternalHandle(enableCmd->handle));
          rsp = (void *)enableRsp;
          break;

        case ULOGDIAG_LIST:
          listCmd = (ulogdiag_cmd_type_list *)req;
          listRsp = (ulogdiag_cmd_rsp_type_list *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_list));
          if (listRsp == NULL)
          {
            return(NULL);
          }
          baseOffsetBytes = offsetof(ulogdiag_cmd_rsp_type_list, nameArray);	
          listRsp->result = ULogCore_ListEx(listCmd->logListReadOffset,
                                            &listRsp->registeredCount,  
                                            sizeof(listRsp->nameArray),  
                                            &listRsp->namesReadCount,  
                                            listRsp->nameArray);
          listRsp->offsetCount = listCmd->logListReadOffset;
          // Shorten this allocation based on the number of logs read
          diagpkt_shorten(listRsp, (baseOffsetBytes + 24 * listRsp->namesReadCount));

          rsp = (void *)listRsp;
          break;

        case ULOGDIAG_READ_FORMAT:
          readCmd = (ulogdiag_cmd_type_read *)req;
          rsp = ULogDiagReadAndFormat(readCmd);
          break;

        case ULOGDIAG_HEADER_READ:
          headerReadCmd = (ulogdiag_cmd_type_header_read *)req;
          headerReadRsp = (ulogdiag_cmd_rsp_type_header_read *)diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_header_read));
          if (headerReadRsp == NULL)
          {
            return(NULL);
          }
          headerReadRsp->result = ULogCore_HeaderRead(GetInternalHandle(headerReadCmd->handle),  
                                                       headerReadCmd->headerReadOffset,
                                                       headerReadRsp->headerData,
                                                       sizeof(headerReadRsp->headerData),
                                                       &headerReadRsp->headerLength);
          rsp = (void *)headerReadRsp;
          break;

        case ULOGDIAG_DISABLE:
          disableCmd = (ulogdiag_cmd_type_disable *)req;
          disableRsp = (ulogdiag_cmd_rsp_type_disable *)diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_disable));
          if (disableRsp == NULL)
          {
            return(NULL);
          }
          disableRsp->result = ULogCore_Disable(GetInternalHandle(disableCmd->handle));
          rsp = (void *)disableRsp;
          break;

        case ULOGDIAG_PLUGIN: 
          pluginCmd = (ulogdiag_cmd_type_plugin *) req;
          pluginRsp = (ulogdiag_cmd_rsp_type_plugin_cmd *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_plugin_cmd));
          if (pluginRsp == NULL)
          {
            return(NULL);
          }
          pluginRsp->result = ULogDiag_RunPlugin(pluginCmd->plugin_id, pluginCmd->msg_to_plugin);
          rsp = (void *)pluginRsp;
		  break;

        case ULOGDIAG_PLUGIN_EXT:
          pluginExtCmd = (ulogdiag_cmd_type_plugin_ext *) req;
          pluginRsp = (ulogdiag_cmd_rsp_type_plugin_cmd *) diagpkt_subsys_alloc(DIAG_SUBSYS_ULOG,
                                            (uint16) hdr->subsysCmdCode, 
                                            sizeof(ulogdiag_cmd_rsp_type_plugin_cmd));
          if (pluginRsp == NULL)
          {
            return(NULL);
          }
          pluginRsp->result = ULogDiag_RunPluginExt(pluginExtCmd->plugin_id,(void*)pluginExtCmd->msg_to_plugin, pluginExtCmd->msg_size);
          rsp = (void *)pluginRsp;
          break;

        default:
          rsp = diagpkt_err_rsp(DIAG_BAD_PARM_F, req, pkt_len);
          break;

      }

      if (rsp)
      {
        /*  Send out our packet */
        diagpkt_commit(rsp);
        rsp = NULL;
      }
    }
  }

  return (rsp);
}


/** Map the diag functions to the proper commands */
static const diagpkt_user_table_entry_type ulogdiag_diag_tbl[] = 
{
  {ULOGDIAG_VERSION | ULOGDIAG_PROCESSOR_ID, 
   ULOGDIAG_MAX_CMD | ULOGDIAG_PROCESSOR_ID, 
   ulogdiag_handler}
};


/**
 * <!-- ULogDiag_Init -->
 * 
 * @brief Register with Diag to have our ulogdiag_handler called.
 */
void ULogDiag_Init(void)
{
  DIAGPKT_DISPATCH_TABLE_REGISTER (DIAG_SUBSYS_ULOG, ulogdiag_diag_tbl);
}


/**
 * <!-- ULogBackend_Init -->
 *
 * @brief The diag functionality is setup when this is called. 
 *
 * Called early in a system's boot to initialize any available ULog backend features. 
 */
void ULogBackend_Init(void)
{
  ULogDiag_Init();
}


#else
/**
 * <!-- ULogBackend_Init -->
 *
 * Do nothing if Diag is not enabled. 
 */
void ULogBackend_Init(void)
{
}


/**
 * <!-- ULogDiag_AddPlugin -->
 *
 * @return ULOG_ERR_NOTSUPPORTED if Diag is not enabled. 
 */
ULogResult ULogDiag_AddPlugin( int(*name)(uint32), uint32 ulogdiag_plugin_id )
{
   return ULOG_ERR_NOTSUPPORTED;
}
#endif /* DEFEATURE_ULOG_DIAG */

#ifdef __cplusplus
}
#endif
