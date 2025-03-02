/*
==============================================================================

FILE:         HALclkQPIC.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   QPIC clocks.

   List of clock domains:
   -HAL_clk_mGCCQPICClkDomain


==============================================================================

                             Edit History

$Header: //components/rel/rpm.bf/2.1.1/core/systemdrivers/hal/clk/hw/msm8909/src/GCC/HALclkQPIC.c#1 $

when          who     what, where, why
----------    ---     --------------------------------------------------------
08/21/2014            Auto-generated.

==============================================================================
            Copyright (c) 2014 QUALCOMM Technologies Incorporated.
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
 *  HAL_clk_mQPICClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mQPICClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_qpic_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_QPIC_CBCR), HWIO_OFFS(GCC_QPIC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_QPIC_CLK
  },
};


/*
 * HAL_clk_mGCCQPICClkDomain
 *
 * QPIC clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCQPICClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_QPIC_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mQPICClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mQPICClkDomainClks)/sizeof(HAL_clk_mQPICClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl,
  /* .pmNextClockDomain    = */ NULL
};


