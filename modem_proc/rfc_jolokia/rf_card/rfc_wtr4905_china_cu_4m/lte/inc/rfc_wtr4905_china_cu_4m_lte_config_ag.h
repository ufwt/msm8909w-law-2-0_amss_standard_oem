
#ifndef RFC_WTR4905_CHINA_CU_4M_LTE_CONFIG_AG
#define RFC_WTR4905_CHINA_CU_4M_LTE_CONFIG_AG

#ifdef __cplusplus
extern "C" {
#endif
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

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/rfc_jolokia/rf_card/rfc_wtr4905_china_cu_4m/lte/inc/rfc_wtr4905_china_cu_4m_lte_config_ag.h#1 $ 


=============================================================================*/

/*=============================================================================
INCLUDE FILES
=============================================================================*/
#include "comdef.h"

#include "rfc_msm_typedef.h"
#include "rfc_common.h"
#include "rfc_lte_data.h"



class rfc_wtr4905_china_cu_4m_lte_ag:public rfc_lte_data
{
public:
  static rfc_lte_data * get_instance();
  boolean sig_cfg_data_get( rfc_cfg_params_type *cfg, rfc_sig_cfg_type **ptr );
  boolean devices_cfg_data_get( rfc_cfg_params_type *cfg, rfc_device_info_type **ptr );
  boolean timing_cfg_data_get( rfc_cfg_params_type *cfg, rfc_timing_info_type **ptr );
  boolean ca_scell_log_path_swap_data_get( rfc_band_pair_list_type **ptr );
  boolean band_split_cfg_data_get( rfc_cfg_params_type *cfg, rfc_band_split_info_type **ptr );

protected:
  rfc_wtr4905_china_cu_4m_lte_ag(void);  /*  Constructor  */
};


#ifdef __cplusplus
}
#endif



#endif

