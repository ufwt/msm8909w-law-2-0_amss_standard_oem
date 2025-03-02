#ifndef __VSS_IMVM_PRIVATE_IF_H__
#define __VSS_IMVM_PRIVATE_IF_H__

/*
   Copyright (C) 2009-2013 QUALCOMM Technologies Incorporated.
   All rights reserved.
   Qualcomm Confidential and Proprietary

   $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/avs/vsd/inc/private/vss_imvm_private_if.h#1 $
   $Author: mplcsds1 $
*/

#include "apr_comdef.h"
#include "vss_common_public_if.h"

/****************************************************************************
 * CONCURRENCY MONITORING APIS                                              *
 ****************************************************************************/

/**
  Event generated by an MVM session to the CCM indicating that MVM is going
  to voice session active state.
 
  @par Payload
  #vss_imvm_evt_voice_active_t
  
  @return 
  None.

  @dependencies
  None.
 
  @comments
  This event informs the CCM of the current configuration of the MVM session
  (i.e. the number of nb/wb+ streams/vocproc connected to it). In response to
  this event the CCM performs the following two actions:
 
    1. Sets the VDSP clock.
 
    2. Broadcasts #VSS_ICCM_EVT_ACTIVE_SESSIONS event to all the currently
       active MVM sessions in the system (including the one that originated
       this event), informing them of the total number of streams and vocprocs
       in the system as well as the current VDSP clock.
 
   Based on the concurency information received in the #VSS_ICCM_EVT_ACTIVE_SESSIONS
   event, each MVM session configures the voice path timing offsets for the
   streams and vocprocs connected to it.
*/
#define VSS_IMVM_EVT_VOICE_SESSION_ACTIVE ( 0x00012E6B )

/** @brief Type definition for #vss_imvm_evt_voice_session_active_t.
*/
typedef struct vss_imvm_evt_voice_session_active_t vss_imvm_evt_voice_session_active_t;

#include "apr_pack_begin.h"

/** @brief Payload structure for the #VSS_IMVM_EVT_VOICE_SESSION_ACTIVE event.
*/
struct vss_imvm_evt_voice_session_active_t
{
  uint16_t num_nb_streams;
    /**< Number of narrow-band (8 KHz) streams connected to this MVM session. */
  uint16_t num_wb_plus_streams;
    /**< Number of wide-band (16 KHz) or higher streams connected to this MVM 
         session. */
  uint16_t num_nb_vocprocs;
    /**< Number of narrow-band (8 KHz) vocprocs connected to this MVM session. */
  uint16_t num_wb_plus_vocprocs;
    /**< Number of wide-band (16 Khz) or higher vocprocs connected to this MVM 
         session. */
  uint32_t total_kpps;
    /**< Total number of KPPS for all the streams and vocprocs connected to this 
         MVM session. */
  uint32_t tx_topology_id;
    /**< The TX vocproc topology ID connected to this MVM session. This paramter 
         is ignored if more than one vocproc is connected to the MVM. */
  uint32_t rx_topology_id;
    /**< The RX vocproc topology ID connected to this MVM session. This parameter 
         is ignored if more than one vocproc is connected to the MVM. */
  uint16_t vfr_mode; 
    /**< Vocoder frame synchronization mode. Possible values:\n
         - #VSS_ICOMMON_VFR_MODE_SOFT -- No frame synchronization. \n
         - #VSS_ICOMMON_VFR_MODE_HARD -- Hard Vocoder Frame Reference (VFR). 
           A 20 ms VFR interrupt. */
  uint16_t num_timewarp_streams;
    /**< Number of streams with time warping enabled. */
}
#include "apr_pack_end.h"
;


/**
  Event generated by the MVM session to the CCM indicating that MVM is going 
  to voice session inactive state. 
 
  @par Payload
  None.
  
  @return 
  None.

  @dependencies
  None.
 
  @comments
  In response to this event the CCM performs the following two actions: 
   
    1. Sets the VSDP clock.
   
    2. Broadcasts #VSS_ICCM_EVT_ACTIVE_SESSIONS event to all the currently
       active MVM sessions in the system (excluding the one that originated
       this event), informing them of the total number of streams and vocprocs
       in the system as well as the VDSP clock.
*/
#define VSS_IMVM_EVT_VOICE_SESSION_INACTIVE ( 0x00012E6C )


/**
  Command sent by the MVM session to itself to indicate that a reconfiguration 
  of the voice path is necessary.
 
  @par Payload
  None.
  
  @return 
  None.

  @dependencies
  None.
 
  @comments
  This command is generated when the MVM session is notified by one of the 
  streams or vocprocs attached to it that their configuration (i.e. media type, 
  topology, sample rates and/or KPPS requirements) has changed, which requires 
  MVM to re-calculate the timing offsets for this session, as well report the 
  configuration changes to the CCM, so that the CCM may set the clocks 
  accordingly and notify all other MVM sessions of the changes.
*/
#define VSS_IMVM_CMD_RECONFIG ( 0x00012E6D )

#endif /* __VSS_IMVM_PRIVATE_IF_H__ */

