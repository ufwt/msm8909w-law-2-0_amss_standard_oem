
/*=============================================================================

                        Boot Visual Indication

GENERAL DESCRIPTION
  This file defines SBL visual indication functions

Copyright 2013 by Qualcomm Technologies, Inc.  All Rights Reserved.
=============================================================================*/


/*=============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/boot/secboot3/src/boot_visual_indication.c#1 $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
04/09/13   dh      Initial creation
=============================================================================*/

/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "boot_visual_indication.h"
#include "boot_extern_pmic_interface.h"

static uint32 current_time = 0;
static uint32 previous_time = 0;
static boot_boolean current_led_status = FALSE;

/* The LED flash interval in microseconds*/
static uint32 LED_FLASH_INTERVAL_US = 500000;


/*===========================================================================

**  Function :  boot_enable_led

** ==========================================================================
*/
/*! 
 * @brief This function turn on/off the blue led according to input
 * @return None.
 *
 */ 
boot_boolean boot_enable_led(boot_boolean led_on)
{
  return (boot_pm_enable_led(led_on) ==  PM_ERR_FLAG__SUCCESS) ? TRUE : FALSE;
}


/*===========================================================================

**  Function :  boot_toggle_led_init

** ==========================================================================
*/
/*! 
 * @brief This function initializes the timer count for led toggling
 * @return None.
 *
 */ 
void boot_toggle_led_init(void)
{
  previous_time = boot_get_time();
}


/*===========================================================================

**  Function :  boot_toggle_led

** ==========================================================================
*/
/*! 
 * @brief This function executes the pmic rgb led functions to toggle LED
 * @return TRUE if operation is successful, FALSE if not.
 *
 */ 
boot_boolean boot_toggle_led(void)
{
  boot_boolean ret_val = TRUE;
  current_time = boot_get_time();
  
  /* There may be problem when current_time is out of range, but only 
   * one time, so do not take it into account
   */
  if ((current_time - previous_time) >= LED_FLASH_INTERVAL_US)
  {
    current_led_status = !current_led_status;
    ret_val = boot_enable_led(current_led_status);
    previous_time = current_time;
  }
  
  return ret_val;
}
