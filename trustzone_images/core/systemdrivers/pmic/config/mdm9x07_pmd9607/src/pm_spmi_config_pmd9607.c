/*! \file
*  \n
*  \brief  pm_spmi_config_pma8916.c
*  \n
*  \n This file contains pmic configuration data specific for SPMI Controller's
      Peripheral for MSM8962 device..
*  \n
*  \n &copy; Copyright 2013 Qualcomm Technologies Incorporated, All Rights Reserved
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/systemdrivers/pmic/config/mdm9x07_pmd9607/src/pm_spmi_config_pmd9607.c#1 $

when       who    what, where, why
--------   ---    ----------------------------------------------------------
10/01/15   sv     PVC port configured to S1 rail.
08/18/15   ps     Added PMD9607 support for MDM9x07 (CR-892107)
08/22/14   akt    Support for MGPI for PA_ON on Bolt modem [TZ portion] (CR - 513341)
08/08/13   vtw    Created.
========================================================================== */

/*-------------------------------------------------------------------------
* Include Files
* ----------------------------------------------------------------------*/
//#include "PmicArbCfg.h"
#include "SpmiCfg.h"

/*-------------------------------------------------------------------------
* Preprocessor Definitions and Constants
* ----------------------------------------------------------------------*/

/* Converts a PVC port index to an overall PMIC Arbiter port index */
#define PVC_PORT_TO_PMIC_ARB_PORT(p) (p+1)

/*   Port assignment in MSM9x07(Lykan)    */
#define KRAIT_L2_PORT   2   /* Krait L2  */
#define MSS_SAW_PORT    3   /* MSS SAW   */

#define MSS_CPR_PORT    6   /* MSS CPR   */
#define OXILI_PORT      7   /* Oxili CPR */
#define TOP_CPR_PORT    4   /* Top CPR   */
#define MSS_MGPI_PORT   0   /* MGPI   */




/*
 * pm_periph_intr_owner
 *
 * A type to choose the interrupt owner for the peripheral.
 */
typedef enum {
  PM_APPS_HLOS_OWNER = 0,
  PM_APPS_TZ_OWNER,
  PM_MSS_OWNER,
  PM_LPASS_OWNER,
  PM_RPM_OWNER,
  PM_WCONNECT_OWNER
} pm_periph_intr_owner;

/*-------------------------------------------------------------------------
* Static Variable Definitions
* ----------------------------------------------------------------------*/

/*
 * pm_pvc_L2_addr
 *
 * PVC port addr for Krait.
 */
static SpmiCfg_Ppid pm_pvc_L2_addr[] =
{
  {0x1, 0x1441}, //{0x1, 0x1441}, /* PMIC PMD9607, Periph S1_CTRL, S1_CTRL_VOLTAGE_CTL2 */
  {0x0, 0x0100}, //{0x0, 0x0100}, /* PMIC PMD9607, Dummy write to REVID read-only register */ 
  {0x1, 0x1445}, //{0x1, 0x1445}, /* PMIC PMD9607, Periph S1_CTRL, S1_CTRL_MODE_CTL */
  {0x1, 0x1446}, //{0x1, 0x1446}, /* PMIC PMD9607, Periph S1_CTRL, S1_CTRL_EN_CTL */
};

/*
 * pm_pvc_mgpi_addr
 *
 * PVC port addr for MGPI.
 */
static SpmiCfg_Ppid pm_pvc_mgpi_addr[] =
{
  {0x0, 0x094A}, /* PMIC 9x07, TX_GTR_THRES_CTL */
};

const uint8 pm_arb_priorities[] =
{
    0,                                         /* SW port -- highest priority */
    PVC_PORT_TO_PMIC_ARB_PORT( MSS_MGPI_PORT ), /* port 3, next highest priority */
    PVC_PORT_TO_PMIC_ARB_PORT( KRAIT_L2_PORT ) /* port 4, next highest priority */
};

/* Number of pm arb priorities. */
const uint32 pm_num_prio = sizeof(pm_arb_priorities) / sizeof(uint8);

/*
 * pm_arb_pvc_cfg_9x07
 *
 * PMIC Arbiter PVC ports config.
 */
const SpmiCfg_PvcPortCfg pm_arb_pvc_cfg_9x07[] =
{
  {
    /* .pvcPortId           = */ KRAIT_L2_PORT,
    /* .priority = */ SPMI_ACCESS_PRIORITY_LOW,
    /* .ppids       = */ pm_pvc_L2_addr,
    /* .numPpids           = */ sizeof(pm_pvc_L2_addr)/sizeof(SpmiCfg_Ppid)
  },
  {
    /* .pvcPortId           = */ MSS_MGPI_PORT,
    /* .priority = */ SPMI_ACCESS_PRIORITY_LOW,
    /* .ppids       = */ pm_pvc_mgpi_addr,
    /* .numPpids           = */ sizeof(pm_pvc_mgpi_addr)/sizeof(SpmiCfg_Ppid)
  },
};

/* Number of pvc ports. */
const uint32 pm_num_pvc = sizeof(pm_arb_pvc_cfg_9x07) / sizeof(SpmiCfg_PvcPortCfg);



