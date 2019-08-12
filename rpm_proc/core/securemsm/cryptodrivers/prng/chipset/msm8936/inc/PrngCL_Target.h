#ifndef _PRNGCL_TARGET_H
#define _PRNGCL_TARGET_H
/*===========================================================================

                       P R N G E n g i n e D r i v e r

                       H e a d e r  F i l e (e x t e r n a l)

DESCRIPTION
  This header file contains HW Crypto specific declarations.

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None

Copyright (c) 2010 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

  This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/rpm.bf/2.1.1/core/securemsm/cryptodrivers/prng/chipset/msm8936/inc/PrngCL_Target.h#1 $
  $DateTime: 2015/02/25 02:53:43 $
  $Author: pwbldsvc $
when       who     what, where, why
--------   ---     ----------------------------------------------------------
2010-06-25   yk     Initial version
============================================================================*/

/*===========================================================================

                           INCLUDE FILES


===========================================================================*/
#include "comdef.h"
#include "HALhwio.h"
#include "PrngCL_Msmhwioreg.h"
#include "assert.h"


/*===========================================================================

                      PUBLIC DATA DECLARATIONS

===========================================================================*/
#define SEC_RETAILMSG(a, b, c, d)  MSG_ERROR(a, b, c, d)

#define SEC_PRNG_STATUS PRNG_PRNG_STATUS
#define SEC_PRNG_DATA_OUT PRNG_PRNG_DATA_OUT
#define SEC_PRNG_CONFIG PRNG_PRNG_CONFIG
#define SEC_PRNG_EN PRNG_EN
#define SEC_PRNG_LFSR_CFG PRNG_PRNG_LFSR_CFG

#define SEC_LFSR0_EN LFSR0_EN
#define SEC_LFSR1_EN LFSR1_EN
#define SEC_LFSR2_EN LFSR2_EN
#define SEC_LFSR3_EN LFSR3_EN

#define SEC_HWIO_PRNG_STATUS_DATA_AVAIL_BMSK HWIO_PRNG_PRNG_STATUS_DATA_AVAIL_BMSK

#endif /* _PRNGCL_TARGET_H */