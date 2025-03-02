/*!
  @file
  ConnectionAttempt.h

  @brief
  Connection Attempt Log packet parser

*/

/*===========================================================================

  Copyright (c) 2007 Qualcomm Technologies Incorporated. All Rights Reserved

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

===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/lte/RRC/qxdm_parser/src/Parsers/ConnectionAttempt.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
06/13/07   sb      Initial version
===========================================================================*/

#ifndef CONNECTION_ATTEMPT_H
#define CONNECTION_ATTEMPT_H

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/

#include "Common.h"

/*===========================================================================

                   EXTERNAL DEFINITIONS AND TYPES

===========================================================================*/


/*===========================================================================

                    EXTERNAL FUNCTION PROTOTYPES

===========================================================================*/

extern void ConnectionAttemptSummary
(
  const LogPacketHeaderType   *pInBuf,  
  UINT                        nBufSize,  
  COutputBuffer               &OutBuf
);

#endif /* CONNECTION_ATTEMPT_H */
