#ifndef OTDT_SERVICE_01_H
#define OTDT_SERVICE_01_H
/**
  @file on_target_data_test_v01.h
  
  @brief This is the public header file which defines the otdt service Data structures.

  This header file defines the types and structures that were defined in 
  otdt. It contains the constant values defined, enums, structures,
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
  Copyright (c) 2012-2013 Qualcomm Technologies, Inc.
 All rights reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.



  $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/qmimsgs/otdt/api/on_target_data_test_v01.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====* 
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY 
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.5 
   It was generated on: Sun Sep 29 2013 (Spin 2)
   From IDL File: on_target_data_test_v01.idl */

/** @defgroup otdt_qmi_consts Constant values defined in the IDL */
/** @defgroup otdt_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup otdt_qmi_enums Enumerated types used in QMI messages */
/** @defgroup otdt_qmi_messages Structures sent as QMI messages */
/** @defgroup otdt_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup otdt_qmi_accessor Accessor for QMI service object */
/** @defgroup otdt_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup otdt_qmi_version 
    @{ 
  */ 
/** Major Version Number of the IDL used to generate this file */
#define OTDT_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define OTDT_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define OTDT_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define OTDT_V01_MAX_MESSAGE_ID 0x0022
/** 
    @} 
  */


/** @addtogroup otdt_qmi_consts 
    @{ 
  */
#define TEST_GROUP_MAX_LENGTH_V01 32
/**
    @}
  */

/** @addtogroup otdt_qmi_enums
    @{
  */
typedef enum {
  OTDT_TASK_PRIORITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTDT_PRIORITY_DEFAULT_V01 = 0, /**<  Default priority (must be 0)         */
  OTDT_PRIORITY_ABOVE_DS_TASK_V01 = 1, /**<  Higher priority than DS task         */
  OTDT_PRIORITY_BELOW_DS_TASK_V01 = 2, /**<  Lower priority than DS task          */
  OTDT_PRIORITY_ABOVE_QMI_MODEM_TASK_V01 = 3, /**<  Higher priority than QMI MODEM task  */
  OTDT_PRIORITY_BELOW_QMI_MODEM_TASK_V01 = 4, /**<  Lower priority than QMI MODEM task   */
  OTDT_PRIORITY_ABOVE_DCC_TASK_V01 = 5, /**<  Higher priority than DCC task        */
  OTDT_PRIORITY_BELOW_DCC_TASK_V01 = 6, /**<  Lower priority than DCC task         */
  OTDT_PRIORITY_ABOVE_DS_SIG_TASK_V01 = 7, /**<  Higher priority than DS SIG task     */
  OTDT_PRIORITY_BELOW_DS_SIG_TASK_V01 = 8, /**<  Lower priority than DS SIG task      */
  OTDT_PRIORITY_ABOVE_PS_TASK_V01 = 9, /**<  Higher priority than PS task         */
  OTDT_PRIORITY_BELOW_PS_TASK_V01 = 10, /**<  Lower priority than PS task          */
  OTDT_PRIORITY_ENUM_MAX_V01 = 11, /**<  Last value of enum                   */
  OTDT_TASK_PRIORITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}otdt_task_priority_enum_v01;
/**
    @}
  */

/** @addtogroup otdt_qmi_messages
    @{
  */
/** Request Message; This command starts a DS test application. */
typedef struct {

  /* Mandatory */
  /*  Test group name */
  char test_group[TEST_GROUP_MAX_LENGTH_V01 + 1];

  /* Mandatory */
  /*  Test number in group */
  uint32_t test_number;

  /* Optional */
  /*  Task priority for the test to be run */
  uint8_t task_priority_valid;  /**< Must be set to true if task_priority is being passed */
  otdt_task_priority_enum_v01 task_priority;
}otdt_start_test_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup otdt_qmi_messages
    @{
  */
/** Response Message; This command starts a DS test application. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type*/
}otdt_start_test_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef struct {
  /* This element is a placeholder to prevent the declaration of 
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}otdt_stop_test_req_msg_v01;

/** @addtogroup otdt_qmi_messages
    @{
  */
/** Response Message; This command stops a DS test application, if running. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type*/
}otdt_stop_test_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup otdt_qmi_enums
    @{
  */
typedef enum {
  OTDT_TEST_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTDT_TEST_SUCCESS_V01 = 0, /**<  Test ended with success.                          */
  OTDT_TEST_STOPPED_V01 = 1, /**<  Test has stopped. @SEE QMI_OTDT_STOP_TEST         */
  OTDT_TEST_FAIL_V01 = 2, /**<  Test ended with failure. @SEE dss_errno           */
  OTDT_TEST_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}otdt_test_status_enum_v01;
/**
    @}
  */

/** @addtogroup otdt_qmi_messages
    @{
  */
/** Indication Message; This indication represent the test result */
typedef struct {

  /* Mandatory */
  /*  Test group name */
  char test_group[TEST_GROUP_MAX_LENGTH_V01 + 1];

  /* Mandatory */
  /*  Test number in group */
  uint32_t test_number;

  /* Mandatory */
  /*  Test Result */
  otdt_test_status_enum_v01 test_result;
  /**<   Result Code.
                                                    - OTDT_TEST_SUCCESS
                                                    - OTDT_TEST_STOPPED
                                                    - OTDT_TEST_FAIL (with dss_errno)
                                                */

  /* Optional */
  /*  DSS Errno */
  uint8_t dss_errno_valid;  /**< Must be set to true if dss_errno is being passed */
  int32_t dss_errno;
  /**<   Optional errno. It contains dss_errno as 
                                 described in dserrno.h or (-1) which 
                                 indicates that the test was expecting a
                                 callback and a timeout occured.
                             */
}otdt_test_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/*Service Message Definition*/
/** @addtogroup otdt_qmi_msg_ids
    @{
  */
#define QMI_OTDT_START_TEST_REQ_V01 0x0020
#define QMI_OTDT_START_TEST_RESP_V01 0x0020
#define QMI_OTDT_STOP_TEST_REQ_V01 0x0021
#define QMI_OTDT_STOP_TEST_RESP_V01 0x0021
#define QMI_OTDT_TEST_STATUS_IND_V01 0x0022
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor 
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro otdt_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type otdt_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );
 
/** This macro should be used to get the service object */ 
#define otdt_get_service_object_v01( ) \
          otdt_get_service_object_internal_v01( \
            OTDT_V01_IDL_MAJOR_VERS, OTDT_V01_IDL_MINOR_VERS, \
            OTDT_V01_IDL_TOOL_VERS )
/** 
    @} 
  */


#ifdef __cplusplus
}
#endif
#endif

