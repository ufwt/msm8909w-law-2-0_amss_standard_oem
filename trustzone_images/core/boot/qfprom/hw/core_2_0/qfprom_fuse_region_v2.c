/*===========================================================================

                       QFPROM  Driver Source  Code

DESCRIPTION
 Contains target specific defintions and APIs to be used to read and write
 qfprom values for sec ctrl 3.0.2 (used by 8x26).

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None

Copyright  2013 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/boot/qfprom/hw/core_2_0/qfprom_fuse_region_v2.c#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
05/31/13   jz      Ported and updated for 8x26 fuse map

============================================================================*/

/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include QFPROM_HWIO_REG_INCLUDE_H
#include QFPROM_TARGET_INCLUDE_H

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/
/*
**  Array containing QFPROM data items that can be read and associated
**  registers, mask and shift values for the same.
*/
const QFPROM_REGION_INFO qfprom_region_data[] =
{
    {
        QFPROM_JTAG_ID_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_JTAG_ID_LSB_ADDR,
        HWIO_QFPROM_CORR_JTAG_ID_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_JTAG_ID_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_JTAG_ID_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        1
    },
    
    {
        QFPROM_READ_WRITE_PERMISSION_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_RD_WR_PERM_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_RD_WR_PERM_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_RD_WR_PERM_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        2
    },
    
    {
        QFPROM_PTE_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_PTE_LSB_ADDR,
        HWIO_QFPROM_CORR_PTE_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_PTE_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_PTE_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        3
    },
    
    {
        QFPROM_AP_ANTI_ROLLBACK_REGION,
        2,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_AP_ANTI_ROLLBACK_ROW0_LSB_ADDR ,
        HWIO_QFPROM_CORR_AP_ANTI_ROLLBACK_ROW0_LSB_ADDR ,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_AP_ANTI_ROLLBACK_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_AP_ANTI_ROLLBACK_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        4
    },
    
    {
        QFPROM_MSA_ANTI_ROLLBACK_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_MSA_ANTI_ROLLBACK_LSB_ADDR,
        HWIO_QFPROM_CORR_MSA_ANTI_ROLLBACK_LSB_ADDR ,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_MSA_ANTI_ROLLBACK_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_MSA_ANTI_ROLLBACK_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        5
    },
    
    {
        QFPROM_IMEI_ESN0_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_IMEI_ESN0_LSB_ADDR,
        HWIO_QFPROM_CORR_IMEI_ESN0_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_IMEI_ESN0_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_IMEI_ESN0_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        6
    },
   
    {
        QFPROM_IMEI_ESN1_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_IMEI_ESN1_LSB_ADDR,
        HWIO_QFPROM_CORR_IMEI_ESN1_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_IMEI_ESN1_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_IMEI_ESN1_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        7
    },
    
    {
        QFPROM_IMEI_ESN2_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_IMEI_ESN2_LSB_ADDR,
        HWIO_QFPROM_CORR_IMEI_ESN2_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_IMEI_ESN2_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_IMEI_ESN2_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        8
    },
    
    {
        QFPROM_OEM_CONFIG_REGION,
        2,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_OEM_CONFIG_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_OEM_CONFIG_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        9
    },
    
    {
        QFPROM_FEATURE_CONFIG_REGION,
        4,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_FEAT_CONFIG_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_FEAT_CONFIG_BMSK ,
        QFPROM_ROW_LSB,
        TRUE,
        10
    },
    
    {
        QFPROM_DEBUG_KEY_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_DEBUG_KEY_LSB_ADDR,
        HWIO_QFPROM_CORR_DEBUG_KEY_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_DEBUG_KEY_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_DEBUG_KEY_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        12
    },
      
    {
        QFPROM_FEC_EN_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR,
        HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_FEC_EN_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_FEC_EN_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        15
    },
    
    {
        QFPROM_INTAGLIO_GLUEBIT_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_INTAGLIO_GLUEBIT_LSB_ADDR,
        HWIO_QFPROM_CORR_INTAGLIO_GLUEBIT_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_INTAGLIO_GLUEBIT_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_INTAGLIO_GLUEBIT_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        16
    },
    
    {
        QFPROM_CUST_KEY_REGION,
        2,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_CUST_KEY_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_CUST_KEY_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_CUST_KEY_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_CUST_KEY_BMSK,
        QFPROM_ROW_LSB,
        FALSE,
        17
    },
    
    {
        QFPROM_SERIAL_NUM_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SERIAL_NUM_LSB_ADDR,
        HWIO_QFPROM_CORR_SERIAL_NUM_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SERIAL_NUM_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SERIAL_NUM_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        18
    },
    
    {
        QFPROM_SPARE19_REGION,
        1,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SPARE_REG19_LSB_ADDR,
        HWIO_QFPROM_CORR_SPARE_REG19_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SPARE19_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SPARE19_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        19
    },
    {
        QFPROM_SEC_KEY_DERIVATION_KEY_REGION,
        5,
        QFPROM_FEC_63_56,
        HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(0) ,
        HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(0) ,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SEC_KEY_DERIVATION_KEY_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        22
    },    
    {
        QFPROM_OEM_PK_HASH_REGION,
        5,
        QFPROM_FEC_63_56,
        HWIO_QFPROM_RAW_OEM_PK_HASH_ROWn_LSB_ADDR(0) ,
        HWIO_QFPROM_CORR_OEM_PK_HASH_ROWn_LSB_ADDR(0) ,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_OEM_PK_HASH_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_OEM_PK_HASH_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        23
    },
    
    {
        QFPROM_OEM_SEC_BOOT_REGION,
        4,
        QFPROM_FEC_63_56,
        HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_OEM_SEC_BOOT_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_OEM_SEC_BOOT_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        24
    },
    
    {
        QFPROM_QC_SEC_BOOT_REGION,
        4,
        QFPROM_FEC_63_56,
        HWIO_QFPROM_RAW_QC_SEC_BOOT_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_QC_SEC_BOOT_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_QC_SEC_BOOT_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_QC_SEC_BOOT_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        25
    },
    
    {
        QFPROM_USB_VID_PID_REGION,
        1,
        QFPROM_FEC_63_56,
        HWIO_QFPROM_RAW_USB_VID_PID_LSB_ADDR,
        HWIO_QFPROM_CORR_USB_VID_PID_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_USB_VID_PID_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_USB_VID_PID_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        26
    },
    
    {
        QFPROM_SW_CALIBRATION_REGION,
        2,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SW_CALIB_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_SW_CALIB_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SW_CALIB_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SW_CALIB_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        27
    },
    
    {
        QFPROM_SPARE28_REGION,
        3,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SPARE_REG28_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_SPARE_REG28_ROW0_LSB_ADDR,
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SPARE28_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SPARE28_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        28
    },
    
    {
        QFPROM_SPARE29_REGION, 
        18,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SPARE_REG29_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_SPARE_REG29_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SPARE29_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SPARE29_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        29
    },
    
    {
        QFPROM_SPARE30_REGION, 
        17,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SPARE_REG30_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_SPARE_REG30_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SPARE30_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SPARE30_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        30
    },
    
    {
        QFPROM_SPARE31_REGION, 
        16,
        QFPROM_FEC_NONE,
        HWIO_QFPROM_RAW_SPARE_REG31_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_SPARE_REG31_ROWn_LSB_ADDR(0),
        HWIO_QFPROM_CORR_RD_WR_PERM_LSB_SPARE31_BMSK,
        HWIO_QFPROM_CORR_RD_WR_PERM_MSB_SPARE31_BMSK,
        QFPROM_ROW_LSB,
        TRUE,
        31
    },
    
    /* Add above this entry */
    {
        QFPROM_LAST_REGION_DUMMY,
        0,
        QFPROM_FEC_NONE,
        0,
        0,
        0,
        0,
        QFPROM_ROW_LSB
    }
};
