/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.6.5, Date: 13-Nov-2013.
 * This file has been generated from 25.331V10.12.0(2013-06) ASN
 * $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/wcdma/rrc/inc/rrcasn1.h#1 $ $DateTime: 2016/12/13 08:00:12 $ $Author: mplcsds1 $
 */
#ifndef RRCASN1_H
#define RRCASN1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtpersrc/asn1per.h"

#include "rrcasn1_pdu.h"
#include "rrcasn1_ie.h"

/**
 * Header file for ASN.1 module rrcasn1
 */
/**************************************************************/
/*                                                            */
/*  DL_DCCH_MessageType                                       */
/*                                                            */
/**************************************************************/
/*
DL-DCCH-MessageType ::= CHOICE {
   activeSetUpdate [0] ActiveSetUpdate,
   assistanceDataDelivery [1] AssistanceDataDelivery,
   cellChangeOrderFromUTRAN [2] CellChangeOrderFromUTRAN,
   cellUpdateConfirm [3] CellUpdateConfirm,
   counterCheck [4] CounterCheck,
   downlinkDirectTransfer [5] DownlinkDirectTransfer,
   handoverFromUTRANCommand-GSM [6] HandoverFromUTRANCommand-GSM,
   handoverFromUTRANCommand-CDMA2000 [7] HandoverFromUTRANCommand-CDMA2000,
   measurementControl [8] MeasurementControl,
   pagingType2 [9] PagingType2,
   physicalChannelReconfiguration [10] PhysicalChannelReconfiguration,
   physicalSharedChannelAllocation [11] PhysicalSharedChannelAllocation,
   radioBearerReconfiguration [12] RadioBearerReconfiguration,
   radioBearerRelease [13] RadioBearerRelease,
   radioBearerSetup [14] RadioBearerSetup,
   rrcConnectionRelease [15] RRCConnectionRelease,
   securityModeCommand [16] SecurityModeCommand,
   signallingConnectionRelease [17] SignallingConnectionRelease,
   transportChannelReconfiguration [18] TransportChannelReconfiguration,
   transportFormatCombinationControl [19] TransportFormatCombinationControl,
   ueCapabilityEnquiry [20] UECapabilityEnquiry,
   ueCapabilityInformationConfirm [21] UECapabilityInformationConfirm,
   uplinkPhysicalChannelControl [22] UplinkPhysicalChannelControl,
   uraUpdateConfirm [23] URAUpdateConfirm,
   utranMobilityInformation [24] UTRANMobilityInformation,
   handoverFromUTRANCommand-GERANIu [25] HandoverFromUTRANCommand-GERANIu,
   mbmsModifiedServicesInformation [26] MBMSModifiedServicesInformation,
   etwsPrimaryNotificationWithSecurity [27] ETWSPrimaryNotificationWithSecurity,
   handoverFromUTRANCommand-EUTRA [28] HandoverFromUTRANCommand-EUTRA,
   ueInformationRequest [29] UEInformationRequest,
   loggingMeasurementConfiguration [30] LoggingMeasurementConfiguration,
   spare1 [31] NULL
}
*/
/* Choice tag constants */

#define T_rrc_DL_DCCH_MessageType_activeSetUpdate 1
#define T_rrc_DL_DCCH_MessageType_assistanceDataDelivery 2
#define T_rrc_DL_DCCH_MessageType_cellChangeOrderFromUTRAN 3
#define T_rrc_DL_DCCH_MessageType_cellUpdateConfirm 4
#define T_rrc_DL_DCCH_MessageType_counterCheck 5
#define T_rrc_DL_DCCH_MessageType_downlinkDirectTransfer 6
#define T_rrc_DL_DCCH_MessageType_handoverFromUTRANCommand_GSM 7
#define T_rrc_DL_DCCH_MessageType_handoverFromUTRANCommand_CDMA2000 8
#define T_rrc_DL_DCCH_MessageType_measurementControl 9
#define T_rrc_DL_DCCH_MessageType_pagingType2 10
#define T_rrc_DL_DCCH_MessageType_physicalChannelReconfiguration 11
#define T_rrc_DL_DCCH_MessageType_physicalSharedChannelAllocation 12
#define T_rrc_DL_DCCH_MessageType_radioBearerReconfiguration 13
#define T_rrc_DL_DCCH_MessageType_radioBearerRelease 14
#define T_rrc_DL_DCCH_MessageType_radioBearerSetup 15
#define T_rrc_DL_DCCH_MessageType_rrcConnectionRelease 16
#define T_rrc_DL_DCCH_MessageType_securityModeCommand 17
#define T_rrc_DL_DCCH_MessageType_signallingConnectionRelease 18
#define T_rrc_DL_DCCH_MessageType_transportChannelReconfiguration 19
#define T_rrc_DL_DCCH_MessageType_transportFormatCombinationControl 20
#define T_rrc_DL_DCCH_MessageType_ueCapabilityEnquiry 21
#define T_rrc_DL_DCCH_MessageType_ueCapabilityInformationConfirm 22
#define T_rrc_DL_DCCH_MessageType_uplinkPhysicalChannelControl 23
#define T_rrc_DL_DCCH_MessageType_uraUpdateConfirm 24
#define T_rrc_DL_DCCH_MessageType_utranMobilityInformation 25
#define T_rrc_DL_DCCH_MessageType_handoverFromUTRANCommand_GERANIu 26
#define T_rrc_DL_DCCH_MessageType_mbmsModifiedServicesInformation 27
#define T_rrc_DL_DCCH_MessageType_etwsPrimaryNotificationWithSecurity 28
#define T_rrc_DL_DCCH_MessageType_handoverFromUTRANCommand_EUTRA 29
#define T_rrc_DL_DCCH_MessageType_ueInformationRequest 30
#define T_rrc_DL_DCCH_MessageType_loggingMeasurementConfiguration 31
#define T_rrc_DL_DCCH_MessageType_spare1 32

typedef struct EXTERN rrc_DL_DCCH_MessageType {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_ActiveSetUpdate activeSetUpdate;
      /* t = 2 */
      rrc_AssistanceDataDelivery assistanceDataDelivery;
      /* t = 3 */
      rrc_CellChangeOrderFromUTRAN cellChangeOrderFromUTRAN;
      /* t = 4 */
      rrc_CellUpdateConfirm cellUpdateConfirm;
      /* t = 5 */
      rrc_CounterCheck counterCheck;
      /* t = 6 */
      rrc_DownlinkDirectTransfer downlinkDirectTransfer;
      /* t = 7 */
      rrc_HandoverFromUTRANCommand_GSM handoverFromUTRANCommand_GSM;
      /* t = 8 */
      rrc_HandoverFromUTRANCommand_CDMA2000 handoverFromUTRANCommand_CDMA2000;
      /* t = 9 */
      rrc_MeasurementControl measurementControl;
      /* t = 10 */
      rrc_PagingType2 pagingType2;
      /* t = 11 */
      rrc_PhysicalChannelReconfiguration physicalChannelReconfiguration;
      /* t = 12 */
      rrc_PhysicalSharedChannelAllocation physicalSharedChannelAllocation;
      /* t = 13 */
      rrc_RadioBearerReconfiguration radioBearerReconfiguration;
      /* t = 14 */
      rrc_RadioBearerRelease radioBearerRelease;
      /* t = 15 */
      rrc_RadioBearerSetup radioBearerSetup;
      /* t = 16 */
      rrc_RRCConnectionRelease rrcConnectionRelease;
      /* t = 17 */
      rrc_SecurityModeCommand securityModeCommand;
      /* t = 18 */
      rrc_SignallingConnectionRelease signallingConnectionRelease;
      /* t = 19 */
      rrc_TransportChannelReconfiguration transportChannelReconfiguration;
      /* t = 20 */
      rrc_TransportFormatCombinationControl transportFormatCombinationControl;
      /* t = 21 */
      rrc_UECapabilityEnquiry ueCapabilityEnquiry;
      /* t = 22 */
      rrc_UECapabilityInformationConfirm ueCapabilityInformationConfirm;
      /* t = 23 */
      rrc_UplinkPhysicalChannelControl uplinkPhysicalChannelControl;
      /* t = 24 */
      rrc_URAUpdateConfirm uraUpdateConfirm;
      /* t = 25 */
      rrc_UTRANMobilityInformation utranMobilityInformation;
      /* t = 26 */
      rrc_HandoverFromUTRANCommand_GERANIu handoverFromUTRANCommand_GERANIu;
      /* t = 27 */
      rrc_MBMSModifiedServicesInformation mbmsModifiedServicesInformation;
      /* t = 28 */
      rrc_ETWSPrimaryNotificationWithSecurity etwsPrimaryNotificationWithSecurity;
      /* t = 29 */
      rrc_HandoverFromUTRANCommand_EUTRA handoverFromUTRANCommand_EUTRA;
      /* t = 30 */
      rrc_UEInformationRequest ueInformationRequest;
      /* t = 31 */
      rrc_LoggingMeasurementConfiguration loggingMeasurementConfiguration;
      /* t = 32 */
   } u;
} rrc_DL_DCCH_MessageType;

/**************************************************************/
/*                                                            */
/*  DL_DCCH_Message                                           */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 Downlink DCCH messages

**************************************************************

DL-DCCH-Message ::= SEQUENCE {
   integrityCheckInfo [0] IntegrityCheckInfo OPTIONAL,
   message [1] DL-DCCH-MessageType
}
*/
typedef struct EXTERN rrc_DL_DCCH_Message {
   struct {
      unsigned integrityCheckInfoPresent : 1;
   } m;
   rrc_IntegrityCheckInfo integrityCheckInfo;
   rrc_DL_DCCH_MessageType message;
} rrc_DL_DCCH_Message;

/**************************************************************/
/*                                                            */
/*  UL_DCCH_MessageType_ext                                   */
/*                                                            */
/**************************************************************/
/*
UL-DCCH-MessageType-ext ::= CHOICE {
   ueInformationResponse [0] UEInformationResponse,
   spare15 [1] NULL,
   spare14 [2] NULL,
   spare13 [3] NULL,
   spare12 [4] NULL,
   spare11 [5] NULL,
   spare10 [6] NULL,
   spare9 [7] NULL,
   spare8 [8] NULL,
   spare7 [9] NULL,
   spare6 [10] NULL,
   spare5 [11] NULL,
   spare4 [12] NULL,
   spare3 [13] NULL,
   spare2 [14] NULL,
   spare1 [15] NULL
}
*/
/* Choice tag constants */

#define T_rrc_UL_DCCH_MessageType_ext_ueInformationResponse 1
#define T_rrc_UL_DCCH_MessageType_ext_spare15 2
#define T_rrc_UL_DCCH_MessageType_ext_spare14 3
#define T_rrc_UL_DCCH_MessageType_ext_spare13 4
#define T_rrc_UL_DCCH_MessageType_ext_spare12 5
#define T_rrc_UL_DCCH_MessageType_ext_spare11 6
#define T_rrc_UL_DCCH_MessageType_ext_spare10 7
#define T_rrc_UL_DCCH_MessageType_ext_spare9 8
#define T_rrc_UL_DCCH_MessageType_ext_spare8 9
#define T_rrc_UL_DCCH_MessageType_ext_spare7 10
#define T_rrc_UL_DCCH_MessageType_ext_spare6 11
#define T_rrc_UL_DCCH_MessageType_ext_spare5 12
#define T_rrc_UL_DCCH_MessageType_ext_spare4 13
#define T_rrc_UL_DCCH_MessageType_ext_spare3 14
#define T_rrc_UL_DCCH_MessageType_ext_spare2 15
#define T_rrc_UL_DCCH_MessageType_ext_spare1 16

typedef struct EXTERN rrc_UL_DCCH_MessageType_ext {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_UEInformationResponse ueInformationResponse;
      /* t = 2 */
      /* t = 3 */
      /* t = 4 */
      /* t = 5 */
      /* t = 6 */
      /* t = 7 */
      /* t = 8 */
      /* t = 9 */
      /* t = 10 */
      /* t = 11 */
      /* t = 12 */
      /* t = 13 */
      /* t = 14 */
      /* t = 15 */
      /* t = 16 */
   } u;
} rrc_UL_DCCH_MessageType_ext;

/**************************************************************/
/*                                                            */
/*  UL_DCCH_MessageType                                       */
/*                                                            */
/**************************************************************/
/*
UL-DCCH-MessageType ::= CHOICE {
   activeSetUpdateComplete [0] ActiveSetUpdateComplete,
   activeSetUpdateFailure [1] ActiveSetUpdateFailure,
   cellChangeOrderFromUTRANFailure [2] CellChangeOrderFromUTRANFailure,
   counterCheckResponse [3] CounterCheckResponse,
   handoverToUTRANComplete [4] HandoverToUTRANComplete,
   initialDirectTransfer [5] InitialDirectTransfer,
   handoverFromUTRANFailure [6] HandoverFromUTRANFailure,
   measurementControlFailure [7] MeasurementControlFailure,
   measurementReport [8] MeasurementReport,
   physicalChannelReconfigurationComplete [9] PhysicalChannelReconfigurationComplete,
   physicalChannelReconfigurationFailure [10] PhysicalChannelReconfigurationFailure,
   radioBearerReconfigurationComplete [11] RadioBearerReconfigurationComplete,
   radioBearerReconfigurationFailure [12] RadioBearerReconfigurationFailure,
   radioBearerReleaseComplete [13] RadioBearerReleaseComplete,
   radioBearerReleaseFailure [14] RadioBearerReleaseFailure,
   radioBearerSetupComplete [15] RadioBearerSetupComplete,
   radioBearerSetupFailure [16] RadioBearerSetupFailure,
   rrcConnectionReleaseComplete [17] RRCConnectionReleaseComplete,
   rrcConnectionSetupComplete [18] RRCConnectionSetupComplete,
   rrcStatus [19] RRCStatus,
   securityModeComplete [20] SecurityModeComplete,
   securityModeFailure [21] SecurityModeFailure,
   signallingConnectionReleaseIndication [22] SignallingConnectionReleaseIndication,
   transportChannelReconfigurationComplete [23] TransportChannelReconfigurationComplete,
   transportChannelReconfigurationFailure [24] TransportChannelReconfigurationFailure,
   transportFormatCombinationControlFailure [25] TransportFormatCombinationControlFailure,
   ueCapabilityInformation [26] UECapabilityInformation,
   uplinkDirectTransfer [27] UplinkDirectTransfer,
   utranMobilityInformationConfirm [28] UTRANMobilityInformationConfirm,
   utranMobilityInformationFailure [29] UTRANMobilityInformationFailure,
   mbmsModificationRequest [30] MBMSModificationRequest,
   ul-DCCH-MessageType-ext [31] UL-DCCH-MessageType-ext
}
*/
/* Choice tag constants */

#define T_rrc_UL_DCCH_MessageType_activeSetUpdateComplete 1
#define T_rrc_UL_DCCH_MessageType_activeSetUpdateFailure 2
#define T_rrc_UL_DCCH_MessageType_cellChangeOrderFromUTRANFailure 3
#define T_rrc_UL_DCCH_MessageType_counterCheckResponse 4
#define T_rrc_UL_DCCH_MessageType_handoverToUTRANComplete 5
#define T_rrc_UL_DCCH_MessageType_initialDirectTransfer 6
#define T_rrc_UL_DCCH_MessageType_handoverFromUTRANFailure 7
#define T_rrc_UL_DCCH_MessageType_measurementControlFailure 8
#define T_rrc_UL_DCCH_MessageType_measurementReport 9
#define T_rrc_UL_DCCH_MessageType_physicalChannelReconfigurationComplete 10
#define T_rrc_UL_DCCH_MessageType_physicalChannelReconfigurationFailure 11
#define T_rrc_UL_DCCH_MessageType_radioBearerReconfigurationComplete 12
#define T_rrc_UL_DCCH_MessageType_radioBearerReconfigurationFailure 13
#define T_rrc_UL_DCCH_MessageType_radioBearerReleaseComplete 14
#define T_rrc_UL_DCCH_MessageType_radioBearerReleaseFailure 15
#define T_rrc_UL_DCCH_MessageType_radioBearerSetupComplete 16
#define T_rrc_UL_DCCH_MessageType_radioBearerSetupFailure 17
#define T_rrc_UL_DCCH_MessageType_rrcConnectionReleaseComplete 18
#define T_rrc_UL_DCCH_MessageType_rrcConnectionSetupComplete 19
#define T_rrc_UL_DCCH_MessageType_rrcStatus 20
#define T_rrc_UL_DCCH_MessageType_securityModeComplete 21
#define T_rrc_UL_DCCH_MessageType_securityModeFailure 22
#define T_rrc_UL_DCCH_MessageType_signallingConnectionReleaseIndication 23
#define T_rrc_UL_DCCH_MessageType_transportChannelReconfigurationComplete 24
#define T_rrc_UL_DCCH_MessageType_transportChannelReconfigurationFailure 25
#define T_rrc_UL_DCCH_MessageType_transportFormatCombinationControlFailure 26
#define T_rrc_UL_DCCH_MessageType_ueCapabilityInformation 27
#define T_rrc_UL_DCCH_MessageType_uplinkDirectTransfer 28
#define T_rrc_UL_DCCH_MessageType_utranMobilityInformationConfirm 29
#define T_rrc_UL_DCCH_MessageType_utranMobilityInformationFailure 30
#define T_rrc_UL_DCCH_MessageType_mbmsModificationRequest 31
#define T_rrc_UL_DCCH_MessageType_ul_DCCH_MessageType_ext 32

typedef struct EXTERN rrc_UL_DCCH_MessageType {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_ActiveSetUpdateComplete activeSetUpdateComplete;
      /* t = 2 */
      rrc_ActiveSetUpdateFailure activeSetUpdateFailure;
      /* t = 3 */
      rrc_CellChangeOrderFromUTRANFailure cellChangeOrderFromUTRANFailure;
      /* t = 4 */
      rrc_CounterCheckResponse counterCheckResponse;
      /* t = 5 */
      rrc_HandoverToUTRANComplete handoverToUTRANComplete;
      /* t = 6 */
      rrc_InitialDirectTransfer initialDirectTransfer;
      /* t = 7 */
      rrc_HandoverFromUTRANFailure handoverFromUTRANFailure;
      /* t = 8 */
      rrc_MeasurementControlFailure measurementControlFailure;
      /* t = 9 */
      rrc_MeasurementReport measurementReport;
      /* t = 10 */
      rrc_PhysicalChannelReconfigurationComplete physicalChannelReconfigurationComplete;
      /* t = 11 */
      rrc_PhysicalChannelReconfigurationFailure physicalChannelReconfigurationFailure;
      /* t = 12 */
      rrc_RadioBearerReconfigurationComplete radioBearerReconfigurationComplete;
      /* t = 13 */
      rrc_RadioBearerReconfigurationFailure radioBearerReconfigurationFailure;
      /* t = 14 */
      rrc_RadioBearerReleaseComplete radioBearerReleaseComplete;
      /* t = 15 */
      rrc_RadioBearerReleaseFailure radioBearerReleaseFailure;
      /* t = 16 */
      rrc_RadioBearerSetupComplete radioBearerSetupComplete;
      /* t = 17 */
      rrc_RadioBearerSetupFailure radioBearerSetupFailure;
      /* t = 18 */
      rrc_RRCConnectionReleaseComplete rrcConnectionReleaseComplete;
      /* t = 19 */
      rrc_RRCConnectionSetupComplete rrcConnectionSetupComplete;
      /* t = 20 */
      rrc_RRCStatus rrcStatus;
      /* t = 21 */
      rrc_SecurityModeComplete securityModeComplete;
      /* t = 22 */
      rrc_SecurityModeFailure securityModeFailure;
      /* t = 23 */
      rrc_SignallingConnectionReleaseIndication signallingConnectionReleaseIndication;
      /* t = 24 */
      rrc_TransportChannelReconfigurationComplete transportChannelReconfigurationComplete;
      /* t = 25 */
      rrc_TransportChannelReconfigurationFailure transportChannelReconfigurationFailure;
      /* t = 26 */
      rrc_TransportFormatCombinationControlFailure transportFormatCombinationControlFailure;
      /* t = 27 */
      rrc_UECapabilityInformation ueCapabilityInformation;
      /* t = 28 */
      rrc_UplinkDirectTransfer uplinkDirectTransfer;
      /* t = 29 */
      rrc_UTRANMobilityInformationConfirm utranMobilityInformationConfirm;
      /* t = 30 */
      rrc_UTRANMobilityInformationFailure utranMobilityInformationFailure;
      /* t = 31 */
      rrc_MBMSModificationRequest mbmsModificationRequest;
      /* t = 32 */
      rrc_UL_DCCH_MessageType_ext ul_DCCH_MessageType_ext;
   } u;
} rrc_UL_DCCH_MessageType;

/**************************************************************/
/*                                                            */
/*  UL_DCCH_Message                                           */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 Uplink DCCH messages

**************************************************************

UL-DCCH-Message ::= SEQUENCE {
   integrityCheckInfo [0] IntegrityCheckInfo OPTIONAL,
   message [1] UL-DCCH-MessageType
}
*/
typedef struct EXTERN rrc_UL_DCCH_Message {
   struct {
      unsigned integrityCheckInfoPresent : 1;
   } m;
   rrc_IntegrityCheckInfo integrityCheckInfo;
   rrc_UL_DCCH_MessageType message;
} rrc_UL_DCCH_Message;

/**************************************************************/
/*                                                            */
/*  DL_CCCH_MessageType                                       */
/*                                                            */
/**************************************************************/
/*
DL-CCCH-MessageType ::= CHOICE {
   cellUpdateConfirm [0] CellUpdateConfirm-CCCH,
   rrcConnectionReject [1] RRCConnectionReject,
   rrcConnectionRelease [2] RRCConnectionRelease-CCCH,
   rrcConnectionSetup [3] RRCConnectionSetup,
   uraUpdateConfirm [4] URAUpdateConfirm-CCCH,
   dummy [5] ETWSPrimaryNotificationWithSecurity,
   spare2 [6] NULL,
   spare1 [7] NULL
}
*/
/* Choice tag constants */

#define T_rrc_DL_CCCH_MessageType_cellUpdateConfirm 1
#define T_rrc_DL_CCCH_MessageType_rrcConnectionReject 2
#define T_rrc_DL_CCCH_MessageType_rrcConnectionRelease 3
#define T_rrc_DL_CCCH_MessageType_rrcConnectionSetup 4
#define T_rrc_DL_CCCH_MessageType_uraUpdateConfirm 5
#define T_rrc_DL_CCCH_MessageType_dummy 6
#define T_rrc_DL_CCCH_MessageType_spare2 7
#define T_rrc_DL_CCCH_MessageType_spare1 8

typedef struct EXTERN rrc_DL_CCCH_MessageType {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_CellUpdateConfirm_CCCH cellUpdateConfirm;
      /* t = 2 */
      rrc_RRCConnectionReject rrcConnectionReject;
      /* t = 3 */
      rrc_RRCConnectionRelease_CCCH rrcConnectionRelease;
      /* t = 4 */
      rrc_RRCConnectionSetup rrcConnectionSetup;
      /* t = 5 */
      rrc_URAUpdateConfirm_CCCH uraUpdateConfirm;
      /* t = 6 */
      rrc_ETWSPrimaryNotificationWithSecurity dummy;
      /* t = 7 */
      /* t = 8 */
   } u;
} rrc_DL_CCCH_MessageType;

/**************************************************************/
/*                                                            */
/*  DL_CCCH_Message                                           */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 Downlink CCCH messages

**************************************************************

DL-CCCH-Message ::= SEQUENCE {
   integrityCheckInfo [0] IntegrityCheckInfo OPTIONAL,
   message [1] DL-CCCH-MessageType
}
*/
typedef struct EXTERN rrc_DL_CCCH_Message {
   struct {
      unsigned integrityCheckInfoPresent : 1;
   } m;
   rrc_IntegrityCheckInfo integrityCheckInfo;
   rrc_DL_CCCH_MessageType message;
} rrc_DL_CCCH_Message;

/**************************************************************/
/*                                                            */
/*  UL_CCCH_MessageType                                       */
/*                                                            */
/**************************************************************/
/*
UL-CCCH-MessageType ::= CHOICE {
   cellUpdate [0] CellUpdate,
   rrcConnectionRequest [1] RRCConnectionRequest,
   uraUpdate [2] URAUpdate,
   spare [3] NULL
}
*/
/* Choice tag constants */

#define T_rrc_UL_CCCH_MessageType_cellUpdate 1
#define T_rrc_UL_CCCH_MessageType_rrcConnectionRequest 2
#define T_rrc_UL_CCCH_MessageType_uraUpdate 3
#define T_rrc_UL_CCCH_MessageType_spare 4

typedef struct EXTERN rrc_UL_CCCH_MessageType {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_CellUpdate cellUpdate;
      /* t = 2 */
      rrc_RRCConnectionRequest rrcConnectionRequest;
      /* t = 3 */
      rrc_URAUpdate uraUpdate;
      /* t = 4 */
   } u;
} rrc_UL_CCCH_MessageType;

/**************************************************************/
/*                                                            */
/*  UL_CCCH_Message                                           */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 Uplink CCCH messages

**************************************************************

UL-CCCH-Message ::= SEQUENCE {
   integrityCheckInfo [0] IntegrityCheckInfo OPTIONAL,
   message [1] UL-CCCH-MessageType
}
*/
typedef struct EXTERN rrc_UL_CCCH_Message {
   struct {
      unsigned integrityCheckInfoPresent : 1;
   } m;
   rrc_IntegrityCheckInfo integrityCheckInfo;
   rrc_UL_CCCH_MessageType message;
} rrc_UL_CCCH_Message;

/**************************************************************/
/*                                                            */
/*  PCCH_MessageType                                          */
/*                                                            */
/**************************************************************/
/*
PCCH-MessageType ::= CHOICE {
   pagingType1 [0] PagingType1,
   spare [1] NULL
}
*/
/* Choice tag constants */

#define T_rrc_PCCH_MessageType_pagingType1 1
#define T_rrc_PCCH_MessageType_spare    2

typedef struct EXTERN rrc_PCCH_MessageType {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_PagingType1 pagingType1;
      /* t = 2 */
   } u;
} rrc_PCCH_MessageType;

/**************************************************************/
/*                                                            */
/*  PCCH_Message                                              */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 PCCH messages

**************************************************************

PCCH-Message ::= SEQUENCE {
   message [0] PCCH-MessageType
}
*/
typedef struct EXTERN rrc_PCCH_Message {
   rrc_PCCH_MessageType message;
} rrc_PCCH_Message;

/**************************************************************/
/*                                                            */
/*  BCCH_FACH_MessageType                                     */
/*                                                            */
/**************************************************************/
/*
BCCH-FACH-MessageType ::= CHOICE {
   systemInformation [0] SystemInformation-FACH,
   systemInformationChangeIndication [1] SystemInformationChangeIndication,
   spare2 [2] NULL,
   spare1 [3] NULL
}
*/
/* Choice tag constants */

#define T_rrc_BCCH_FACH_MessageType_systemInformation 1
#define T_rrc_BCCH_FACH_MessageType_systemInformationChangeIndication 2
#define T_rrc_BCCH_FACH_MessageType_spare2 3
#define T_rrc_BCCH_FACH_MessageType_spare1 4

typedef struct EXTERN rrc_BCCH_FACH_MessageType {
   OSUINT32 t;
   union {
      /* t = 1 */
      rrc_SystemInformation_FACH systemInformation;
      /* t = 2 */
      rrc_SystemInformationChangeIndication systemInformationChangeIndication;
      /* t = 3 */
      /* t = 4 */
   } u;
} rrc_BCCH_FACH_MessageType;

/**************************************************************/
/*                                                            */
/*  BCCH_FACH_Message                                         */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 BCCH messages sent on FACH

**************************************************************

BCCH-FACH-Message ::= SEQUENCE {
   message [0] BCCH-FACH-MessageType
}
*/
typedef struct EXTERN rrc_BCCH_FACH_Message {
   rrc_BCCH_FACH_MessageType message;
} rrc_BCCH_FACH_Message;

/**************************************************************/
/*                                                            */
/*  BCCH_BCH_Message                                          */
/*                                                            */
/**************************************************************/
/*
**************************************************************

 BCCH messages sent on BCH

**************************************************************

BCCH-BCH-Message ::= SEQUENCE {
   message [0] SystemInformation-BCH
}
*/
typedef struct EXTERN rrc_BCCH_BCH_Message {
   rrc_SystemInformation_BCH message;
} rrc_BCCH_BCH_Message;

#ifdef __cplusplus
}
#endif

#endif
