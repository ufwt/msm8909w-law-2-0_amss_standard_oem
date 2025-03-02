#ifndef _SNS_EM_H
#define _SNS_EM_H

/*============================================================================
  @file sns_em.h

  The sensors subsystem event manager header.

  This header file contains the public interface for the sensors event manager.
  The Event Manager provides timer functionality to the various modules in the
  sensor subsystem.

  Copyright (c) 2010-2015 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
============================================================================*/

/* $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/Sensors/common/inc/sns_em.h#1 $ */
/* $DateTime: 2016/12/13 08:00:23 $ */
/* $Author: mplcsds1 $ */

/*---------------------------------------------------------------------------
* Include Files
* -------------------------------------------------------------------------*/
#ifdef FAST_PLAYBACK
  #ifndef TIMETICK_NOMINAL_FREQ_HZ
    #define TIMETICK_NOMINAL_FREQ_HZ      32768uL
  #endif
#else
#include "timetick.h"
#endif
#include "sns_common.h"

/*---------------------------------------------------------------------------
* Preprocessor Definitions and Constants
* -------------------------------------------------------------------------*/

/** This is the sleep clock speed (32.768 Khz) */
#define DSPS_SLEEP_CLK       TIMETICK_NOMINAL_FREQ_HZ

/*---------------------------------------------------------------------------
* Type Declarations
* -------------------------------------------------------------------------*/

/**
 Defines the timer type
*/
typedef enum {
  SNS_EM_TIMER_TYPE_PERIODIC, /**< Periodic timer */
  SNS_EM_TIMER_TYPE_ONESHOT   /**< One shot timer */
} sns_em_timer_type_e;


/**
 Defines the timer (event manager) object
*/
typedef struct sns_em_tmr_s * sns_em_timer_obj_t;

extern uint64_t sns_em_system_time_offset;

/*---------------------------------------------------------------------------
* Function Declarations and Documentation
* -------------------------------------------------------------------------*/

/*=====================================================================================
  FUNCTION:  sns_em_get_system_time
=====================================================================================*/
/**
Returns system time in DSPS 64-bit ticks

@retval uint64_t (ticks)
*/
uint64_t sns_em_get_system_time( void );

/*=====================================================================================
  FUNCTION:  sns_em_get_timestamp
=====================================================================================*/
/**
This API can be used by modules in apps, modules or DSPS to read the local timer value.
It reads the underlying hardware timer register and returns the value in ticks.

@retval uint32_t (ticks)
*/
uint32_t sns_em_get_timestamp( void );

/*=====================================================================================
  FUNCTION:  sns_em_get_timestamp64
=====================================================================================*/
/**
This API can be used by modules in apps, modules or DSPS to read the local timer value.
It reads the underlying hardware timer register and returns the value in ticks.

@param timestamp_p  [OUT] Pointer to a 64-bit number to place the timestamp.

@retval SNS_SUCCESS if the timestamp is set successfully.
*/
sns_err_code_e
sns_em_get_timestamp64( uint64_t *timestamp_p );

/*=====================================================================================
  FUNCTION:  sns_em_create_timer_obj
=====================================================================================*/
/**
This API can be used to create a timer object. A module can subsequently use the timer
object to register and cancel timer requests. This API should be called by modules
before registering for a timer callback.

@retval sns_err_code_e

@see sns_em_delete_timer_obj()

@param timer_cb       [IN]  Address of the timer callback
@param timer_cb_arg   [IN]  Parameters to be passed onto the timer callback
@param timer_category [IN]  Type of timer (periodic or single-shot)
@param timer_obj_ptr  [OUT] Pointer to the the timer object
*/
sns_err_code_e sns_em_create_timer_obj( void (*timer_cb)(void *),
                                        void *timer_cb_arg,
                                        sns_em_timer_type_e timer_category,
                                        sns_em_timer_obj_t* timer_obj_ptr );

/*=====================================================================================
  FUNCTION:  sns_em_create_utimer_obj
=====================================================================================*/
/**
This API can be used to create a uImage timer object.
A module can subsequently use the timer
object to register and cancel timer requests.
This API should be called by modules
before registering for a timer callback.

@retval sns_err_code_e

@see sns_em_delete_utimer_obj()

@param timer_cb       [IN]  Address of the timer callback
@param timer_cb_arg   [IN]  Parameters to be passed onto the timer callback
@param timer_category [IN]  Type of timer (periodic or single-shot)
@param timer_obj_ptr  [OUT] Pointer to the the timer object
*/
sns_err_code_e sns_em_create_utimer_obj( void (*timer_cb)(void *),
                                        void *timer_cb_arg,
                                        sns_em_timer_type_e timer_category,
                                        sns_em_timer_obj_t* timer_obj_ptr );

/*=====================================================================================
  FUNCTION:  sns_em_delete_timer_obj
=====================================================================================*/
/**
This API is used to delete the timer object. The timer cannot be used after calling
this function and this should only be called when the application has no more timers
to register.

This API will free any memory associated with the timer object.

@retval sns_err_code_e

@param timer_obj_ptr [IN] The Timer object

@see sns_em_create_timer_obj()
*/
sns_err_code_e sns_em_delete_timer_obj( sns_em_timer_obj_t timer_obj );

/*=====================================================================================
  FUNCTION:  sns_em_delete_utimer_obj
=====================================================================================*/
/**
This API is used to delete a uImage timer object.
The timer cannot be used after calling this function and this should only be
called when the application has no more timers to register.

This API will free any memory associated with the timer object.

@retval sns_err_code_e

@param timer_obj_ptr [IN] The Timer object

@see sns_em_create_utimer_obj()
*/
sns_err_code_e sns_em_delete_utimer_obj( sns_em_timer_obj_t timer_obj );

/*=====================================================================================
  FUNCTION:  sns_em_register_timer
=====================================================================================*/
/**
This API is used to initiate a timer service. A module which wishes to be notified
after expiration of 'delta_tick_time' should call this API to register with the
event manager.

If a timer is already registered a subsequent call to this API will overwrite the
current registered value.

@retval sns_err_code_e

@param timer_obj_ptr    [IN] The timer object
@param delta_tick_time  [IN] The time after which the client needs to be notified.
                              (measured in ticks)

@see sns_em_cancel_timer()
*/
sns_err_code_e sns_em_register_timer( sns_em_timer_obj_t  timer_obj,
                                      uint32_t            delta_tick_time );

/*=====================================================================================
  FUNCTION:  sns_em_register_timer64
=====================================================================================*/
/**
  Same as sns_em_register_timer, but with a 64-bit delta tick time.
*/
sns_err_code_e sns_em_register_timer64( sns_em_timer_obj_t  timer_obj,
                                        uint64_t            delta_tick_time );


/*=====================================================================================
  FUNCTION:  sns_em_register_utimer
=====================================================================================*/
/**
This API is used to initiate a utimer service. A module which wishes to be notified
after expiration of 'delta_tick_time' should call this API to register with the
event manager.

If a timer is already registered a subsequent call to this API will overwrite the
current registered value.

@retval sns_err_code_e

@param timer_obj_ptr    [IN] The timer object
@param delta_tick_time  [IN] The time after which the client needs to be notified.
                              (measured in ticks)

@see sns_em_cancel_timer()
*/
sns_err_code_e sns_em_register_utimer(sns_em_timer_obj_t  timer_obj,
                                      uint32_t            delta_tick_time );

/*=====================================================================================
  FUNCTION:  sns_em_register_utimer64
=====================================================================================*/
/**
  Same as sns_em_register_utimer, but with a 64-bit delta tick time.
*/
sns_err_code_e sns_em_register_utimer64(sns_em_timer_obj_t  timer_obj,
                                        uint64_t            delta_tick_time );


/*=====================================================================================
  FUNCTION:  sns_em_cancel_timer
=====================================================================================*/
/**
This API is used to cancel the requested timer service. This will preempt the calling
module from being notified. If this function is called just when the timer interrupt
happens the client callback will still get called.

@retval sns_err_code_e

@param timer_obj_ptr  [IN] The timer object

@see sns_em_register_timer()
@see sns_em_delete_all_timers()
*/
sns_err_code_e sns_em_cancel_timer( sns_em_timer_obj_t timer_obj );

/*=====================================================================================
  FUNCTION:  sns_em_cancel_utimer
=====================================================================================*/
/**
This API is used to cancel the requested utimer service. This will preempt the calling
module from being notified. If this function is called just when the timer interrupt
happens the client callback will still get called.

@retval sns_err_code_e

@param timer_obj_ptr  [IN] The timer object

@see sns_em_register_utimer()
@see sns_em_delete_all_timers()
*/
sns_err_code_e sns_em_cancel_utimer( sns_em_timer_obj_t timer_obj );

/*=====================================================================================
  FUNCTION:  sns_em_sleep
=====================================================================================*/
/**
  This API is used to suspend the thread from execution until the specified duration
  has elapsed.

  @param time_us  [IN] Value of the time to be suspended in unit of us
*/
void sns_em_sleep( uint32_t time_us );

/*=====================================================================================
  FUNCTION:  sns_em_cancel_all_timers
=====================================================================================*/
/**
This API is used to cancel all remaining timers.

It will cancel all the pending timers and empty the timer queue. This might be used
by the power management module to shut down the DSPS.

@retval sns_err_code_e
*/
sns_err_code_e sns_em_cancel_all_timers ( void );


/*=====================================================================================
  FUNCTION:  sns_em_check_timer_pending
=====================================================================================*/
/**
This API is used to retrieve the time pending for the next timer interrupt. The
pending time will be retrieved in ticks.

@retval uint32_t (time in ticks)
*/
uint32_t sns_em_check_timer_pending( void );

/*=========================================================================
  FUNCTION:  sns_em_timer_get_remaining_time
  =========================================================================*/
/*!
  @brief Gets the timer remaining duration in microseconds

  @param[i] timer: timer
  @param[o] remaining: remaining duration in microseconds

  @return Sensors error code
*/
/*=======================================================================*/
sns_err_code_e sns_em_timer_get_remaining_time(
   const sns_em_timer_obj_t timer, uint32_t *remaining_time);

/*=====================================================================================
  FUNCTION:  sns_em_convert_dspstick_to_usec
=====================================================================================*/
/**
This is a utility API which can be used to by modules to covert the DSPS ticks into
microsecond units.

@retval uint32_t (time in microseconds)

@param dsps_tick  [IN]  Time in DSPS ticks

@see sns_em_convert_usec_to_dspstick()
*/
uint32_t sns_em_convert_dspstick_to_usec( uint32_t dsps_tick );

/*=====================================================================================
  FUNCTION:  sns_em_convert_dspstick_to_usec
=====================================================================================*/
/**
  Same as sns_em_convert_dspstick_to_usec, but with a 64-bit timestamp.
*/
uint64_t sns_em_convert_dspstick_to_usec64( uint64_t dsps_tick );

/*=====================================================================================
  FUNCTION:  sns_em_convert_localtick_to_usec
=====================================================================================*/
/**
This is a utility API which can be used to by modules to covert the local tick unit into
microsecond units.

@retval uint32_t (time in microseconds)

@param local_tick  [IN]  Time in local processor ticks

*/
uint32_t sns_em_convert_localtick_to_usec( uint32_t local_tick );

/*=====================================================================================
  FUNCTION:  sns_em_convert_localtick_to_usec64
=====================================================================================*/
/**
  Same as sns_em_convert_localtick_to_usec, but with a 64-bit timestamp.
*/
uint64_t sns_em_convert_localtick_to_usec64( uint64_t local_tick );


/*=====================================================================================
  FUNCTION:  sns_em_convert_usec_to_dspstick
=====================================================================================*/
/**
This is a utility API which can be used to by modules to covert the microsecond time
into DSPS ticks.

@retval uint32

@param microsec_time  [IN]  Time in microseconds

@see sns_em_convert_dspstick_to_usec()
*/
uint32_t sns_em_convert_usec_to_dspstick( uint32_t microsec_time );

/*=====================================================================================
  FUNCTION:  sns_em_convert_usec_to_localtick
=====================================================================================*/
/**
This is a utility API which can be used to by modules to covert the microsecond time
into local processor ticks.

@retval uint32_t representing ticks in local processor units

@param microsec_time  [IN]  Time in microseconds

@see sns_em_convert_dspstick_to_usec()
*/
uint32_t sns_em_convert_usec_to_localtick( uint32_t microsec_time );

/*=====================================================================================
  FUNCTION:  sns_em_convert_usec_to_dspstick64
=====================================================================================*/
/**
  Same as sns_em_convert_usec_to_dspstick, but with a 64-bit timestamp.
*/
uint64_t sns_em_convert_usec_to_dspstick64( uint64_t microsec_time );

/*=====================================================================================
  FUNCTION:  sns_em_convert_usec_to_localtick64
=====================================================================================*/
/**
  Same as sns_em_convert_usec_to_localtick, but with a 64-bit timestamp.
*/
uint64_t sns_em_convert_usec_to_localtick64( uint64_t microsec_time );


/*=====================================================================================
  FUNCTION:  sns_em_convert_dspstick_to_appstime
=====================================================================================*/
/**
This is a utility API which can be used to by modules to covert the DSPS ticks into
Apps processor ticks.

@retval uint32_t (time in apps tick)

@param dsps_tick  [IN] Time in DSPS ticks
*/
uint32_t sns_em_convert_dspstick_to_appstime( uint32_t dsps_tick );


/*=====================================================================================
  FUNCTION:  sns_em_convert_dspstick_to_gpstime
=====================================================================================*/
/**
This is a utility API which can be used to by modules to covert the DSPS ticks into
GPS time.

@retval uint32_t (GPS time)

@param dsps_tick  [IN] Time in DSPS ticks
*/
uint32_t sns_em_convert_dspstick_to_gpstime( uint32_t dsps_tick );


/*=====================================================================================
  FUNCTION:  sns_em_convert_sec_in_q16_to_localtick
=====================================================================================*/
/**
This is a utility API which can be used by modules to covert the time in seconds
in Q16 format into local processor ticks.

@retval uint32_t representing ticks in local processor units

@param time_sec_q16  [IN]  Time in seconds in Q16 format
*/
uint32_t sns_em_convert_sec_in_q16_to_localtick( uint32_t time_sec_q16 );

/*=====================================================================================
  FUNCTION:  sns_em_convert_qtimertick_to_dspstick
=====================================================================================*/
/**
into an equivalent value in DSPS-ticks (32 KHz based clock).
@retval uint64_t equivalent value in DSPS ticks (32 KHz ticks).
@param qtimer_tick   [IN]  Time in QTimer ticks
*/
uint64_t sns_em_convert_qtimertick_to_dspstick( uint64_t qtimer_tick );
/*=====================================================================================
  FUNCTION:  sns_em_convert_dspstick_to_qtimertick
=====================================================================================*/
/**
This API can be used to convert a value in DSPS-ticks (32 KHz based clock) into
an equivalent value in QTimer-ticks (19.2 MHz based clock).

@retval uint64_t equivalent value in QTimer ticks (19.2 MHz ticks).

@param dsps_tick     [IN]  Time in DSPS ticks
*/
uint64_t sns_em_convert_dspstick_to_qtimertick( uint64_t dsps_tick );
/*=====================================================================================
  FUNCTION:  sns_em_is_utimer
=====================================================================================*/
/**
This is a utility API which lets the client know if the timer is an uImage
timer.

@retval TRUE, if the timer is an uImage timer
        FALSE otherwise

@param timer timer object
*/
bool sns_em_is_utimer( const sns_em_timer_obj_t timer );


/*=====================================================================================
  FUNCTION:  sns_em_set_system_time_offset
=====================================================================================*/
/**
Called by Debug task to set system time offset

@details This function facilitates testing timestamp rollover by faking
         the passage of time by 'offset' number of DSPS ticks

@retval none

@param uint64_t offset to be added to system time

*/
void sns_em_set_system_time_offset( uint64_t offset );

#endif /*#ifndef _SNS_EM_H*/
