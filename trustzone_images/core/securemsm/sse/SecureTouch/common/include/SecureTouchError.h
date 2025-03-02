/*
 * Copyright (c) 2013 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#pragma once

#include "sse_error.h"

#define TL_SECURETOUCH_ERROR_BASE 0x00010000

#define E_ST_BUSY                   SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x1)
#define E_ST_DRIVER_BUSY            SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x2)
#define E_ST_INVALID_LAYOUT         SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x3)
#define E_ST_NO_SESSION_ACTIVE      SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x4)
#define E_ST_INPUT_NOT_IN_PROGRESS  SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x5)
#define E_ST_DRIVER_ERROR           SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x6)
#define E_ST_MULTI_TOUCH_DETECTED   SSE_ERROR_CREATE(TL_SECURETOUCH_ERROR_BASE,0x7)
