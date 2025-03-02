/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                        S N S _ P M _ A P I _ V 0 1  . C

GENERAL DESCRIPTION
  This is the file which defines the SNS_PM_SVC service Data structures.

  Copyright (c) 2012 Qualcomm Technologies, Inc.  All Rights Reserved. 
 Confidential and Proprietary - Qualcomm Technologies, Inc.

  $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/Sensors/common/idl/src/sns_pm_api_v01.c#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====* 
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY 
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.0 
   It requires encode/decode library version 5 or later
   It was generated on: Tue Jan 15 2013 (Spin )
   From IDL File: sns_pm_api_v01.idl */

#include "stdint.h"
#include "qmi_idl_lib_internal.h"
#include "sns_pm_api_v01.h"
#include "sns_common_v01.h"


/*Type Definitions*/
/*Message Definitions*/
static const uint8_t sns_pm_active_pwr_st_change_req_msg_data_v01[] = {
  0x01,
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_pm_active_pwr_st_change_req_msg_v01, vote_value),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_pm_active_pwr_st_change_req_msg_v01, module_id)
};

static const uint8_t sns_pm_active_pwr_st_change_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(sns_pm_active_pwr_st_change_resp_msg_v01, resp),
  0, 1
};

static const uint8_t sns_pm_active_pwr_st_change_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(sns_pm_active_pwr_st_change_ind_msg_v01, curr_active_state)
};

/* Type Table */
/* No Types Defined in IDL */

/* Message Table */
static const qmi_idl_message_table_entry SNS_PM_SVC_message_table_v01[] = {
  {sizeof(sns_pm_active_pwr_st_change_req_msg_v01), sns_pm_active_pwr_st_change_req_msg_data_v01},
  {sizeof(sns_pm_active_pwr_st_change_resp_msg_v01), sns_pm_active_pwr_st_change_resp_msg_data_v01},
  {sizeof(sns_pm_active_pwr_st_change_ind_msg_v01), sns_pm_active_pwr_st_change_ind_msg_data_v01}
};

/* Predefine the Type Table Object */
static const qmi_idl_type_table_object SNS_PM_SVC_qmi_idl_type_table_object_v01;

/*Referenced Tables Array*/
static const qmi_idl_type_table_object *SNS_PM_SVC_qmi_idl_type_table_object_referenced_tables_v01[] =
{&SNS_PM_SVC_qmi_idl_type_table_object_v01, &sns_common_qmi_idl_type_table_object_v01};

/*Type Table Object*/
static const qmi_idl_type_table_object SNS_PM_SVC_qmi_idl_type_table_object_v01 = {
  0,
  sizeof(SNS_PM_SVC_message_table_v01)/sizeof(qmi_idl_message_table_entry),
  1,
  NULL,
  SNS_PM_SVC_message_table_v01,
  SNS_PM_SVC_qmi_idl_type_table_object_referenced_tables_v01
};

/*Arrays of service_message_table_entries for commands, responses and indications*/
static const qmi_idl_service_message_table_entry SNS_PM_SVC_service_command_messages_v01[] = {
  {SNS_PM_CANCEL_REQ_V01, QMI_IDL_TYPE16(1, 0), 0},
  {SNS_PM_VERSION_REQ_V01, QMI_IDL_TYPE16(1, 2), 0},
  {SNS_PM_ACTIVE_PWR_ST_CHANGE_REQ_V01, QMI_IDL_TYPE16(0, 0), 8}
};

static const qmi_idl_service_message_table_entry SNS_PM_SVC_service_response_messages_v01[] = {
  {SNS_PM_CANCEL_RESP_V01, QMI_IDL_TYPE16(1, 1), 5},
  {SNS_PM_VERSION_RESP_V01, QMI_IDL_TYPE16(1, 3), 17},
  {SNS_PM_ACTIVE_PWR_ST_CHANGE_RESP_V01, QMI_IDL_TYPE16(0, 1), 5}
};

static const qmi_idl_service_message_table_entry SNS_PM_SVC_service_indication_messages_v01[] = {
  {SNS_PM_ACTIVE_PWR_ST_CHANGE_IND_V01, QMI_IDL_TYPE16(0, 2), 4}
};

/*Service Object*/
struct qmi_idl_service_object SNS_PM_SVC_qmi_idl_service_object_v01 = {
  0x05,
  0x01,
  SNS_QMI_SVC_ID_1_V01,
  17,
  { sizeof(SNS_PM_SVC_service_command_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(SNS_PM_SVC_service_response_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(SNS_PM_SVC_service_indication_messages_v01)/sizeof(qmi_idl_service_message_table_entry) },
  { SNS_PM_SVC_service_command_messages_v01, SNS_PM_SVC_service_response_messages_v01, SNS_PM_SVC_service_indication_messages_v01},
  &SNS_PM_SVC_qmi_idl_type_table_object_v01,
  0x02,
  NULL
};

/* Service Object Accessor */
qmi_idl_service_object_type SNS_PM_SVC_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version ){
  if ( SNS_PM_SVC_V01_IDL_MAJOR_VERS != idl_maj_version || SNS_PM_SVC_V01_IDL_MINOR_VERS != idl_min_version 
       || SNS_PM_SVC_V01_IDL_TOOL_VERS != library_version) 
  {
    return NULL;
  } 
  return (qmi_idl_service_object_type)&SNS_PM_SVC_qmi_idl_service_object_v01;
}

