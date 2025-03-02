#ifndef BOOT_EXTERN_SECBOOT_INTERFACE_H
#define BOOT_EXTERN_SECBOOT_INTERFACE_H
/*===========================================================================

                    BOOT EXTERN CRYPTO AUTH DRIVER DEFINITIONS

DESCRIPTION
  Contains wrapper definition for external authentication drivers

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
Copyright 2013 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
============================================================================*/
/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.
    
$Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/boot/secboot3/src/boot_extern_secboot_interface.h#1 $
$DateTime: 2015/09/01 00:30:35 $
$Author: pwbldsvc $
    
when       who     what, where, why
--------   ---     ----------------------------------------------------------
02/13/13   dh      Initial Creation.

===========================================================================*/

/*==========================================================================

                               INCLUDE FILES

===========================================================================*/

#include "boot_comdef.h"
#include "secboot.h"
#include "secboot_hw.h"


/**
 * @brief This function return pointers to the secboot functions linked into
 *        the image
 *
 * @param[in,out] ftbl_ptr              Pointer to the function table structure
 *                                      to populate. The pointer must be allocated
 *                                      by the caller.
 *
 * @return E_SECBOOT_HW_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 *
 */
#ifdef FEATURE_BOOT_EXTERN_SECBOOT_COMPLETED
  secboot_hw_etype boot_secboot_hw_get_ftbl(secboot_hw_ftbl_type* ftbl_ptr);
#else
  static __inline secboot_hw_etype boot_secboot_hw_get_ftbl(secboot_hw_ftbl_type* ftbl_ptr)
  {
    return E_SECBOOT_HW_SUCCESS;
  }
#endif  


/**
 * @brief This function return pointers to the secboot functions linked into
 *        the image
 *
 * @param[in,out] ftbl_ptr              Pointer to the function table structure
 *                                      to populate. The pointer must be allocated
 *                                      by the caller.
 *
 * @return E_SECBOOT_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 *
 */
#ifdef FEATURE_BOOT_EXTERN_SECBOOT_COMPLETED
  secboot_error_type boot_secboot_get_ftbl(secboot_ftbl_type* ftbl_ptr);
#else
  static __inline secboot_error_type boot_secboot_get_ftbl(secboot_ftbl_type* ftbl_ptr)
  {
    return E_SECBOOT_SUCCESS;
  }
#endif  

#endif /* BOOT_EXTERN_SECBOOT_INTERFACE_H */
