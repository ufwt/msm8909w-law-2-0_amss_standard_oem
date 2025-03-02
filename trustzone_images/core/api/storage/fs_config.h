/***********************************************************************
 * fs_config.h
 *
 * EFS2 configuration settings.
 * Copyright (C) 2010 Qualcomm Technologies, Inc.
 *
 * This file contains all of the settable parameters used in EFS2.
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/storage/fs_config.h#1 $ $DateTime: 2016/06/17 14:31:11 $ $Author: pwbldsvc $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2010-07-12   rp    Added defines for major and minor number for API files.
2010-02-08   rp    Create

===========================================================================*/

#ifndef __FS_CONFIG_H__
#define __FS_CONFIG_H__


#include "customer.h"

/** Identifies the major version number of this API file. */
#define VER_FS_CONFIG_H_MAJOR     1
/** Identifies the minor version number of this API file. */
#define VER_FS_CONFIG_H_MINOR     1

/**********************************************************************
 * CONFIGURATION ITEMS
 *
 * These parameters can be configured as desired.  Note that changing their
 * values doesn't affect existing files in the filesystem.  If a build is
 * loaded with smaller parameters for these values than earlier builds,
 * files may become inaccessible.
 */

/**
 * Maximum length of a full pathname, not including a trailing '\\0'
 * character.  The filesystem only has a few buffers of this length, so it
 * doesn't increase EFS2's RAM usage much, however, other code (such as
 * fs_compat, and fs_am) us this value to allocate a large number of
 * buffers. */
#ifndef FS_PATH_MAX
  #define FS_PATH_MAX 1024
#endif

/**
 * Maximum length of the 'name' component of a file.  The name is the
 * longest string of characters delimited by beginning of string, the '/'
 * character or the end of the string.  This is the maximum length for a
 * filename or directory name.
 */
#ifndef FS_NAME_MAX
  #define FS_NAME_MAX 768
#endif

/* Maximum number of data pages in a transaction.  This needs to be small
 * enough so that all of the transaction data can be processed in a single
 * log page. */
#define FS_MAX_TRANSACTION_DATA_PAGES 16

/** Maximum transaction size in bytes. */
#define FS_MAX_TRANSACTION (FS_MAX_TRANSACTION_DATA_PAGES * EFS_PAGE_SIZE)



#endif /* not __FS_CONFIG_H__ */
