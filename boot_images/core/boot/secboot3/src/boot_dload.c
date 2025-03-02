/*=============================================================================

                         Boot Downloader 
 
GENERAL DESCRIPTION
  This file contains the code to initiate a reset of the chip and
  transition to the into the downloader.

EXTERNALIZED FUNCTIONS
  boot_dload_transition
  boot_dload_entry
  boot_dload_is_dload_mode_set

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None

Copyright 2014 by Qualcomm Technologies, Inc.  All Rights Reserved.
=============================================================================*/


/*=============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/boot/secboot3/src/boot_dload.c#1 $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
01/13/15   mva     Added support to check for warm reset status
06/18/14   ck      BLOCK_RESIN clear moved to reset logic
06/02/14   jz      Updated to use common USB driver API
05/28/14   jz      Updated to use QUSB driver
03/18/14   ck      Updated boot_hw_reset calls as they now take a reset type parameter
01/10/14   ck      Removed static download mode variable as the BOOT_MISC_DETECT register should be used
01/06/14   ck      Modified boot_dload_transition_pbl_forced_dload to use BOOT_MISC_DETECT register
01/06/14   ck      Modified boot_dload_entry, boot_dload_is_dload_mode_set, and boot_dload_set_cookie
                   logic to reference BOOT_MISC_DETECT register for dload cookie
08/07/13   aus     Added support to check for D+ line to force PBL download mode
02/14/13   dh      Add a static variable to indicate if dload mode is set 
12/07/12   kedara  revert boot_dload_entry updates to not retain dload status.
11/16/12   dh      Add boot_dload_set_cookie
10/26/12   kedara  Update boot_dload_entry to retain dload status.
06/26/12   dh      Remove FEATURE_DLOAD_HW_RESET_DETECT from boot_dload_check
02/28/12   dh      use boot_shared_imem_cookie_ptr to refer to dload magic number
09/13/11   dh      Include boot_cache_mmu.h instead of cache_mmu.h
05/02/11   dh      flush the data cache after resetting dload magic number 
12/22/10   dxiang  Add support to read the dload cookie 
07/02/10   aus     Reordered the function calls
05/07/10   aus     Added dload support for Fusion
02/03/10   niting  Moved to DLOAD_ID_ADDR to cust file.
12/08/09   msm     Fixes made for HOSTDL
10/15/09   tbg     Corrected API for FEATURE_DLOAD_HW_RESET_DETECT
08/23/08   dhaval  Fix DLOAD transition from AMSS to BOOT with JTAG connected.
05/08/07   ty      Modify structure saved to IRAM to include serial number
03/26/07   tbg     Added support for FEATURE_DLOAD_HW_RESET_DETECT
01/24/07   ly      Add HS_USB support
10/13/05   sd      Initial revision.

=============================================================================*/


/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "boot_dload.h"
#include "boot_cache_mmu.h"
#include "boothw_target.h"
#include "boot_shared_imem_cookie.h"
#include "boot_extern_usb_interface.h"
#include "boot_extern_pmic_interface.h"

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/


/*=============================================================================
   
                              FUNCTION DEFINITIONS

=============================================================================*/

/*===========================================================================

FUNCTION  BOOT_DLOAD_ENTRY

DESCRIPTION
  Determines if identifier is present in BOOT_MISC_DETECT register to tell 
  SBL to enter the boot downloader, instead on continuing the normal boot 
  process.
  
DEPENDENCIES
  Data in BOOT_MISC_DETECT is retained across a reset.
  
RETURN VALUE
  TRUE indicates downloader should be entered.

SIDE EFFECTS
  None

===========================================================================*/
boolean boot_dload_entry( void )
{
  /* Check to see if download ID is present. 
     For Bear family the cookie is now stored in the register BOOT_MISC_DETECT 
     and not IMEM.  This register is shared with PBL and maybe others.  Only
     one bit is needed and the mask SBL_BOOT_MISC_DETECT_MASK defines what
     section of the register SBL owns. */
  
  boolean dload_flag =
    HWIO_TCSR_BOOT_MISC_DETECT_INM(SBL_DLOAD_MODE_BIT_MASK);
  
  if (dload_flag)
  {
    /* Clear ID so the downloader is not entered again on the next boot. */
    HWIO_TCSR_BOOT_MISC_DETECT_OUTM(SBL_DLOAD_MODE_BIT_MASK,
                                    0);

    return TRUE;
  }

  return FALSE;
} /* boot_dload_entry() */

/*===========================================================================

FUNCTION  BOOT_DLOAD_IS_DLOAD_MODE_SET

DESCRIPTION
  This function shall return if the dload cookie is set or not for the
  phone to go in download mode.

DEPENDENCIES
  Data in BOOT_MISC_DETECT is retained across a reset.
  
RETURN VALUE
  TRUE indicates cookies are set
  FALSE cookies are not set
  
SIDE EFFECTS
  None

===========================================================================*/
boolean boot_dload_is_dload_mode_set( void )
{
  /* Evaluate dload mode bit that is in the BOOT_MISC_DETECT register */
  if (HWIO_TCSR_BOOT_MISC_DETECT_INM(SBL_DLOAD_MODE_BIT_MASK))
  {
    return TRUE;
  }

  return FALSE;
}


/*===========================================================================
**  Function :  boot_dload_set_cookie
** ==========================================================================
*/
/*!
* 
* @brief
*   Set the SBL dload mode cookie
**        
* @par Dependencies
*  None
*   
*/
void boot_dload_set_cookie()
{
  HWIO_TCSR_BOOT_MISC_DETECT_OUTM(SBL_DLOAD_MODE_BIT_MASK,
                                  SBL_DLOAD_MODE_BIT_MASK);
}


/*=============================================================================

**  Function :  boot_dload_transition_pbl_forced_dload

** ==========================================================================
*/
/*!
* 
* @brief
*   This function sets the magic numbers for PBL to detect and enter forced
*   download mode.  It then calls the target specific function to trigger a
*   system reset.
* 
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   Set's PBL magic numbers to enter forced download, resets target, never to
*   return.
* 
*/
void boot_dload_transition_pbl_forced_dload( void )
{
  /* PBL uses the last four bits of BOOT_MISC_DETECT to trigger forced download.
     Preserve the other bits of the register. */

  uint32 register_value = 
    HWIO_TCSR_BOOT_MISC_DETECT_INM(HWIO_TCSR_BOOT_MISC_DETECT_RMSK);

  /* Clear the PBL masked area and then apply HS_USB value */
  register_value &= ~(FORCE_DLOAD_MASK);
  register_value |= FORCE_DLOAD_HS_USB_MAGIC_NUM;

  /* Write the new value back out to the register */
  HWIO_TCSR_BOOT_MISC_DETECT_OUTM(FORCE_DLOAD_MASK,
                                  register_value);

  boot_hw_reset(BOOT_WARM_RESET_TYPE);
} /* boot_dload_transition_pbl_forced_dload() */


/*===========================================================================

**  Function :  boot_init_for_dload

** ==========================================================================
*/
/*!
* 
* @brief
*   Wrapper function that calls smem_boot_debug_init().
*  
* @param[in] bl_shared_data Pointer to shared data structure
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
void boot_init_for_dload
( 
   bl_shared_data_type *bl_shared_data 
)
{
#ifdef BOOT_DISABLE_DCACHE_IN_DLOAD
  /* Disable cache and MMU */
  cache_mmu_disable();
#endif /* BOOT_DISABLE_DCACHE_IN_DLOAD */
 
} /* boot_smem_init_for_dload() */


/*===========================================================================

**  Function :  boot_dload_check

** ==========================================================================
*/
/*!
* 
* @brief
*   This function will check to see if the downloader should be entered
*   for QPST download, and enter the downloader if directed to.
*  
* @param[in] bl_shared_data Pointer to the shared data 
*
* @par Dependencies
*   Download ID must be present in IRAM if downloader is to be entered.
* 
* @retval
*   None
* 
* @par Side Effects
*   Boot may be halted and QPST downloader entered.
* 
*/
void boot_dload_check
( 
  bl_shared_data_type *bl_shared_data 
)
{
  boolean status = FALSE;
  /* Check whether USB D+ line is grounded. If it is, then enter
     PBL Download mode */
  if(boot_usb_al_check_for_pbl_dload(0))
  {
    boot_dload_transition_pbl_forced_dload();
  }

  /* Determine if the downloader should be entered at this time,
     instead of continuing with the normal boot process. */
  if ( boot_dload_entry( ) == TRUE )
  {
    /* Check the UEFI ram dump cookie, we enter download mode
       only if UEFI ram dump cookie is NOT set*/
    if ( !( boot_shared_imem_cookie_ptr != NULL &&
            boot_shared_imem_cookie_ptr->uefi_ram_dump_magic == 
            UEFI_CRASH_DUMP_MAGIC_NUM ) )
    {
      /* Enter downloader for QPST */  
      sbl_dload_entry();
    }
  }
 /* Check if PMIC warm reset occured */
  BL_VERIFY((boot_pm_pon_warm_reset_status(0, &status) == PM_ERR_FLAG__SUCCESS), BL_ERR_SBL);

  /* If status is true, set abonormal reset cookie and 
     clear the warm reset status in PMIC */
  if(status)
  { 
    if ( boot_shared_imem_cookie_ptr != NULL )
       boot_shared_imem_cookie_ptr->abnormal_reset_occurred = ABNORMAL_RESET_ENABLED;

    BL_VERIFY((boot_pm_pon_warm_reset_status_clear(0) == PM_ERR_FLAG__SUCCESS), BL_ERR_SBL);
  }
} /* boot_dload_check() */
