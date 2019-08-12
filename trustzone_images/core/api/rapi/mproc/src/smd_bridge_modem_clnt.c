/* SMD_BRIDGE_MODEM TOOL VERSION: 4.41 */
/* GENERATED: TUE JUL 20 2010 */
/*=============================================================================
                 S M D _ B R I D G E _ M O D E M _ C L N T . C

GENERAL DESCRIPTION
  This is an AUTO GENERATED file that provides RPC client functionality for the
  smd_bridge_modem API.

  ---------------------------------------------------------------------------
  Copyright (c) 2010 Qualcomm Technologies Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------
=============================================================================*/

/*=============================================================================

                              Edit History

                             AUTO GENERATED                                  */
/* Generated by following versions of Htorpc modules:
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/htorpc.pl#2 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/Start.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/Htoxdr.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/XDR.pm#2 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/Output.pm#3 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/Parser.pm#2 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/Metacomments.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.02/htorpc/lib/Htorpc/SymbolTable.pm#1   

smd_bridge_modem Definition File(s):
Id: //source/qcom/qct/core/api/mproc/rel/05.02/smd_bridge_modem.h#2
=============================================================================*/
/*=============================================================================
$Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/mproc/src/smd_bridge_modem_clnt.c#1 $ 
=============================================================================*/


/* Include files */
#include "oncrpc.h"
#include "smd_bridge_modem.h"
#include "smd_bridge_modem_rpc.h"

/* Only one copy needed per API */
static opaque_auth Smd_bridge_modemCred = { ONCRPC_AUTH_NONE, 0, 0 };
static opaque_auth Smd_bridge_modemVerf = { ONCRPC_AUTH_NONE, 0, 0 };

//static opaque_auth Smd_bridge_modemcbCred = { ONCRPC_AUTH_NONE, 0, 0 };
static opaque_auth Smd_bridge_modemcbVerf = { ONCRPC_AUTH_NONE, 0, 0 };


/*=======================================================================
             Prototypes for the API Callbacks RPC Server Functions
=======================================================================*/
  
static void smd_bridge_modemcbprog_0x00040001 ( struct svc_req *rqstp, xdr_s_type *srv );

static void smd_bridge_server_receive_f_type_svc_0x00040001( xdr_s_type *srv );

static void smd_bridge_forward_callback_f_type_svc_0x00040001( xdr_s_type *srv );


/*=======================================================================
             API RPC Clients Implementation
=======================================================================*/

boolean smd_bridge_modem_null(void)
{
  xdr_s_type       *clnt;
  rpc_reply_header  reply_header;
  boolean           xdr_status = TRUE;
  int               xdr_op_number = 0;

  clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_NULL_VERS, 0);

  if ( clnt == NULL ) {
    XDR_CLNT_LOOKUP2_ERR(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_NULL_VERS, 0);
    return FALSE;
  }

  oncrpcxdr_mem_free( clnt );

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  if ( ! xdr_call_msg_start( clnt,
                             SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_NULL_VERS,
                             ONCRPC_SMD_BRIDGE_MODEM_NULL_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf ) ) {
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
} /* smd_bridge_modem_null */

boolean smd_bridge_modem_rpc_glue_code_info_remote
(
  uint32 *toolvers,
  uint32 *features,
  uint32 *proghash,
  uint32 *cbproghash
)
{
  xdr_s_type       *clnt;
  rpc_reply_header  reply_header;
  uint32            result = 0;
  boolean           xdr_status = TRUE;
  int               xdr_op_number = 0;

  clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_RPC_GLUE_CODE_INFO_REMOTE_VERS, 0);

  if ( clnt == NULL ) {
    XDR_CLNT_LOOKUP2_ERR(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_RPC_GLUE_CODE_INFO_REMOTE_VERS, 0);
    return FALSE;
  }
  oncrpcxdr_mem_free( clnt );

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  if ( ! xdr_call_msg_start( clnt,
                             SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_RPC_GLUE_CODE_INFO_REMOTE_VERS,
                             ONCRPC_SMD_BRIDGE_MODEM_RPC_GLUE_CODE_INFO_REMOTE_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf ) ) {
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
} /* smd_bridge_modem_rpc_glue_code_info_remote */

boolean smd_bridge_modem_rpc_glue_code_info_local
(
  uint32 *toolvers,
  uint32 *features,
  uint32 *proghash,
  uint32 *cbproghash
)
{
  if ( toolvers != NULL )
  {
    *toolvers = SMD_BRIDGE_MODEM_TOOLVERS; /* 4.41 */
  }

  if ( features != NULL )
  {
    *features = SMD_BRIDGE_MODEM_FEATURES; /* ONCRPC Server Cleanup Support */
                
  }

  if ( proghash != NULL )
  {
    *proghash = 0x00040001; /* 0x00040001 */
  }

  if ( cbproghash != NULL )
  {
    *cbproghash = 0x00040001; /* 0x00040001 */
  }

  return TRUE;
} /* smd_bridge_modem_rpc_glue_code_info_local */

smd_bridge_remote_cmd_ret_type smd_bridge_receive_cmd_modem(smd_bridge_remote_cmd_param_type param,  void *data)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  smd_bridge_remote_cmd_ret_type smd_bridge_receive_cmd_modem_result;

  do {
    clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_RECEIVE_CMD_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_RECEIVE_CMD_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_RECEIVE_CMD_MODEM_VERS,
                               ONCRPC_SMD_BRIDGE_RECEIVE_CMD_MODEM_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf );

    (void) xdr_smd_bridge_modem_send_smd_bridge_remote_cmd_param( clnt, &param );

    (void) XDR_SEND_HANDLE( clnt, &data );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_ENUM( clnt, &smd_bridge_receive_cmd_modem_result );


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return smd_bridge_receive_cmd_modem_result;
} /* smd_bridge_receive_cmd_modem */

boolean smd_bridge_register_server_modem(smd_bridge_server_receive_f_type server_cb,  uint32 proc_id,  void *data)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  uint32 cb_id;
  boolean smd_bridge_register_server_modem_result;

  do {
    clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_REGISTER_SERVER_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_REGISTER_SERVER_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_REGISTER_SERVER_MODEM_VERS,
                               ONCRPC_SMD_BRIDGE_REGISTER_SERVER_MODEM_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf );

    /*lint -save -e611*/
    cb_id = rpc_clnt_callback_register( (void *) server_cb );
    /*lint -restore */

    (void) XDR_SEND_UINT32( clnt, &cb_id );

    (void) XDR_SEND_UINT32( clnt, &proc_id );

    (void) XDR_SEND_HANDLE( clnt, &data );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_BOOLEAN( clnt, &smd_bridge_register_server_modem_result );


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return smd_bridge_register_server_modem_result;
} /* smd_bridge_register_server_modem */

boolean smd_bridge_register_forward_callback_modem(smd_bridge_forward_callback_f_type forward_cb,  uint32 proc_id,  void *data)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  uint32 cb_id;
  boolean smd_bridge_register_forward_callback_modem_result;

  do {
    clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_REGISTER_FORWARD_CALLBACK_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_REGISTER_FORWARD_CALLBACK_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_REGISTER_FORWARD_CALLBACK_MODEM_VERS,
                               ONCRPC_SMD_BRIDGE_REGISTER_FORWARD_CALLBACK_MODEM_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf );

    /*lint -save -e611*/
    cb_id = rpc_clnt_callback_register( (void *) forward_cb );
    /*lint -restore */

    (void) XDR_SEND_UINT32( clnt, &cb_id );

    (void) XDR_SEND_UINT32( clnt, &proc_id );

    (void) XDR_SEND_HANDLE( clnt, &data );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_BOOLEAN( clnt, &smd_bridge_register_forward_callback_modem_result );


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return smd_bridge_register_forward_callback_modem_result;
} /* smd_bridge_register_forward_callback_modem */

boolean smd_bridge_forward_callback_modem(uint32 bridge_id,  smd_bridge_callback_type callback,  void *data)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  boolean smd_bridge_forward_callback_modem_result;

  do {
    clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_FORWARD_CALLBACK_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_FORWARD_CALLBACK_MODEM_VERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_FORWARD_CALLBACK_MODEM_VERS,
                               ONCRPC_SMD_BRIDGE_FORWARD_CALLBACK_MODEM_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf );

    (void) XDR_SEND_UINT32( clnt, &bridge_id );

    (void) XDR_SEND_ENUM( clnt, &callback );

    (void) XDR_SEND_HANDLE( clnt, &data );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_BOOLEAN( clnt, &smd_bridge_forward_callback_modem_result );


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return smd_bridge_forward_callback_modem_result;
} /* smd_bridge_forward_callback_modem */


/*=======================================================================
             API Standard Functions for version info
=======================================================================*/

uint32 *smd_bridge_modem_api_versions(uint32 *len)
{
  xdr_s_type *clnt;
  rpc_reply_header reply_header;

  uint32 i;
  boolean output_pointer_not_null;
  void *memset_temp;
  uint32 length_uint32;
  uint32 *smd_bridge_modem_api_versions_result = NULL;

  do {
    clnt = rpc_clnt_lookup2(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_API_VERSIONS_VERS, RPC_CLNT_LOOKUP_TIMEOUT);

    if ( clnt == NULL ) {
      XDR_CLNT_LOOKUP2_ERR_FATAL(SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_API_VERSIONS_VERS, RPC_CLNT_LOOKUP_TIMEOUT);
    }

    oncrpcxdr_mem_free( clnt );

    XDR_ERRCHK( clnt, ON );

    (void) xdr_call_msg_start( clnt,
                               SMD_BRIDGE_MODEMPROG, SMD_BRIDGE_MODEM_API_VERSIONS_VERS,
                               ONCRPC_SMD_BRIDGE_MODEM_API_VERSIONS_PROC, &Smd_bridge_modemCred, &Smd_bridge_modemVerf );

    /* Send TRUE if len is not NULL and FALSE otherwise so that the server
     * can correctly allocate memory for the service to use
     */
    output_pointer_not_null = (len != NULL);

    (void) XDR_SEND_UINT8( clnt, &output_pointer_not_null );


    /* Send the RPC message and block waiting for a reply */
  } while ( ! XDR_MSG_SEND( clnt, &reply_header ) );

  if ( reply_header.stat != RPC_MSG_ACCEPTED ) {
    XDR_CALL_REJECTED_ERR_FATAL( clnt, &reply_header );
  }

  if ( reply_header.u.ar.stat != RPC_ACCEPT_SUCCESS ) {
    XDR_ERR_ON_SERVER_ERR_FATAL( clnt, &reply_header );
  }

  (void) XDR_RECV_UINT32( clnt, &length_uint32 );

  if ( length_uint32 > 0 )
  {
    memset_temp = oncrpcxdr_mem_alloc( clnt, length_uint32 * sizeof( *smd_bridge_modem_api_versions_result ));
    memset(memset_temp, 0, length_uint32 * sizeof( *smd_bridge_modem_api_versions_result ));
    smd_bridge_modem_api_versions_result = memset_temp;


    /* Calling array of XDR routines */
    for ( i = 0; i < (length_uint32); i++ ) {
      /*lint -save -e545*/
      (void) XDR_RECV_UINT32( clnt, &(smd_bridge_modem_api_versions_result[i]) );
      /*lint -restore */
    }
  }

  /*lint -save -e123*/
  XDR_RECV_POINTER_NO_ERRCHK( clnt, &len, XDR_RECV_UINT32 );
  /*lint -restore */


  if ( ! XDR_MSG_DONE( clnt ) )
  {
    XDR_OP_ERR_FATAL( clnt, 0 );
  }

  XDR_ERRCHK( clnt, OFF );

  return smd_bridge_modem_api_versions_result;
} /* smd_bridge_modem_api_versions */




/*=======================================================================
             API Callbacks RPC Server Implementation
=======================================================================*/

void smd_bridge_modemcb_app_init( void )
{
  (void) svc_register_auto(SMD_BRIDGE_MODEMCBPROG, SMD_BRIDGE_MODEMCBVERS, smd_bridge_modemcbprog_0x00040001);
} /* smd_bridge_modemcb_app_init */

void smd_bridge_modemcb_app_lock( boolean lock )
{
  svc_lock( SMD_BRIDGE_MODEMCBPROG, SMD_BRIDGE_MODEMCBVERS, lock );
} /* smd_bridge_modemcb_app_enable */

static void smd_bridge_modemcbprog_0x00040001( struct svc_req *rqstp, xdr_s_type *srv )
{
  switch( rqstp->rq_proc ) {
    case ONCRPC_SMD_BRIDGE_SERVER_RECEIVE_F_TYPE_PROC:
      smd_bridge_server_receive_f_type_svc_0x00040001( srv );
      break;
    case ONCRPC_SMD_BRIDGE_FORWARD_CALLBACK_F_TYPE_PROC:
      smd_bridge_forward_callback_f_type_svc_0x00040001( srv );
      break;
    default:
      // invalid RPC procedure number
      (void) XDR_MSG_DONE( srv );
      svcerr_default_err( srv, rqstp, smd_bridge_modem_api_versions  );
      break;
  }

  oncrpcxdr_mem_free( srv );
} /* smd_bridge_modemcbprog_0x00040001 */

static void smd_bridge_server_receive_f_type_svc_0x00040001( xdr_s_type *srv )
{
  smd_bridge_server_receive_f_type cmd_cb_func;
  uint32  cb_id;
  boolean xdr_status = TRUE;
  int     xdr_op_number = 0;

  smd_bridge_remote_cmd_param_type arg1;
  void *arg2 = NULL;

  smd_bridge_remote_cmd_ret_type cmd_cb_func_result;

  /* 
   * For struct or union parameters, use memset to zero out their memory on
   * the stack to make sure any pointer members are initialized to NULL
   */
  memset( (void *) &arg1, 0, sizeof(arg1) );


  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_UINT32( srv, &cb_id );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = xdr_smd_bridge_modem_recv_smd_bridge_remote_cmd_param( srv, &arg1 );
  }

  /* XDR OP NUMBER = 3 */
  if ( xdr_status )
  {
    xdr_op_number = 3;
    xdr_status = XDR_RECV_HANDLE( srv, &arg2 );
  }

  if ( xdr_status )
  {
    xdr_op_number++;
  }      

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  /*lint -save -e611*/
  cmd_cb_func = (smd_bridge_server_receive_f_type ) rpc_clnt_callback_lookup( cb_id );
  /*lint -restore */

  if ( cmd_cb_func == NULL ) {
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  cmd_cb_func_result = cmd_cb_func(arg1, arg2);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Smd_bridge_modemcbVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_ENUM( srv, &cmd_cb_func_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* smd_bridge_server_receive_f_type_svc_0x00040001 */

static void smd_bridge_forward_callback_f_type_svc_0x00040001( xdr_s_type *srv )
{
  smd_bridge_forward_callback_f_type cmd_cb_func;
  uint32  cb_id;
  boolean xdr_status = TRUE;
  int     xdr_op_number = 0;

  uint32 arg1 = 0;
  smd_bridge_callback_type arg2 = SMD_BRIDGE_SERVER_CALLBACK;
  void *arg3 = NULL;

  boolean cmd_cb_func_result;


  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_UINT32( srv, &cb_id );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_RECV_UINT32( srv, &arg1 );
  }

  /* XDR OP NUMBER = 3 */
  if ( xdr_status )
  {
    xdr_op_number = 3;
    xdr_status = XDR_RECV_ENUM( srv, &arg2 );
  }

  /* XDR OP NUMBER = 4 */
  if ( xdr_status )
  {
    xdr_op_number = 4;
    xdr_status = XDR_RECV_HANDLE( srv, &arg3 );
  }

  if ( xdr_status )
  {
    xdr_op_number++;
  }      

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  /*lint -save -e611*/
  cmd_cb_func = (smd_bridge_forward_callback_f_type ) rpc_clnt_callback_lookup( cb_id );
  /*lint -restore */

  if ( cmd_cb_func == NULL ) {
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  cmd_cb_func_result = cmd_cb_func(arg1, arg2, arg3);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Smd_bridge_modemcbVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &cmd_cb_func_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* smd_bridge_forward_callback_f_type_svc_0x00040001 */
