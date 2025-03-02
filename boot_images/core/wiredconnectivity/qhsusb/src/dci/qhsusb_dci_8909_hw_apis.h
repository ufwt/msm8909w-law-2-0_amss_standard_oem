//============================================================================
/**
 * @file        qhsusb_dci_8909_hw_apis.h
 * @author      dsegal
 * @date        12-Sept-2010
 *
 * @brief       QHSUSB (Qualcomm High-Speed USB) DCI (Device-Controller-Interface) HW 
 *              interface.
 *
 * 
 *
 *              Copyright (c) 2012 Qualcomm Technologies Incorporated.
 *              All Rights Reserved.
 *              Qualcomm Confidential and Proprietary
 * 
 */
//============================================================================

// ===========================================================================
// 
//                            EDIT HISTORY FOR FILE
//   This section contains comments describing changes made to the module.
//   Notice that changes are listed in reverse chronological order.
// 
// $Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/wiredconnectivity/qhsusb/src/dci/qhsusb_dci_8909_hw_apis.h#1 $
// 
// when          who     what, where, why
// ----------   -----    ----------------------------------------------------------
// 2012-10-25   shreyasr  Ported the code for MSM8916
// 2010-09-12   dsegal   First Draft
// 
// ===========================================================================

//----------------------------------------------------------------------------
// Include Files
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Preprocessor Definitions and Constants
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Type Declarations
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Externalized Function Definitions
//----------------------------------------------------------------------------
#ifndef FEATURE_EMMCBLD
extern void dcache_inval_region(void *addr, unsigned int length);
extern void dcache_flush_region(void *addr, unsigned int length);
#endif 

//============================================================================


//============================================================================
/**
 * @function  qhsusb_dci_clk_enable
 *
 * @brief Enable USB related clock
 *
 * @note
 *
 * @param    
 *
 * @return none
 *
 * @ref 
 *
 */
//============================================================================
void qhsusb_dci_clk_enable(void);
//============================================================================
/**
 * @function  qhsusb_dci_dcache_flush
 *
 * @brief Flush Data-Cache
 *
 *
 * @param address    
 * @param length
 *
 * @return none
 *
 */
//============================================================================
void qhsusb_dci_dcache_flush(uint32 *addr, uint32 length);
//============================================================================
/**
 * @function  qhsusb_dci_dcache_inval
 *
 * @brief Invalidate Data-Cache
 *
 *
 * @param address    
 * @param length
 *
 * @return none
 *
 */
//============================================================================
void qhsusb_dci_dcache_inval(uint32 *addr, uint32 length);
//============================================================================
/**
 * @function  qhsusb_dci_soft_reset_core
 *
 * @brief This is used the Reset the USB
 *
 *
 * @param core_id    
 *
 * @return none
 *
 */
//============================================================================
void qhsusb_dci_soft_reset_core(uint32 core_id);
//============================================================================
/**
 * @function  qhsusb_dci_clk_disable
 *
 * @brief Disable USB related clock
 *
 * @note
 *
 * @param Clock to be disabled   
 *
 * @return none
 *
 * @ref 
 *
 */
//============================================================================
void qhsusb_dci_clk_disable(void);




