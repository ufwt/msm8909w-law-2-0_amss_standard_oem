#ifndef FTM_1X_LOG_H
#define FTM_1X_LOG_H

/*!
  @file
  ftm_1x_log.h

  @brief
  This module defines the function prototypes and defintions used by
  1x RF Logging.
*/

/*==============================================================================

  Copyright (c) 2010 - 2013 Qualcomm Technologies Incorporated. All Rights Reserved

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

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.

  $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/rftech_cdma/1x/ftm/inc/ftm_1x_log.h#1 $

when       who     what, where, why
--------   ---     ------------------------------------------------------------- 
03/14/13   aro     Deprecated Composite Calibration and TxSweep Commands
09/09/11   aro     Changed argument type to INT32
09/09/11   aro     Renamed CDMA logging functions to reflect primary and
                   secondary chains
09/07/11   aro     changed chain 1 agc data to pointer type
08/24/11   aro     Added functions to initialize, de-initialize and push the
                   RFM_DEVICE_0 AGC logging data
03/07/11   aro     Added Composite Calibration Log function
12/13/10   aro     Removed FTM_HAS_LOGGING Feature
12/07/10   aro     Initial Revision : Common Calibration

==============================================================================*/

#include "comdef.h"
#include "ftm_cdma_log.h"

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/*! Data structure containing CDMA 1x logging information */
typedef struct
{

  ftm_cdma_c0_agc_type *c0_agc;
  /*!< Pointer to data structure containing Chain 0 AGC log information */

  ftm_cdma_c1_agc_type *c1_agc;
  /*!< Pointer to data structure containing Chain 1 AGC log information */

} ftm_1x_log_data_type;

/*----------------------------------------------------------------------------*/
void
ftm_1x_log_primary_agc_init_func
(
  void
);

/*----------------------------------------------------------------------------*/
void
ftm_1x_log_primary_agc_exit_func
(
  void
);

/*----------------------------------------------------------------------------*/
void
ftm_1x_log_primary_agc_cb
(
  int32 interval
);

/*----------------------------------------------------------------------------*/
void
ftm_1x_log_diversity_agc_init_func
(
  void
);

/*----------------------------------------------------------------------------*/
void
ftm_1x_log_diversity_agc_exit_func
(
  void
);

/*----------------------------------------------------------------------------*/
void
ftm_1x_log_diversity_agc_cb
(
  int32 interval
);

#ifdef __cplusplus
}
#endif

#endif /* FTM_1X_LOG_H */

