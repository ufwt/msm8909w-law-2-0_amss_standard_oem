/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

              T H E R M A L _ M I T I G A T I O N _ D E V I C E _ S E R V I C E _ I M P L _ V 0 1  . C

GENERAL DESCRIPTION
  This is the file which defines the tmd service Data structures.

  Copyright (c) 2012-2013 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.


  $Header: //components/rel/core.mpss/3.5.c12.3/power/thermal/src/common/thermal_mitigation_device_service_impl_v01.c#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.1
   It was generated on: Sun Mar  3 2013 (Spin 0)
   From IDL File: thermal_mitigation_device_service_v01.idl */

#include "qmi_si.h"
#include "thermal_mitigation_device_service_v01.h"

static const uint32_t qmi_get_supported_msgs_resp_impl_array_v01[] =
{
    QMI_SI_TLV_SET(0x10)      /* supported_msgs */
};

static const qmi_implemented_optionals qmi_get_supported_msgs_resp_impl_v01 =
{
  1, /* number of elements in array */
  qmi_get_supported_msgs_resp_impl_array_v01
};
static const qmi_implemented_optionals_tuple qmi_tmd_get_supported_msgs_reqresp_impl_tuple_v01 = 
{
  NULL,
  &qmi_get_supported_msgs_resp_impl_v01,
  NULL
};

static const qmi_implemented_optionals qmi_get_supported_fields_req_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const uint32_t qmi_get_supported_fields_resp_impl_array_v01[] =
{
    QMI_SI_TLV_SET(0x10)   |  /* request_fields */
    QMI_SI_TLV_SET(0x11)   |  /* response_fields */
    QMI_SI_TLV_SET(0x12)      /* indication_fields */
};

static const qmi_implemented_optionals qmi_get_supported_fields_resp_impl_v01 =
{
  1, /* number of elements in array */
  qmi_get_supported_fields_resp_impl_array_v01
};
static const qmi_implemented_optionals_tuple qmi_tmd_get_supported_fields_reqresp_impl_tuple_v01 = 
{
  &qmi_get_supported_fields_req_impl_v01,
  &qmi_get_supported_fields_resp_impl_v01,
  NULL
};

static const uint32_t tmd_get_mitigation_device_list_resp_msg_impl_array_v01[] =
{
    QMI_SI_TLV_SET(0x10)      /* mitigation_device_list */
};

static const qmi_implemented_optionals tmd_get_mitigation_device_list_resp_msg_impl_v01 =
{
  1, /* number of elements in array */
  tmd_get_mitigation_device_list_resp_msg_impl_array_v01
};
static const qmi_implemented_optionals_tuple qmi_tmd_get_mitigation_device_list_reqresp_impl_tuple_v01 = 
{
  NULL,
  &tmd_get_mitigation_device_list_resp_msg_impl_v01,
  NULL
};

static const qmi_implemented_optionals tmd_set_mitigation_level_req_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals tmd_set_mitigation_level_resp_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals_tuple qmi_tmd_set_mitigation_level_reqresp_impl_tuple_v01 = 
{
  &tmd_set_mitigation_level_req_msg_impl_v01,
  &tmd_set_mitigation_level_resp_msg_impl_v01,
  NULL
};

static const qmi_implemented_optionals tmd_get_mitigation_level_req_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const uint32_t tmd_get_mitigation_level_resp_msg_impl_array_v01[] =
{
    QMI_SI_TLV_SET(0x10)   |  /* current_mitigation_level */
    QMI_SI_TLV_SET(0x11)      /* requested_mitigation_level */
};

static const qmi_implemented_optionals tmd_get_mitigation_level_resp_msg_impl_v01 =
{
  1, /* number of elements in array */
  tmd_get_mitigation_level_resp_msg_impl_array_v01
};
static const qmi_implemented_optionals_tuple qmi_tmd_get_mitigation_level_reqresp_impl_tuple_v01 = 
{
  &tmd_get_mitigation_level_req_msg_impl_v01,
  &tmd_get_mitigation_level_resp_msg_impl_v01,
  NULL
};

static const qmi_implemented_optionals tmd_register_notification_mitigation_level_req_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals tmd_register_notification_mitigation_level_resp_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals_tuple qmi_tmd_register_notification_mitigation_level_reqresp_impl_tuple_v01 = 
{
  &tmd_register_notification_mitigation_level_req_msg_impl_v01,
  &tmd_register_notification_mitigation_level_resp_msg_impl_v01,
  NULL
};

static const qmi_implemented_optionals tmd_deregister_notification_mitigation_level_req_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals tmd_deregister_notification_mitigation_level_resp_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals_tuple qmi_tmd_deregister_notification_mitigation_level_reqresp_impl_tuple_v01 = 
{
  &tmd_deregister_notification_mitigation_level_req_msg_impl_v01,
  &tmd_deregister_notification_mitigation_level_resp_msg_impl_v01,
  NULL
};

static const qmi_implemented_optionals tmd_mitigation_level_report_ind_msg_impl_v01 =
{
  0, /* No Optional TLVs in message */
  0
};
static const qmi_implemented_optionals_tuple qmi_tmd_mitigation_level_report_impl_tuple_v01 = 
{
  NULL,
  NULL,
  &tmd_mitigation_level_report_ind_msg_impl_v01
};

static const qmi_implemented_optionals_tuple * const tmd_service_implemented_array_v01[] =
{
    NULL,                                                /* 0x0000 */
    NULL,                                                /* 0x0001 */
    NULL,                                                /* 0x0002 */
    NULL,                                                /* 0x0003 */
    NULL,                                                /* 0x0004 */
    NULL,                                                /* 0x0005 */
    NULL,                                                /* 0x0006 */
    NULL,                                                /* 0x0007 */
    NULL,                                                /* 0x0008 */
    NULL,                                                /* 0x0009 */
    NULL,                                                /* 0x000A */
    NULL,                                                /* 0x000B */
    NULL,                                                /* 0x000C */
    NULL,                                                /* 0x000D */
    NULL,                                                /* 0x000E */
    NULL,                                                /* 0x000F */
    NULL,                                                /* 0x0010 */
    NULL,                                                /* 0x0011 */
    NULL,                                                /* 0x0012 */
    NULL,                                                /* 0x0013 */
    NULL,                                                /* 0x0014 */
    NULL,                                                /* 0x0015 */
    NULL,                                                /* 0x0016 */
    NULL,                                                /* 0x0017 */
    NULL,                                                /* 0x0018 */
    NULL,                                                /* 0x0019 */
    NULL,                                                /* 0x001A */
    NULL,                                                /* 0x001B */
    NULL,                                                /* 0x001C */
    NULL,                                                /* 0x001D */
    &qmi_tmd_get_supported_msgs_reqresp_impl_tuple_v01,  /* 0x001E */
    &qmi_tmd_get_supported_fields_reqresp_impl_tuple_v01, /* 0x001F */
    &qmi_tmd_get_mitigation_device_list_reqresp_impl_tuple_v01, /* 0x0020 */
    &qmi_tmd_set_mitigation_level_reqresp_impl_tuple_v01, /* 0x0021 */
    &qmi_tmd_get_mitigation_level_reqresp_impl_tuple_v01, /* 0x0022 */
    &qmi_tmd_register_notification_mitigation_level_reqresp_impl_tuple_v01, /* 0x0023 */
    &qmi_tmd_deregister_notification_mitigation_level_reqresp_impl_tuple_v01, /* 0x0024 */
    &qmi_tmd_mitigation_level_report_impl_tuple_v01      /* 0x0025 */
};

static const qmi_implemented_messages tmd_service_implemented_v01 =
{
  0x0025,  /* maximum message ID in this service */
  tmd_service_implemented_array_v01
};

const qmi_implemented_messages *tmd_get_service_impl_v01 (void)
{
  return &tmd_service_implemented_v01;
}
