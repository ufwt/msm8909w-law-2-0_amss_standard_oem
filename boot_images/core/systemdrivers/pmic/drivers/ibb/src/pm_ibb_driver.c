/*! \file
*  
*  \brief  pm_ibb_driver.c driver implementation.
*  \details charger driver implementation.
*  &copy;
*  Copyright (c) 2014 Qualcomm Technologies, Inc.  All Rights Reserved. 
*  Qualcomm Technologies Proprietary and Confidential.
*/

/*===========================================================================

EDIT HISTORY FOR MODULE

$Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/systemdrivers/pmic/drivers/ibb/src/pm_ibb_driver.c#1 $ 

when       	who     	 what, where, why
--------   	---    		 ---------------------------------------------------------- 
08/20/14         al              Updating comm lib 
08/29/14         al              KW fixes
05/20/14         al              Architecture update 
04/30/14         al              Initial revision
========================================================================== */

/*===========================================================================

					INCLUDE FILES

===========================================================================*/
#include "pm_ibb_driver.h"
#include "CoreVerify.h"
#include "device_info.h"

/*===========================================================================

                        STATIC VARIABLES 

===========================================================================*/

/* Static global variable to store the IBB data */
static pm_ibb_data_type *pm_ibb_data_arr[PM_MAX_NUM_PMICS];

/*===========================================================================

                        FUNCTION DEFINITIONS

===========================================================================*/
void pm_ibb_driver_init(pm_comm_info_type *comm_ptr, peripheral_info_type *peripheral_info, uint8 pmic_index)
{
	pm_ibb_data_type *ibb_ptr = NULL;

    ibb_ptr = pm_ibb_data_arr[pmic_index];

    if (NULL == ibb_ptr)
    {
        pm_malloc( sizeof(pm_ibb_data_type), (void**)&ibb_ptr);
                                                    
        /* Assign Comm ptr */
        ibb_ptr->comm_ptr = comm_ptr;
		
		/* IBB Register Info - Obtaining Data through dal config */
        ibb_ptr->ibb_reg_table = (pm_ibb_register_info_type*)pm_target_information_get_common_info(PM_PROP_IBB_REG);
        CORE_VERIFY_PTR(ibb_ptr->ibb_reg_table);
		
        ibb_ptr->num_of_peripherals = pm_target_information_get_periph_count_info(PM_PROP_IBB_NUM, pmic_index);
        CORE_VERIFY(ibb_ptr->num_of_peripherals  != 0);

        pm_ibb_data_arr[pmic_index] = ibb_ptr;
    }
}


pm_ibb_data_type* pm_ibb_get_data(uint8 pmic_index)
{
    if(pmic_index < PM_MAX_NUM_PMICS)
    {
        return pm_ibb_data_arr[pmic_index];
    }
    return NULL;
}

uint8 pm_ibb_get_num_peripherals(uint8 pmic_index)
{
  if((pm_ibb_data_arr[pmic_index] !=NULL)&& 
  	  (pmic_index < PM_MAX_NUM_PMICS))
  {
      return pm_ibb_data_arr[pmic_index]->num_of_peripherals;
  }

  return 0;
}


