/*=============================================================================
           			 SYSDBG  	T A R G E T		S E Q U E N C E 

GENERAL DESCRIPTION     
		  The file defines the pass sequence to be followed by the debug image
		  for a particular target. 
  
	Copyright 2012- 2014 by Qualcomm Technologies, Inc.  All Rights Reserved.
=============================================================================*/

/*=============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who          what, where, why
--------   ---          --------------------------------------------------
07/15/13    AJCheriyan  Sequence changes for PMIC Watchdog 
07/28/13    AJCheriyan  Updated for APQ8084
02/19/12	AJCheriyan	First cut for Aragorn. First ever SYSDBG

===========================================================================*/


/* ===========================================================================
 *							H E A D E R		F I L E S 	
 * =========================================================================*/

#include "sysdbg_def.h"
#include "sysdbg_target.h"
#include "sysdbg_mem_dump.h"
#include "sysdbg_spmi.h"
#include "sysdbg_pmic.h"
/* ========================================================================
===========================================================================*/


/* ===========================================================================
 *					E X T E R N A L 		F U N C T I O N S 
 * Note: Ideally empty except for functions within the debug image main control code
 * as it has to work closely with the data in this file. 	
 * =========================================================================*/

/* ========================================================================
===========================================================================*/




/* Pointer to the pass data structure */
const sysdbg_pass_data_type * const sysdbg_pass;

/* The pass data structure itself. For any particular group of init / work / exit functions, 
 * the first NULL entry will result in skipping the rest of the init sequence. So populate the
 * structure starting at the top and entries empty only after that */
const sysdbg_pass_data_type sysdbg_pass_data[] =
{
	[0] = 
		{
			.pass_sequence = 
			{
				.fcn_info =
				{
					{
						{ TRUE, FALSE, FALSE, FALSE },
						sysdbg_enable,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						// PMIC Regulator configuration has been removed,this is only used for regulator mapping for SPMi reads
						sysdbg_pmic_init,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						sysdbgMemoryReset,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL, 
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL, 
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						NULL,
					},
				},
			},
		},
	[1] =
		{
			.pass_sequence = 
			{
				.fcn_info =
				{
					{
                        { TRUE, FALSE, FALSE, FALSE },
                        sysdbg_update_core_info,
                    },
					{
						{ TRUE, FALSE, FALSE, FALSE },
						spmi_init,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						sysdbg_dump_stats_init,
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						 sysdbg_enable_pmic_wdog,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						sysdbgFlushCache,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						sysdbgMemoryDumpInit,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						sysdbgCPUDumpCopy, 
					},
					{
						{ TRUE, FALSE, FALSE, FALSE },
						sysdbgDumpTrace,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						sysdbgDumpETM,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						sysdbg_reset_next_core,
					},
         		    {
						{ TRUE, TRUE, TRUE, TRUE },
						sysdbg_exit,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						NULL,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						NULL,
					},
					{
						{ TRUE, TRUE, TRUE, TRUE },
						NULL,
					},
				},
			},
		},
};
