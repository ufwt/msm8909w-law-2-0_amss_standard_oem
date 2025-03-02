/*!
  @file
  qdi.h

  @brief
  Provides a wrapper that manages multiple QMI WDS service handles for
  dual IP over a single RmNet port.

*/

/*===========================================================================

  Copyright (c) 2011-2012,2014-2015 Qualcomm Technologies, Inc. All Rights Reserved

  Qualcomm Technologies Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ----------------------------------------------------------
12/01/10   jf      created file

===========================================================================*/

#ifndef QDI_H
#define QDI_H

#include "qmi_client.h"
#include "dsi_netctrl.h"
#include "wireless_data_service_v01.h"
#include "comdef.h"

typedef int  qdi_client_handle_t;
typedef void *qdi_call_handle_t;

#define QDI_INVALID_CLIENT_HANDLE  (-1)
#define QDI_INVALID_QMI_HANDLE     (NULL)
#define QDI_INVALID_CALL_HANDLE    (NULL)

#define QDI_RSP_DATA_V4     0x01
#define QDI_RSP_DATA_V6     0x02
#define QDI_RSP_DATA_V4_V6  (QDI_RSP_DATA_V4 | QDI_RSP_DATA_V6)

#define QDI_SUCCESS       (0)
#define QDI_FAILURE       (-1)

#define QDI_EMBMS_TMGI_SIZE  (6)

typedef enum
{
  QDI_MODE_NOT_SET,
  QDI_MODE_V4 = 1,
  QDI_MODE_V6 = 2,
  QDI_MODE_V4V6 = QDI_MODE_V4 | QDI_MODE_V6
} qdi_mode_t;

typedef union
{
  wds_start_network_interface_resp_msg_v01 start_nw_rsp;
}qdi_qmi_wds_async_rsp_data_type;

/* Typedef for QDI response data */
typedef struct
{
  int                         sys_err;
  qmi_error_type_v01          qmi_err;
  qdi_qmi_wds_async_rsp_data_type rsp_data;
} qdi_wds_resp_data_type;

/* Typedef for QDI async response data */
typedef struct
{
  int flags;

  qdi_wds_resp_data_type      rsp_data_v4;
  qdi_wds_resp_data_type      rsp_data_v6;
} qdi_wds_async_rsp_data_type;

typedef union
{
  wds_pkt_srvc_status_ind_msg_v01                pkt_srvc_status;
  wds_embms_tmgi_activate_ind_msg_v01            embms_activate_status;
  wds_embms_tmgi_deactivate_ind_msg_v01          embms_deactivate_status;
  wds_embms_tmgi_act_deact_ind_msg_v01           embms_act_deact_status;
  wds_embms_content_desc_control_ind_msg_v01     embms_content_desc_control;
  wds_embms_svc_interest_ind_msg_v01             embms_svc_interest;
  wds_handoff_information_ind_msg_v01            handoff_info;
  wds_embms_tmgi_list_ind_msg_v01                embms_list;
  wds_embms_sai_list_ind_msg_v01                 sai_list;
} qdi_qmi_wds_indication_data_type;

typedef struct
{
  wds_call_end_reason_enum_v01 legacy_reason;
  struct
  {
    wds_verbose_call_end_reason_type_enum_v01 verbose_reason_type;
    unsigned int verbose_reason;
  }call_end_reason_verbose;
}qdi_wds_call_end_reason_type;

/* Typedef for a QDI async callback function */
typedef void (*qdi_wds_user_async_cb_type)
(
  int                          user_handle,
  qmi_service_id_type          service_id,
  int                          sys_err_code,
  int                          qmi_err_code,
  void                        *user_data,
  int                          rsp_id,
  qdi_wds_async_rsp_data_type *rsp_data
);

typedef void (*qdi_wds_indication_hdlr_type)
(
  qmi_client_type               user_handle,
  qmi_service_id_type           service_id,
  void                          *user_data,
  int                            ind_id,
  qdi_qmi_wds_indication_data_type  *ind_data
);

/*===========================================================================
  FUNCTION  qdi_init
===========================================================================*/
/*!
@brief
  This function is called to initialize the QDI library.  This function
  must be called prior to calling any other QDI functions.

@return
  QDI_SUCCESS if the operation was sucessful
  QDI_FAILURE otherwise

*/
/*=========================================================================*/
int
qdi_init (void);


/*===========================================================================
  FUNCTION  qdi_release
===========================================================================*/
/*!
@brief
  This function is called to deinitialize the QDI library.

@return
  QDI_SUCCESS if the operation was sucessful
  QDI_FAILURE otherwise

*/
/*=========================================================================*/
int
qdi_release (void);

/*===========================================================================
  FUNCTION  qdi_flush_cmd_q
===========================================================================*/
/*
@brief
  This function is called to flush qdi_cmdq

@return
  QDI_SUCCESS if the operation was sucessful
  QDI_FAILURE otherwise

*/
/*=========================================================================*/
int
qdi_flush_cmdq(void);


/*===========================================================================
  FUNCTION  qdi_wds_srvc_init_client
===========================================================================*/
/*!
@brief
  This function is called to initialize the QDI service.  This function
  must be called prior to calling any other QDI service functions.

@return
  QMI_NO_ERR if the operation was sucessful, < 0 if not. If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note
  - Dependencies
    - qmi_connection_init() must be called for the associated port first.
*/
/*=========================================================================*/
qdi_client_handle_t
qdi_wds_srvc_init_client
(
  const char                             *wds_id,
  const char                             *dev_id,
  void                                   *user_ind_msg_hdlr,
  void                                   *user_ind_msg_hdlr_user_data,
  wds_bind_subscription_enum_v01          subs_id
);


/*===========================================================================
  FUNCTION  qdi_wds_srvc_release_client
===========================================================================*/
/*!
@brief
  This function is called to release a client created by the
  qdi_wds_srvc_init_client() function.

@return
  QMI_NO_ERR if the operation was sucessful, < 0 if not. If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note
  - Dependencies
    - qmi_connection_init() must be called for the associated port first.
*/
/*=========================================================================*/
int
qdi_wds_srvc_release_client
(
  qdi_client_handle_t  user_handle
);

/*===========================================================================
  FUNCTION  qdi_alloc_call_handle
===========================================================================*/
/*!
@brief
  This function is called to allocate a new call handle

@return
  Valid call handle on success
  QDI_INVALID_CALL_HANDLE on error

@note
  None
*/
/*=========================================================================*/
qdi_call_handle_t
qdi_alloc_call_handle
(
  qdi_client_handle_t  user_handle
);

/*===========================================================================
  FUNCTION  qdi_release_call_handle
===========================================================================*/
/*!
@brief
  This function is called to release a previously allocated call handle

@return
  None

@note
  None
*/
/*=========================================================================*/
void
qdi_release_call_handle
(
  qdi_call_handle_t  call_hndl
);

/*===========================================================================
  FUNCTION  qdi_wds_start_nw_if
===========================================================================*/
/*!
@brief
  This function is used to bring up a data call. Call profile parameters are
  specified in the params parameter.

  The result of this call is reported asynchronously via the user_cb
  callback function.

@return
  If the return code < 0, the operation failed and there won't be an
  asynchronous response.  If the operation doesn't fail
  (return code >=0), the returned value will be a transaction handle which
  can be used to cancel the transaction via the qdi_wds_abort() command.

@note
  - Dependencies
    - qdi_wds_srvc_init_client() must be called before calling this.
*/
/*=========================================================================*/
int qdi_wds_start_nw_if
(
  qdi_client_handle_t                      user_handle,
  qdi_call_handle_t                        call_hndl,
  wds_start_network_interface_req_msg_v01 *params,
  boolean                                  partial_retry,
  qdi_wds_user_async_cb_type               user_cb,
  void                                    *user_data,
  int                                      rl_qmi_inst,
  qdi_wds_call_end_reason_type            *call_end_reason_resp,
  int                                     *qmi_err_code,
  int                                     *ip_family
);
/*===========================================================================
  FUNCTION  qdi_wds_stop_nw_if
===========================================================================*/
/*!
@brief
  This function is used to bring down a data call. The result of this call is
  reported asynchronously via the user_cb callback function.

@return
  If the return code < 0, the operation failed and there won't be an
  asynchronous response.  If the operation doesn't fail
  (return code >=0), the returned value will be a transaction handle which
  can be used to cancel the transaction via the qdi_wds_abort() command.

@note
  - Dependencies
    - qdi_wds_srvc_init_client() must be called before calling this.
*/
/*=========================================================================*/
int
qdi_wds_stop_nw_if
(
  qdi_client_handle_t         user_handle,
  qdi_call_handle_t           call_hndl,
  qdi_wds_user_async_cb_type  user_cb,
  qdi_mode_t                  stop_mode,
  void                        *user_data,
  int                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qdi_wds_abort
===========================================================================*/
/*!
@brief
  Aborts an asynchronous QDI operation. If the user_cb function pointer is
  set to NULL, then this function will be invoked synchronously, otherwise
  it will be invoked asynchronously.  The txn_handle parameter is the
  return code returned from any other asynchronous WDS call.  Note that
  synchronous API calls cannot be aborted.

@return
  0 if abort operation was sucessful, < 0 if not.  In the case where the
  abort is successful, an asychronous reply to the aborted command will NOT
  be returned, otherwise, it will.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error.  Note that asynchronous abort commands cannot
  themselves be aborted.

@note
  - Dependencies
    - qdi_wds_srvc_init_client() must be called before calling this.
*/
/*=========================================================================*/
int qdi_wds_abort
(
  qdi_client_handle_t         user_handle,
  qdi_call_handle_t           call_hndl,
  int                         txn_handle,
  int                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qdi_get_qmi_wds_handle
===========================================================================*/
/*!
@brief
  This function returns the QMI-WDS handle corresponding to the QDI handle

@return
  QMI_INTERNAL_ERR on error or the corresponding QMI handle

@note
  - Dependencies
    - qdi_wds_srvc_init_client() must be called before calling this.
*/
/*=========================================================================*/
qmi_client_type
qdi_get_qmi_wds_handle
(
  qdi_client_handle_t user_handle
);

/*==========================================================================
  FUNCTION: qdi_get_qmi_wds_handle_for_ip
===========================================================================*/
/*!
  @brief
  Returns the QMI WDS handle corresponding to the QDI handle based on IP
  type

 @return
  QMI_INTERNAL_ERR on error or the corresponding QMI handle

 @note
  - Dependencies
    - qdi_wds_srvc_init_client() must be called before calling this.
*/
/*=========================================================================*/
qmi_client_type
qdi_get_qmi_wds_handle_for_ip
(
  qdi_client_handle_t     user_handle,
  wds_ip_family_preference_enum_v01 ip_type
);

/*===========================================================================
  FUNCTION  qdi_get_addr_info
===========================================================================*/
/*!
@brief
  This function returns the IP address of the given IP family for the given
  interface

@param
  user_handle - Interface on which IP address is being requested
  ifname      - IP family of the address to return
  ipfamily    - AF_INET or AF_INET6

@return
  QDI_SUCCESS on successful operation
  QDI_FAILURE otherwise

@note
  - Dependencies
    - qdi_wds_srvc_init_client() must be called before calling this.
*/
/*=========================================================================*/
int
qdi_get_addr_info
(
  qdi_client_handle_t          user_handle,
  const char                  *ifname,
  int                          ipfamily,
  dsi_addr_info_t             *addr_info,
  wds_technology_name_enum_v01 tech_name
);

#endif /* QDI_H */
