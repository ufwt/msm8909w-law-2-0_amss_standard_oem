/*
==============================================================================

FILE:         HALclkSystemNOC.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   System NOC clocks.

   List of clock domains:
   -HAL_clk_mGCCSYSNOCBFDCDClkDomain


==============================================================================

                             Edit History

$Header: //components/rel/core.mpss/3.5.c12.3/systemdrivers/hal/clk/hw/msm8909/src/gcc/HALclkSystemNOC.c#1 $

when          who     what, where, why
----------    ---     --------------------------------------------------------
09/26/2013            Auto-generated.

==============================================================================
            Copyright (c) 2013 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


#include <HALhwio.h>

#include "HALclkInternal.h"
#include "HALclkTest.h"
#include "HALclkGeneric.h"
#include "HALclkHWIO.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Prototypes
** ==========================================================================*/


/* ============================================================================
**    Externs
** ==========================================================================*/

extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControl;


/* ============================================================================
**    Data
** ==========================================================================*/

                                    
/*                           
 *  HAL_clk_mSYSNOCBFDCDClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mSYSNOCBFDCDClkDomainClks[] =
{
#if 0
  {
    /* .szClockName      = */ "gcc_sys_noc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_AXI_CLK
  },
#endif
  {
    /* .szClockName      = */ "gcc_imem_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_IMEM_AXI_CBCR), HWIO_OFFS(GCC_IMEM_BCR), HAL_CLK_FMSK(PROC_CLK_BRANCH_ENA_VOTE, IMEM_AXI_CLK_ENA) },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_IMEM_AXI_CLK
  },
#if 0
  {
    /* .szClockName      = */ "gcc_mdp_tbu_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MDP_TBU_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MDP_TBU_CLK
  },
  {
    /* .szClockName      = */ "gcc_venus_tbu_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_VENUS_TBU_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_VENUS_TBU_CLK
  },
  {
    /* .szClockName      = */ "gcc_pronto_tbu_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_PRONTO_TBU_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_PRONTO_TBU_CLK
  },
  {
    /* .szClockName      = */ "gcc_mss_tbu_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MSS_TBU_AXI_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MSS_TBU_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_mss_tbu_gss_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MSS_TBU_GSS_AXI_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MSS_TBU_GSS_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_vfe_tbu_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_VFE_TBU_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_VFE_TBU_CLK
  },
  {
    /* .szClockName      = */ "gcc_smmu_cats_clk", /*Need to discuss*/
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SMMU_CATS_CBCR), HWIO_OFFS(GCC_SMMU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SMMU_CATS_CLK
  },
  {
    /* .szClockName      = */ "gcc_qdss_etr_usb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_QDSS_ETR_USB_CBCR), HWIO_OFFS(GCC_QDSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_QDSS_ETR_USB_CLK
  },
  {
    /* .szClockName      = */ "gcc_spdm_snoc_cy_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SPDM_SNOC_CY_CBCR), HWIO_OFFS(GCC_SPDM_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SPDM_SNOC_CY_CLK
  },
  {
    /* .szClockName      = */ "gcc_bimc_sysnoc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BIMC_SYSNOC_AXI_CBCR), HWIO_OFFS(GCC_BIMC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BIMC_SYSNOC_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_venus0_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_VENUS0_AXI_CBCR), HWIO_OFFS(GCC_VENUS0_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_VENUS0_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_mdss_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MDSS_AXI_CBCR), HWIO_OFFS(GCC_MDSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MDSS_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_camss_vfe_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_CAMSS_VFE_AXI_CBCR), HWIO_OFFS(GCC_CAMSS_VFE_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_CAMSS_VFE_AXI_CLK
  },
#endif
};


/*
 * HAL_clk_mGCCSYSNOCBFDCDClkDomain
 *
 * SYS NOCBFDCD clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCSYSNOCBFDCDClkDomain =
{
  /* .nCGRAddr             = */ 0, /* This is a shared resource -  Mux access removed */
  /* .pmClocks             = */ HAL_clk_mSYSNOCBFDCDClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mSYSNOCBFDCDClkDomainClks)/sizeof(HAL_clk_mSYSNOCBFDCDClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl,
  /* .pmNextClockDomain    = */ NULL
};


