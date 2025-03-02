#ifndef SNS_PM_SVC_SERVICE_H
#define SNS_PM_SVC_SERVICE_H
/**
  @file sns_pm_api_v01.h
  
  @brief This is the public header file which defines the SNS_PM_SVC service Data structures.

  This header file defines the types and structures that were defined in 
  SNS_PM_SVC. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were 
  defined in the IDL as messages contain mandatory elements, optional 
  elements, a combination of mandatory and optional elements (mandatory 
  always come before optionals in the structure), or nothing (null message)
   
  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to. 
   
  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:
   
  uint32_t test_opaque_len;
  uint8_t test_opaque[16];
   
  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set 
  by the decode routine and should be checked so that the correct number of 
  elements in the array will be accessed. 

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2012 Qualcomm Technologies, Inc.  All Rights Reserved. 
 Confidential and Proprietary - Qualcomm Technologies, Inc.

  $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/Sensors/common/idl/inc/sns_pm_api_v01.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====* 
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY 
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.0 
   It requires encode/decode library version 5 or later
   It was generated on: Tue Jan 15 2013 (Spin )
   From IDL File: sns_pm_api_v01.idl */

/** @defgroup SNS_PM_SVC_qmi_consts Constant values defined in the IDL */
/** @defgroup SNS_PM_SVC_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup SNS_PM_SVC_qmi_enums Enumerated types used in QMI messages */
/** @defgroup SNS_PM_SVC_qmi_messages Structures sent as QMI messages */
/** @defgroup SNS_PM_SVC_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup SNS_PM_SVC_qmi_accessor Accessor for QMI service object */
/** @defgroup SNS_PM_SVC_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "sns_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup SNS_PM_SVC_qmi_version 
    @{ 
  */ 
/** Major Version Number of the IDL used to generate this file */
#define SNS_PM_SVC_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define SNS_PM_SVC_V01_IDL_MINOR_VERS 0x02
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define SNS_PM_SVC_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define SNS_PM_SVC_V01_MAX_MESSAGE_ID 0x0002;
/** 
    @} 
  */


/** @addtogroup SNS_PM_SVC_qmi_consts 
    @{ 
  */

/**  Inactive power state: inactive state when there's no client */
#define SNS_PM_ST_INACTIVE_V01 0

/**  Active low power state: In this state when DSPS not interacting with any other processor or DDR */
#define SNS_PM_ST_ACTIVE_LOW_V01 1

/**  Active high power state: critical DSPS modules expecting high BW in this state */
#define SNS_PM_ST_ACTIVE_HIGH_V01 2
/**
    @}
  */

/** @addtogroup SNS_PM_SVC_qmi_messages
    @{
  */
/** Request Message; This command sent by client (SAM & SMGR) to place their
    active state change votes to power manager.
    SAM is expected to vote for active low/active high power states
    SMGR is expected to vote for active low/active high/hibernation states */
typedef struct {

  /* Mandatory */
  uint8_t vote_value;
  /**<   Clients like SMGR & SAM placing their vote to PM module
       Possible values are SNS_PM_ST_INACTIVE, SNS_PM_ST_ACTIVE_LOW, and SNS_PM_ST_ACTIVE_HIGH
  */

  /* Mandatory */
  uint8_t module_id;
  /**<   Clients module ID
  */
}sns_pm_active_pwr_st_change_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup SNS_PM_SVC_qmi_messages
    @{
  */
/** Response Message; This command sent by client (SAM & SMGR) to place their
    active state change votes to power manager.
    SAM is expected to vote for active low/active high power states
    SMGR is expected to vote for active low/active high/hibernation states */
typedef struct {

  /* Mandatory */
  sns_common_resp_s_v01 resp;
  /**<   
    Giving a feedback(ack.nack) to the Clients (SMGR, SAM)
  */
}sns_pm_active_pwr_st_change_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup SNS_PM_SVC_qmi_messages
    @{
  */
/** Indication Message; This command sent by client (SAM & SMGR) to place their
    active state change votes to power manager.
    SAM is expected to vote for active low/active high power states
    SMGR is expected to vote for active low/active high/hibernation states */
typedef struct {

  /* Mandatory */
  uint8_t curr_active_state;
  /**<   
    Current active state of DSPS
  */
}sns_pm_active_pwr_st_change_ind_msg_v01;  /* Message */
/**
    @}
  */

/*Service Message Definition*/
/** @addtogroup SNS_PM_SVC_qmi_msg_ids
    @{
  */
#define SNS_PM_CANCEL_REQ_V01 0x0000
#define SNS_PM_CANCEL_RESP_V01 0x0000
#define SNS_PM_VERSION_REQ_V01 0x0001
#define SNS_PM_VERSION_RESP_V01 0x0001
#define SNS_PM_ACTIVE_PWR_ST_CHANGE_REQ_V01 0x0002
#define SNS_PM_ACTIVE_PWR_ST_CHANGE_RESP_V01 0x0002
#define SNS_PM_ACTIVE_PWR_ST_CHANGE_IND_V01 0x0002
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor 
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro SNS_PM_SVC_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type SNS_PM_SVC_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );
 
/** This macro should be used to get the service object */ 
#define SNS_PM_SVC_get_service_object_v01( ) \
          SNS_PM_SVC_get_service_object_internal_v01( \
            SNS_PM_SVC_V01_IDL_MAJOR_VERS, SNS_PM_SVC_V01_IDL_MINOR_VERS, \
            SNS_PM_SVC_V01_IDL_TOOL_VERS )
/** 
    @} 
  */


#ifdef __cplusplus
}
#endif
#endif

