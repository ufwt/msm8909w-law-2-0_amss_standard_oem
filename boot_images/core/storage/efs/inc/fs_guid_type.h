/***********************************************************************
 * fs_guid_type.h
 *
 * The fs guid type module.
 * Copyright (C) 2012 Qualcomm Technologies, Inc.
 *
 * The fs guild type module defines the guid structure used in EFS code.
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.bf/3.1.2.c3/boot_images/core/storage/efs/inc/fs_guid_type.h#1 $ $DateTime: 2015/09/01 00:30:35 $ $Author: pwbldsvc $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2012-12-05   nr   Update description.
2012-10-03   nr   Create

===========================================================================*/

#ifndef __FS_GUID_TYPE_H__
#define __FS_GUID_TYPE_H__

#include "comdef.h"

PACKED struct fs_guid_type
{
  uint32  data1;
  uint16  data2;
  uint16  data3;
  uint8   data4[8];
} PACKED_POST;

#endif /*__FS_GUID_TYPE_H__ */
