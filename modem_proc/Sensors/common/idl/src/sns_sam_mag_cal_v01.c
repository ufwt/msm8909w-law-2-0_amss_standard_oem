/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                        S N S _ S A M _ M A G _ C A L _ V 0 1  . C

GENERAL DESCRIPTION
  This is the file which defines the SNS_SAM_MAG_CAL_SVC service Data structures.

  Copyright (c) 2013 Qualcomm Technologies, Inc.  All Rights Reserved. 
 Confidential and Proprietary - Qualcomm Technologies, Inc.

  $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/Sensors/common/idl/src/sns_sam_mag_cal_v01.c#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====* 
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY 
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.13 
   It was generated on: Tue Sep 23 2014 (Spin 0)
   From IDL File: sns_sam_mag_cal_v01.idl */

#include "stdint.h"
#include "qmi_idl_lib_internal.h"
#include "sns_sam_mag_cal_v01.h"
#include "sns_common_v01.h"


/*Type Definitions*/
static const uint8_t sns_sam_mag_cal_result_s_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_result_s_v01, m),
  3,

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_result_s_v01, b),
  3,

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_result_s_v01, accuracy),

  QMI_IDL_FLAG_END_VALUE
};

/*Message Definitions*/
static const uint8_t sns_sam_mag_cal_enable_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_req_msg_v01, report_period),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_req_msg_v01, sample_rate) - QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_req_msg_v01, sample_rate_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_req_msg_v01, sample_rate)
};

static const uint8_t sns_sam_mag_cal_enable_resp_msg_data_v01[] = {
  2,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_resp_msg_v01, instance_id) - QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_resp_msg_v01, instance_id_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_enable_resp_msg_v01, instance_id)
};

static const uint8_t sns_sam_mag_cal_disable_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_disable_req_msg_v01, instance_id)
};

static const uint8_t sns_sam_mag_cal_disable_resp_msg_data_v01[] = {
  2,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_disable_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(sns_sam_mag_cal_disable_resp_msg_v01, instance_id) - QMI_IDL_OFFSET8(sns_sam_mag_cal_disable_resp_msg_v01, instance_id_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_disable_resp_msg_v01, instance_id)
};

static const uint8_t sns_sam_mag_cal_report_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_report_ind_msg_v01, instance_id),

  0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_report_ind_msg_v01, timestamp),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x03,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_report_ind_msg_v01, result),
  QMI_IDL_TYPE88(0, 0)
};

static const uint8_t sns_sam_mag_cal_get_report_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_req_msg_v01, instance_id)
};

static const uint8_t sns_sam_mag_cal_get_report_resp_msg_data_v01[] = {
  2,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, instance_id) - QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, instance_id_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, instance_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, timestamp) - QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, timestamp_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, timestamp),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, result) - QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, result_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_get_report_resp_msg_v01, result),
  QMI_IDL_TYPE88(0, 0)
};

static const uint8_t sns_sam_mag_cal_error_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_error_ind_msg_v01, error),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_sam_mag_cal_error_ind_msg_v01, instance_id)
};

/* Type Table */
static const qmi_idl_type_table_entry  SNS_SAM_MAG_CAL_SVC_type_table_v01[] = {
  {sizeof(sns_sam_mag_cal_result_s_v01), sns_sam_mag_cal_result_s_data_v01}
};

/* Message Table */
static const qmi_idl_message_table_entry SNS_SAM_MAG_CAL_SVC_message_table_v01[] = {
  {sizeof(sns_sam_mag_cal_enable_req_msg_v01), sns_sam_mag_cal_enable_req_msg_data_v01},
  {sizeof(sns_sam_mag_cal_enable_resp_msg_v01), sns_sam_mag_cal_enable_resp_msg_data_v01},
  {sizeof(sns_sam_mag_cal_disable_req_msg_v01), sns_sam_mag_cal_disable_req_msg_data_v01},
  {sizeof(sns_sam_mag_cal_disable_resp_msg_v01), sns_sam_mag_cal_disable_resp_msg_data_v01},
  {sizeof(sns_sam_mag_cal_report_ind_msg_v01), sns_sam_mag_cal_report_ind_msg_data_v01},
  {sizeof(sns_sam_mag_cal_get_report_req_msg_v01), sns_sam_mag_cal_get_report_req_msg_data_v01},
  {sizeof(sns_sam_mag_cal_get_report_resp_msg_v01), sns_sam_mag_cal_get_report_resp_msg_data_v01},
  {sizeof(sns_sam_mag_cal_error_ind_msg_v01), sns_sam_mag_cal_error_ind_msg_data_v01}
};

/* Range Table */
/* No Ranges Defined in IDL */

/* Predefine the Type Table Object */
static const qmi_idl_type_table_object SNS_SAM_MAG_CAL_SVC_qmi_idl_type_table_object_v01;

/*Referenced Tables Array*/
static const qmi_idl_type_table_object *SNS_SAM_MAG_CAL_SVC_qmi_idl_type_table_object_referenced_tables_v01[] =
{&SNS_SAM_MAG_CAL_SVC_qmi_idl_type_table_object_v01, &sns_common_qmi_idl_type_table_object_v01};

/*Type Table Object*/
static const qmi_idl_type_table_object SNS_SAM_MAG_CAL_SVC_qmi_idl_type_table_object_v01 = {
  sizeof(SNS_SAM_MAG_CAL_SVC_type_table_v01)/sizeof(qmi_idl_type_table_entry ),
  sizeof(SNS_SAM_MAG_CAL_SVC_message_table_v01)/sizeof(qmi_idl_message_table_entry),
  1,
  SNS_SAM_MAG_CAL_SVC_type_table_v01,
  SNS_SAM_MAG_CAL_SVC_message_table_v01,
  SNS_SAM_MAG_CAL_SVC_qmi_idl_type_table_object_referenced_tables_v01,
  NULL
};

/*Arrays of service_message_table_entries for commands, responses and indications*/
static const qmi_idl_service_message_table_entry SNS_SAM_MAG_CAL_SVC_service_command_messages_v01[] = {
  {SNS_SAM_MAG_CAL_CANCEL_REQ_V01, QMI_IDL_TYPE16(1, 0), 0},
  {SNS_SAM_MAG_CAL_VERSION_REQ_V01, QMI_IDL_TYPE16(1, 2), 0},
  {SNS_SAM_MAG_CAL_ENABLE_REQ_V01, QMI_IDL_TYPE16(0, 0), 14},
  {SNS_SAM_MAG_CAL_DISABLE_REQ_V01, QMI_IDL_TYPE16(0, 2), 4},
  {SNS_SAM_MAG_CAL_GET_REPORT_REQ_V01, QMI_IDL_TYPE16(0, 5), 4}
};

static const qmi_idl_service_message_table_entry SNS_SAM_MAG_CAL_SVC_service_response_messages_v01[] = {
  {SNS_SAM_MAG_CAL_CANCEL_RESP_V01, QMI_IDL_TYPE16(1, 1), 5},
  {SNS_SAM_MAG_CAL_VERSION_RESP_V01, QMI_IDL_TYPE16(1, 3), 17},
  {SNS_SAM_MAG_CAL_ENABLE_RESP_V01, QMI_IDL_TYPE16(0, 1), 9},
  {SNS_SAM_MAG_CAL_DISABLE_RESP_V01, QMI_IDL_TYPE16(0, 3), 9},
  {SNS_SAM_MAG_CAL_GET_REPORT_RESP_V01, QMI_IDL_TYPE16(0, 6), 44}
};

static const qmi_idl_service_message_table_entry SNS_SAM_MAG_CAL_SVC_service_indication_messages_v01[] = {
  {SNS_SAM_MAG_CAL_REPORT_IND_V01, QMI_IDL_TYPE16(0, 4), 39},
  {SNS_SAM_MAG_CAL_ERROR_IND_V01, QMI_IDL_TYPE16(0, 7), 8}
};

/*Service Object*/
struct qmi_idl_service_object SNS_SAM_MAG_CAL_SVC_qmi_idl_service_object_v01 = {
  0x06,
  0x01,
  SNS_QMI_SVC_ID_16_V01,
  44,
  { sizeof(SNS_SAM_MAG_CAL_SVC_service_command_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(SNS_SAM_MAG_CAL_SVC_service_response_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(SNS_SAM_MAG_CAL_SVC_service_indication_messages_v01)/sizeof(qmi_idl_service_message_table_entry) },
  { SNS_SAM_MAG_CAL_SVC_service_command_messages_v01, SNS_SAM_MAG_CAL_SVC_service_response_messages_v01, SNS_SAM_MAG_CAL_SVC_service_indication_messages_v01},
  &SNS_SAM_MAG_CAL_SVC_qmi_idl_type_table_object_v01,
  0x02,
  NULL
};

/* Service Object Accessor */
qmi_idl_service_object_type SNS_SAM_MAG_CAL_SVC_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version ){
  if ( SNS_SAM_MAG_CAL_SVC_V01_IDL_MAJOR_VERS != idl_maj_version || SNS_SAM_MAG_CAL_SVC_V01_IDL_MINOR_VERS != idl_min_version 
       || SNS_SAM_MAG_CAL_SVC_V01_IDL_TOOL_VERS != library_version) 
  {
    return NULL;
  } 
  return (qmi_idl_service_object_type)&SNS_SAM_MAG_CAL_SVC_qmi_idl_service_object_v01;
}

