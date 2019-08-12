/*=============================================================================

    __ds_epc_pdn_ho_sub_sm.h

Description:
  This file contains the machine generated header file for the state machine
  specified in the file:
  ds_epc_pdn_ho_sub_sm.stm

=============================================================================*/

/*===========================================================================

  Copyright (c) 2017 Qualcomm Technologies Incorporated.
  All Rights Reserved
  Qualcomm Confidential and Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.

===========================================================================*/


#ifndef __DS_EPC_PDN_HO_SUB_SM_H
#define __DS_EPC_PDN_HO_SUB_SM_H

#ifdef __cplusplus
/* If compiled into a C++ file, ensure symbols names are not mangled */
extern "C"
{
#endif

/* Include STM framework header */
#include <stm2.h>

/* Begin machine generated code for state machine array: epc_pdn_ho_sub_sm[] */

/* Define a macro for the number of SM instances */
#define epc_pdn_ho_sub_sm_NUM_INSTANCES 16

/* External reference to state machine structure */
extern stm_state_machine_t epc_pdn_ho_sub_sm[ epc_pdn_ho_sub_sm_NUM_INSTANCES ];

/* External enumeration representing state machine's states */
enum
{
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_IDLE,
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_HO_STARTED,
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_HO_TRAT_GOING_DOWN,
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_PREREG_STARTED,
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_PREREG_COMPLETED,
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_PREREG_HO_WAITING_RSP,
  epc_pdn_ho_sub_sm__EPC_PDN_HO_STATE_SRAT_DOWN,
};

#ifndef STM_DATA_STRUCTURES_ONLY
/* User called 'reset' routine.  Should never be needed, but can be used to
   effect a complete reset of all a given state machine's instances. */
extern void epc_pdn_ho_sub_sm_reset(void);
#endif /* !STM_DATA_STRUCTURES_ONLY */

/* End machine generated code for state machine array: epc_pdn_ho_sub_sm[] */


#ifdef __cplusplus
} /* extern "C" {...} */
#endif

#endif /* __DS_EPC_PDN_HO_SUB_SM_H */