/*===========================================================================
  	
  	FILE:         rbcpr_bsp.c


	DESCRIPTION:  Per target rbcpr bsp configurations
  	
=============================================================================
	
Edit History

$Header: //components/rel/rpm.bf/2.1.1/core/power/rbcpr/src/target/8916/rbcpr_bsp.c#1 $
$Date: 2015/02/25 $
	 
when       who     what, where, why
--------   ---     --------------------------------------------------------
  
===========================================================================
Copyright (c) 2014 Qualcomm Technologies Incorporated.
All Rights Reserved.
QUALCOMM Proprietary and Confidential.
===========================================================================*/

 /* -----------------------------------------------------------------------
**                           INCLUDES
** ----------------------------------------------------------------------- */

#include "rbcpr.h"
#include "rbcpr_comdef.h"
#include "HAL_rbcpr_qfprom.h"
#include "railway.h"
#include "Chipinfo.h"

 /* -----------------------------------------------------------------------
**                     		DATA
** ----------------------------------------------------------------------- */

const rbcpr_bsp_rail_params_type gf_tn1_cpr_settings[] =
{
     {   // VDDCX
        .target_params = (rbcpr_corner_params_type[])
        {
            {
                .rosc_target[0] = 307,
                .rosc_target[1] = 354,
                .rosc_target[2] = 542,
                .rosc_target[3] = 494,
                .rosc_target[4] = 331,
                .rosc_target[5] = 286,
                .rosc_target[6] = 496,
                .rosc_target[7] = 450,
                .corner         = RAILWAY_SVS_SOC,
                .fuse           = HAL_RBCPR_FUSE_SVS,
                .voltage_ceil   = 1050000,
                .voltage_floor  = 900000,
            },
            {
                .rosc_target[0] = 432,
                .rosc_target[1] = 481,
                .rosc_target[2] = 695,
                .rosc_target[3] = 646,
                .rosc_target[4] = 447,
                .rosc_target[5] = 399,
                .rosc_target[6] = 637,
                .rosc_target[7] = 587,
                .corner         = RAILWAY_NOMINAL,
                .fuse           = HAL_RBCPR_FUSE_NOMINAL,
                .voltage_ceil   = 1150000,
                .voltage_floor  = 1000000,
            },
            {
                .rosc_target[0] = 568,
                .rosc_target[1] = 614,
                .rosc_target[2] = 850,
                .rosc_target[3] = 799,
                .rosc_target[4] = 568,
                .rosc_target[5] = 525,
                .rosc_target[6] = 777,
                .rosc_target[7] = 725,
                .corner         = RAILWAY_SUPER_TURBO,
                .fuse           = HAL_RBCPR_FUSE_TURBO,
                .voltage_ceil   = 1287500,
                .voltage_floor  = 1137500,
            },
        },
        .rbcpr_enablement=RBCPR_ENABLED_CLOSED_LOOP,
        .number_of_target_params=3,
    },
};

const rbcpr_bsp_rail_params_type gf_tn3_cpr_settings[] =
{
     {   // VDDCX
        .target_params = (rbcpr_corner_params_type[])
        {
            {
                .rosc_target[0] = 324,
                .rosc_target[1] = 332,
                .rosc_target[2] = 575,
                .rosc_target[3] = 536,
                .rosc_target[4] = 292,
                .rosc_target[5] = 308,
                .rosc_target[6] = 506,
                .rosc_target[7] = 481,
                .corner         = RAILWAY_SVS_SOC,
                .fuse           = HAL_RBCPR_FUSE_SVS,
                .voltage_ceil   = 1050000,
                .voltage_floor  = 900000,
            },
            {
                .rosc_target[0] = 471,
                .rosc_target[1] = 473,
                .rosc_target[2] = 757,
                .rosc_target[3] = 708,
                .rosc_target[4] = 429,
                .rosc_target[5] = 441,
                .rosc_target[6] = 672,
                .rosc_target[7] = 637,
                .corner         = RAILWAY_NOMINAL,
                .fuse           = HAL_RBCPR_FUSE_NOMINAL,
                .voltage_ceil   = 1150000,
                .voltage_floor  = 1000000,
            },
            {
                .rosc_target[0] = 658,
                .rosc_target[1] = 648,
                .rosc_target[2] = 971,
                .rosc_target[3] = 908,
                .rosc_target[4] = 603,
                .rosc_target[5] = 605,
                .rosc_target[6] = 869,
                .rosc_target[7] = 821,
                .corner         = RAILWAY_SUPER_TURBO,
                .fuse           = HAL_RBCPR_FUSE_TURBO,
                .voltage_ceil   = 1287500,
                .voltage_floor  = 1137500,
            },
        },
        .rbcpr_enablement=RBCPR_ENABLED_CLOSED_LOOP,
        .number_of_target_params=3,
    },
};

const rbcpr_bsp_rail_params_type tsmc_tn1_cpr_settings[] =
{
     {   // VDDCX
        .target_params = (rbcpr_corner_params_type[])
        {
            {
                .rosc_target[0] = 324,
                .rosc_target[1] = 332,
                .rosc_target[2] = 575,
                .rosc_target[3] = 536,
                .rosc_target[4] = 292,
                .rosc_target[5] = 308,
                .rosc_target[6] = 506,
                .rosc_target[7] = 481,
                .corner         = RAILWAY_SVS_SOC,
                .fuse           = HAL_RBCPR_FUSE_SVS,
                .voltage_ceil   = 1050000,
                .voltage_floor  = 900000,
            },
            {
                .rosc_target[0] = 471,
                .rosc_target[1] = 473,
                .rosc_target[2] = 757,
                .rosc_target[3] = 708,
                .rosc_target[4] = 429,
                .rosc_target[5] = 441,
                .rosc_target[6] = 672,
                .rosc_target[7] = 637,
                .corner         = RAILWAY_NOMINAL,
                .fuse           = HAL_RBCPR_FUSE_NOMINAL,
                .voltage_ceil   = 1150000,
                .voltage_floor  = 1000000,
            },
            {
                .rosc_target[0] = 658,
                .rosc_target[1] = 648,
                .rosc_target[2] = 971,
                .rosc_target[3] = 908,
                .rosc_target[4] = 603,
                .rosc_target[5] = 605,
                .rosc_target[6] = 869,
                .rosc_target[7] = 821,
                .corner         = RAILWAY_SUPER_TURBO,
                .fuse           = HAL_RBCPR_FUSE_TURBO,
                .voltage_ceil   = 1287500,
                .voltage_floor  = 1137500,
            },
        },
        .rbcpr_enablement=RBCPR_ENABLED_CLOSED_LOOP,
        .number_of_target_params=3,
    },
};

const rbcpr_bsp_rail_params_type tsmc_tn3_cpr_settings[] =
{
     {   // VDDCX
        .target_params = (rbcpr_corner_params_type[])
        {
            {
                .rosc_target[0] = 324,
                .rosc_target[1] = 332,
                .rosc_target[2] = 575,
                .rosc_target[3] = 536,
                .rosc_target[4] = 292,
                .rosc_target[5] = 308,
                .rosc_target[6] = 506,
                .rosc_target[7] = 481,
                .corner         = RAILWAY_SVS_SOC,
                .fuse           = HAL_RBCPR_FUSE_SVS,
                .voltage_ceil   = 1050000,
                .voltage_floor  = 900000,
            },
            {
                .rosc_target[0] = 471,
                .rosc_target[1] = 473,
                .rosc_target[2] = 757,
                .rosc_target[3] = 708,
                .rosc_target[4] = 429,
                .rosc_target[5] = 441,
                .rosc_target[6] = 672,
                .rosc_target[7] = 637,
                .corner         = RAILWAY_NOMINAL,
                .fuse           = HAL_RBCPR_FUSE_NOMINAL,
                .voltage_ceil   = 1150000,
                .voltage_floor  = 1000000,
            },
            {
                .rosc_target[0] = 658,
                .rosc_target[1] = 648,
                .rosc_target[2] = 971,
                .rosc_target[3] = 908,
                .rosc_target[4] = 603,
                .rosc_target[5] = 605,
                .rosc_target[6] = 869,
                .rosc_target[7] = 821,
                .corner         = RAILWAY_SUPER_TURBO,
                .fuse           = HAL_RBCPR_FUSE_TURBO,
                .voltage_ceil   = 1287500,
                .voltage_floor  = 1137500,
            },
        },
        .rbcpr_enablement=RBCPR_ENABLED_CLOSED_LOOP,
        .number_of_target_params=3,
    },
};

const rbcpr_bsp_revision_array_type hw_version_specific_settings_8916 =
{
    .hw_version_count = 1,
    .hw_version_array = (const rbcpr_versioned_bsp_rail_params_type[])
    {
		{
		.fab_process_id_count = 4,
		.rbcpr_bsp_params_tsmc_fab = (const rbcpr_tsmc_fab_id_settings[])
			{
				{
					.bsp_params = ( rbcpr_bsp_rail_params_type*)&gf_tn1_cpr_settings,
					.process_id = 0,
					.foundry_id = 1,
				},
			  
				{
					.bsp_params = ( rbcpr_bsp_rail_params_type*)&gf_tn3_cpr_settings,
					.process_id = 1,
					.foundry_id = 1,
				},
			  
				{
					.bsp_params = ( rbcpr_bsp_rail_params_type*)&tsmc_tn1_cpr_settings,
					.process_id = 0,
					.foundry_id = 0,
				},
			  
				{
					.bsp_params = ( rbcpr_bsp_rail_params_type*)&tsmc_tn3_cpr_settings,
					.process_id = 1,
					.foundry_id = 0,
				},
			},
		 
        .supported_hw_after_version = CHIPINFO_VERSION(0, 0),
		}	
    },
    .supported_chipset = CHIPINFO_FAMILY_MSM8916,
};

const rbcpr_supported_hw_array_type rbcpr_supported_hw_array =
{
    .hw_version_specific_settings = (const rbcpr_bsp_revision_array_type*[])
    {
        &hw_version_specific_settings_8916,
    },
    .hw_version_specific_settings_count = 1,
};

const rbcpr_bsp_rail_const_info rbcpr_rail_const_info[] =
{
    {   // VDDCX
        .ref_clk_resource       = "gcc_rbcpr_clk",
        .ahb_clk_resource       = "gcc_rbcpr_ahb_clk",
        .rail_name              = "vddcx",
        .interrupt_id           = 62,   // top_cpr_irq[0]
        .idle_clocks            = 15,
        .step_quot              = 26,
        .pmic_step_size_uv      = 12500,
        .up_threshold           = 0,
        .dn_threshold           = 2,
        .consecutive_up         = 0,
        .consecutive_dn         = 2,
        .gcnt                   = 19,
        .count_mode = HAL_RBCPR_STAGGERED,
        .efuse_target_voltage_multipler = 10000,
    },
};

rbcpr_bsp_type rbcpr_bsp_data =
{
    .rails = (rbcpr_bsp_rail_info[])
    {
        {   // VDDCX
            .rail_const_info = &rbcpr_rail_const_info[0],
        },
    },
    .num_rails = 1,
};
