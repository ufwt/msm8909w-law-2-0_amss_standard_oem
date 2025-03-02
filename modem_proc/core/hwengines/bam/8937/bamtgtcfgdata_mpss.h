/**
  @file bamtgtcfgdata_mpss.h
  @brief
  This file contains configuration data for the BAM driver for the
  8937 mpss system.

*/
/*
===============================================================================

                             Edit History

 $Header: //components/rel/core.mpss/3.5.c12.3/hwengines/bam/8937/bamtgtcfgdata_mpss.h#1 $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
07/20/15   PR      Branched from 8909 and updated for 8937.

===============================================================================
                   Copyright (c) 2013-2015 QUALCOMM Technologies Incorporated.
                          All Rights Reserved.
                        Qualcomm Confidential and Proprietary.
===============================================================================
*/

/** Configs supported for
    CE_M
    A2
    BLSP1
    BLSP2
    BAM_TGT_CFG_LAST
 */

#define BAM_CNFG_BITS_VAL 0xFFFFF004

const bam_target_config_type  bam_tgt_config[] = {
        {                     // CE_M_BAM
         /* .bam_pa     */    0x041C4000,
         /* .options    */    0x0,
         /* .cfg_bits   */    BAM_CNFG_BITS_VAL,
         /* .ee         */    0,
         /* .sec_config */    NULL
    },
    { // A2_BAM
         /* .bam_pa     */    0x04044000,
         /* .options    */    BAM_TGT_CFG_SW_DEBUG_INIT,
         /* .cfg_bits   */    BAM_CNFG_BITS_VAL,
         /* .ee         */    0,
         /* .sec_config */    NULL
    },
    { // BLSP1_BAM
         /* .bam_pa     */    0x07884000,
         /* .options    */    BAM_TGT_CFG_SHARABLE,
         /* .cfg_bits   */    BAM_CNFG_BITS_VAL,
         /* .ee         */    2,
         /* .sec_config */    NULL
    },
    { // BLSP2_BAM
         /* .bam_pa     */    0x07AC4000,
         /* .options    */    BAM_TGT_CFG_SHARABLE,
         /* .cfg_bits   */    BAM_CNFG_BITS_VAL,
         /* .ee         */    2,
         /* .sec_config */    NULL
    },
        {                     //LAST
         /* .bam_pa     */    BAM_TGT_CFG_LAST,
         /* .options    */    0,
         /* .cfg_bits   */    0,
         /* .ee         */    0,
         /* .sec_config */    NULL
    },
};

