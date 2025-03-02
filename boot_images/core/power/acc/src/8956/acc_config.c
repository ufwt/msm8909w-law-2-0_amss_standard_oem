/*===========================================================================

  Copyright (c) 2013 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================*/
  
#include "tcsr_hwio.h"
#include "acc.h"

const unsigned acc_register_settings[ACC_REGISTER_NUM_SETTING] =
{
    0x1,    //SVS_REGISTER_SVS_SETTING
    0x0,    //SVS_REGISTER_NOM_SETTING
};


const acc_target_config acc_config = 
{
   .config = (const acc_control_config[])
    {
        {
        .rail_name = "vddcx",
        .acc_register_setting = (const int[])
            {
                ACC_MODE_NOT_SUPPORTED,         // RAILWAY_NO_REQUEST
                ACC_REGISTER_SVS_SETTING,       // RAILWAY_RETENTION
                ACC_MODE_NOT_SUPPORTED,         // RAILWAY_SVS_KRAIT
                ACC_REGISTER_SVS_SETTING,       // RAILWAY_SVS_SOC
                ACC_MODE_NOT_SUPPORTED,         // RAILWAY_SVS_HIGH
                ACC_REGISTER_NOM_SETTING,       // RAILWAY_NOMINAL
                ACC_REGISTER_NOM_SETTING        // RAILWAY_TURBO
                ACC_MODE_NOT_SUPPORTED,         // RAILWAY_TURBO_HIGH
                ACC_REGISTER_NOM_SETTING,       // RAILWAY_SUPER_TURBO
                ACC_MODE_NOT_SUPPORTED,        // RAILWAY_SUPER_TURBO_NO_CPR
            },
        .acc_register_address = (volatile unsigned*) HWIO_TCSR_MEM_ACC_SEL_VDDCX_ADDR,
        },
    },
    .number_of_acc_controls = 1,
};

const acc_target_config* ACC_TARGET_CONFIG = &acc_config;

