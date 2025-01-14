/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                        A C C E S S _ T E R M I N A L _ S E R V I C E _ V 0 1  . C

GENERAL DESCRIPTION
  This is the file which defines the at service Data structures.

  Copyright (c) 2015 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.


  $Header$
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.5
   It was generated on: Thu Jun 18 2015 (Spin 0)
   From IDL File: access_terminal_service_v01.idl */

#include "stdint.h"
#include "qmi_idl_lib_internal.h"
#include "access_terminal_service_v01.h"
#include "common_v01.h"


/*Type Definitions*/
/*Message Definitions*/
/*
 * at_reset_req_msg is empty
 * static const uint8_t at_reset_req_msg_data_v01[] = {
 * };
 */

static const uint8_t at_reset_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(at_reset_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * at_req_at_cmd_fwd_req is empty
 * static const uint8_t at_req_at_cmd_fwd_req_data_v01[] = {
 * };
 */

static const uint8_t at_req_at_cmd_fwd_resp_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(at_req_at_cmd_fwd_resp_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * at_fwd_at_cmd_ind is empty
 * static const uint8_t at_fwd_at_cmd_ind_data_v01[] = {
 * };
 */

/*
 * at_fwd_resp_at_cmd_req is empty
 * static const uint8_t at_fwd_resp_at_cmd_req_data_v01[] = {
 * };
 */

/*
 * at_abort_at_cmd_ind is empty
 * static const uint8_t at_abort_at_cmd_ind_data_v01[] = {
 * };
 */

/*
 * at_send_at_urc_req is empty
 * static const uint8_t at_send_at_urc_req_data_v01[] = {
 * };
 */

static const uint8_t at_send_at_urc_resp_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(at_send_at_urc_resp_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t at_dummy_at_cmd_ind_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(at_dummy_at_cmd_ind_v01, qmi_at_dummy_buffer) - QMI_IDL_OFFSET8(at_dummy_at_cmd_ind_v01, qmi_at_dummy_buffer_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(at_dummy_at_cmd_ind_v01, qmi_at_dummy_buffer),
  ((QMI_AT_DUMMY_BUFFER_LEN_MAX_V01) & 0xFF), ((QMI_AT_DUMMY_BUFFER_LEN_MAX_V01) >> 8),
  QMI_IDL_OFFSET8(at_dummy_at_cmd_ind_v01, qmi_at_dummy_buffer) - QMI_IDL_OFFSET8(at_dummy_at_cmd_ind_v01, qmi_at_dummy_buffer_len)
};

/* Type Table */
/* No Types Defined in IDL */

/* Message Table */
static const qmi_idl_message_table_entry at_message_table_v01[] = {
  {sizeof(at_reset_req_msg_v01), 0},
  {sizeof(at_reset_resp_msg_v01), at_reset_resp_msg_data_v01},
  {sizeof(at_req_at_cmd_fwd_req_v01), 0},
  {sizeof(at_req_at_cmd_fwd_resp_v01), at_req_at_cmd_fwd_resp_data_v01},
  {sizeof(at_fwd_at_cmd_ind_v01), 0},
  {sizeof(at_fwd_resp_at_cmd_req_v01), 0},
  {sizeof(at_abort_at_cmd_ind_v01), 0},
  {sizeof(at_send_at_urc_req_v01), 0},
  {sizeof(at_send_at_urc_resp_v01), at_send_at_urc_resp_data_v01},
  {sizeof(at_dummy_at_cmd_ind_v01), at_dummy_at_cmd_ind_data_v01}
};

/* Range Table */
/* No Ranges Defined in IDL */

/* Predefine the Type Table Object */
static const qmi_idl_type_table_object at_qmi_idl_type_table_object_v01;

/*Referenced Tables Array*/
static const qmi_idl_type_table_object *at_qmi_idl_type_table_object_referenced_tables_v01[] =
{&at_qmi_idl_type_table_object_v01, &common_qmi_idl_type_table_object_v01};

/*Type Table Object*/
static const qmi_idl_type_table_object at_qmi_idl_type_table_object_v01 = {
  0,
  sizeof(at_message_table_v01)/sizeof(qmi_idl_message_table_entry),
  1,
  NULL,
  at_message_table_v01,
  at_qmi_idl_type_table_object_referenced_tables_v01,
  NULL
};

/*Arrays of service_message_table_entries for commands, responses and indications*/
static const qmi_idl_service_message_table_entry at_service_command_messages_v01[] = {
  {QMI_AT_RESET_REQ_V01, QMI_IDL_TYPE16(0, 0), 0},
  {QMI_AT_REG_AT_CMD_FWD_REQ_V01, QMI_IDL_TYPE16(0, 2), 0},
  {QMI_AT_FWD_RESP_AT_CMD_REQ_V01, QMI_IDL_TYPE16(0, 5), 0},
  {QMI_AT_SEND_AT_URC_REQ_V01, QMI_IDL_TYPE16(0, 7), 0}
};

static const qmi_idl_service_message_table_entry at_service_response_messages_v01[] = {
  {QMI_AT_RESET_RESP_V01, QMI_IDL_TYPE16(0, 1), 7},
  {QMI_AT_REG_AT_CMD_FWD_RESP_V01, QMI_IDL_TYPE16(0, 3), 7},
  {QMI_AT_FWD_RESP_AT_CMD_RESP_V01, QMI_IDL_TYPE16(0, 5), 0},
  {QMI_AT_SEND_AT_URC_RESP_V01, QMI_IDL_TYPE16(0, 8), 7}
};

static const qmi_idl_service_message_table_entry at_service_indication_messages_v01[] = {
  {QMI_AT_FWD_AT_CMD_IND_V01, QMI_IDL_TYPE16(0, 4), 0},
  {QMI_AT_ABORT_AT_CMD_IND_V01, QMI_IDL_TYPE16(0, 6), 0},
  {QMI_AT_DUMMY_AT_CMD_IND_V01, QMI_IDL_TYPE16(0, 9), 4101}
};

/*Service Object*/
struct qmi_idl_service_object at_qmi_idl_service_object_v01 = {
  0x06,
  0x01,
  0x08,
  4101,
  { sizeof(at_service_command_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(at_service_response_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(at_service_indication_messages_v01)/sizeof(qmi_idl_service_message_table_entry) },
  { at_service_command_messages_v01, at_service_response_messages_v01, at_service_indication_messages_v01},
  &at_qmi_idl_type_table_object_v01,
  0x03,
  NULL
};

/* Service Object Accessor */
qmi_idl_service_object_type at_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version ){
  if ( AT_V01_IDL_MAJOR_VERS != idl_maj_version || AT_V01_IDL_MINOR_VERS != idl_min_version
       || AT_V01_IDL_TOOL_VERS != library_version)
  {
    return NULL;
  }
  return (qmi_idl_service_object_type)&at_qmi_idl_service_object_v01;
}

