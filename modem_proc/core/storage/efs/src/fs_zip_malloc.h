/***********************************************************************
 * fs_zip_malloc.h
 *
 * FS ZIP Malloc Module.
 * Copyright (C) 2011-2012 QUALCOMM Technologies, Inc.
 *
 * This module provides API to manage dynamic memory allocation for FS_ZIP.
 * This library assume frees are called in reverse order of mallocs.
 * Pattern malloc(a) malloc(b) free(a) free(b) is not allowed.
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/core.mpss/3.5.c12.3/storage/efs/src/fs_zip_malloc.h#1 $ $DateTime: 2016/12/13 07:59:23 $ $Author: mplcsds1 $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2012-05-24   nr    Fix bugs in fs_zip and fs_tar initialization.
2011-06-28   nr    Create

===========================================================================*/

#ifndef __FS_ZIP_MALLOC_H__
#define __FS_ZIP_MALLOC_H__

#include "fs_config_i.h"
#include "comdef.h"

#ifdef FEATURE_EFS_ZIP


typedef struct fs_zip_malloc_heap_state* fs_zip_malloc_handle;

/**************************************************************************//**
 * @par Name:
 *   fs_zip_malloc_init - Initialize the malloc module.
 *
 * @par Synopsis:
 *  @code
 *    #include "fs_zip_malloc.h"
 *    void fs_zip_malloc_init (void);
 *  @endcode
 *
 * @par Description:
 *  Initializes the malloc handle and data structures.
 *
******************************************************************************/
void
fs_zip_malloc_init (void);

/**************************************************************************//**
 * @par Name:
 *   fs_zip_malloc_open - Open the malloc heap for zip and return the handle .
 *
 * @par Synopsis:
 *  @code
 *    #include "fs_zip_malloc.h"
 *    fs_zip_malloc_handle
 *    fs_zip_malloc_open (void *heap_start, uint32 heap_size);
 *  @endcode
 *
 * @par Description:
 *  Initializes the malloc heap and returns a handle.
 *
 * @param heap_start
 *  The buffer to use as the heap for malloc.
 *
 * @param heap_size
 *  Size of the previous argument.
 *
 * @return
 * Returns the pointer to the handle to use.
 *
******************************************************************************/
fs_zip_malloc_handle
fs_zip_malloc_open (void *heap_start, uint32 heap_size);

/**************************************************************************//**
 * @par Name:
 *   fs_zip_malloc_alloc - Allocate memory and return pointer to it .
 *
 * @par Synopsis:
 *  @code
 *    #include "fs_zip_malloc.h"
 *    void* fs_zip_malloc_alloc (void *handle, unsigned items, unsigned size);
 *  @endcode
 *
 * @par Description:
 *  Allocate items*size of memory and return a pointer to the memory.
 *
 * @param handle
 *  The handle generated by fs_zip_malloc_open.
 *
 * @param items
 *  Number of items to allocate.
 *
 * @param size
 *  Size of each item.
 *
 * @return
 * Returns the pointer to the start of allocated memory.
 *
******************************************************************************/
void*
fs_zip_malloc_alloc (void *handle, unsigned items, unsigned size);

/**************************************************************************//**
 * @par Name:
 *   fs_zip_malloc_free - Free the memory .
 *
 * @par Synopsis:
 *  @code
 *    #include "fs_zip_malloc.h"
 *    void fs_zip_malloc_free (void *handle, void *addr);
 *  @endcode
 *
 * @par Description:
 *  Free the memory specified as addr and return it to heap.
 *
 * @param handle
 *  The handle generated by fs_zip_malloc_open.
 *
 * @param addr
 *  The start of memory to free.
 *
******************************************************************************/
void
fs_zip_malloc_free (void *handle, void *addr);

/**************************************************************************//**
 * @par Name:
 *   fs_zip_malloc_close - Clear the heap and check for memory leaks.
 *
 * @par Synopsis:
 *  @code
 *    #include "fs_zip_malloc.h"
 *    void fs_zip_malloc_close (void);
 *  @endcode
 *
 * @par Description:
 *  Clear the heap and check for memory leaks.
 *
 * @param malloc_handle
 *  The handle generated by fs_zip_malloc_open.
 *
******************************************************************************/
void
fs_zip_malloc_close (fs_zip_malloc_handle malloc_handle);

#endif /*end FEATURE_EFS_ZIP */
#endif /*end __FS_ZIP_MALLOC_H__ */