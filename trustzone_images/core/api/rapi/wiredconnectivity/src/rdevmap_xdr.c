/* RDEVMAP TOOL VERSION: 4.35 */
/*=============================================================================
                           R D E V M A P _ X D R . C

GENERAL DESCRIPTION
  This is an AUTO GENERATED file that provides xdr encode/decode routines
  specific to the data types used in the exported rdevmap API.

  ---------------------------------------------------------------------------
  Copyright (c) 2009 Qualcomm Technologies Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------
=============================================================================*/

/*=============================================================================

                              Edit History

                             AUTO GENERATED                                  */

/* Generated by following versions of Htorpc modules:
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/htorpc.pl#6 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/Start.pm#2 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/Htoxdr.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/XDR.pm#2 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/Output.pm#5 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/Parser.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/Metacomments.pm#3 
Id: //source/qcom/qct/core/mproc/tools/rel/04.07/htorpc/lib/Htorpc/SymbolTable.pm#2   

rdevmap Definition File(s):
Id: //source/qcom/qct/core/api/wiredconnectivity/rel/2h09/rdevmap.h#6
=============================================================================*/
/*=============================================================================
$Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/wiredconnectivity/src/rdevmap_xdr.c#1 $ 
=============================================================================*/


/* Include files */
#include "oncrpc.h"
#include "rdevmap.h"
#include "rdevmap_rpc.h"


/*=======================================================================
                  XDR send/recv routines for API types
=======================================================================*/


/*
 * rdm_service_display_type XDR_RDEVMAP_SEND
 */
boolean xdr_rdevmap_send_rdm_service_display_type (xdr_s_type *xdrs, rdm_service_display_type const *sptr)
{
  if ( ! XDR_SEND_ENUM( xdrs, &(sptr->device) ) ) {
    return (FALSE);
  }

  if ( ! XDR_SEND_BOOLEAN( xdrs, &(sptr->display) ) ) {
    return (FALSE);
  }

  if ( ! XDR_SEND_BOOLEAN( xdrs, &(sptr->current) ) ) {
    return (FALSE);
  }

  return (TRUE);
} /* xdr_rdevmap_send_rdm_service_display_type */

/*
 * rdm_service_display_type XDR_RDEVMAP_RECV
 */
boolean xdr_rdevmap_recv_rdm_service_display_type (xdr_s_type *xdrs, rdm_service_display_type *sptr)
{
  if ( ! XDR_RECV_ENUM( xdrs, &(sptr->device) ) ) {
    return (FALSE);
  }

  if ( ! XDR_RECV_BOOLEAN( xdrs, &(sptr->display) ) ) {
    return (FALSE);
  }

  if ( ! XDR_RECV_BOOLEAN( xdrs, &(sptr->current) ) ) {
    return (FALSE);
  }

  return (TRUE);
} /* xdr_rdevmap_recv_rdm_service_display_type */



