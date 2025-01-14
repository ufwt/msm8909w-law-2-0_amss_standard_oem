#ifndef SNS_SAM_CAL_SERVICE_01_H
#define SNS_SAM_CAL_SERVICE_01_H
/**
  @file sns_sam_cal_v01.h

  @brief This is the public header file which defines the sns_sam_cal service Data structures.

  This header file defines the types and structures that were defined in
  sns_sam_cal. It contains the constant values defined, enums, structures,
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

  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.



  $Header$
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7
   It was generated on: Thu Jul 14 2016 (Spin 0)
   From IDL File: sns_sam_cal_v01.idl */

/** @defgroup sns_sam_cal_qmi_consts Constant values defined in the IDL */
/** @defgroup sns_sam_cal_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup sns_sam_cal_qmi_enums Enumerated types used in QMI messages */
/** @defgroup sns_sam_cal_qmi_messages Structures sent as QMI messages */
/** @defgroup sns_sam_cal_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup sns_sam_cal_qmi_accessor Accessor for QMI service object */
/** @defgroup sns_sam_cal_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "sns_sam_common_v01.h"
#include "sns_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup sns_sam_cal_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define SNS_SAM_CAL_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define SNS_SAM_CAL_V01_IDL_MINOR_VERS 0x00
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define SNS_SAM_CAL_V01_IDL_TOOL_VERS 0x06

/**
    @}
  */


/** @addtogroup sns_sam_cal_qmi_consts
    @{
  */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_enums
    @{
  */
typedef enum {
  SNS_SAM_CALIBRATION_ACCURACY_E_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CAL_ACCURACY_UNRELIABLE_V01 = 0,
  CAL_ACCURACY_LOW_V01 = 1,
  CAL_ACCURACY_MEDIUM_V01 = 2,
  CAL_ACCURACY_HIGH_V01 = 3,
  SNS_SAM_CALIBRATION_ACCURACY_E_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}sns_sam_calibration_accuracy_e_v01;
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_enums
    @{
  */
typedef enum {
  SNS_SAM_CAL_UPDATE_TYPE_E_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CAL_UPDATE_RESET_V01 = 0,
  SNS_SAM_CAL_UPDATE_TYPE_E_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}sns_sam_cal_update_type_e_v01;
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Request Message; This command enables a Calibration algorithm. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}sns_sam_cal_enable_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Response Message; This command enables a Calibration algorithm. */
typedef struct {

  /* Mandatory */
  sns_common_resp_s_v01 resp;

  /* Optional */
  uint8_t instance_id_valid;  /**< Must be set to true if instance_id is being passed */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance.  */
}sns_sam_cal_enable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Request Message; This command disables a Calibration algorithm. */
typedef struct {

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance.  */
}sns_sam_cal_disable_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Response Message; This command disables a Calibration algorithm. */
typedef struct {

  /* Mandatory */
  sns_common_resp_s_v01 resp;

  /* Optional */
  uint8_t instance_id_valid;  /**< Must be set to true if instance_id is being passed */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance. */
}sns_sam_cal_disable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Indication Message; Report containing Calibration algorithm output */
typedef struct {

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance. */

  /* Mandatory */
  uint32_t timestamp;
  /**<   Timestamp of input used to generate the latest algorithm output */

  /* Mandatory */
  float bias[3];
  /**<   if Magnetometer Calibration: Bias offset in Gauss.
       if Gyroscope Calibration: Bias in radians. */

  /* Mandatory */
  sns_sam_calibration_accuracy_e_v01 accuracy;
}sns_sam_cal_report_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Indication Message; Asynchronous error indication for a calibration algorithm. */
typedef struct {

  /* Mandatory */
  uint8_t error;
  /**<   Sensor1 error code */

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance. */
}sns_sam_cal_error_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Request Message; This command updates the Calibration algorithm configuration. */
typedef struct {

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance. */

  /* Mandatory */
  sns_sam_cal_update_type_e_v01 update_type;
  /**<   Update type, 0=reset */
}sns_sam_cal_update_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup sns_sam_cal_qmi_messages
    @{
  */
/** Response Message; This command updates the Calibration algorithm configuration. */
typedef struct {

  /* Mandatory */
  sns_common_resp_s_v01 resp;

  /* Optional */
  uint8_t instance_id_valid;  /**< Must be set to true if instance_id is being passed */
  uint8_t instance_id;
  /**<   Instance ID identifies the algorithm instance.  */
}sns_sam_cal_update_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */

/*Extern Definition of Type Table Object*/
/*THIS IS AN INTERNAL OBJECT AND SHOULD ONLY*/
/*BE ACCESSED BY AUTOGENERATED FILES*/
extern const qmi_idl_type_table_object sns_sam_cal_qmi_idl_type_table_object_v01;


#ifdef __cplusplus
}
#endif
#endif

