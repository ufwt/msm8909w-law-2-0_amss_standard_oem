# 1 "/local/mnt/workspace/CRMBuilds/MPSS.JO.2.0.c1.4-00005-8909_GENS_PACK-1_20170119_051958/b/modem_proc/audio_avs/vsd/common/cvd/cvd_devcfg/msm8909/cvd_devcfg.xml"
# 1 "/local/mnt/workspace/CRMBuilds/MPSS.JO.2.0.c1.4-00005-8909_GENS_PACK-1_20170119_051958/b/modem_proc/audio_avs/vsd/common/cvd/cvd_devcfg/msm8909/cvd_devcfg.xml" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 136 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/local/mnt/workspace/CRMBuilds/MPSS.JO.2.0.c1.4-00005-8909_GENS_PACK-1_20170119_051958/b/modem_proc/audio_avs/vsd/common/cvd/cvd_devcfg/msm8909/cvd_devcfg.xml" 2
<!--
  Copyright (C) 2013 - 2014 QUALCOMM Technologies Inc.
  All rights reserved.
  Qualcomm Technologies Inc. Confidential and Proprietary.

  $Header: $
  $Author: $
 -->

<!-- Non-DAL drivers uses NULL driver name. -->
<driver name="NULL">
<!-- CVD voice use case power management configurations. -->
<device id="QCOM_CVD">

<props name="CLOCK_TABLE" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
cvd_devcfg_clock_table
</props>
<props name="USE_CASE_NA_VAL" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
cvd_devcfg_voice_use_case_na_values
</props>
<props name="MMPM_CORE_INFO" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
cvd_devcfg_mmpm_core_info
</props>
<props name="MMPM_BW_REQUIREMENT" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
cvd_devcfg_mmpm_bw_requirement
</props>
<props name="MMPM_SLEEP_LATENCY" type=DALPROP_ATTR_TYPE_UINT32>
20
</props>
<props name="CYCLES_PER_KP_FACTOR" type=DALPROP_ATTR_TYPE_UINT32>
2400
</props>

</device>

</driver>
