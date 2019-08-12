#ifndef RFLM_API_C2K_H
#define RFLM_API_C2K_H
/*!
  @file
  rflm_api_c2k.h

  @brief
  RFLM API definitions for C2K
  
  @detail
  Provides the following API's for C2K FW to call:
  - RXLM and TXLM static startup configuration (via autogenerated LM code)
  - RF tune
  - RF on/off control
  - rx LNA gain update
  - tx-AGC update
  
  @addtogroup RFLM_CDMA_INTF_DEFN
  @{

*/

/*==============================================================================

  Copyright (c) 2013 - 2014 Qualcomm Technologies, Inc. (QTI). All Rights Reserved

  Qualcomm Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.

==============================================================================*/

/*==============================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/rflm/api/fw/rflm_api_c2k.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
12/20/15   vr      Autopin check-in
11/27/15   vr      Synchronized Therm Read with TxAGC event
01/28/15   spa     Add "lna_update_scheduled" flag to rx gain update outputs
08/18/14   spa     Add API rflm_c2k_get_tx_tune_times
07/03/14   hdz     Added rflm_c2k_tx_rf_init()
05/22/14   JJ      Added support for FBRX CCS Enable/Disable Scripts 
03/28/14   zhw     Added txagc_dynamic_update API
03/17/14   hdz     Added txfe_stop_indicator in txagc_in interface
03/11/14   zhw     Redefine skip_cl_hdet_update flag to rpc_indicator
02/14/14   hdz     Added skip_cl_hdet_update flag and rri_indicator
02/04/14   hdz     Added rflm_c2k_set_antenna() and support
02/03/14   spa     Added initial Rx on/off support
01/15/14   spa     Added API for WBDC accumulation freeze/unfreeze 
10/04/13   hdz     Added FBRx interface
10/02/13   spa     Changed rflm_c2k_rxagc_640_t to int (temporarily)
10/02/13   hdz     Added API version number
09/19/13   Apu     Deleted two items in rf_cdma_mdsp_event_id_type 
08/27/13   hdz     Added RFLM c2k script ID
08/05/13   sty     changed RxAGC units to be compatible with FW AGC units
07/30/13   hdz     Changed script_id type to int32
07/29/13   hdz     Added c2k interface change
07/03/13   sty     added members to rxagc in/out structs
06/17/13   hdz     Initial creation
==============================================================================*/

/*==============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "rflm_api_cmn.h"
#include "rflm_api_fbrx_fw.h"

/*! @brief Version of the rflm c2k module.
*/
#define RFLM_API_C2K_MAJOR_VERSION            1
#define RFLM_API_C2K_MINOR_VERSION            1
#define RFLM_API_C2K_VERSION    \
              ((RFLM_API_C2K_MAJOR_VERSION << 16) | RFLM_API_C2K_MINOR_VERSION )


#define RFLM_CDMA_MDSP_TXPWR_15DBM_CHECK   150

/*----------------------------------------------------------------------------*/
/*! 
  @brief
   
*/
#define RFLM_CDMA_MAX_CARRIERS                                                 3

/*----------------------------------------------------------------------------*/
/*! 
  @brief #def for the maximum number of antennas that will be used by the same
  tech at the same time (primary + diversity chains),There is only 2 possible 
  for now, but it might increase in the future   
*/
#define RFLM_CDMA_MAX_ANTENNAS                                                 2
/*----------------------------------------------------------------------------*/
/*! 
  @brief   RF CDMA script ID list 

  @details
  The script ID in the list is one to one mapping to 
  rf_cdma_mdsp_event_id_type in rf_cdma_mdsp_ccs_events.h with a constant 
  offset. eg.,

  RFLM_CDMA_MDSP_CCS_EVENT_WAKEUP_RX_ID = 
  RF_CDMA_MDSP_CCS_EVENT_WAKEUP_RX_ID - RF_CDMA_DUMMY_EVENT;

  whenever a new script ID is added or an old script ID is deleted, both
  rflm_cdma_mdsp_script_id_t and rf_cdma_mdsp_event_id_type need to be updated 
  consistently.

*/
typedef enum 
{
  RFLM_CDMA_DUMMY_EVENT =  0     ,
  /*----------------------------------*/
  /*! Wakeup Rx Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_WAKEUP_RX_ID  ,  
  /*----------------------------------*/
  /*! Sleep Rx Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_SLEEP_RX_ID  ,  
  /*----------------------------------*/
  /*! Wakeup Tx Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_WAKEUP_TX_ID ,  
  /*----------------------------------*/
  /*! Slee Tx Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_SLEEP_TX_ID  ,  
  /*----------------------------------*/
  /*! Re-Tune Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_RETUNE_ID   ,  
  /*----------------------------------*/
  /*! RF ON Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_RF_ON_ID  ,  
  /*----------------------------------*/
  /*! RF OFF Event.*/
   RFLM_CDMA_MDSP_CCS_EVENT_RF_OFF_ID  ,  
  /*----------------------------------*/
  /*! RF IRAT Build tune in script Event.*/ 
   RFLM_CDMA_MDSP_CCS_EVENT_RF_IRAT_TUNE_IN_ID  ,  
  /*----------------------------------*/
  /*! RF HDET read event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RF_HDET_CONFIG_ID   ,  
  /*----------------------------------*/
  /*! Rx LNA State 0 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_LNA_G0_ID  ,  
  /*----------------------------------*/
  /*! Rx LNA State 1 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_LNA_G1_ID  ,  
  /*----------------------------------*/
  /*! Rx LNA State 2 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_LNA_G2_ID  ,  
  /*----------------------------------*/
  /*! Rx LNA State 3 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_LNA_G3_ID  ,  
  /*----------------------------------*/
  /*! Rx LNA State 4 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_LNA_G4_ID ,  
  /*----------------------------------*/
  /*! Rx LNA State 5 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_LNA_G5_ID,
  /*----------------------------------*/
  /*! D-LNA State 0 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_ON_ID ,
  /*-----------------------------------*/
  /*! D-LNA State 1 program event */ 
   RFLM_CDMA_MDSP_CCS_EVENT_RX_OFF_ID ,
  /*------------------------------------*/
  /*! TxAGC generic sequence event*/ 
   RFLM_CDMA_MDSP_CCS_EVENT_TXAGC_GENERIC_ID ,
  /*--------------------------------------------*/
  /*! TxAGC generic sequence event DMA format*/ 
  RFLM_CDMA_MDSP_CCS_EVENT_TXAGC_GENERIC_DMA_ID ,
  /*----------------------------------------------*/
  /*! TxAGC RGI Lo to Hi event DMA format */ 
  RFLM_CDMA_MDSP_CCS_EVENT_TXAGC_RGI_LO_2_HI_DMA_ID ,
  /*----------------------------------*/
  /*! TxAGC RGI Hi to Lo event DMA format*/ 
  RFLM_CDMA_MDSP_CCS_EVENT_TXAGC_RGI_HI_2_LO_DMA_ID   ,  
  /*----------------------------------*/
  /*! TxAGC PA Lo to Hi event DMA format*/ 
  RFLM_CDMA_MDSP_CCS_EVENT_TXAGC_PA_LO_2_HI_DMA_ID  ,  
  /*----------------------------------*/
  /*! TxAGC PA Hi to Lo event DMA format*/ 
  RFLM_CDMA_MDSP_CCS_EVENT_TXAGC_PA_HI_2_LO_DMA_ID  , 
  /*----------------------------------*/
  /*! CL tunner                     */ 
  RFLM_CDMA_MDSP_CCS_EVENT_CLOSE_LOOP_TUNNER_ID  , 
  /*----------------------------------*/
  /*! OL tunner                         */ 
  RFLM_CDMA_MDSP_CCS_EVENT_OPEN_LOOP_TUNNER_ID  , 
  /*----------------------------------*/
  /*! Async diversity              */ 
  RFLM_CDMA_MDSP_CCS_EVENT_ASDIV_ID  ,  
  /*----------------------------------*/
  /*! Enable FBRx              */ 
  RFLM_CDMA_MDSP_CCS_EVENT_ENABLE_FBRX_ID  ,
  /*----------------------------------*/
  /*! Enable FBRx              */ 
  RFLM_CDMA_MDSP_CCS_EVENT_DISABLE_FBRX_ID  ,
  /*----------------------------------*/
  /*! RF Therm Config read event */ 
  RFLM_CDMA_MDSP_CCS_EVENT_THERM_CONFIG_ID   , 
   /*----------------------------------*/
  /*!  Autopin Gain State 1 read event */ 
  RFLM_CDMA_MDSP_CCS_EVENT_AUTOPIN_TRIGGER_G1_ID,
  /*----------------------------------*/
  /*! Autopin Gain State 2 read event */ 
  RFLM_CDMA_MDSP_CCS_EVENT_AUTOPIN_TRIGGER_G2_ID,
} rflm_cdma_mdsp_script_id_t ;

/*----------------------------------------------------------------------------*/
/*! 
  @brief   RF CDMA sleep modes 

  @details
  For features like DLNA , FW can call the rx_on_off_ctrl API, with different
  sleep modes. Each sleep mode is responsible for a different set of register 
  writes i.e. micro sleep mode will not disable the PLL on the WTR and will
  be a lower scale sleep, while milli sleep will put the PLL to sleep as well
  each sleep mode has its own use-case. 

*/
typedef enum 
{
  /*! Micro Sleep mode, micro sleep is used in features like DLNA or enhanced 
  DLNA where the Rx path is shut off for shorter durations and PLL is still 
  locked */ 
  RFLM_CDMA_MICRO_SLEEP_MODE =  0     ,
  /*----------------------------------*/
  /*! Milli sleep mode on/off both (not supported right now) */
   RFLM_CDMA_MILLI_SLEEP_ON_OFF_MODE  , 

  /*----------------------------------*/
  /*! Milli sleep mode with off only mode , RFLM will schdule ccs events 
  for enabling Rx chain only and not disabling it (not 
  supported right now) */ 
   RFLM_CDMA_MILLI_SLEEP_ON_ONLY_MODE  , 

  /*----------------------------------*/
  /*! Milli sleep mode with off only mode , RFLM will schdule ccs events 
  for disabling Rx chain only and not enabling it (not 
  supported right now) */ 
  RFLM_CDMA_MILLI_SLEEP_OFF_ONLY_MODE  , 
   
}rflm_c2k_sleep_mode_e;

/*----------------------------------------------------------------------------*/
/*! 
  @brief
  RxAGC is in 1/640dB units TODO: Make int16
*/
typedef int rflm_c2k_rxagc_640_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief  WB and NB info for rflm_c2k_rx_rf_tune API

  @detail Holds c2k WB and NB indices that C2K FW populates after querying CFW. 
*/
typedef struct ALIGN(4)
{
  /*! @brief  WB index used for the given Rx chain. */
  uint8     wb_idx ;        

  /*! @brief NB used for a given carrier on the given Rx chain. */
  uint8     nb_idx [RFLM_CMN_RXAGC_MAX_NB_PER_WB] ;         

} rflm_c2k_rx_chain_info_t ;


/*----------------------------------------------------------------------------*/
/*!
  @brief  Input parameters for rflm_c2k_rx_rf_tune API

  @detail Hold c2k rx tune information, passing from c2k FW to RFLM. 
*/
typedef struct ALIGN(4)
{
  /*! @brief  Time for script to take effect in USTMR */
  rflm_ustmr_t   action_time;        

  /*! @brief Flag for immediate action_time */
  boolean         immediate_flag;     

  /*! @brief id of script to run */
  int32            script_id;
  
  /*! @brief WB and NB indices populated by FW */
  rflm_c2k_rx_chain_info_t      wb_nb_info ;
  
} rflm_c2k_rx_rf_tune_in_t;

/*----------------------------------------------------------------------------*/
/*! 
  @brief  Output parameters for rflm_c2k_rx_rf_tune API 

  @detail Hold output of c2k rx tune API, mainly the estimate of done time in 
  USTMR unit
*/
typedef struct
{
  /*! @brief estimate done time 
    todo does it need to be absolute or relative? 
    */
  rflm_ustmr_t   est_done_time;      
  
} rflm_c2k_rx_rf_tune_out_t;

/*----------------------------------------------------------------------------*/
/*! 
  @brief  Input parameters for rflm_c2k_tx_rf_tune API

  @detail Hold parameter for c2k tx tune, e.g., wakeup tx/sleep tx.
*/
typedef struct ALIGN(4)
{
  /*! @brief Time for script to take effect in USTMR */
  rflm_ustmr_t   action_time;        

  /*! @brief Flag for immediate action_time */  
  boolean         immediate_flag;     

  /*! @brief id of script to run */    
  int32            script_id;              
  
} rflm_c2k_tx_rf_tune_in_t;

/*----------------------------------------------------------------------------*/
/*! 
  @brief  Output parameters for rflm_c2k_tx_rf_tune API 

  @detail Hold output of c2k tx tune API, mainly the estimate of done time in 
  USTMR unit
*/
typedef struct
{
  /*! @brief estimate done time */
  rflm_ustmr_t   est_done_time;     
  
} rflm_c2k_tx_rf_tune_out_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Input parameters for rflm_c2k_rx_rf_on_off_ctrl API */
typedef struct ALIGN(4)
{
  /*! @brief 
  Timed or immediate sleep  
  TRUE:Timed RF OFF 
  FALSE:Immediate RF OFF 
  For features like enhanced DLNA the Rx off event 
  will be scheduled at some time in the future, as opposed to standard DLNA 
  where the Rx off event is immediate. If enhanced DLNA is enabled this 
  flag will be set to TRUE, if this is true FW must also mention a rf_off_time 
  in USTMR, which tells the time at which Rx path needs to be shut off in the 
  future, if this flag is FALSE ,RF will assume that the Rx off needs to be 
  scheduled immediately */ 
  boolean timed_rf_off_enabled;

  /*! @brief 
    USTMR time for timed RF off, not valid for immediate mode ; This 
    must be a time in the future if the "timed_rf_off_enabled" flag is TRUE */
  rflm_ustmr_t rf_off_time;

  /*! @brief 
    USTMR time by which FW expects Rx path to be enabled and 
    RxAGC to be settled, After Rx path has been disabled, RF will schedule
    an event to enable it such that by this time the Rx path is enabled,
    previous LNA state is restored, and WBDC state is restored to what it is 
    before the path is put to sleep, if this time is in the past, RF will 
    do nothing and return ignored flag */ 
  rflm_ustmr_t rf_on_settled_time;

  /*! @brief 
    Micro/milli sleep, enum internal to c2k to determine whether 
    the sleep is micro or milli type.*/
  rflm_c2k_sleep_mode_e sleep_mode;

  /*! @brief Handle array, array of handles for rx paths enabled 
    0xFFFFFFFF for disabled antennas*/
  rflm_handle_rx_t rx_handle_array[RFLM_CDMA_MAX_ANTENNAS];

} rflm_c2k_rx_rf_on_off_ctrl_in_t;


/*----------------------------------------------------------------------------*/
/*! @brief  Output parameters for rflm_c2k_rx_rf_on_off_ctrl API */
typedef struct
{
  /*! @brief RF off scheduled time in USTMR, used for logging purposes on FW 
  side */ 
  rflm_ustmr_t   rf_off_schedule_time;       
   
  /*! @brief RF on scheduled time in USTMR, used for logging purposes on FW 
  side */
  rflm_ustmr_t   rf_on_schedule_time;    
  
  /*! @brief LNA state restored to per handle on wakeup 
   whenever the rx is turned back on , the previous LNA state is restored
   for each chain that was disabled */
  int8 rx_lna_state_restored[RFLM_CDMA_MAX_ANTENNAS];

} rflm_c2k_rx_rf_on_off_ctrl_out_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Input parameters for rflm_c2k_tx_rf_on_ctrl API */
typedef struct ALIGN(4)
{
  /*! @brief Time for script to take effect in USTMR */
  rflm_ustmr_t   action_time;        

  /*! @brief Flag for immediate action_time */  
  boolean         immediate_flag;     

  /*! @brief  TRUE=on, FALSE=off */  
  boolean         rf_on;             
  
} rflm_c2k_tx_rf_on_ctrl_in_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Output parameters for rflm_c2k_tx_rf_on_ctrl API */
typedef struct
{
  /*! @brief estimate done time */
  rflm_ustmr_t   est_done_time ;      ///< estimated completion time  
  
} rflm_c2k_tx_rf_on_ctrl_out_t;

/*----------------------------------------------------------------------------*/
/*! 
  @brief
  Input parameters for rflm_c2k_rx_gain_update API
*/
typedef struct ALIGN(4)
{
  /*! 
    @brief
    If TRUE, it indicates that the writes are to be done immediately (taking 
    into account RFLM processing delays). The "action_time" argument is ignored
   
    If False (which means a "timed-write") , the "action_time" argument 
    will be used.
   
    todo: need to find out what the use-case for write_immediate=FALSE would be.
    Remove it not needed
  */
  boolean write_immediate;

  /*! 
    @brief
    flag that indicates if a LNA gain state needs to be programmed 
    If FALSE, only the DVGA is updated
    If TRUE, (a) LNA gain state script needs to be scheduled to CCS. 
             (b) If action_time is in the past, then the API will crash.
             (c) DVGA is updated as well
  */
  boolean lna_update_needed;

  /*! 
    @brief 
    LNA gain state to which the LNA has to be transitioned to 
  */
  int8 new_lna_gain_state;  

  /*! 
    @brief 
    the previous LNA gain state (or: the "current" LNA state when this API is 
    called). This is needed for DVGA calculation when lna_update_needed is TRUE
  */
  int8 prev_lna_gain_state;  

  /*! 
    @brief
    Time for script to take effect in USTMR.
   
    If write_immediate = TRUE, then this field is ignored.
   
    If write_immediate = FALSE, and if the action_time is in the past, then
    the API will crash
    todo: will be removed if write_immediate is deleted
  */
  rflm_ustmr_t action_time;

  /*! 
    @brief
    per carrier AGC value in 1/640dB units - used in DVGA calculations
  */
  rflm_c2k_rxagc_640_t agc_val[RFLM_CDMA_MAX_CARRIERS];

  /*! 
   @brief
   Indicates the carriers that are enabled
  */
  boolean carrier_enabled[RFLM_CDMA_MAX_CARRIERS];
  
} rflm_c2k_rx_gain_update_in_t;

/*----------------------------------------------------------------------------*/ 
/*! 
  @brief 
  Output parameters for rflm_c2k_rx_gain_update API
*/
typedef struct
{
  /*! 
    @brief
    updated DVGA gain for each carrier (in 1/640dB units). Used for logging on
    FW side
  */
  rflm_c2k_rxagc_640_t dvga_gain_dB[RFLM_CDMA_MAX_CARRIERS];        

  /*! 
  @brief
  This field is populated only when on a LNA state change

  Time when DC has settled. At the end of this time, DC is expected to go from
  acq to track mode
    
  */
  rflm_ustmr_t nbee_ready_time;

  /*! 
    @brief
    Flag to indicate if Rx gain update API scheduled LNA update or not

    This flag will be set to TRUE if an LNA update is scheduled in CCS.
    If the previous LNA update is not complete when another LNA update is
    requested, Rx gain update API will ignore request for LNA state change
    and set this flag to FALSE

  */
  boolean lna_update_scheduled;

} rflm_c2k_rx_gain_update_out_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Input parameters for rflm_c2k_txagc_update API */
typedef struct ALIGN(4)
{
  /*! @brief Time for script to take effect in USTMR */
  rflm_ustmr_t   action_time;        

  /*! @brief TRUE = skip PA STM; FALSE = run PA STM */
  boolean        skip_pa_stm;         

  /*! @brief Desired output power */
  rflm_dbm100_t  out_pwr;    

  /*! @brief  will be replaced */  
  rflm_drif_in_cfg_t  drif_in_cfg;   

 /*! @ brief indicate if uK is available or not. If if FALSE, the FED will skip all FBRX APIs 
  call*/
  boolean fbrx_available;

  /*! @brief If this TxAGC update corresponds to a RPC command 
      TRUE if RPC is decoded for this TxAGC. FED will be allowed to freeze the
      next TxAGC update
      FALSE if RPC is not decoded for this TxAGC. FED will not be allowed to
      freeze the next TxAGC update */
  boolean rpc_indicator;

  /*! @brief  HDR RRI indicator;
      1x: always being 0;
      hdr: rri    
  */
  uint8 rri_indicator;

  /*! @brief  TxFE stop indicator
      @details
      TRUE:TxFE will be shutdown after this txagc updated;
           Therefore, the current txagc needs to put tx power to min power to reset
           txagc status, and force to run PA STM
      FALSE:TxFE will not be shutdown after this txagc updated;
  */
  boolean txfe_stop_indicator;
 
} rflm_c2k_txagc_update_in_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Output parameters for rflm_c2k_txagc_update API */
typedef struct
{
  /*! @brief   PA state index for logging */  
  int8            pa_state;           

  /*! @brief  RGI index for logging */  
  int8            rgi_smps_row_index;  

  /*! @brief  RGI index for logging */  
  int8            rgi_const_row_index; 

  /*! @brief SMPS value for logging */  
  int8            smps_value; 

  /*! @brief  DRIF output config */  
  rflm_drif_out_cfg_t drif_out_cfg;   

  /*! @brief return fbrx pwr params */  
  rflm_fbrx_pwr_dependent_param_t fbrx_pwr_params;

  /*! @brief return fbrx dynamic params */  
  rflm_fbrx_dynamic_param_t fbrx_dynamic_params;

  /*! @brief flag to indicate if to run fbrx or not */  
  boolean run_fbrx;
  
  // add FBRx parameters  
} rflm_c2k_txagc_update_out_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Input parameters for rflm_c2k_wbdc_accum_onoff API */
typedef struct ALIGN(4)
{
  /*! @brief WB index for which the accumulaiton needs to be enabled/disabled 
*/ uint8   wb_idx;        

  /*! @brief TRUE = Start WBDC accum; FALSE = Stop WBDC accum */
  boolean        start_imm;         

} rflm_c2k_wbdc_accum_freeze_unfreeze_in_t;

/*----------------------------------------------------------------------------*/
/*! @brief  Output parameters for rflm_c2k_wbdc_accum_onoff API */
typedef struct
{
  /*! @brief flag to indicate if requested action was succesful or not */  
  boolean api_status;
  
} rflm_c2k_wbdc_accum_freeze_unfreeze_out_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief enum of c2k RF state
*/
typedef enum
{
  /*! @brief Tx and Rx both are on */
  RFLM_C2K_RF_RXTX = 0,

  /*! @brief  Rx only */
  RFLM_C2K_RF_RX,

  /*! @brief  Max state */
  RFLM_C2K_RF_MAX,

}rflm_c2k_rf_state;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k asd input data type
*/
typedef struct ALIGN(4)
{
  /*! @brief Time for script to take effect in USTMR */
  rflm_ustmr_t   action_time;        

  /*! @brief Desired output power */
  rflm_dbm100_t  out_pwr;    

  /*! @brief If this TxAGC update corresponds to a RPC command 
      TRUE if RPC is decoded for this TxAGC. FED will be allowed to freeze the
      next TxAGC update
      FALSE if RPC is not decoded for this TxAGC. FED will not be allowed to
      freeze the next TxAGC update */
  boolean rpc_indicator;

  /*! @brief reserved */
  uint32 reserved;
}rflm_c2k_txagc_dynamic_update_input_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k asd output data type 
*/
typedef struct ALIGN(4)
{
  /*! @brief reserved */
  uint32 reserved;

}rflm_c2k_txagc_dynamic_update_output_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k asd input data type
*/
typedef struct ALIGN(4)
{
  /*! @brief 1= immediate; 0=timed*/
  boolean immediate;

  /*! @brief c2k rf state*/
  rflm_c2k_rf_state rf_state;

  /*! @brief action time for ads script*/
  uint32 action_time;

  /*! @brief reserved */
  uint32 reserved;

}rflm_c2k_asd_input_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k asd output data type 
*/
typedef struct ALIGN(4)
{
  /*! @brief reserved */
  uint32 reserved;

}rflm_c2k_asd_output_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k tx rf init input data type
*/
typedef struct ALIGN(4)
{
  /*! @brief reserved */
  uint32 reserved;
}rflm_c2k_tx_rf_init_in_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k tx rf init output data type 
*/
typedef struct ALIGN(4)
{
  /*! @brief reserved */
  uint32 reserved;
}rflm_c2k_tx_rf_init_out_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k get tx tune times input data type
*/
typedef struct ALIGN(4)
{
  /*! @brief reserved1 */
  uint32 reserved_1;

  /*! @brief reserved2 */
  uint32 reserved_2;

  /*! @brief reserved3 */
  uint32 reserved_3;
}rflm_c2k_get_tx_tune_times_input_t;

/*----------------------------------------------------------------------------*/
/*!
  @brief rflm c2k get tx tune times data type 
*/
typedef struct ALIGN(4)
{
  /*! @brief Tx start script estimate (USTMR) */
  rflm_ustmr_t tx_start_estimate;

  /*! @brief Tx stop script estimate (USTMR) */
  rflm_ustmr_t tx_stop_estimate;

  /*! @brief reserved1 */
  uint32 reserved_1;

  /*! @brief reserved2 */
  uint32 reserved_2;

}rflm_c2k_get_tx_tune_times_output_t;

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/*!
  @brief API to do c2k rx tune 

  @detail 
  This API is called by FW to do rx tune, including dereference
  rx tune script, build rx gain tune sequence in CCS format and commit to 
  CCS

  @param handle
  handle that contains information to de-referene rx tune script.

  @param in
  pointer to a structure that holds input parameters from FW
  
  @param out
  pointer to a stucture that holds output parameter to FW

  @return
  enum of API status  

==============================================================================*/
rflm_err_t rflm_c2k_rx_rf_tune( rflm_handle_rx_t handle_id,
                                const rflm_c2k_rx_rf_tune_in_t  *in,
                                rflm_c2k_rx_rf_tune_out_t *out );

/*----------------------------------------------------------------------------*/
/*!
  @brief API to do c2k tx tune

  @detail 
  This API is called by FW to do rx gain update, including dereference
  tx tune script, build tx tune sequence in CCS format and commit to 
  CCS
  
  @param handle
  handle that contains information to de-referene tx tune script.

  @param in
  pointer to a structure that holds input parameters from FW
  
  @param out
  pointer to a stucture that holds output parameter to FW
  
  @return
  enum of API status  

==============================================================================*/
rflm_err_t rflm_c2k_tx_rf_tune( rflm_handle_tx_t handle_id,
                                const rflm_c2k_tx_rf_tune_in_t *in,
                                rflm_c2k_tx_rf_tune_out_t *out );

/*==============================================================================
  RF on/off related API's
==============================================================================*/
/*!
  @brief API to do c2k rx on-off 

  @details
  This API is called by FW for enabling or disabling Rx path momentarily for
  power saving features like DLNA.
 
  -> The API will turn off Rx path for some time and wakeup at the time 
   requested by FW and restore the previous LNA state.
  -> If there is not sufficient time for the API to sleep-wakeup-restore 
   previous LNA state, the API will do nothing.
  -> If diversity is enabled, the API expects FW to send in the correct handle 
   information for the diversity chain as well.If there is a valid handle for
   diversity chain, RF will run scripts to disable that RF path as well 
 
  The API takes as input, the time FW wants RF to sleep, the time by 
  which it expects RxAGC to be settled and the handle IDs for the chains that
  FW wants to disable the Rx path.
 
  all the times are in USTMR units
  t_off = Time at which FW wants Rx to sleep (known)
  t_settled = Time FW wants RxAGC settled (known)
  t_sleep_min = minimun time for which rx stop needs to be disabled (known)
  t_sleep_curr = time for which Rx can be asleep in this scenario (computed)
  t_sleep_script = script execution time for sleep script (computed)
  t_wakeup_script = script exec time for wakeup script (computed)
 
  t_sleep_script & t_wakeup_script are calculated based on script size
 
  if( t_settled < t_sleep_script + t_wakeup_script + t_sleep_curr) &&
  if( t_sleep_curr >= t_sleep_min )
  Return status ignored
  else
  schedule_rxoff and rx on events
 
   _____________________                        ____________________   
  |                     |                      |                    | 
  |<---t_sleep_script-->|<----t_sleep_curr---->|<--t_wakeup_script->| 
  |_____________________|______________________|____________________|___| 
 t_off                                                                t_settled
    
  @param handle
  handle that contains information to de-referene rx on-off script.
  
  @param in
  pointer to a structure that holds input parameters from FW
    
  @param out
  pointer to a stucture that holds output parameter to FW
    
  @return
  enum of API status:
  RFLM_ERR_IGNORED if there isn't  sufficient time to run the script 
  RFLM_ERR_NONE if the sleep-wakeup is feasible and task scheduling is success
  RFLM_ERR_API_FAILED if the API fails or inputs are invalid
==============================================================================*/
rflm_err_t rflm_c2k_rx_rf_on_off_ctrl(
                                    const  rflm_c2k_rx_rf_on_off_ctrl_in_t  *in,
                                    rflm_c2k_rx_rf_on_off_ctrl_out_t *out );

/*----------------------------------------------------------------------------*/
/*!
  @brief API to do c2k tx on-off 

  @detail 
  This API is called by FW to do tx on-off, including dereference
  tx on-off script, build tx on-off sequence in CCS format and commit to 
  CCS
  
  @param handle
  tx handle that contains information to de-referene tx on-off script.

  @param in
  pointer to a structure that holds input parameters from FW
  
  @param out
  pointer to a stucture that holds output parameter to FW
  
  @return
  enum of API status  

==============================================================================*/
rflm_err_t rflm_c2k_tx_rf_on_ctrl( rflm_handle_tx_t handle_id,
                                   const  rflm_c2k_tx_rf_on_ctrl_in_t  *in,
                                   rflm_c2k_tx_rf_on_ctrl_out_t *out );

/*----------------------------------------------------------------------------*/
/*!
  @brief API to do c2k rx gain update

  @detail 
  This API is called by FW to do rx gain update, including dereference
  rx gain script, build rx gain update sequence in CCS format and commit to 
  CCS. FW calls this once per rx chain.
  
  @param handle
  rx handle that contains information to de-referene rx gain update script.

  @param in
  pointer to a structure that holds input parameters from FW
  
  @param out
  pointer to a stucture that holds output parameter to FW
  
  @return
  enum of API status  

==============================================================================*/
rflm_err_t rflm_c2k_rx_gain_update( rflm_handle_rx_t handle_id,
                                    const rflm_c2k_rx_gain_update_in_t *in,
                                    rflm_c2k_rx_gain_update_out_t *out );

/*----------------------------------------------------------------------------*/
/*!
  @brief API to do c2k txagc update

  @detail 
  This API is  called by FW to do txagc update, including pa 
  state machine, txagc lookup, build txagc ccs issue_seq script and commit to 
  CCS, and program  iq_gain,env_scale and dpd table via DRIF driver.
  FW is expected to call this 64-chips ahead of action time.  

  @param handle
  tx handle that contains information to de-referene tx LUT and tx script.

  @param in
  pointer to a structure that holds input parameters from FW

  @param out
  pointer to a stucture that holds output parameter to FW

  @return
  enum of API status  

==============================================================================*/
rflm_err_t rflm_c2k_txagc_update( rflm_handle_tx_t handle_id,
                                  const rflm_c2k_txagc_update_in_t  *in,
                                  rflm_c2k_txagc_update_out_t *out );

/*----------------------------------------------------------------------------*/
/*!
  @brief API for WBDC accumulaiton freeze/unfreeze

  @details
  This API is  called by FW for enabling or disabling Wideband DC accumulation
  loop. This might be required in scenarios where FW wants to disable the Rx
  path for a small amount of time. This could be to prevent interference to 
  another path running on another chain, or because of some on demand algorithm.
  Freeze WBDC implies stopping of the WBDC accumulatios , unfreezing implies
  starting of WBDC accumulations again
  
  @param in
  pointer to a structure that holds input parameters from FW

  @param out
  pointer to a stucture that holds output parameter to FW

  @return
  enum of API status , alywas success for now, since the API is only doing a 
  register write 

==============================================================================*/
rflm_err_t rflm_c2k_wbdc_accum_freeze_unfreeze( 
                             const rflm_c2k_wbdc_accum_freeze_unfreeze_in_t *in, 
                             rflm_c2k_wbdc_accum_freeze_unfreeze_out_t *out );
							 
/*----------------------------------------------------------------------------*/
/*!
  @brief This is FW-FED interface API to do AsDiv feature
*/
rflm_err_t rflm_c2k_set_antenna( rflm_handle_rx_t handle_id,
                                 const rflm_c2k_asd_input_t *in,
                                 rflm_c2k_asd_output_t *out );							 


/*---------------------------------------------------------------------------*/
/*! 
  @brief 
  Schedule dynamic event update (Tuner AOL/CL, HDET, AsDiv, etc)
 
  @details
  This API schedules a dynamic event. If there are multiple events pending,
  based on the priority between events one of them will be scheduled. This API
  also determines whether or not to skip next TxAGC update, if required for
  certain events.
  
  @param handle_id
  RFLM handle
 
  @param in
  input config strucutre that should include:
  1. intended action time for this dynamic update
  1. current raw TxAGC power
  2. rpc indicator for this TxAGC update
 
  @param out
  Output for TxAGC dynamic update. Reserved.
*/
rflm_err_t
rflm_c2k_txagc_dynamic_update
(
   rflm_handle_tx_t handle_id,
   const rflm_c2k_txagc_dynamic_update_input_t  *in,
   rflm_c2k_txagc_dynamic_update_output_t *out
);

/*---------------------------------------------------------------------------*/
rflm_err_t
rflm_c2k_tx_rf_init
(
  rflm_handle_tx_t handle_id,
  const rflm_c2k_tx_rf_init_in_t  *in,
  rflm_c2k_tx_rf_init_out_t *out 
);

/*---------------------------------------------------------------------------*/
/*! 
  @brief 
  Give FW estimated Tx tune times in USTMR units(for Tx start and stop)
 
  @details
  This API sprovides FW with Tx start and stop time estimates, based on script 
  sizes. The execution time for a script is a funciton of the number of 
  trasactions, the type of trasnaction (RFFE/SSBI/GRFC), the bus contention
  when the API is called and any other latencies that might occur.
  
  @param handle_id
  RFLM handle
 
  @param in
 
  @param out
  Output for Tx tune time query
  The estimated time for Tx enable and disable in USTMR units
  
*/
rflm_err_t
rflm_c2k_get_tx_tune_times
(
   rflm_handle_tx_t handle_id,
   const rflm_c2k_get_tx_tune_times_input_t  *in,
   rflm_c2k_get_tx_tune_times_output_t *out
);

#ifdef __cplusplus
} // extern "C"
#endif

/*! @} */

#endif /* #ifndef RFLM_API_C2K_H */