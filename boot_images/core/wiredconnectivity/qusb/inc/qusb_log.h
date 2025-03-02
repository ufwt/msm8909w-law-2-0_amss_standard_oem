/*=======================================================================*//**
 * @file        qusb_log.h
 * @author:     shreyasr
 * @date        13-Mar-2012
 *
 * @brief       QUSB (Qualcomm High-Speed USB) Logging implementation.
 *
 * @details     This file contains the implementation of the APIs to be used by
 *              the boot Sahara downloader.
 *
 * @note        
 *
 *              Copyright 2012 Qualcomm Technologies Incorporated.
 *              All Rights Reserved.
 *              Qualcomm Confidential and Proprietary
 * 
*//*========================================================================*/


// ===========================================================================
// 
//                            EDIT HISTORY FOR FILE
//   This section contains comments describing changes made to the module.
//   Notice that changes are listed in reverse chronological order.
// 
// $Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/wiredconnectivity/qusb/inc/qusb_log.h#1 $ 
// $DateTime: 2015/09/01 00:30:35 $ $Author: pwbldsvc $
// 
// when         who        what, where, why
// --------     ---        ----------------------------------------------------------
// 06/13/12   shreyasr 		Initial revision
//
// ===========================================================================

#ifndef _QUSB_LOG__H_
#define _QUSB_LOG__H_

#include "comdef.h" 

#define QUSB_GENERIC_LOG_SIZE       256
#define QUSB_BUS_LOG_SIZE           256
#define QUSB_ERROR_LOG_SIZE         64

//This enumerated type must end with a suffix _LOG 
typedef enum
{
  QUSB_DEFAULT_LOG = 0x0,

  //AL Layer Logs 
  AL_BULK_RECEIVE_ZLP_LOG,
  AL_BULK_HANDLE_RX_ZLP_MODE_LOG,
  AL_BULK_RX_COMPLETE_LOG,
  AL_BULK_ZLP_ARRIVED_LOG,
  AL_BULK_SHORT_PACKET_RECVD_LOG,
  TRANSFER_DONE_LOG,
  TRANSFER_ERROR_LOG,
  AL_BULK_DATA_RECVD_INSTEAD_OF_ZLP_LOG,
  AL_BULK_RX_CB_RX_DONE_LOG,
  AL_BULK_RX_CB_SHORT_PACKET_LOG,
  AL_BULK_RX_MORE_DATA_LOG,
  AL_BULK_TX_COMPLETE_LOG,
  AL_ENUM_COMPLETE_LOG,
  AL_BULK_INIT_ENTRY_LOG,
  AL_BULK_INIT_EXIT_LOG,
  AL_BULK_SHUTDOWN_LOG,
  AL_BULK_RECEIVE_LOG,
  AL_BULK_RX_ZLP_COPY_LOG,
  AL_BULK_TRANSMIT_LOG,
  SNPS_CONTROLLER_ENUM_COMPLETE_LOG,
  TRANSFER_LENGTH_LOG,
  AL_BULK_ERR_WRITE_LOG,
  AL_BULK_RX_CB_NO_ZLP_BUT_SHORT_PACKET_LOG,
  AL_DISCONNECT_HANDLER_LOG,
  AL_NULL_POINTER_ERROR_LOG,
  AL_BULK_SET_ZLP_MODE_LOG,

  //DCD Layer Logs 
  DCD_UPDATE_PACKET_SIZE_LOG,
  DCD_NOTIFY_LOG,
  DCD_SET_INTERFACE_LOG,
  DCD_SET_CONFIG_LOG,
  DCD_CONTROL_TRANSFER_RX_LOG,
  DCD_CONTROL_TRANSFER_TX_LOG,
  DCD_CH9_NULL_POINTER_ERROR_LOG,

  //Get Descriptor logs 
  HANDLE_GET_DESCRIPTOR_LOG,
  HANDLE_GET_DESCRIPTOR_DEVICE_LOG,
  HANDLE_GET_DESCRIPTOR_CONFIG_LOG,
  HANDLE_GET_DESCRIPTOR_BOS_LOG,
  HANDLE_GET_DESCRIPTOR_STRING_LOG,
  HANDLE_GET_DESCRIPTOR_DEVQUAL_LOG,
  UNKNOWN_GET_DESCRIPTOR_RECEIVED_LOG,

  //Setup device logs 
  HANDLE_SETUP_DEV_LOG,
  HANDLE_SETUP_DEV_GET_STATUS_LOG,
  HANDLE_SETUP_DEV_CLEAR_FEATURE_LOG,
  HANDLE_SETUP_DEV_SET_FEATURE_LOG,
  HANDLE_SETUP_DEV_SET_ADDRESS_LOG,
  HANDLE_SETUP_DEV_SET_SEL_LOG,
  HANDLE_SETUP_DEV_SET_ISOCH_DELAY_LOG,
  HANDLE_SETUP_DEV_GET_DESCRIPTOR_LOG,
  HANDLE_SETUP_DEV_SET_DESCRIPTOR_LOG,
  HANDLE_SETUP_DEV_GET_CONFIGURATION_LOG,
  HANDLE_SETUP_DEV_SET_CONFIGURATION_LOG,

  HANDLE_SETUP_IFC_LOG,
  HANDLE_SETUP_IFC_GET_STATUS_LOG,
  HANDLE_SETUP_IFC_CLEAR_FEATURE_LOG,
  HANDLE_SETUP_IFC_SET_FEATURE_LOG,
  HANDLE_SETUP_IFC_GET_INTERFACE_LOG,
  HANDLE_SETUP_IFC_SET_INTERFACE_LOG,
  CALL_SETUP_HANDLER_FOR_IFC_LOG,

  HANDLE_EP_HALT_LOG,
  EP_COMMAND_COMPLETE_LOG,

  HANDLE_SETUP_EP_LOG,
  HANDLE_SETUP_EP_GET_STATUS_LOG,
  HANDLE_SETUP_EP_CLEAR_FEATURE_LOG,
  HANDLE_SETUP_EP_SET_FEATURE_LOG,
  HANDLE_SETUP_EP_REQ_SYNCH_FRAME_LOG,
  CALL_SETUP_HANDLER_FOR_EP_LOG,

  //Control State machine logs
  CTRL_XFER_STATE_OFFSET,
  CTRL_XFER_STATE_NORMAL_LOG,
  CTRL_XFER_STATE_SETUP_LOG,
  CTRL_XFER_STATE_STATUS_2_LOG,
  CTRL_XFER_STATE_STATUS_3_LOG,
  CTRL_XFER_STATE_DATA_LOG,
  XFER_COMPLETE_SETUP_LOG,
  XFER_COMPLETE_STATUS_LOG,
  XFER_COMPLETE_DATA_LOG,
  XFER_NOT_READY_LOG,
  XFER_NOT_READY_IN_SETUP_STAGE_ERROR_LOG,
  XFER_NOT_READY_DATA_LOG,
  XFER_NOT_READY_INCORRECT_DIR_ERROR_LOG,
  XFER_NOT_READY_STATUS_IN_DATA_STAGE_ERROR_LOG,
  XFER_NOT_READY_STATUS2_LOG,
  XFER_NOT_READY_DATA_IN_STATUS2_STAGE_ERROR_LOG,
  XFER_NOT_READY_INCORRECT_DIR_STATUS2_ERROR_LOG,
  XFER_NOT_READY_STATUS3_LOG,
  XFER_NOT_READY_DATA_IN_STATUS3_STAGE_ERROR_LOG,
  XFER_NOT_READY_INCORRECT_DIR_STATUS3_ERROR_LOG,
  XFER_COMPLETE_NOT_EXPECTED_IN_EP0_STATE_DATA_LOG,
  XFER_NOT_READY_DATA_STILL_IN_PROGRESS_LOG,
  INVALID_EVENT_STATUS_ERROR_LOG,

  ENUM_COMPLETE_LOG,
  ENUM_FAILED_TIMEOUT_LOG,

  DCD_CALLBACK_RESET_LOG,
  DCD_CALLBACK_DISCONNECT_LOG,
  DCD_CALLBACK_SUSPEND_LOG,
  DCD_CALLBACK_SETUP_LOG,
  DCD_PORT_STATUS_CHANGED_LOG,
  DCD_INIT_LOG,
  DCD_SHUTDOWN_LOG,
  DCD_SUBMIT_URB_ERROR_LOG,
  DCD_URB_ACTIVE_LOG,
  DCD_UNSUPPORTED_SETUP_REQUEST_LOG,

  //DCI logs 
  DCI_INIT_LOG,
  DCI_INIT_ERROR_LOG,
  DCI_CORE_INIT_LOG,
  DCI_EVENT_BUFFER_INIT_LOG,
  DCI_EVENT_BUFFER_RESTORE_LOG,
  DCI_SET_RUN_STOP_LOG,
  DCI_GET_XFER_RSC_INDEX_LOG,
  DCI_HANDLE_DEV_EVENT_LOG,
  DCI_HANDLE_USB_RESET_LOG,
  DCI_HANDLE_CONNECT_DONE_LOG,
  DCI_HANDLE_USB_DISCONNECT_LOG,
  DCI_GET_LINK_STATE_LOG,
  DCI_HANDLE_LINK_STATUS_CHANGE_LOG,
  DCI_HANDLE_SUSPEND_ENTRY_LOG,
  DCI_HANDLE_WAKEUP_LOG,
  DCI_SET_ADDRESS_LOG,
  DCI_STALL_ENDPOINT_LOG,
  DCI_UNSTALL_ENDPOINT_LOG,
  DCI_CONFIG_ENDPOINT_LOG,
  DCI_UNCONFIG_ENDPOINT_LOG,
  DCI_TRANSFER_DATA_REQUEST_LOG,
  DCI_TRANSFER_REQUEST_LOG,
  DCI_CTRL_XFER_TO_HW_LOG,
  DCI_PREPARE_TRB_LOG,
  DCI_PREPARE_TRB_ZLP_LOG,
  DCI_CANCEL_TRANSFER_LOG,
  DCI_SHUTDOWN_LOG,
  DCI_GET_SPEED_LOG,
  DCI_SET_MAX_PACKET_SIZE_LOG,
  DCI_GET_MAX_PACKET_SIZE_LOG,
  DCI_HANDLE_SET_SELECT_LOG,
  DCI_ERRATIC_ERROR_EVENT_LOG,
  DCI_EVT_BUFFER_OVERFLOW_EVENT_LOG,
  DCI_TRANSFER_SIZE_TOO_LARGE_LOG,
  DCI_DEV_CMD_ACTIVE_ERROR_LOG,
  DCI_DEV_CMD_INVALID_ERROR_LOG,
  DCI_EP_CMD_ACTIVE_ERROR_LOG,
  DCI_EP_CMD_INVALID_ERROR_LOG,
  DCI_UNSUPPORTED_SPEED_LOG,
  DCI_EN_CLK_FAIL_LOG,
  DCI_EN_PWR_FAIL_LOG,
  DCI_ASSERT_LOG,
  DCI_SKIP_ENUMERATION_LOG,
  SINGLE_BOOT_ENUM_MAGIC_DL_LOG,

  //FD Layer logs 
  HDLC_INIT_RX_LOG,
  HDLC_NOTIFY_CB_LOG,
  HDLC_TX_CALLBACK_LOG,
  HDLC_RX_CALLBACK_LOG,
  FD_HDLC_INIT_LOG,
  FD_HDLC_IS_TX_ACTIVE_LOG,
  FD_HDLC_RX_COMPLETED_LOG,
  FD_HDLC_UPDATE_VID_PID_LOG,
  FD_HDLC_GET_VID_PID_LOG,
  FD_HDLC_SHUTDOWN_LOG,
  NOTIFY_EVT_CFG_LOG,
  NOTIFY_EVT_SPEED_LOG,
  NOTIFY_EVT_DISCONNECT_LOG,
  NOTIFY_EVT_SUSPEND_LOG,
  HDLC_RX_CALLBACK_ACTUAL_LENGTH_LOG,
  HDLC_RX_CALLBACK_TRANSFER_LENGTH_LOG,
  FD_HDLC_SET_CORE_LOG,
  FD_HDLC_TX_PKT_LOG,
  FD_HDLC_RX_PKT_LOG,
  SUBMIT_RX_URB_LOG,
  FD_NULL_POINTER_ERROR_LOG,
  FD_CORE_ID_WRONG_LOG,
  FD_TX_BYTE_LOG,
  FD_SET_BUFFER_MODE_LOG,
  RX_CALLBACK_INT_BUF_MODE_LOG,
  RX_COMPLETED_INT_BUF_MODE_LOG,
  
  //Cfg Log 
  QUSB_DCI_HWIO_REG_ARRAY_PROCESS__START_LOG,
  QUSB_DCI_HWIO_REG_ARRAY_PROCESS____END_LOG,
  QUSB_DCI_HWIO_REG_ARRAY_PROCESS__FAIL_LOG,
  QUSB_DCI_PHY_REG_ARRAY_PROCESS__START_LOG,
  QUSB_DCI_PHY_REG_ARRAY_PROCESS____END_LOG,
  QUSB_DCI_PHY_REG_ARRAY_PROCESS__FAIL_LOG,
  INVALID_QUSB_DCI_SS_PHY_FOUNDRY_ID_LOG,

  //DCI Initialization Path Log 
  QUSB_DCI_SELECT_UTMI_CLK_LOG,
  QUSB_SS_PHY_INIT_LOG,
  QUSB_SNPS_SWITCH_PIPE_CLOCK_LOG,

  //Error Logs 
  DCI_ERROR_LOG,
  AL_BULK_RECEIVE_ZLP_ERROR_LOG,
  DCI_SS_PHY_RESET_ERROR_LOG,
  GET_XFER_RSC_INDEX_ERROR_LOG,
  DCI_RESET_DEVICE_ERROR_LOG,
  DCI_EVENT_ERROR_LOG,
  DCI_CONFIG_EP_WRITE_EP_CMD_ERROR_LOG,
  DCI_SUBMIT_TRB_DATA_WRITE_EP_CMD_ERROR_LOG,
  DCI_CANCEL_TRANSFER_WRITE_EP_CMD_ERROR_LOG,
  DCI_CORE_INIT_WRITE_EP_CMD_ERROR_LOG,
  DCI_HANDLE_CONNECT_DONE_WRITE_EP_CMD_ERROR_LOG,
  DCI_CANCEL_TRANSFER_URB_NULL_ERROR_LOG,
  DCI_HANDLE_TRANSFER_COMPLETE_URB_PTR_NULL_ERROR_LOG,
  DCI_NULL_POINTER_ERROR_LOG,
  DCI_MEMORY_OUT_OF_BOUNDS_ERROR_LOG,
  ZLP_TIMEOUT_ERROR_LOG,
  HLOS_PASSED_NULL_BUFFER_PORT_HOP_LOG,
  DLOAD_INFO_POINTER_NULL_LOG,
  QUSB_PIPE_CLK_SWITCH_ERROR_LOG,
  QUSB_SS_PHY_PRESENT,
  
  //HostDL and EHOSTDL Logs
  HOSTDL_DO_USB_CHECK_LOG,
  HOSTDL_USB_TRANSMIT_BYTE_LOG,
  HOSTDL_USB_DRAIN_LOG,
  HOSTDL_USB_ACTIVE_LOG,
  HOSTDL_AP_RX_COMPLETE_LOG,
  HOSTDL_USB_INIT_SUCCESS_LOG,
  HOSTDL_USB_INIT_LOG,
  HOSTDL_USB_INIT_FAILED_LOG,
  HOSTDL_USB_DEINIT_LOG,
  
  //timer logs 
  QUSB_QTIMER_IS_ALREADY_RUNNING_LOG, 
  QUSB_START_TIMER_LOG,
  QUSB_STOP_TIMER_LOG,
  QUSB_CHECK_QTIMER_FOR_EXPIRY_LOG,
  
  //Forced download logs
  QUSB_SKIP_PBL_DLOAD_LOG, 
  QUSB_ENTER_PBL_DLOAD_LOG,
  
  //Fast Enum Logs
  FAST_ENUM_NULL_PTR_ERROR_LOG,
  QUSB_AL_FAST_ENUM_INIT_LOG,
  QUSB_AL_FAST_ENUM_SHUTDOWN_LOG,
  QUSB_AL_DO_FAST_ENUM_LOG, 
  QUSB_AL_DO_FAST_ENUM_UNSUPPORTED_LOG,
  FD_FAST_ENUM_INIT_LOG,
  FD_FAST_ENUM_SHUTDOWN_LOG,

}qusb_log_enum;

typedef struct 
{
  uint16 idx;
  qusb_log_enum id_0;
  uint32 param;
} qusb_generic_log_entry;

typedef struct 
{
  uint16 idx;
  qusb_log_enum id_0;
  uint32 param;
} qusb_bus_log_entry;

typedef struct 
{
  uint16 idx;
  qusb_log_enum id_0;
  uint32 param;
} qusb_error_log_entry;

typedef struct
{
  uint16 seq_num; 
  uint16 generic_buffer_index; 
  uint16 bus_buffer_index;
  uint16 error_buffer_index;
  qusb_generic_log_entry generic_log[QUSB_GENERIC_LOG_SIZE];
  qusb_bus_log_entry     bus_log[QUSB_BUS_LOG_SIZE];
  qusb_error_log_entry   error_log[QUSB_ERROR_LOG_SIZE];
}qusb_log_type;

void qusb_log(qusb_log_enum id_0, uint8 offset, uint32 param);
void qusb_bus_log(qusb_log_enum id_0, uint8 offset, uint32 param);
void qusb_error_log(qusb_log_enum id_0, uint8 offset, uint32 param);

#endif /*QUSB_LOG_H*/
