/*==============================================================================

FILE:      icbcfg_data.c

DESCRIPTION: This file implements the ICB Configuration driver.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A
 
Edit History

$Header: //components/rel/core.mpss/3.5.c12.3/buses/icb/src/8937/icbcfg_data.c#1 $ 
$DateTime: 2016/12/13 07:59:23 $
$Author: mplcsds1 $
$Change: 11985146 $ 

When        Who    What, where, why
----------  ---    -----------------------------------------------------------
2014/05/20  sds    Change the hardware base address to a uint8_t*.
2014/05/15  sds    Update to 0.05 spreadsheet
2014/02/28  sds    Update to 0.04 spreadsheet
2013/12/11  sds    First pass at DDR settings spreadsheet
2013/10/09  sds    Branched for 8916
2013/02/26  sds    Changed how available DDR regions are handled.
2013/02/04  jc     Updated masters and slaves to match TO
2012/12/06  jc     8x10 implementation
2012/03/26  av     Created
 
        Copyright (c) 2012-2015 Qualcomm Technologies Incorporated.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
==============================================================================*/
#include "icbcfg.h"
#include "icbcfgi.h"
#include "icbcfg_hwio.h"
#include "HALbimc.h"
#include "HALbimcHwioGeneric.h"

/*---------------------------------------------------------------------------*/
/*          Macro and constant definitions                                   */
/*---------------------------------------------------------------------------*/
/* BIMC register value macros */
#define SLAVE_SEGMENT(slave,index,addr_base,addr_mask)  \
  {ICBCFG_32_BIT_REG, \
   (void *)BIMC_SEGMENTn_ADDR_BASEm_LOWER_ADDR((uint8_t *)BIMC_BASE,slave,index), \
   BIMC_SEGMENTn_ADDR_BASEm_LOWER_RMSK, \
   BIMC_SEGMENTn_ADDR_BASEm_LOWER_RMSK, \
   (addr_base) }, \
  {ICBCFG_32_BIT_REG, \
   (void *)BIMC_SEGMENTn_ADDR_MASKm_LOWER_ADDR((uint8_t *)BIMC_BASE,slave,index), \
   BIMC_SEGMENTn_ADDR_MASKm_LOWER_RMSK, \
   BIMC_SEGMENTn_ADDR_MASKm_LOWER_RMSK, \
   (addr_mask) }

#define ARB_MODE(slave,mode) \
  {ICBCFG_32_BIT_REG, \
   (void *)BIMC_S_ARB_MODE_ADDR((uint8_t *)BIMC_BASE,slave), \
   BIMC_S_ARB_MODE_RMSK, \
   BIMC_S_ARB_MODE_RMSK, \
   (mode) }

/* Slave indexes */
#define SLAVE_DDR_CH0 0
#define SLAVE_APPS_L2 1
#define SLAVE_SNOC    2

#define MPORT_MODE(master,mode) \
  {ICBCFG_32_BIT_REG, \
   (void *)BIMC_M_MODE_ADDR((uint8_t *)BIMC_BASE,master), \
   BIMC_M_MODE_RMSK, \
   BIMC_M_MODE_RMSK, \
   (mode) }

/* Master indexes */
#define MASTER_APP   0
#define MASTER_DSP   1
#define MASTER_GPU   2
#define MASTER_SYS0  3
#define MASTER_SYS1  4
#define MASTER_TCU0  5
#define MASTER_TCU1  6

/*============================================================================
                        DEVICE CONFIG PROPERTY DATA
============================================================================*/

/*---------------------------------------------------------------------------*/
/*          Properties data for device ID  = "icbcfg/boot"                   */
/*---------------------------------------------------------------------------*/

/* ICBcfg Boot Configuration Data*/

icbcfg_data_type icbcfg_boot_data[] = 
{
    /* Add configuration data using
      ICBCFG_HWIO_*() or
      ICBCFG_RAW_*() macros below
      .
      .                          
      .                          */
      ICBCFG_DEFAULT()
};

icbcfg_prop_type icbcfg_boot_prop = 
{
    /* Length of the config  data array */
    sizeof(icbcfg_boot_data)/sizeof(icbcfg_data_type), 
    /* Pointer to config data array */ 
    icbcfg_boot_data                                    
};

/* DDR map information. */
uint32 map_ddr_region_count = 1; 
icbcfg_mem_region_type map_ddr_regions[1] =
{
  { 0x10000000ULL, 0x100000000ULL },
};

uint32 channel_map[1] = { SLAVE_DDR_CH0 };

HAL_bimc_InfoType bimc_hal_info =
{
  (uint8_t *)BIMC_BASE, /* Base address */
  19200,                /* QoS frequency */
};

/* Make sure the config region is always prohibited when "resetting" */
HAL_bimc_SlaveSegmentType safe_reset_seg =
{
  true,
  0x00000000ULL,                 /* start of config region */
  0x10000000ULL,                 /* 256 MB */
  BIMC_SEGMENT_TYPE_SUBTRACTIVE,
  BIMC_INTERLEAVE_NONE,
};

/*---------------------------------------------------------------------------*/
/*          Properties data for new Device IDs: Add below                    */
/*---------------------------------------------------------------------------*/
