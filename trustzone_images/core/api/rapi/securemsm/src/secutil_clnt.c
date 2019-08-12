/* SECUTIL TOOL VERSION: 7 */
/*=============================================================================
                          S E C U T I L _ C L N T . C

GENERAL DESCRIPTION
  This is an AUTO GENERATED file that provides RPC client functionality for the
  secutil API.

  ---------------------------------------------------------------------------
  Copyright (c) 2008 Qualcomm Technologies Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------
=============================================================================*/

/*=============================================================================

                              Edit History

                             AUTO GENERATED                                  */
#ifdef FEATURE_HTORPC_METACOMMENTS
/* Generated by following versions of Htorpc modules:
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/htorpc.pl#6 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/Start.pm#10 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/Htoxdr.pm#6 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/XDR.pm#15 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/Output.pm#30 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/Parser.pm#10 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/Metacomments.pm#11 
Id: //depot/asic/msmshared/services/mproc/tools/main/htorpc/lib/Htorpc/SymbolTable.pm#5  */
#endif
/* $Id: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/securemsm/src/secutil_clnt.c#1 $
=============================================================================*/

#include "customer.h"
#include "target.h"

#ifdef FEATURE_ONCRPC
#ifdef FEATURE_EXPORT_SECUTIL
#define HTORPC_SECUTIL_GLUE

/* Include files */
#include "err.h"
#include "msg.h"
#include "oncrpc.h"

#include "secutil.h"
#include "secutil_rpc.h"

/* Only one copy needed per API */
static opaque_auth SecutilCred = { ONCRPC_AUTH_NONE, 0, 0 };
static opaque_auth SecutilVerf = { ONCRPC_AUTH_NONE, 0, 0 };


/*=======================================================================
             API RPC Clients Implementation
=======================================================================*/

boolean secutil_null(void)
{
  xdr_s_type       *clnt;
  rpc_reply_header  reply_header;
  boolean           xdr_status = TRUE;
  int               xdr_op_number = 0;

  clnt = rpc_clnt_lookup2(SECUTILPROG, SECUTILVERS, 0);

  if ( clnt == NULL ) {
    XDR_CLNT_LOOKUP2_ERR(SECUTILPROG, SECUTILVERS, 0);
    return FALSE;
  }

  oncrpcxdr_mem_free( clnt );

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  if ( ! xdr_call_msg_start( clnt,
                             SECUTILPROG, SECUTILVERS,
                             ONCRPC_SECUTIL_NULL_PROC, &SecutilCred, &SecutilVerf ) ) {
    XDR_OP_ERR( clnt, xdr_op_number );
    return FALSE;
  }

  /* Send the RPC message and block waiting for a reply */
  if ( ! XDR_MSG_SEND( clnt, &reply_header ) )
  {
    XDR_MSG_SEND_ERR( clnt, &reply_header );
    return FALSE;
  }
  /* XDR OP NUMBER = 1 */

  if ( reply_header.stat != RPC_MSG_ACCEPTED )
  {
    XDR_CALL_REJECTED_ERR( clnt, &reply_header );
    xdr_status = FALSE;
  }
  else if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS )
  {
    XDR_ERR_ON_SERVER_ERR( clnt, &reply_header );
    xdr_status = FALSE;
  }

  if ( xdr_status )
  {
    /* XDR OP NUMBER = 2 */
    xdr_op_number = 2;
  }

  if ( ! XDR_MSG_DONE( clnt ) || ! xdr_status )
  {
    XDR_OP_ERR( clnt, xdr_op_number );
    return FALSE;
  }
  else
  {
    return TRUE;
  }
} /* secutil_null */

boolean secutil_rpc_glue_code_info_remote
(
  uint32 *toolvers,
  uint32 *features,
  uint32 *proghash,
  uint32 *cbproghash
)
{
  xdr_s_type       *clnt;
  rpc_reply_header  reply_header;
  uint32            result;
  boolean           xdr_status = TRUE;
  int               xdr_op_number = 0;

  clnt = rpc_clnt_lookup2(SECUTILPROG, SECUTILVERS, 0);

  if ( clnt == NULL ) {
    XDR_CLNT_LOOKUP2_ERR(SECUTILPROG, SECUTILVERS, 0);
    return FALSE;
  }

  oncrpcxdr_mem_free( clnt );

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  if ( ! xdr_call_msg_start( clnt,
                             SECUTILPROG, SECUTILVERS,
                             ONCRPC_SECUTIL_RPC_GLUE_CODE_INFO_REMOTE_PROC, &SecutilCred, &SecutilVerf ) ) {
    XDR_OP_ERR( clnt, xdr_op_number );
    return FALSE;
  }

  /* Send the RPC message and block waiting for a reply */
  if ( ! XDR_MSG_SEND( clnt, &reply_header ) )
  {
    XDR_MSG_SEND_ERR( clnt, &reply_header );
    // return here without calling XDR_MSG_DONE
    return FALSE;
  }
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( reply_header.stat != RPC_MSG_ACCEPTED )
  {
    XDR_CALL_REJECTED_ERR( clnt, &reply_header );
    xdr_status = FALSE;
  }
  else if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS )
  {
    XDR_ERR_ON_SERVER_ERR( clnt, &reply_header );
    xdr_status = FALSE;
  }

  if ( xdr_status )
  {
    /* XDR OP NUMBER = 2 */
    xdr_op_number = 2;
    xdr_status = XDR_RECV_UINT32( clnt, &result );
  }

  if ( xdr_status )
  {
    if ( toolvers != NULL )
    {
      *toolvers = result;
    }
    /* XDR OP NUMBER = 3 */
    xdr_op_number = 3;
    xdr_status = XDR_RECV_UINT32( clnt, &result );
  }

  if ( xdr_status )
  {
    if ( features != NULL )
    {
      *features = result;
    }
    /* XDR OP NUMBER = 4 */
    xdr_op_number = 4;
    xdr_status = XDR_RECV_UINT32( clnt, &result );
  }

  if ( xdr_status )
  {
    if ( proghash != NULL )
    {
      *proghash = result;
    }
    /* XDR OP NUMBER = 5 */
    xdr_op_number = 5;
    xdr_status = XDR_RECV_UINT32( clnt, &result );
  }

  if ( xdr_status )
  {
    if ( cbproghash != NULL )
    {
      *cbproghash = result;
    }
    /* XDR OP NUMBER = 6 */
    xdr_op_number = 6;
  }

  if ( xdr_status )
  {
    /* XDR OP NUMBER = 7 */
    xdr_op_number = 7;
  }

  if ( ! XDR_MSG_DONE( clnt ) || ! xdr_status )
  {
    XDR_OP_ERR( clnt, xdr_op_number );
    return FALSE;
  }
  else
  {
    return TRUE;
  }
} /* secutil_rpc_glue_code_info_remote */

boolean secutil_rpc_glue_code_info_local
(
  uint32 *toolvers,
  uint32 *features,
  uint32 *proghash,
  uint32 *cbproghash
)
{
  if ( toolvers != NULL )
  {
    *toolvers = 7;
  }

  if ( features != NULL )
  {
    *features = ( 0x00000000
#ifdef FEATURE_ONCRPC_SERVER_CLEANUP_SUPPORT
                | 0x00000001
#endif
                );
  }

  if ( proghash != NULL )
  {
    *proghash = 0x9b497ec4;
  }

  if ( cbproghash != NULL )
  {
    *cbproghash = 0x811c9dc5;
  }

  return TRUE;
} /* secutil_rpc_glue_code_info_local */

secerrno_enum_type secutil_get_random(uint8 *random_ptr,  uint16 random_len)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  boolean output_pointer_not_null;
  uint32 length_uint32;
  uint16 length_uint16;
  secerrno_enum_type secutil_get_random_result;

  do {
    clnt = rpc_clnt_lookup2(SECUTILPROG, SECUTILVERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SECUTILPROG, SECUTILVERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SECUTILPROG, SECUTILVERS,
                               ONCRPC_SECUTIL_GET_RANDOM_PROC, &SecutilCred, &SecutilVerf );

    /* Send TRUE if random_ptr is not NULL and FALSE otherwise so that the server
     * can correctly allocate memory for the service to use. Also since this is
     * a pointer to a variable array, we need to send the maximum size of the
     * array too.
     */
    output_pointer_not_null = (random_ptr != NULL);

    (void) XDR_SEND_UINT8( clnt, &output_pointer_not_null );

    if ( output_pointer_not_null ) {
      length_uint32 = random_len;

      (void) XDR_SEND_UINT32( clnt, &length_uint32 );

    }

    (void) XDR_SEND_UINT16( clnt, &random_len );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_ENUM( clnt, &secutil_get_random_result );

  (void) XDR_RECV_UINT16( clnt, &length_uint16 );

  if ( length_uint16 > 0 )
  {
    if ( random_ptr != NULL ) {
      (void) XDR_RECV_BYTES(clnt, random_ptr, length_uint16);
    }
  }


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return secutil_get_random_result;
} /* secutil_get_random */

secerrno_enum_type secutil_get_sfs_key(uint8 *key_ptr,  uint32 key_len)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  boolean output_pointer_not_null;
  uint32 length_uint32;
  secerrno_enum_type secutil_get_sfs_key_result;

  do {
    clnt = rpc_clnt_lookup2(SECUTILPROG, SECUTILVERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SECUTILPROG, SECUTILVERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SECUTILPROG, SECUTILVERS,
                               ONCRPC_SECUTIL_GET_SFS_KEY_PROC, &SecutilCred, &SecutilVerf );

    /* Send TRUE if key_ptr is not NULL and FALSE otherwise so that the server
     * can correctly allocate memory for the service to use. Also since this is
     * a pointer to a variable array, we need to send the maximum size of the
     * array too.
     */
    output_pointer_not_null = (key_ptr != NULL);

    (void) XDR_SEND_UINT8( clnt, &output_pointer_not_null );

    if ( output_pointer_not_null ) {
      length_uint32 = key_len;

      (void) XDR_SEND_UINT32( clnt, &length_uint32 );

    }

    (void) XDR_SEND_UINT32( clnt, &key_len );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_ENUM( clnt, &secutil_get_sfs_key_result );

  (void) XDR_RECV_UINT32( clnt, &length_uint32 );

  if ( length_uint32 > 0 )
  {
    if ( key_ptr != NULL ) {
      (void) XDR_RECV_BYTES(clnt, key_ptr, length_uint32);
    }
  }


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return secutil_get_sfs_key_result;
} /* secutil_get_sfs_key */


/*=======================================================================
             API Callbacks RPC Server Implementation
=======================================================================*/


void secutilcb_app_init( void ) {
} /* secutilcb_app_init */

void secutilcb_app_lock( boolean lock ){
} /* secutilcb_app_enable */

#endif /* FEATURE_EXPORT_SECUTIL */
#endif /* FEATURE_ONCRPC */