#ifndef DS_3GPP_OP_PCO_HDLR_H
#define DS_3GPP_OP_PCO_HDLR_H
/*===========================================================================  
            E P S   S P E C I F I C   M O D E   H A N D L E R

===========================================================================*/
/*!
  @file
  ds_3gpp_op_pco_hdlr.h

  @brief

  @detail
  OPTIONAL detailed description of this C header file.
  - DELETE this section if unused.

*/        
/*==============================================================================

  Copyright (c) 2014 QUALCOMM Incorporated. All Rights Reserved

  Qualcomm Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  QUALCOMM Incorporated and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of QUALCOMM Incorporated.

==============================================================================*/
/*==============================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/datamodem/3gpp/ps/inc/ds_3gpp_op_pco_hdlr.h#1 $ 
 
when       who     what, where, why
--------   ---     -------------------------------------------------------------
12/20/13   vb      Header file to handle operator pco
==============================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include "datamodem_variation.h"
#include "comdef.h"
#include "queue.h"
#include "ds_3gpp_pdn_context.h"
#include "ps_iface.h"

/*===========================================================================

                   EXTERNAL DEFINITIONS AND TYPES

=============================================================================*/

/*----------------------------------------------------------------------------
  Function pointer type to be called by the MH to retrieve contents of
  modified operator pco from ATP client
-----------------------------------------------------------------------------*/
typedef boolean (*ds_3gpp_get_op_pco_f_ptr_type)
(
  char                                   *apn_name,
  ps_iface_op_reserved_pco_type          *op_pco_ptr
);

/*----------------------------------------------------------------------------
  Structure to determine if the function ptr needs to be queried to get the
  op_pco contents
-----------------------------------------------------------------------------*/
typedef struct
{
  char                              *apn_name;
  ds_3gpp_get_op_pco_f_ptr_type      get_op_pco_f_ptr;
}ds_3gpp_op_pco_holder_type;

/*----------------------------------------------------------------------------- 
  OP PCO BLOCK to be inserted into the queue
  ----------------------------------------------------------------------------*/
typedef struct  
{
  q_link_type                   link; 
  ds_3gpp_op_pco_holder_type   *op_pco_holder_ptr; 
}ds_3gpp_op_pco_q_block;

/*----------------------------------------------------------------------------- 
  OP_RESERVED_PCO_EVENTs 
-----------------------------------------------------------------------------*/
typedef enum
{
  DS_3GPP_ADD_OP_PCO_EV = 0x00,
  DS_3GPP_DEL_OP_PCO_EV = 0x01,
  DS_3GPP_MAX_OP_PCO_EV = 0xFF
}ds_3gpp_op_pco_ev_enum_type;


/*=============================================================================
FUNCTION DS_3GPP_OP_PCO_INIT

DESCRIPTION
  This function initializes the op_pco queue 

PARAMETERS
  None.

DEPENDENCIES
  None.

RETURN VALUE
  void

SIDE EFFECTS
  None.

=============================================================================*/
void ds_3gpp_op_pco_init( void );

/*=============================================================================
FUNCTION DS_3GPP_OP_PCO_MOD_IND

DESCRIPTION
  This api is called by the client to indicate the reception of a OP_PCO_EV
  It is the client's responsibility to populate memory apn and
  get_op_pco_f_ptr.

PARAMETERS
  ds_3gpp_op_pco_ev_enum_type           op_modified_ev_name,
  char                                 *apn,
  ds_3gpp_get_op_pco_f_ptr_type        *get_op_pco_f_ptr

DEPENDENCIES
  None.

RETURN VALUE
  TRUE  --  PCO MOD is successful
  FALSE --  Otherwise

SIDE EFFECTS
  None.

=============================================================================*/

boolean ds_3gpp_op_pco_mod_ind
(
  ds_3gpp_op_pco_ev_enum_type           op_modified_ev_name,
  char                                 *apn,
  ds_3gpp_get_op_pco_f_ptr_type         get_op_pco_f_ptr
);

/*=============================================================================
FUNCTION DS_3GPP_OP_PCO_HOLDER_ADD_ENTRY 
 
DESCRIPTION
  This is used to add the apn, f_ptr entry in the op_pco_holder

PARAMETERS
  char                                 *apn,
  ds_3gpp_get_op_pco_f_ptr_type        *get_op_pco_f_ptr
 
DEPENDENCIES
  None.

RETURN VALUE
  TRUE -- PCO ADDITION IS SUCCESSFUL
  FALSE-- Otherwise

SIDE EFFECTS
  None.

=============================================================================*/
boolean ds_3gpp_op_pco_holder_add_entry
(
  char                                 *apn,
  ds_3gpp_get_op_pco_f_ptr_type         get_op_pco_f_ptr
);

/*=============================================================================
FUNCTION DS_3GPP_OP_PCO_HOLDER_SEARCH_ENTRY 
 
DESCRIPTION
  This is used to search if the searched apn string is present in the
  op_pco_holder

PARAMETERS
  Item_Ptr   -- Queue Blob
  Target_Val -- Input to be searched
 
DEPENDENCIES
  None.

RETURN VALUE
  1  -- Search is successful
  0  -- Search is not successful

SIDE EFFECTS
  None.

=============================================================================*/
int ds_3gpp_op_pco_holder_search_entry
(
  void *item_ptr, 
  void *target_val
);

/*=============================================================================
FUNCTION DS_3GPP_OP_PCO_HOLDER_DEL_ENTRY 
 
DESCRIPTION
  This is used to delete the apn, f_ptr entry in the op_pco_holder

PARAMETERS
  apn string

DEPENDENCIES
  None.

RETURN VALUE
  TRUE  -- Deletion is successful
  FALSE -- Otherwise

SIDE EFFECTS
  None.

=============================================================================*/
boolean ds_3gpp_op_pco_holder_del_entry
(
  char  *apn
);

/*=============================================================================
FUNCTION DS_3GPP_OP_PCO_HOLDER_SEARCH_APN_ENTRY 
 
DESCRIPTION
  This is used to search if the searched apn string is present in the
  op_pco_holder

PARAMETERS
  pdn_context_ptr 
 
DEPENDENCIES
  None.

RETURN VALUE
  op_pco_q_blk_ptr *

SIDE EFFECTS
  None.

=============================================================================*/
void *ds_3gpp_op_pco_holder_search_apn_entry
(
  ds_pdn_context_s *pdn_cntxt_ptr
);


#ifdef TEST_FRAMEWORK
#error code not present
#endif /*TEST_FRAMEWORK*/
#endif
