/*
=================================================================================

                  T O P  L E V E L  M O D E  M U X  ( T L M M ) 
              H A R D W A R E   A B S T R A C T I O N   L A Y E R
                               F O R   8 9 6 0 

FILE:         HALtlmmCommon.c

DESCRIPTION:  
              This modules contains common functionality to the application
              processor and the master processor.

=================================================================================

                             Edit History

$Header: //components/rel/core.mpss/3.5.c12.3/systemdrivers/tlmm/hw/v2/HALtlmm.c#1 $

when       who     what, where, why
--------   ---     --------------------------------------------------------------
08/05/10   dcf     Created.

=================================================================================
             Copyright (c) 2011 Qualcomm Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
=================================================================================
*/

/*===============================================================================
                         INCLUDE FILES FOR MODULE
===============================================================================*/
#include <HALcomdef.h>
#include <HALhwio.h>
#include "HALtlmm.h"
#include "HALtlmmHWIO.h"


/*===============================================================================
                    GLOBAL STRUCTURES FOR THIS MODULE
===============================================================================*/



/* ==============================================================================
   The following macro takes the configuration values from the BSP format used
   by the driver and restructures them to fit the format of the configuration
   registers for this target.
   ----------------------------------------------------------------------------*/

#define HAL_TLMM_GPIO_CONFIG_MASK(cfg)   \
    ((HAL_PULL_VAL(cfg)   << 0x0) | \
     (HAL_FUNC_VAL(cfg)   << 0x2) | \
     (HAL_DRVSTR_VAL(cfg) << 0x6) | \
     (HAL_DIR_VAL(cfg)    << 0x9) )


static HAL_tlmm_InitType tHALTLMMInit;


/*===============================================================================
  ===============================================================================
                     FUNCTIONS CONTAINED WITHIN THIS MODULE
===============================================================================*/



/*===============================================================================

FUNCTION  
  void HAL_tlmm_Init ( HAL_tlmm_InitType* pInit)

DESCRIPTION
   Does the initializing of the hardware buffers and address structures.

PARAMETERS
   Pointer to the version of this HAL module.

DEPENDENCIES
   None.

RETURN VALUE
   The current version via input parameter.

SIDE EFFECTS
   None.
===============================================================================*/

void HAL_tlmm_Init( HAL_tlmm_InitType* pInit )
{
  /* Initialize the registers and buffers. */
  if( pInit )
  {
    tHALTLMMInit.nNumGpio = pInit->nNumGpio;
    tHALTLMMInit.nBaseAddress = pInit->nBaseAddress;
  }

}/* END HAL_tlmm_Init */


/*===========================================================================

FUNCTION  
  HAL_tlmm_SetOwner( uint16 nWhichGpio, uint8 nWhichOwner )

DESCRIPTION
   Programs the GPIO_OWNER register to the processor specified in the
   parameter.

PARAMETERS
   nWhichConfig - The masked configuration containing the GPIO number to set.
   nWhichOwner  - The owner processor to set the GPIO ownership to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===============================================================================*/
void HAL_tlmm_SetOwner(uint32 nWhichGpio, uint32 nWhichOwner)
{

}

/*===============================================================================

FUNCTION  
  void HAL_tlmm_SetOwnerGroup(const uint16 nWhichGroup[], nWhatSize, uint8 nWhichOwner)

DESCRIPTION
   Programs the GPIO_OWNER register to the processor specified in the
   parameter.

PARAMETERS
   nWhichGroup*  - A array of GPIO configurations which includes GPIO number.
   nWhatSize     - The size of the array to configure.
   nWhichOwner   - The owner to set the group of GPIOs to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===============================================================================*/
void HAL_tlmm_SetOwnerGroup
(
  uint32 *nWhichGroup, 
  uint32 nWhatSize, 
  uint32 nWhichOwner
)
{
  /* Nothing to be done on this target. */
}

/*===============================================================================

FUNCTION  
  void HAL_tlmm_WriteConfig( uint32 nGpioNumber, uint32 nConfig )

DESCRIPTION
   Programs the GPIOn_PAGE and GPIOn_CFG registers based on the input 
   parameters.  For APPS processor, this function is stubbed out.

PARAMETERS
   nGpioNumber  - GPIO number to configure
   nGroup       - The registe group that this GPIO number belongs to.
   nConfig      - The masked configuration for this GPIO.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===============================================================================*/
void HAL_tlmm_WriteConfig( uint32 nGpioNumber, uint32 nConfig )
{
  if( nGpioNumber < tHALTLMMInit.nNumGpio )
  {
     HWIO_TLMM_GPIO_CFGn_OUTI(tHALTLMMInit.nBaseAddress, nGpioNumber, nConfig);
  }
}


/*===============================================================================

FUNCTION  
   void HAL_tlmm_Reset( void )

DESCRIPTION
   Will program the reset state of the TLMM block.

DEPENDENCIES
   None.

RETURN VALUE
   None.

SIDE EFFECTS
   None.
===============================================================================*/

void HAL_tlmm_Reset( void )
{
  /* Reserved for future use. */
}


/*===============================================================================

FUNCTION  
  void HAL_tlmm_ConfigGpio ( uint32 nWhichConfig )

DESCRIPTION
   Configures the specified GPIO to the requested configuration at the
   provided index.

PARAMETERS
   Packed configuration data containing GPIO number and configuration info.

DEPENDENCIES
   None.

RETURN VALUE
   None.

SIDE EFFECTS
   None.
===============================================================================*/

void HAL_tlmm_ConfigGpio( uint32 nWhichConfig )
{
  uint32 nWhichGpio = (uint32)HAL_GPIO_NUMBER(nWhichConfig);

  if( nWhichGpio < tHALTLMMInit.nNumGpio )
  {
     /* If an output value was specified. */
    if( HAL_GPIO_OUTVAL(nWhichConfig) == HAL_TLMM_OUTPUT_LOW )
    {
      HAL_tlmm_WriteGpio( nWhichConfig, FALSE );
    }
    else if( HAL_GPIO_OUTVAL(nWhichConfig) == HAL_TLMM_OUTPUT_HIGH )
    {
      HAL_tlmm_WriteGpio( nWhichConfig, TRUE );
    } 
 
    HAL_tlmm_WriteConfig(nWhichGpio, (uint32)HAL_TLMM_GPIO_CONFIG_MASK(nWhichConfig));

  }
}


/*===============================================================================
FUNCTION  
  void HAL_tlmm_Save ( void )

DESCRIPTION
   Saves the contents of the GPIO registers.

PARAMETERS
   None.

DEPENDENCIES
   None.

RETURN VALUE
   None.

SIDE EFFECTS
   None.

===============================================================================*/
void HAL_tlmm_Save( void )
{
  /* Nothing to do here. */
}


/*===============================================================================
FUNCTION  
  void HAL_tlmm_Restore( void )

DESCRIPTION
   Restores the state of the GPIO_OUT and GPIO_OE registers.

PARAMETERS
   None.

DEPENDENCIES
   None.

RETURN VALUE
   None.

SIDE EFFECTS
   None.
===============================================================================*/
void HAL_tlmm_Restore( void )
{
  /* Nothing to do here. */
}


/*===============================================================================

FUNCTION  
  HAL_tlmm_ReadGpio( uint32 nWhichConfig )

DESCRIPTION
   Returns the boolean value read at the register location extracted 
   from the configuration.

PARAMETERS
   The packed configuration data containing GPIO number and configuration.

DEPENDENCIES
   None. 

RETURN VALUE
   Returns the value "HIGH" or "LOW" as a boolean value.

SIDE EFFECTS
   None.

===============================================================================*/
boolean HAL_tlmm_ReadGpio( uint32 nWhichConfig )
{
  boolean retval = FALSE;
  uint32 nWhichGpio = (uint32)HAL_GPIO_NUMBER(nWhichConfig);

  if( nWhichGpio < tHALTLMMInit.nNumGpio )
  {
    if( HWIO_TLMM_GPIO_IN_OUTn_INMI(tHALTLMMInit.nBaseAddress, nWhichGpio, 0x1))
      retval = TRUE;
  }
  return(retval);
}


/*===============================================================================

FUNCTION  
  void HAL_tlmm_WriteGpio( uint32 nWhichConfig, bool bValue )

DESCRIPTION
   Outputs the supplied value to the GPIO register at the GPIO location..

DEPENDENCIES
   The GPIO should be configured to be output before calling this function;
   otherwise, the value written to the GPIO may not take effect.

RETURN VALUE
   None.

SIDE EFFECTS
   None.

===============================================================================*/
void HAL_tlmm_WriteGpio( uint32 nWhichConfig, boolean bValue )
{
  uint32 nWhichGpio = (uint32)HAL_GPIO_NUMBER(nWhichConfig);

  if(nWhichGpio < tHALTLMMInit.nNumGpio)
  {
    if(TRUE == bValue)
    {
       HWIO_TLMM_GPIO_IN_OUTn_OUTMI(tHALTLMMInit.nBaseAddress, nWhichGpio, 0x2, 0x2);
    }
    else
    {
       HWIO_TLMM_GPIO_IN_OUTn_OUTMI(tHALTLMMInit.nBaseAddress, nWhichGpio, 0x2, 0x0);
    }
  }
}

/*===============================================================================

FUNCTION  
   void HAL_tlmm_WriteGpioGroup( uint32 nWhichConfigSet[], uint16 nWhatSize )

DESCRIPTION
   Outputs a given value to a group of GPIOs based on the input parameters.

PARAMETERS
   nWhichConfigSet[]  - The array of GPIO configurations to write to.
   nWhatSize          - The size of the above array.
   bWriteVal          - Boolean representation of the value to write:
                            TRUE  = HIGH 
                            FALSE = LOW

DEPENDENCIES
   The GPIO should be configured to be output before calling this function;
   otherwise, the value written to the GPIO may not take effect.

RETURN VALUE
   None.

SIDE EFFECTS
   None.

===============================================================================*/
void HAL_tlmm_WriteGpioGroup
(
  uint32 *nWhichConfigSet, 
  uint32 nWhatSize,
  boolean bWriteVal
)
{
  uint32 nIdx;

  for( nIdx=0; nIdx< (uint32)nWhatSize; ++nIdx )
    HAL_tlmm_WriteGpio(nWhichConfigSet[nIdx], bWriteVal);
}


/*===============================================================================

FUNCTION  
  void HAL_tlmm_ConfigGpioGroup ( uint32 nWhichGpioSet[], 
                                  uint32 nWhichCfgSet[], 
                                  uint32 size )

DESCRIPTION
   Configures a group of GPIOs based on the supplied input parameters.  Each
   array contains a GPIO/Configuration set, but we extract only the GPIO from
   the first array and the configuration from the second.  This allows GPIO
   groups to be set to several different configurations, such as primary,
   sleep, or default group configuration.

PARAMETERS
   nWhichGpioSet[]  - An array of GPIO configurations to extract the GPIO 
                      numbers to configure.
   nWhichCfgSet[]   - An array of GPIO configurations to extract the GPIO
                      configuration information to set the above GPIOs to.
   nWhatSize        - The size of the first array.

DEPENDENCIES
   None.

RETURN VALUE
   None.

SIDE EFFECTS
   None.

===============================================================================*/
void HAL_tlmm_ConfigGpioGroup
(
  uint32 *nWhichGpioSet,
  uint32 nWhatSize
)
{
  uint32 nIdx;

  for( nIdx=0; nIdx<(uint32)nWhatSize; ++nIdx )
    HAL_tlmm_ConfigGpio(nWhichGpioSet[nIdx]);
}


/*===============================================================================

FUNCTION  
  void HAL_tlmm_GetOutput ( uint32 nWhichGpio, boolean value )

DESCRIPTION
   Reads the output state of a GPIO configured as a generic bit-banged
   operation.

PARAMETERS
   GPIO number to read output from.

DEPENDENCIES
  GPIO must be programmed as a generic output, or this will return FALSE.

RETURN VALUE
  TRUE  - Corresponds to a HIGH value.
  FALSE - Corresponds to a LOW value.

SIDE EFFECTS
  None.
===============================================================================*/
boolean HAL_tlmm_GetOutput
(
  uint32 nWhichGpio
)
{
    dword  val = 0;
    /* Ensure GPIO number is valid. */
    if( nWhichGpio < tHALTLMMInit.nNumGpio )
    {
      val =  HWIO_TLMM_GPIO_IN_OUTn_INMI(tHALTLMMInit.nBaseAddress, nWhichGpio, 0x1);
      if( val )
        return(TRUE);
    }
    return(FALSE);
}


/*=========================================================================

FUNCTION  
  void HAL_tlmm_SetPort(HAL_tlmm_PortType ePort, uint32 mask, uint32 value)

DESCRIPTION
   Selects the specified port if it is defined.

PARAMETERS
   ePort - The requested port to configure.
   mask  - The mask to use for this port.
   value - The value to be written to the port.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_SetPort(HAL_tlmm_PortType nPortOffs, uint32 nMask, uint32 nValue)
{
  uint32 inValue = 0;

  inValue = in_dword(tHALTLMMInit.nBaseAddress + nPortOffs);
  inValue &= ~nMask;

  out_dword((tHALTLMMInit.nBaseAddress + nPortOffs), (inValue | (nMask & nValue)));


} /* END HAL_tlmm_SetPort */


/*=========================================================================

FUNCTION  
  void HAL_tlmm_GetNumberGpio( uint32* pnNumGpio )

DESCRIPTION
   Returns the number of GPIO supported on this target.

PARAMETERS
   pnNumGpio - Pointer to the number of GPIO to return.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_GetNumberGpio( uint32* pnNumGPIO )
{
  *pnNumGPIO = tHALTLMMInit.nNumGpio;
}


/*=========================================================================

FUNCTION  
  void HAL_tlmm_SetPull( uint32 nGpioNumber, HAL_tlmm_PullType nPull )

DESCRIPTION
   Updates the PULL value of a GPIO.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   ePull       - The HAL_tlmm_PullType value to set to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_SetPull( uint32 nGpioNumber, HAL_tlmm_PullType ePull )
{
  uint32 nValue = 0;
  if( nGpioNumber < tHALTLMMInit.nNumGpio )
  {
    nValue = ( HWIO_TLMM_GPIO_CFGn_INI(tHALTLMMInit.nBaseAddress, nGpioNumber) & \
                     ~( HWIO_TLMM_GPIO_CFGn_GPIO_PULL_BMSK));

    nValue |= (ePull << HWIO_TLMM_GPIO_CFGn_GPIO_PULL_SHFT);

     HWIO_TLMM_GPIO_CFGn_OUTI(tHALTLMMInit.nBaseAddress, nGpioNumber, nValue);
  }

} /* END HAL_tlmm_SetPull */


/*=========================================================================

FUNCTION  
  void HAL_tlmm_SetDirection( uint32 nGpioNumber, HAL_tlmm_DirType nPull )

DESCRIPTION
   Changes the direction of a GPIO.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   eDirection  - The HAL_tlmm_DirType value to change to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_SetDirection
(
  uint32 nGpioNumber,
  HAL_tlmm_DirType eDirection
)
{
  uint32 nValue = ( HWIO_TLMM_GPIO_CFGn_INI(tHALTLMMInit.nBaseAddress, nGpioNumber) & \
                   ~(HWIO_TLMM_GPIO_CFGn_GPIO_OE_BMSK));

  nValue |= (eDirection <<  HWIO_TLMM_GPIO_CFGn_GPIO_OE_SHFT);

   HWIO_TLMM_GPIO_CFGn_OUTI(tHALTLMMInit.nBaseAddress, nGpioNumber, nValue);

} /* END HAL_tlmm_SetDirection */


/*=========================================================================

FUNCTION  
  void HAL_tlmm_SetDriveStrength( uint32 nGpioNumber, HAL_tlmm_DriveType nPull )

DESCRIPTION
   Changes the drive strength of a GPIO.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   eDrive      - The HAL_tlmm_DriveType value to change to.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_SetDriveStrength
(
  uint32 nGpioNumber,
  HAL_tlmm_DriveType eDrive
)
{
  uint32 nValue = (HWIO_TLMM_GPIO_CFGn_INI(tHALTLMMInit.nBaseAddress, nGpioNumber) & \
                    ~(HWIO_TLMM_GPIO_CFGn_DRV_STRENGTH_BMSK));

  nValue |= (eDrive <<  HWIO_TLMM_GPIO_CFGn_DRV_STRENGTH_SHFT);

   HWIO_TLMM_GPIO_CFGn_OUTI(tHALTLMMInit.nBaseAddress, nGpioNumber, nValue);

} /* END HAL_tlmm_SetDriveStrength */


/*=========================================================================

FUNCTION  
  void HAL_tlmm_SetFunction( uint32 nGpioNumber, HAL_tlmm_DriveType nPull )

DESCRIPTION
   Changes the function select of a GPIO.  Only use this API if you know
   what you're doing as HW may enter a bad state if not properly set.

PARAMETERS
   nGpioNumber - The GPIO nubmer to change the direction for.
   nFuncVal    - The Function select to set.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_SetFunction
(
  uint32 nGpioNumber,
  uint32 nFuncVal
)
{
  uint32 nValue =  HWIO_TLMM_GPIO_CFGn_INI(tHALTLMMInit.nBaseAddress, nGpioNumber) & \
                    ~(HWIO_TLMM_GPIO_CFGn_FUNC_SEL_BMSK);

  nValue |= (nFuncVal <<  HWIO_TLMM_GPIO_CFGn_FUNC_SEL_SHFT);

   HWIO_TLMM_GPIO_CFGn_OUTI(tHALTLMMInit.nBaseAddress, nGpioNumber, nValue);

} /* END HAL_tlmm_SetFunction */


/*=========================================================================

FUNCTION  
  void HAL_tlmm_GetConfig( uint32* pnNumGpio )

DESCRIPTION
   Returns the current configuration of a GPIO read from HW.

PARAMETERS
   nGpioNumber - The GPIO number to read the configuration for.
   tGpio       - The data structure to hold the configuration information.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

=========================================================================*/

void HAL_tlmm_GetConfig
(
  uint32 nGpioNumber,
  HAL_tlmm_GpioType* tGpio
)
{
  uint32 nTempConfig =  HWIO_TLMM_GPIO_CFGn_INI(tHALTLMMInit.nBaseAddress, nGpioNumber);

  tGpio->nFunc =  ((nTempConfig &  HWIO_TLMM_GPIO_CFGn_FUNC_SEL_BMSK)>> HWIO_TLMM_GPIO_CFGn_FUNC_SEL_SHFT);
  tGpio->nDir =   ((nTempConfig &  HWIO_TLMM_GPIO_CFGn_GPIO_OE_BMSK)>> HWIO_TLMM_GPIO_CFGn_GPIO_OE_SHFT);
  tGpio->nPull =  ((nTempConfig &  HWIO_TLMM_GPIO_CFGn_GPIO_PULL_BMSK)>> HWIO_TLMM_GPIO_CFGn_GPIO_PULL_SHFT);
  tGpio->nDrive = ((nTempConfig &  HWIO_TLMM_GPIO_CFGn_DRV_STRENGTH_BMSK)>>  HWIO_TLMM_GPIO_CFGn_DRV_STRENGTH_SHFT);
}


/*=============================================================================*/

