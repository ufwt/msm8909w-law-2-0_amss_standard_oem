
/*
WARNING: This file is auto-generated.

Generated using: xmlautogen.exe
Generated from: V5.9.321 of RFC_HWSWCD.xlsm
*/

/*=============================================================================

          R F C     A U T O G E N    F I L E

GENERAL DESCRIPTION
  This file is auto-generated and it captures the configuration of the RF Card.

Copyright (c) 2016 Qualcomm Technologies Incorporated.  All Rights Reserved.

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/rfc_jolokia/rf_card/rfc_wtr2965_dual_wtr_4320_srx/wcdma/src/rfc_wtr2965_dual_wtr_4320_srx_wcdma_config_data_ag.c#1 $ 


=============================================================================*/

/*=============================================================================
                           INCLUDE FILES
=============================================================================*/
#include "comdef.h"

#include "rfc_wtr2965_dual_wtr_4320_srx_cmn_ag.h" 
#include "rfc_common.h" 
#include "rfcom.h" 
#include "wtr2965_typedef_ag.h" 
#include "qfe4320_pa_port_typedef_ag.h" 
#include "rfdevice_qtuner_api.h" 

rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_init_wcdma_rx_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not Specified */,   /* Modem Chain */
  0 /* Warning: Not Specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not Specified */,   /* Antenna */
  2,  /* NUM_DEVICES_TO_CONFIGURE */
{
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0 /* Warning: Not specified */,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0 /* Warning: Not specified */,   /* INTF_REV */
        0 /* Invalid TRx port */,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0 /* Warning: Not specified */,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0 /* Warning: Not specified */,   /* INTF_REV */
        0 /* Invalid TRx port */,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_init_wcdma_rx_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_init_wcdma_tx_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not Specified */,   /* Modem Chain */
  0 /* Warning: Not Specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not Specified */,   /* Antenna */
  2,  /* NUM_DEVICES_TO_CONFIGURE */
{
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0 /* Warning: Not specified */,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0 /* Warning: Not specified */,   /* INTF_REV */
        0 /* Invalid TRx port */,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0 /* Warning: Not specified */,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0 /* Warning: Not specified */,   /* INTF_REV */
        0 /* Invalid TRx port */,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_init_wcdma_tx_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b1_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  3,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND1_PMB3,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (7)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b1_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_02,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_15,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b1_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND1_PMB3,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b1_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b1_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  7,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND1_THMLB4,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      QFE4320_EPT, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (QFE4320_EPT_WCDMA_BAND1_PORT_TX_PORT_10)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_TX, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (17)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (7)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b1_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b2_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  4,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND2_PMB2,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (2)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      GEN_ASM /* ASM_SP4T_PRX */, /* NAME */
      8,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x20C << 22)/*mfg_id*/ | (0x83 << 14)/*prd_id*/ | (2)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b2_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_02,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b2_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND2_PMB2,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b2_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b2_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  7,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND2_THMLB4,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      QFE4320_EPT, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (QFE4320_EPT_WCDMA_BAND2_PORT_TX_PORT_11)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_TX, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (20)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (2)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b2_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b4_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  3,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND4_PMB3,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (2)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b4_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_02,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_15,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b4_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND4_PMB3,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b4_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b4_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  7,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND4_THMLB4,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      QFE4320_EPT, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (QFE4320_EPT_WCDMA_BAND4_PORT_TX_PORT_13)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_TX, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (19)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (2)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b4_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b5_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  3,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND5_PLB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_LB, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b5_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_04,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_17,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b5_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND5_PLB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b5_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b5_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  7,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND5_THMLB2,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      QFE4320_EPT, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (QFE4320_EPT_WCDMA_BAND5_PORT_TX_PORT_0)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (15)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_TX, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (8)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_LB, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b5_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b8_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  3,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND8_PLB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_LB, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (0)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b8_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_04,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_17,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b8_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND8_PLB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b8_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b8_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  7,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND8_THMLB2,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      QFE4320_EPT, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (QFE4320_EPT_WCDMA_BAND8_PORT_TX_PORT_1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (15)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_TX, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (5)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_LB, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (0)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b8_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b9_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  4,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND9_PMB2,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (7)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      GEN_ASM /* ASM_SP4T_PRX */, /* NAME */
      8,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x20C << 22)/*mfg_id*/ | (0x83 << 14)/*prd_id*/ | (3)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b9_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_02,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b9_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND9_PMB2,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b9_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b9_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  0,   /* Antenna */
  7,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND9_THMLB4,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      QFE4320_EPT, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (QFE4320_EPT_WCDMA_BAND9_PORT_TX_PORT_12)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (1)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_TX, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (18)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      QFE4320_MB, /* NAME */
      2,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x44 << 14)/*prd_id*/ | (7)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_TUNER,
      QFE2550, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:   */,  /* INTF_REV */
        (int)RFDEVICE_QTUNER_IM_DISTORTION_INVALID,  /* DISTORTION_CONFIG */  
        0  /* Orig setting: */,  /* NOTES (REFERENCE ONLY) */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b9_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b11_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  2,   /* Antenna */
  2,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND11_PMB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      GEN_ASM /* ASM_SP6T */, /* NAME */
      7,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x20C << 22)/*mfg_id*/ | (0x20 << 14)/*prd_id*/ | (5)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx0_wcdma_b11_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_02,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_11,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b11_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */
  0,   /* NV Container */
  2,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_PRXLGY1_BAND11_PMB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_rx1_wcdma_b11_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b11_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_TX_MODEM_CHAIN_0,   /* Modem Chain */
  0,   /* NV Container */
  2,   /* Antenna */
  5,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        (int)WTR2965_WCDMA_TX_BAND11_THMLB1,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_VALID | WTR2965_LP_LUT_TYPE << RFDEVICE_PA_STATE_0_BSHFT | WTR2965_HP_LUT_TYPE << RFDEVICE_PA_STATE_1_BSHFT | WTR2965_LUT_PWR_INVALID << RFDEVICE_PA_STATE_2_BSHFT | WTR2965_LUT_PWR_INVALID << RFDEVICE_PA_STATE_3_BSHFT  ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_LOW_ATTN_MODE,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PA,
      GEN_PA /* B11_PA */, /* NAME */
      5,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x134 << 22)/*mfg_id*/ | (0x1D << 14)/*prd_id*/ | (2)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_PAPM,
      QFE2101, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x217 << 22)/*mfg_id*/ | (0x31 << 14)/*prd_id*/ | (3)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_ASM,
      GEN_ASM /* ASM_SP6T */, /* NAME */
      7,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        (0x20C << 22)/*mfg_id*/ | (0x20 << 14)/*prd_id*/ | (5)/*port_num*/, /* PORT_NUM */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
    {
      RFDEVICE_HDET,
      TRX_HDET, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0 /* Warning: Not specified */,   /* PHY_PATH_NUM */
      {
        0  /* Orig setting:  */,  /* INTF_REV */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_tx0_wcdma_b11_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_TX_GTR_TH,   { RFC_CONFIG_ONLY, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal0_fbrx_path_internal_adc_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not specified */,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_INTERNAL_ADC,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal0_fbrx_path_internal_adc_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal0_fbrx_path_internal_adc_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not specified */,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_INTERNAL_ADC,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal0_fbrx_path_internal_adc_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal0_fbrx_path_drx_iq_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_DRX_IQ,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal0_fbrx_path_drx_iq_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal0_fbrx_path_drx_iq_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      0,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_DRX_IQ,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal0_fbrx_path_drx_iq_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal1_fbrx_path_internal_adc_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not specified */,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_INTERNAL_ADC,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal1_fbrx_path_internal_adc_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal1_fbrx_path_internal_adc_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not specified */,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_INTERNAL_ADC,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal1_fbrx_path_internal_adc_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal1_fbrx_path_drx_iq_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_DRX_IQ,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal1_fbrx_path_drx_iq_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal1_fbrx_path_drx_iq_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_DRX_IQ,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal1_fbrx_path_drx_iq_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_14,   { RFC_HIGH, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal2_fbrx_path_internal_adc_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not specified */,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_INTERNAL_ADC,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal2_fbrx_path_internal_adc_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal2_fbrx_path_internal_adc_device_info = 
{
  RFC_ENCODED_REVISION, 
  0 /* Warning: Not specified */,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_INTERNAL_ADC,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal2_fbrx_path_internal_adc_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal2_fbrx_path_drx_iq_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_DRX_IQ,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_en_et_cal2_fbrx_path_drx_iq_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_device_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal2_fbrx_path_drx_iq_device_info = 
{
  RFC_ENCODED_REVISION, 
  RFC_RX_MODEM_CHAIN_1,   /* Modem Chain */        
  0 /* Warning: Not specified */,   /* NV Container */
  RFC_INVALID_PARAM /* Warning: Not specified */,   /* Antenna */
  1,  /* NUM_DEVICES_TO_CONFIGURE */
  {
    {
      RFDEVICE_TRANSCEIVER,
      WTR2965, /* NAME */
      1,   /* DEVICE_MODULE_TYPE_INSTANCE */
      0,   /* PHY_PATH_NUM */            
      {
        0 /* Warning: Not specified */,   /* INTF_REV */                  
        RFDEVICE_FBRX_PATH_DRX_IQ,   /* PORT */
        ( RFDEVICE_PA_LUT_MAPPING_INVALID ),   /* RF_ASIC_BAND_AGC_LUT_MAPPING */        
        FALSE,   /* TXAGC_LUT */
        WTR2965_FBRX_ATTN_DEFAULT,   /* FBRX_ATTN_STATE */
        0,  /* Array Filler */
      },
    },
  },
};


rfc_sig_info_type rf_card_wtr2965_dual_wtr_4320_srx_wcdma_dis_et_cal2_fbrx_path_drx_iq_sig_cfg = 
{
  RFC_ENCODED_REVISION, 
  {
    { (int)RFC_WTR2965_DUAL_WTR_4320_SRX_RF_PATH_SEL_05,   { RFC_LOW, 0/*Warning: Not specified*/ }, {RFC_LOW, 0/*Warning: Not specified*/ }  },
    { (int)RFC_SIG_LIST_END,   { RFC_LOW, 0 }, {RFC_LOW, 0 } }
  },
};


rfc_wcdma_properties_type rfc_wtr2965_dual_wtr_4320_srx_wcdma_properties =
{
  RFC_ENCODED_REVISION,
  /* WCDMA_DBDC_COMBINATIONS_SUPPORTED */
  {
    { (uint32)SYS_BAND_CLASS_NONE, (uint32)SYS_BAND_CLASS_NONE    }
  }
};

























