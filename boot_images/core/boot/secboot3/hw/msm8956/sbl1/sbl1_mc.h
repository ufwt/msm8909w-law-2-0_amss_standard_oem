#ifndef SBL1_MC_H
#define SBL1_MC_H

/*===========================================================================

                      SBL1 Main Control Header File

GENERAL DESCRIPTION
  This file contains the main control for SBL1 execution.

Copyright 2014 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
============================================================================*/
/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/boot/secboot3/hw/msm8956/sbl1/sbl1_mc.h#1 $ 
$DateTime: 2015/09/01 00:30:35 $ 
$Author: pwbldsvc $

when        who      what, where, why
----------  ---      ----------------------------------------------------------
07/14/14    lm       Added sbl1_external_abort_enable
06/20/14    ck       Renamed sbl1_cleanse_qsee_region to sbl1_cleanse_security_regions
05/14/14    ck       Added sbl1_cleanse_qsee_region
03/21/14    ck       Added support to load SEC partition
12/16/13    ck       Removed sbl1_qfprom_test as TZ runs after SBL in Bear family.
10/17/13    ck       Removed sbl1_rpm_sync and sbl1_check_l2_parity_error
06/26/13    aus      Remove sbl1_dead_battery_charge
06/13/13    dh       Update sbl1_load_ddr_training_data_from_partition to take buffer
                     address as argument
03/26/13    dh       Rename sbl1_relocate_page_table to sbl1_relocate_page_table_to_ddr
02/27/13    dh       Add sbl1_hw_platform_pre_ddr and sbl1_hw_platform_post_ddr
02/14/13    kedara   Added sbl1_update_all_rollback_fuses.
02/07/13    dh       Add sbl1_relocate_page_table
12/03/12    dh       Remove sbl1_rollback_version_update
11/27/12    dh       Add sbl1_rpm_sync
11/28/12    dh       Add sbl1_update_sbl1_rollback_fuse
07/19/12    dh       Add sbl1_qfprom_test
05/29/12    dh       Add sbl1_tlmm_init
05/08/12    dh       Add sbl1_dead_battery_charge
03/14/12    dh       Add sbl1_populate_initial_mem_map and sbl1_relocate_page_table
10/27/11    dh       Initial reversion

===========================================================================*/


/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include BOOT_PBL_H

/*===========================================================================
                      PUBLIC FUNCTION DECLARATIONS
===========================================================================*/

/*===========================================================================
**  Function :  sbl1_main_ctl
** ==========================================================================
*/
/*!
* 
* @brief
*   The RPM Main Controller performs the following functions:
*       - Initializes indirect vector table in IMEM
*       - Always calls the cold boot process. (warm boot not supported)
* 
* @param[in] pbl_shared Pointer to shared data
* 
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   This function never returns.
* 
*/
void sbl1_main_ctl(boot_pbl_shared_data_type *pbl_shared);


/*===========================================================================
**  Function :  sbl1_boot_logger_deinit
** ==========================================================================
*/
/*!
* 
* @brief
*   This function stops the boot logger and dumps the log information. Should
*   be called right before exiting the bootloader 
*
* @par Dependencies
*   Called after sbl1_boot_logger_init()
* 
*/
void sbl1_boot_logger_deinit(void);


/*===========================================================================
**  Function :  sbl1_hw_platform_pre_ddr
** ==========================================================================
*/
/*!
* 
* @brief
*     	Parse cdt table to get start of sw-platform id CDB.
*       Call platform-id API and pass pointer to start of sw-platform id CDB.
*       Call hw_init_smem to store platform id to SMEM
* 
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
*/
void sbl1_hw_platform_pre_ddr(bl_shared_data_type* bl_shared_data);


/*===========================================================================
**  Function :  sbl1_hw_platform_smem
** ==========================================================================
*/
/*!
* 
* @brief
*     	Parse cdt table to get start of sw-platform id CDB.
*       Call platform-id API and pass pointer to start of sw-platform id CDB.
*       Call hw_init_smem to store platform id to SMEM
* 
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
*/
void sbl1_hw_platform_smem(bl_shared_data_type* bl_shared_data);

/*===========================================================================
**  Function :  sbl1_post_ddr_init
** ==========================================================================
*/
/*!
* 
* @brief
*   This funcion will initialize the data section in DDR and relocate boot log to DDR
*   After execution of this function SBL1 will enter Sahara in stead of PBL
*   emergency dload mode in case of error
*
* @par Dependencies
*   Must be called after sbl1_ddr_init
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_post_ddr_init(bl_shared_data_type  *shared_data);


/*===========================================================================
**  Function :  sbl1_post_ddr_training_init
** ==========================================================================
*/
/*!
* 
* @brief
*   This funcion will initialize the data section in DDR, populate ddr size information
*   then relocate page table from IMEM to DDR and map all memory regions required by SBL1 
*   in page table.
*
* @par Dependencies
*   Must be called after sbl1_ddr_init
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_post_ddr_training_init(bl_shared_data_type  *shared_data);

/*===========================================================================
**  Function :  sbl1_relocate_page_table_to_ddr
** ==========================================================================
*/
/*!
* 
* @brief
*   This funcion will relocate page table from imem to DDR and map all avaliable
*   DDR memory to page table
* 
* @param[in] bl_shared_data Pointer to shared data
*        
* @par Dependencies
*   Must be called after sbl1_ddr_init
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_relocate_page_table_to_ddr(bl_shared_data_type *bl_shared_data);


/*===========================================================================
**  Function :  sbl1_signal_tz_sbl_done
** ==========================================================================
*/
/*!
* 
* @brief
*   This api makes a smc call to tz to signal end of sbl boot.
*   TZ will jump to the address passed in the second argument.
*   This function will not return!
*
* @param[in] bl_shared_data Pointer to shared data
*        
* @par Dependencies
*  none
*   
*/
void sbl1_signal_tz_sbl_done( bl_shared_data_type *bl_shared_data );


/*===========================================================================
**  Function :  sbl1_efs_handle_cookies
** ==========================================================================
*/
/*!
* 
* @brief
*   Calls efs cookie handling api to perform efs backup/restore action
* 
* @param[in] bl_shared_data Pointer to shared data
*   
* @par Dependencies
*   None
*   
* @retval
*   None                                                               
* 
* @par Side Effects
*   None
* 
*/
void sbl1_efs_handle_cookies(bl_shared_data_type* bl_shared_data);


/*===========================================================================
**  Function :  sbl1_populate_initial_mem_map
** ==========================================================================
*/
/*!
* 
* @brief
*   populate the exiting pbl page table with SBL memory mapping
* 
* @param[in] bl_shared_data Pointer to shared data
*   
* @par Dependencies
*   None
*   
* @retval
*   None                                                               
* 
* @par Side Effects
*   None
* 
*/
void sbl1_populate_initial_mem_map(bl_shared_data_type* bl_shared_data);


/*===========================================================================
**  Function :  sbl1_tlmm_init
** ==========================================================================
*/
/*!
* 
* @brief
*   SBL1 wrapper to Initialize Tlmm and gpio for low power config
*
* @param[in] shared_data Pointer to shared data
*        
* @par Dependencies
*   must be called after boot_smem_init
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_tlmm_init(bl_shared_data_type *bl_shared_data);


/*===========================================================================
**  Function :  sbl1_load_ddr_training_data_from_partition
** ==========================================================================
*/
/*!
* 
* @brief
*   This funcion will read the ddr training data from ddr parition
*
* @par Dependencies
*   Must be called before sbl1_ddr_init
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_load_ddr_training_data_from_partition
(
  uint8* ddr_training_data_buf,
  uint32 ddr_training_data_size
);


/*===========================================================================
**  Function :  sbl1_save_ddr_training_data_to_partition
** ==========================================================================
*/
/*!
* 
* @brief
*   This funcion will save ddr training data to ddr partition
* 
* @param[in] ddr_training_data_ptr Pointer to ddr training data
*
* @param[in] ddr_training_data_size size of ddr training data
*     
* @par Dependencies
*   Must be called after ddr_post_init
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_save_ddr_training_data_to_partition
(
  uint8* ddr_training_data_ptr,
  uint32 ddr_training_data_size
);



/*===========================================================================
**  Function :  sbl1_load_sec_partition
** ==========================================================================
*/
/*!
*
* @brief
*   This funcion will read the sec partition and load it to a defined memory 
*   region
*
* @par Dependencies
*   Must be called after TZ is loaded
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_load_sec_partition ( bl_shared_data_type *bl_shared_data );


/*===========================================================================
**  Function :  sbl1_update_all_rollback_fuses
** ==========================================================================
*/
/*!
* 
* @brief
*  Blow version rollback fuses for all images.
*
* @par Dependencies
*  Has to execute *after* sbl1_rpm_sync api. 
*   
*/
void sbl1_update_all_rollback_fuses(void);

/*===========================================================================
**  Function :  sbl1_update_sbl1_rollback_fuse
** ==========================================================================
*/
/*!
* 
* @brief
*   Update the sbl1 roll back protection version fuse
*
*        
* @par Dependencies
*  Must be called after TZ is initialized
*   
*/
void sbl1_update_sbl1_rollback_fuse(bl_shared_data_type *bl_shared_data);


/*===========================================================================
**  Function :  boot_read_l2esr
** ==========================================================================
*/
/*!
* 
* @brief
*   Returns the value of L2ESR register
**        
* @par Dependencies
*  None
*   
*/
uint32 boot_read_l2esr(void);

/* Global variable indicating if L2 error has happened */
extern  uint32 L2_parity_error_in_sbl;


/*===========================================================================
**  Function :  sbl1_cleanse_security_regions
** ==========================================================================
*/
/*!
* 
* @brief
*   Zero out the QSEE and QHEE DDR region for security if needed.
*
* @param[in]
*   bl_shared_data           Pointer to shared data
*        
* @par Dependencies
*   None
*   
*/
void sbl1_cleanse_security_regions(bl_shared_data_type * bl_shared_data);

/*===========================================================================
**  Function :  sbl1_external_abort_enable
** ==========================================================================
*/
/*!
* 
* @brief
*   Enable the external abort in SBL1.
*
* @param[in]
*   Uint32	Flags
*        
* @par Dependencies
*   None
*   
*/
void sbl1_external_abort_enable(uint32 flags);

#endif  /* SBL1_MC_H */

