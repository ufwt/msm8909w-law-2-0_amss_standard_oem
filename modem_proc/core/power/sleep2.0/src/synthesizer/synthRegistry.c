/*==============================================================================
  FILE:         synthRegistry.c

  OVERVIEW:     Implementation of Sleep Registry which will keep track of all
                registered LPRs and their (enabled) modes.

  DEPENDENCIES: None

                Copyright (c) 2013-2014 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.mpss/3.5.c12.3/power/sleep2.0/src/synthesizer/synthRegistry.c#1 $
$DateTime: 2016/12/13 07:59:23 $
==============================================================================*/
#include "DALStdDef.h"
#include "sleepi.h"
#include "synthRegistry.h"
#include "synthLPRM.h"
#include "synthLPR.h"
#include "CoreVerify.h"
#include "sleep_lpri.h"
#include "sleep_config.h"
#include "npa.h"
#include "sleepActive.h"

/*==============================================================================
                              GLOBAL VARIABLES
 =============================================================================*/
/**
 * @brief g_LPRRegistry
 *
 * Registry for sleep system where low power resources (and their modes) are
 * registered.
 */
static synthRegistry      g_LPRRegistry;

/*============================================================================== 
                              FUNCTION DEFINITION
 =============================================================================*/
/*
 * synthRegistry_getRegistry
 */
synthRegistry* synthRegistry_getRegistry(void)
{
  return(&g_LPRRegistry);
}

/*
 * synthRegistry_init
 */
void synthRegistry_init(void)
{
  uint32 nCore;

  for(nCore = 0; nCore < SLEEP_NUM_CORES; nCore++)
  {
    g_LPRRegistry.synthLPRs[nCore] = NULL;
  }

  /* Trigger Active Time Solver Thread */
  sleepActive_SetSignal( SLEEP_SIGNAL_REGISTRY );

  return;
}

/*
 * synthRegistry_readGlobalConfig
 */
void synthRegistry_readGlobalConfig(sleep_lpr *sleepLPR)
{
  uint8   disable = FALSE;
  uint32  i;
  
  CORE_LOG_VERIFY_PTR(sleepLPR, sleepLog_printf(SLEEP_LOG_LEVEL_ERROR, 
                      0, "ERROR (message: \"NULL Lpr\")"));

  /* Check to see if this LPR has been disabled in the global
   * config settings. */
  sleepConfig_readBool( 0, 
                        (char *)sleepLPR->resource_name, 
                        NULL,
                        (char *)"disable", 
                        &disable );

  if( TRUE == disable )
  {
    sleepLog_printf( SLEEP_LOG_LEVEL_WARNING, 1, 
                      "WARNING (message: \"Disabled in the global config\")"
                      " (LPR Name: \"%s\")", sleepLPR->resource_name );
  }
  
  /* Loop through the modes that are being registered here */
  for( i = 0; i < sleepLPR->mode_count; i++ )
  {
    sleep_lprm *sleepLPRM = &(sleepLPR->modes[i]);

    /* Check to see if this mode has been disabled in the global
     * config settings.  If the entire LPR is disabled, no need to read
     * each individual LPRM. */
    if( TRUE == disable )
    {
      sleepLPRM->global_config_disabled = TRUE;
    }
    else
    {
      sleepConfig_readBool( 0, 
                            (char *)sleepLPR->resource_name, 
                            (char *)sleepLPRM->mode_name, 
                            (char *)"disable",
                            &(sleepLPRM->global_config_disabled) );

      if( TRUE == sleepLPRM->global_config_disabled )
      {
        sleepLog_printf( SLEEP_LOG_LEVEL_WARNING, 2, 
                          "WARNING (message: \"Disabled in the global config\")"
                          " (LPRM Name: \"%s.%s\")",
                          sleepLPR->resource_name, sleepLPRM->mode_name );
      }
    }
  }

  return;
}

/*
 * synthRegistry_registerSleepLPR
 */
void synthRegistry_registerSleepLPR(sleep_lpr *sleepLPR)
{
  uint32      i;
  sleep_lprm  *sleepLPRM;
  
  CORE_LOG_VERIFY_PTR(sleepLPR, sleepLog_printf(SLEEP_LOG_LEVEL_ERROR,
                      0, "ERROR (message: \"NULL Lpr\")"));

  sleepLog_printf(SLEEP_LOG_LEVEL_DEBUG, 2,
                   "Registering LPR (Name: \"%s\") (Shared Cores Mask: 0x%08x)",
                   sleepLPR->resource_name, sleepLPR->sharing_cores);

  /* Loop through the modes that are being registered here */
  for( i = 0; i < sleepLPR->mode_count; i++ )
  {
    sleepLPRM = &(sleepLPR->modes[i]);
    synthLPRM_validate(sleepLPRM);
  }

  return;
}

/*
 * synthRegistry_registerSynthLPR
 */
void synthRegistry_registerSynthLPR(sleep_synth_lpr *synthLPR)
{
  CORE_LOG_VERIFY_PTR(synthLPR, sleepLog_printf(SLEEP_LOG_LEVEL_ERROR, 0,
                           "ERROR (message: \"NULL Pre-Synthesized Lpr\")"));

  sleepLog_printf(SLEEP_LOG_LEVEL_DEBUG, 1,
                   "Registering pre-synthesized LPR (Name: \"%s\")",
                   synthLPR->resource_name);

  /* init synthesized LPR */
  synthLPR_init(synthLPR);

  /* Make sure there is not already a registered synthesized LPR for this
   * core.  Only one is supported per core. */
  CORE_VERIFY(synthLPR->core_num < SLEEP_NUM_CORES);
  CORE_VERIFY(NULL == g_LPRRegistry.synthLPRs[synthLPR->core_num]);
  g_LPRRegistry.synthLPRs[synthLPR->core_num] = synthLPR;

  return;
}

/*
 * synthRegistry_LPRUpdated
 */
void synthRegistry_LPRUpdated(sleep_synth_lpr *synthLPR)
{
  /* A Synth Mode was Enabled or Disabled. Trigger the Run-time Solver */
  sleepActive_SetSignal( SLEEP_SIGNAL_REGISTRY );

  return;
}

/*
 * synthRegistry_getSynthLPRList
 */
sleep_synth_lpr* synthRegistry_getSynthLPRList(int32 coreID)
{
  uint32 core_num = coreID == -1 ? CORE_CURR_CORE : coreID;

  CORE_VERIFY(core_num < SLEEP_NUM_CORES);
  return g_LPRRegistry.synthLPRs[core_num];
}
