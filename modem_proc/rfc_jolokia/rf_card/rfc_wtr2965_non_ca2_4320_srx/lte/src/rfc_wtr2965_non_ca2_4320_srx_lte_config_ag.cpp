
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

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/rfc_jolokia/rf_card/rfc_wtr2965_non_ca2_4320_srx/lte/src/rfc_wtr2965_non_ca2_4320_srx_lte_config_ag.cpp#1 $ 


=============================================================================*/

/*=============================================================================
                           INCLUDE FILES
=============================================================================*/
#include "comdef.h"

#include "rfc_wtr2965_non_ca2_4320_srx_lte_config_ag.h" 
#include "rfc_wtr2965_non_ca2_4320_srx_cmn_ag.h" 
#include "rfc_common.h" 
#include "rfcom.h" 



extern "C" 
{
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_init_lte_rx_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_init_lte_rx_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_init_lte_tx_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_init_lte_tx_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b1_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b1_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b1_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b1_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b1_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b1_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b3_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b3_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b3_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b3_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b3_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b3_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b4_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b4_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b4_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b4_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b4_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b4_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b7_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b7_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b7_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b7_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b7_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b7_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b8_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b8_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b8_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b8_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b8_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b8_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b17_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b17_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b17_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b17_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b17_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b17_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b20_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b20_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b20_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b20_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b20_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b20_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b27_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b27_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b27_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b27_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b27_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b27_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_b_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_b_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_b_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_b_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_b_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_b_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b38_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b38_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b38_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b38_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b38_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b38_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b39_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b39_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b39_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b39_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b39_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b39_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b40_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b40_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b40_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b40_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b40_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b40_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b41_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b41_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b41_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b41_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b41_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b41_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_internal_adc_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_internal_adc_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_internal_adc_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_internal_adc_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_drx_iq_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_drx_iq_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_drx_iq_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_drx_iq_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap0_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap0_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap0_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap0_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap3_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap3_sig_cfg;
  extern rfc_device_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap3_device_info;
  extern rfc_sig_info_type rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap3_sig_cfg;

  extern rfc_timing_info_type rfc_msm_timing_info[RFC_TIMING_PARAMS_NUM];
} /* extern "C" */


rfc_lte_data * rfc_wtr2965_non_ca2_4320_srx_lte_ag::get_instance()
{
  if (rfc_lte_data_ptr == NULL)
  {
    rfc_lte_data_ptr = (rfc_lte_data *)new rfc_wtr2965_non_ca2_4320_srx_lte_ag();
  }
  return( (rfc_lte_data *)rfc_lte_data_ptr);
}

//constructor
rfc_wtr2965_non_ca2_4320_srx_lte_ag::rfc_wtr2965_non_ca2_4320_srx_lte_ag()
  :rfc_lte_data()
{
}

boolean rfc_wtr2965_non_ca2_4320_srx_lte_ag::sig_cfg_data_get( rfc_cfg_params_type *cfg, rfc_sig_cfg_type **ptr )
{

  boolean ret_val = FALSE;

  if (NULL==ptr)
  {
    return FALSE;
  }

  if (NULL==cfg)
  {
    *ptr = NULL;
    return FALSE;
  }

  *ptr = NULL;

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->req == RFC_REQ_INIT ) )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_init_lte_rx_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->req == RFC_REQ_INIT ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_init_lte_tx_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b1_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b1_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b1_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b3_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b3_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b3_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b4_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b4_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b4_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b7_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b7_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b7_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b8_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b8_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b8_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b17_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b17_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b17_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b20_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b20_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b20_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b27_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b27_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b27_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_b_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_b_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_b_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b38_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b38_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b38_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b39_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b39_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b39_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b40_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b40_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b40_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b41_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b41_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b41_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_ENABLE_FBRX ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_internal_adc_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_DISABLE_FBRX ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_internal_adc_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_ENABLE_XPT_CAPTURE ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_drx_iq_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_DISABLE_XPT_CAPTURE ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_drx_iq_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap0_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap0_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap3_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap3_sig_cfg.cfg_sig_list[0]);  ret_val = TRUE; }


  

  return ret_val;
}

boolean rfc_wtr2965_non_ca2_4320_srx_lte_ag::devices_cfg_data_get( rfc_cfg_params_type *cfg, rfc_device_info_type **ptr )
{

  boolean ret_val = FALSE;

  if (NULL==ptr)
  {
    return FALSE;
  }

  if (NULL==cfg)
  {
    *ptr = NULL;
    return FALSE;
  }

  *ptr = NULL;

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->req == RFC_REQ_INIT ) )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_init_lte_rx_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->req == RFC_REQ_INIT ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_init_lte_tx_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b1_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b1_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b1_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b3_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b3_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b3_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b4_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b4_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b4_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b7_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b7_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b7_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b8_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b8_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b8_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b17_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b17_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b17_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b20_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b20_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b20_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b27_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b27_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b27_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_b_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_b_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_b_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b38_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b38_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b38_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b39_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b39_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b39_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b40_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b40_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b40_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b41_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b41_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b41_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_ENABLE_FBRX ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_internal_adc_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_DISABLE_FBRX ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_internal_adc_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_ENABLE_XPT_CAPTURE ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_et_cal0_fbrx_path_drx_iq_device_info);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) &&  ( cfg->req == RFC_REQ_DISABLE_XPT_CAPTURE ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_et_cal0_fbrx_path_drx_iq_device_info);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap0_device_info);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap0_device_info);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_en_ant_swap3_device_info);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rf_card_wtr2965_non_ca2_4320_srx_lte_dis_ant_swap3_device_info);  ret_val = TRUE; }





  return ret_val;
}

boolean rfc_wtr2965_non_ca2_4320_srx_lte_ag::timing_cfg_data_get( rfc_cfg_params_type *cfg, rfc_timing_info_type **ptr )
{

  boolean ret_val = FALSE;

  if (NULL==ptr)
  {
    return FALSE;
  }

  if (NULL==cfg)
  {
    *ptr = NULL;
    return FALSE;
  }

  *ptr = NULL;

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->req == RFC_REQ_INIT ) )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->req == RFC_REQ_INIT ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B1 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B3 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B4 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B7 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B8 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B17 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B20 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B27 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B28_B ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B38 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B39 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B40 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_RX ) && ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) && ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( cfg->band == (int)RFCOM_BAND_LTE_B41 ) && ( cfg->req == RFC_REQ_DEFAULT_GET_DATA ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_FBRX ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_FBRX ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_XPT_CAPTURE ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->rx_tx == RFC_CONFIG_TX ) &&  ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B8 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_XPT_CAPTURE ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_0 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_ENABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }

  if ( ( cfg->logical_device == RFM_DEVICE_1 ) && ( cfg->alternate_path == 0 /*Warning: not specified*/ ) && ( ( cfg->band == (int)RFCOM_BAND_LTE_B1 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B3 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B4 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B7 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B17 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B20 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B27 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B28_B )||  ( cfg->band == (int)RFCOM_BAND_LTE_B38 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B39 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B40 )||  ( cfg->band == (int)RFCOM_BAND_LTE_B41 )) && ( cfg->req == RFC_REQ_DISABLE_ANT_SWAP_1 ) && !ret_val )
  { *ptr = &(rfc_msm_timing_info[0]);  ret_val = TRUE; }


  return ret_val;
}

boolean rfc_wtr2965_non_ca2_4320_srx_lte_ag::ca_scell_log_path_swap_data_get( rfc_band_pair_list_type **ptr )
{
  if (NULL==ptr)
  {
    return FALSE;
  }

  *ptr = NULL;

  return TRUE;
}

extern "C" 
{
  extern rfc_band_split_info_type rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_split_cfg;
  extern rfc_band_split_info_type rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_split_cfg;
  extern rfc_band_split_info_type rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_split_cfg;
}  /* extern "C" */

boolean rfc_wtr2965_non_ca2_4320_srx_lte_ag::band_split_cfg_data_get( rfc_cfg_params_type *cfg, rfc_band_split_info_type **ptr )
{
  boolean ret_val = FALSE;

  if (NULL==ptr)
  {
    return FALSE;
  }

  if (NULL==cfg)
  {
    *ptr = NULL;
    return FALSE;
  }

  *ptr = NULL;

  if ( (cfg->rx_tx == RFC_CONFIG_RX) && (cfg->logical_device == RFM_DEVICE_0) && (cfg->band == (int)RFCOM_BAND_LTE_B28) )
  { *ptr = &rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_split_cfg; ret_val = TRUE; }

  else if ( (cfg->rx_tx == RFC_CONFIG_RX) && (cfg->logical_device == RFM_DEVICE_0) && (cfg->band == (int)RFCOM_BAND_LTE_B28_B) )
  { *ptr = &rf_card_wtr2965_non_ca2_4320_srx_rx0_lte_b28_split_cfg; ret_val = TRUE; }

  else if ( (cfg->rx_tx == RFC_CONFIG_TX) && (cfg->logical_device == RFM_DEVICE_0) && (cfg->band == (int)RFCOM_BAND_LTE_B28) )
  { *ptr = &rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_split_cfg; ret_val = TRUE; }

  else if ( (cfg->rx_tx == RFC_CONFIG_TX) && (cfg->logical_device == RFM_DEVICE_0) && (cfg->band == (int)RFCOM_BAND_LTE_B28_B) )
  { *ptr = &rf_card_wtr2965_non_ca2_4320_srx_tx0_lte_b28_split_cfg; ret_val = TRUE; }

  else if ( (cfg->rx_tx == RFC_CONFIG_RX) && (cfg->logical_device == RFM_DEVICE_1) && (cfg->band == (int)RFCOM_BAND_LTE_B28) )
  { *ptr = &rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_split_cfg; ret_val = TRUE; }

  else if ( (cfg->rx_tx == RFC_CONFIG_RX) && (cfg->logical_device == RFM_DEVICE_1) && (cfg->band == (int)RFCOM_BAND_LTE_B28_B) )
  { *ptr = &rf_card_wtr2965_non_ca2_4320_srx_rx1_lte_b28_split_cfg; ret_val = TRUE; }

  return ret_val;
}

