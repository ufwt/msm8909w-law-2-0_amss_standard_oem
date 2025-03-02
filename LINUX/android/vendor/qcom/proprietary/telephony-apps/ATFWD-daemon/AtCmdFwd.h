/*===========================================================================

Copyright (c) 2015, Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifndef ANDROID_HARDWARE_ATCMDFWD_H
#define ANDROID_HARDWARE_ATCMDFWD_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int opcode;
  char *name;
  int ntokens;
  char **tokens;
} AtCmd;

typedef struct {
  int result;
  char *response;
} AtCmdResponse;

extern void freeAtCmdResponse(AtCmdResponse *response);
extern AtCmd *copyAtCmd(AtCmd *cmd);
#define QCRIL_NOTUSED( var ) ((var) == (var))

#ifdef __cplusplus
}
#endif

#endif /* ANDROID_HARDWARE_ATCMDFWD_H */

