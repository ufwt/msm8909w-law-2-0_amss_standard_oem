/*!
  @file
  lte_rrc_log_serv_cell_info_parser.h

  @brief
  REQUIRED brief one-sentence description of this C header file.

  @detail
  OPTIONAL detailed description of this C header file.
  - DELETE this section if unused.

*/

/*===========================================================================

  Copyright (c) 2008 Qualcomm Technologies Incorporated. All Rights Reserved

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

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/lte/RRC/qxdm_parser/src/Parsers/lte_rrc_log_serv_cell_info_parser.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
01/08/09   amit    Initial Version
===========================================================================*/

#ifndef LTE_RRC_LOG_SERV_CELL_INFO_PARSER_H
#define LTE_RRC_LOG_SERV_CELL_INFO_PARSER_H

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/

#include "comdef.h"
#include "Parsers.h"


/*===========================================================================

                   EXTERNAL DEFINITIONS AND TYPES

===========================================================================*/




/*===========================================================================

                    EXTERNAL FUNCTION PROTOTYPES

===========================================================================*/

void lte_rrc_log_serv_cell_info_parser_summarytext
(
  const LogPacketHeaderType   *pInBuf,
  UINT                        nBufSize,
  COutputBuffer               &OutBuf
);

// Parse a Serv cell info log packet
void RrcServCellInfoParser
(
const LogPacketHeaderType   *pInBuf,
UINT                        nBufSize,
COutputBuffer               &pOutBuf
);

#endif /* LTE_RRC_LOG_SERV_CELL_INFO_PARSER_H */
