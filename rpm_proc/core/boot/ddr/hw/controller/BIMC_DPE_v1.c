/*
 ===========================================================================

 FILE:         BIMC_DPE_v1.c

 DESCRIPTION:
 This is the platform hardware abstraction layer implementation for
 BIMC DPE.

 Copyright 2012 by Qualcomm Technologies, Inc.  All Rights Reserved.
 ===========================================================================

 Edit History

 $Header: //components/rel/rpm.bf/2.1.1/core/boot/ddr/hw/controller/BIMC_DPE_v1.c#1 $

 when       who     what, where, why
 --------   ---     --------------------------------------------------------
 03/01/13   tw      Adjusted high frequency workaround
 03/01/13   tw      Added workaround for additional delay at high frequency
 10/31/12   sl      Changed pad power mode switch logic.
 10/26/12   tw      Re-enabled hw based self refresh
 09/21/12   sl      Combined LPDDR device parameters.
 09/17/12   sl      Updated DPE clock switch functions.
 09/12/12   tw      Disable HW based self refresh.
 09/06/12   sl      Updated HAL_SDRAM_DPE_Update_AC_Parameters().
 08/30/12   sl      Load DPE configuration at the end of DPE initialization.
 08/24/12   sl      Updated DPE functions.
 08/07/12   tw      Modified dpe configuration to support one time settings
 08/06/12   tw      reimplemented time based units, removed hard coded config
                    values, use one time settings instead.
 07/12/12   tw      Revert back to legacy cycle based timing
 02/02/12   tw      Initial revision
 ===========================================================================
 */


/*==============================================================================
                                  INCLUDES
==============================================================================*/
#include "ddr_params.h"
#include "ddr_target.h"
#include "ddr_log.h"
#include "HAL_DDR.h"
#include "BIMC.h"
#include "DDR_PHY.h"
#include "Clock.h"


/*==============================================================================
                                  FUNCTIONS
==============================================================================*/
extern boolean ddr_init_done;

/*==============================================================================
                                  FUNCTIONS
==============================================================================*/
/* =============================================================================
**  Function : HAL_SDRAM_DPE_Init
** =============================================================================
*/
/**
*   @brief
*   Initialize BIMC DPE.
*
*   @param[in]  interface  Interface to initialize for
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_DPE_Init(SDRAM_INTERFACE interface)
{
  uint32 offset;
  struct ddr_device_params_common *ddr_params;
  uint32 width;

  /* Channel offset */
  offset = (interface == SDRAM_INTERFACE_0) ? SDRAM_0_OFFSET : SDRAM_1_OFFSET;

  /* Get DDR device parameters */
  ddr_params = &(ddr_get_params(interface)->common);

  /*
    DPE_CONFIG_0[DEVICE_CFG_RANK0/1]

    Device Configuration for Rank 0/1. This is required for SRR in order to
    update the refresh rate correctly if multiple devices are involved.
    0x0: x8_x8_x8_x8
    0x1: x16_x16
    0x2: x32
  */
  switch (ddr_params->interface_width)
  {
    case 32:
    default:
      width = 2;
      break;

    case 16:
      width = 1;
      break;

    case 8:
      width = 0;
      break;
  }

  BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_0), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_0), DEVICE_CFG_RANK0) |
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_0), DEVICE_CFG_RANK1),
                 width << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_0), DEVICE_CFG_RANK0) |
                 width << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_0), DEVICE_CFG_RANK1));

  /*
    DPE_CONFIG_1[NUM_BANKS_RANK0/1]

    Number of banks for Rank 0/1.
  */
  BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_1), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_1), NUM_BANKS_RANK0) |
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_1), NUM_BANKS_RANK1),
                 ddr_params->num_banks_cs0 << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_1), NUM_BANKS_RANK0) |
                 ddr_params->num_banks_cs1 << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_1), NUM_BANKS_RANK1));

  /* Load DPE configuration from shadow to actual */
  BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));

} /* HAL_SDRAM_DPE_Init */

/* =============================================================================
**  Function : HAL_SDRAM_DPE_Update_AC_Parameters
** =============================================================================
*/
/**
*   @brief
*   Configure DPE timing.
*
*   @param[in]  interface  Interface to configure for
*   @param[in]  clk_speed  Clock speed (in KHz)
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void HAL_SDRAM_DPE_Update_AC_Parameters(SDRAM_INTERFACE interface, uint32 clk_speed)
{
  uint32 offset;
  union ddr_device_params *ddr_params;
  uint32 timing_values[18] = {0}, timing_fmsks[18] = {0};
  uint32 reg;

  /* Channel offset */
  offset = (interface == SDRAM_INTERFACE_0) ? SDRAM_0_OFFSET : SDRAM_1_OFFSET;

  /* Get DDR device parameters */
  ddr_params = ddr_get_params(interface);

  if (ddr_params->common.device_type == DDR_TYPE_LPDDR2 ||
      ddr_params->common.device_type == DDR_TYPE_LPDDR3)
  {
    /* DPE_TIMER_2[TMRW/TMRR] */
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_TIMER_2), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_TIMER_2), TMRW) |
                   HWIO_FMSK(DDR_ADDR(DPE_TIMER_2), TMRR),
                   ddr_params->lpddr.tMRW << HWIO_SHFT(DDR_ADDR(DPE_TIMER_2), TMRW) |
                   ddr_params->lpddr.tMRR << HWIO_SHFT(DDR_ADDR(DPE_TIMER_2), TMRR));

    /* DPE_DRAM_TIMING_0 */
    timing_values[0] = ddr_params->lpddr.tRAS_Min
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_0), TRASMIN);

    timing_fmsks[0] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_0), TRASMIN);

    /* DPE_DRAM_TIMING_1 */
    timing_values[1] = ddr_params->lpddr.tWR
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_1), TWR) |
                       ddr_params->lpddr.tRCD
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_1), TRCD);

    timing_fmsks[1] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_1), TWR) |
                      HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_1), TRCD);

    /* DPE_DRAM_TIMING_2 */
    timing_values[2] = ddr_params->lpddr.tWTR
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_2), TWTR) |
                       ddr_params->lpddr.tRRD
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_2), TRRD);

    timing_fmsks[2] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_2), TWTR) |
                      HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_2), TRRD);

    /* DPE_DRAM_TIMING_3 */
    timing_values[3] = ddr_params->lpddr.tRFC
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_3), TRFCAB);

    timing_fmsks[3] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_3), TRFCAB);

    /* DPE_DRAM_TIMING_4 */
    timing_values[4] = ddr_params->lpddr.tRTP
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_4), TRTP);

    timing_fmsks[4] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_4), TRTP);

    /* DPE_DRAM_TIMING_5 */
    timing_values[5] = ddr_params->lpddr.tRP_AB
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_5), TRPAB) |
                       ddr_params->lpddr.tRP_PB
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_5), TRPPB);

    timing_fmsks[5] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_5), TRPAB) |
                      HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_5), TRPPB);

    /* DPE_DRAM_TIMING_6 */
    timing_values[6] = ddr_params->lpddr.tFAW
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_6), TFAW) |
                       ddr_params->lpddr.tCKE
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_6), TCKE);

    timing_fmsks[6] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_6), TFAW) |
                      HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_6), TCKE);

    /* DPE_DRAM_TIMING_7 */
    timing_values[7] = ddr_params->lpddr.tZQCS
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_7), TZQCS);

    timing_fmsks[7] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_7), TZQCS);

    /* DPE_DRAM_TIMING_9 */
    timing_values[9] = ddr_params->lpddr.tCKESR
                       << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_9), MIN_SR_DURATION);

    timing_fmsks[9] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_9), MIN_SR_DURATION);

    /* DPE_DRAM_TIMING_10 */
    timing_values[10] = ddr_params->lpddr.tXSR
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_10), TXSRD) |
                        ddr_params->lpddr.tXSR
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_10), TXSNR);

    timing_fmsks[10] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_10), TXSRD) |
                       HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_10), TXSNR);

    /* DPE_DRAM_TIMING_11 */
    timing_values[11] = ddr_params->lpddr.tXP
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_11), TXPNR_ACT_PWR_DN) |
                        ddr_params->lpddr.tXP
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_11), TXPR_ACT_PWR_DN);

    timing_fmsks[11] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_11), TXPNR_ACT_PWR_DN) |
                       HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_11), TXPR_ACT_PWR_DN);

    /* DPE_DRAM_TIMING_12 */
    timing_values[12] = ddr_params->lpddr.tXP
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_12), TXPNR_PCHG_PWR_DN) |
                        ddr_params->lpddr.tXP
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_12), TXPR_PCHG_PWR_DN);

    timing_fmsks[12] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_12), TXPNR_PCHG_PWR_DN) |
                       HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_12), TXPR_PCHG_PWR_DN);

    /* DPE_DRAM_TIMING_16 */
    timing_values[16] = HAL_SDRAM_RL((DDR_TYPE)ddr_params->common.device_type, clk_speed)
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_16), RD_LATENCY) |
                        HAL_SDRAM_WL((DDR_TYPE)ddr_params->common.device_type, clk_speed)
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_16), WR_LATENCY);

    timing_fmsks[16] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_16), RD_LATENCY) |
                       HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_16), WR_LATENCY);

    /* DPE_DRAM_TIMING_17 */
    timing_values[17] = ddr_params->lpddr.tZQCL
                        << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_17), TZQCL);

    timing_fmsks[17] = HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_17), TZQCL);
  }

  for (reg = 0; reg < sizeof(timing_values)/sizeof(timing_values[0]); reg++)
  {
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_DRAM_TIMING_0), offset + reg * 4,
                   timing_fmsks[reg], timing_values[reg]);
  }

  /* Compute timing parameters in cycles */
  BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), RECALC_PS_PARAMS),
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), RECALC_PS_PARAMS));
  /* Poll for computing done */
  while ( BOOT_HWIO_INM(DDR_ADDR(DPE_MEMC_STATUS_1), offset,
                        HWIO_FMSK(DDR_ADDR(DPE_MEMC_STATUS_1), CYC_CALC_VALID)) )
  {}

  /* Load timing registers */
  BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));

} /* HAL_SDRAM_DPE_Update_AC_Parameters */

/* ============================================================================
 **  Function : HAL_SDRAM_DPE_Disable_Power_Down
 ** ============================================================================
 */
/*!
 *   @brief
 *   This function will Disable Power down and clock stop power down
 *
 *   @details
 *   This function will Disable Power down and clock stop power down
 *
 *   @param interface_name   -  [IN] Param_description_goes_here
 *
 *   @par Dependencies
 *   None
 *
 *   @par Side Effects
 *   None
 *
 *   @retval  None
 *
 *   @sa None
 */
void HAL_SDRAM_DPE_Disable_Power_Down(SDRAM_INTERFACE interface_name)
{
  uint32 offset;

  /* Configure for correct offset */
  if (interface_name == SDRAM_INTERFACE_0)
  {
    offset = SDRAM_0_OFFSET;
  }
  else
  {
    offset = SDRAM_1_OFFSET;
  }

  /* Disable Powerdown/clockstop-powerdown */
  BOOT_HWIO_OUTM(
      DDR_ADDR(DPE_PWR_CTRL_0),
      offset,
      HWIO_FMSK(DDR_ADDR(DPE_PWR_CTRL_0), PWR_DN_EN) | HWIO_FMSK(DDR_ADDR(DPE_PWR_CTRL_0), CLK_STOP_PWR_DN_EN),
      0x0);
} /* HAL_SDRAM_DPE_Disable_Power_Down */

/* ============================================================================
**  Function : HAL_SDRAM_DPE_Update_Latency
** ============================================================================
*/
/*!
 *   @brief
 *   This function will update the read write latency based on the given
 *   clock speed
 *
 *   @details
 *   This function will update the read write latency based on the given
 *   clock speed
 *
 *   @param interface  -  [IN] interface to update latency for
 *   @param clk_speed  -  [IN] clock speed in khz
 *
 *   @par Dependencies
 *   None
 *
 *   @par Side Effects
 *   None
 *
 *   @retval  None
 *
 *   @sa None
 */
void HAL_SDRAM_DPE_Update_Latency(SDRAM_INTERFACE interface, uint32 clk_speed)
{
  uint32 offset;
  struct ddr_device_params_common *ddr_params;
  uint32 rl, wl, data;

  /* Channel offset */
  offset = (interface == SDRAM_INTERFACE_0) ? SDRAM_0_OFFSET : SDRAM_1_OFFSET;

  /* Get DDR device parameters */
  ddr_params = &(ddr_get_params(interface)->common);

  rl = HAL_SDRAM_RL((DDR_TYPE)ddr_params->device_type, clk_speed);
  wl = HAL_SDRAM_WL((DDR_TYPE)ddr_params->device_type, clk_speed);

  if (rl == 3 && wl == 1) { data = 0x1; }
  else if (rl == 4 && wl == 2) { data = 0x2; }
  else if (rl == 5 && wl == 2) { data = 0x3; }
  else if (rl == 6 && wl == 3) { data = 0x4; }
  else if (rl == 7 && wl == 4) { data = 0x5; }
  else if (rl == 8 && wl == 4) { data = 0x6; }
  else if (rl == 9 && wl == 5) { data = 0x7; }
  else if (rl == 10 && wl == 6) { data = 0x8; }
  else if (rl == 11 && wl == 6) { data = 0x9; }
  else if (rl == 12 && wl == 6) { data = 0xA; }  
  else { data = 0xC; }  /* Use RL=14/WL=8 in case all else fails */

  /* Write data to MRW_AFTER_FREQ_SWITCH to load latency after clock switch */
  BOOT_HWIO_OUTM(
      DDR_ADDR(DPE_MRW_AFTER_FREQ_SWITCH_0),
      offset,
      HWIO_FMSK(DDR_ADDR(DPE_MRW_AFTER_FREQ_SWITCH_0), W_DATA) |
      HWIO_FMSK(DDR_ADDR(DPE_MRW_AFTER_FREQ_SWITCH_0), W_ADDR) ,
      0x2 << HWIO_SHFT(DDR_ADDR(DPE_MRW_AFTER_FREQ_SWITCH_0), W_ADDR) |
      data << HWIO_SHFT(DDR_ADDR(DPE_MRW_AFTER_FREQ_SWITCH_0), W_DATA));

  /* Enable DPE_MRW_FREQ_SWITCH[AFTER_0].*/
  BOOT_HWIO_OUTM( DDR_ADDR(DPE_MRW_FREQ_SWITCH), offset,
      HWIO_FMSK(DDR_ADDR(DPE_MRW_FREQ_SWITCH), AFTER_0),
      0x1 << HWIO_SHFT(DDR_ADDR(DPE_MRW_FREQ_SWITCH), AFTER_0));

  /* Update Timing 16 for same READ and WRITE latency */
  BOOT_HWIO_OUTM(
      DDR_ADDR(DPE_DRAM_TIMING_16),
      offset,
      HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_16), RD_LATENCY) |
      HWIO_FMSK(DDR_ADDR(DPE_DRAM_TIMING_16), WR_LATENCY),
      rl << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_16), RD_LATENCY) |
      wl << HWIO_SHFT(DDR_ADDR(DPE_DRAM_TIMING_16), WR_LATENCY));
}

/* ============================================================================
**  Function : HAL_SDRAM_DPE_Pre_Clock_Switch
** ============================================================================
*/
/*!
 *   @brief
 *   This function update DPE configuration for preparing to clock switch
 *
 *   @details
 *   This function will update the read write latency based on the given
 *   clock speed and update DPE configuration for clock switch
 *
 *   @param interface  -  [IN] interface to update latency for
 *   @param old_clk    -  [IN] Old clock speed (in KHz)
 *   @param new_clk    -  [IN] New clock speed (in KHz)
 *
 *   @par Dependencies
 *   None
 *
 *   @par Side Effects
 *   None
 *
 *   @retval  None
 *
 *   @sa None
 */
void HAL_SDRAM_DPE_Pre_Clock_Switch(SDRAM_INTERFACE interface, uint32 old_clk, uint32 new_clk)
{
  uint32 offset;
  uint32 threshold;

  /* Channel offset */
  offset = (interface == SDRAM_INTERFACE_0) ? SDRAM_0_OFFSET : SDRAM_1_OFFSET;
  
  /* TODO: Remove this once non-legacy mode works */
  /* check for BIMC_MISC [BIMC_DDR_LEGACY_MODE_EN] for legacy mode enable */
  if(Clock_BIMCGetMiscInfo() & 0x400)
  {
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_6), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_WR_DEBUG_MODE) |
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_CA_DEBUG_MODE) |
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), CDC_WR_DEBUG_MODE) |
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), CDC_CA_DEBUG_MODE),
                   1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_WR_DEBUG_MODE) |
                   1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_CA_DEBUG_MODE) |
                   1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), CDC_WR_DEBUG_MODE) |
                   1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), CDC_CA_DEBUG_MODE));

    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                   0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));
  }
  /* Pad power mode switch (for Gen1 DDR PHY only): force to use self refresh
     mode for frequency switch if pad power mode is switched from low to high */
  if ( BOOT_HWIO_INM(DDR_ADDR(DPE_CONFIG_1), offset,
                     HWIO_FMSK(DDR_ADDR(DPE_CONFIG_1), PAD_POWER_MODE)) )
  {
    threshold = BOOT_HWIO_INM(DDR_ADDR(DPE_CONFIG_1), offset,
                              HWIO_FMSK(DDR_ADDR(DPE_CONFIG_1), PERIOD_BUS_THRESHOLD_POWER_MODE))
                >> HWIO_SHFT(DDR_ADDR(DPE_CONFIG_1), PERIOD_BUS_THRESHOLD_POWER_MODE);

    if ( (10000000/old_clk > threshold) && (10000000/new_clk <= threshold) )
    {
      BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_3), offset,
                     HWIO_FMSK(DDR_ADDR(DPE_CONFIG_3), HW_FREQ_SW_SR_ONLY) ,
                     0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_3), HW_FREQ_SW_SR_ONLY));

      BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                     HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                     0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));
    }
  }

#if 0
  if(new_clk > 800000)
  {
    /* apply additional delay for above 800mhz operation */
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_TIMER_0), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_TIMER_0), RTR_SAME_RANK_ADD_DLY) ,
                   0x3U << HWIO_SHFT(DDR_ADDR(DPE_TIMER_0), RTR_SAME_RANK_ADD_DLY));                     
  }
#endif

  /* Update RL/WL */
  HAL_SDRAM_DPE_Update_Latency(interface, new_clk);

} /* HAL_SDRAM_DPE_Pre_Clock_Switch */

/* ============================================================================
**  Function : HAL_SDRAM_DPE_Post_Clock_Switch
** ============================================================================
*/
/*!
 *   @brief
 *   This function update DPE configuration cleaning up after clock switch
 *
 *   @details
 *   This function will update the read write latency based on the given
 *   clock speed, and also prepare the DPE for clock switch operation
 *
 *   @param interface  -  [IN] interface to update latency for
 *   @param old_clk    -  [IN] Old clock speed (in KHz)
 *   @param new_clk    -  [IN] New clock speed (in KHz)
 *
 *   @par Dependencies
 *   None
 *
 *   @par Side Effects
 *   None
 *
 *   @retval  None
 *
 *   @sa None
 */
void HAL_SDRAM_DPE_Post_Clock_Switch(SDRAM_INTERFACE interface, uint32 old_clk, uint32 new_clk)
{
  uint32 offset;
  struct ddr_device_params_common *ddr_params;
  SDRAM_CHIPSELECT csel;

  /* Channel offset */
  offset = (interface == SDRAM_INTERFACE_0) ? SDRAM_0_OFFSET : SDRAM_1_OFFSET;

  /* Get DDR device parameters */
  ddr_params = &(ddr_get_params(interface)->common);

  /* TODO: Remove this once non-legacy mode works */
  /* check for BIMC_MISC [BIMC_DDR_LEGACY_MODE_EN] for legacy mode enable */
  if(Clock_BIMCGetMiscInfo() & 0x400)
  {
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_6), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_WR_DEBUG_MODE) |
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_CA_DEBUG_MODE) |
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), CDC_WR_DEBUG_MODE) |
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_6), CDC_CA_DEBUG_MODE),
                   0U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_WR_DEBUG_MODE) |
                   0U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), IOSTAGE_CA_DEBUG_MODE) |
                   0U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), CDC_WR_DEBUG_MODE) |
                   0U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_6), CDC_CA_DEBUG_MODE));

    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                   0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));
  }
  
  if ( BOOT_HWIO_INM(DDR_ADDR(DPE_CONFIG_1), offset,
                     HWIO_FMSK(DDR_ADDR(DPE_CONFIG_1), PAD_POWER_MODE)) )
  {
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_3), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_3), HW_FREQ_SW_SR_ONLY) ,
                   0x0U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_3), HW_FREQ_SW_SR_ONLY));

    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                   0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));
  }
  
  if(ddr_init_done)
  {
    /* Toggle CSPD enable\disable to fix QCTDD00317322
     * HW Frequency switch using clockstop-powerdown can
     * cause the internal CGC to be active
     */

    /* Disable CSPD */
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_PWR_CTRL_0), offset,
                   HWIO_FMSK(DDR_ADDR(DPE_PWR_CTRL_0), PWR_DN_EN) |
                   HWIO_FMSK(DDR_ADDR(DPE_PWR_CTRL_0), CLK_STOP_PWR_DN_EN),
                   0x0);

    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));

    /* Toggle HW self refresh entry/exit to fix QCTDD00255053 */
    /* QCTDD00255053 - Design does not re-enter idle self refresh after
     * HW Frequency switch if HW Freq switch occurs when both ranks are
     * in self refresh. */
    csel = SDRAM_CS_NONE;
    if (ddr_params->num_rows_cs0 != 0)
    {
      csel |= SDRAM_CS0;
    }
    if (ddr_params->num_rows_cs1 != 0)
    {
      csel |= SDRAM_CS1;
    }
    HAL_SDRAM_SHKE_Disable_HW_Self_Refresh(interface, csel);
    HAL_SDRAM_SHKE_Enable_HW_Self_Refresh(interface, csel);

    /* Re-enable CSPD */
    BOOT_HWIO_OUTM(DDR_ADDR(DPE_PWR_CTRL_0), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_PWR_CTRL_0), PWR_DN_EN) |
                 HWIO_FMSK(DDR_ADDR(DPE_PWR_CTRL_0), CLK_STOP_PWR_DN_EN),
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_PWR_CTRL_0), PWR_DN_EN) |
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_PWR_CTRL_0), CLK_STOP_PWR_DN_EN));

    BOOT_HWIO_OUTM(DDR_ADDR(DPE_CONFIG_4), offset,
                 HWIO_FMSK(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG),
                 0x1U << HWIO_SHFT(DDR_ADDR(DPE_CONFIG_4), LOAD_ALL_CONFIG));
  }
} /* HAL_SDRAM_DPE_Post_Clock_Switch */
