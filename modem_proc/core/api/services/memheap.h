#ifndef MEMHEAP_H
#define MEMHEAP_H
/**
  @file memheap.h
  @brief A simple sub-allocator to manage memory allocations and deallocations
  using a Next Fit strategy. 

*/
/*===========================================================================
NOTE: The @brief description and any detailed descriptions above do not appear 
      in the PDF. 

      The Utility_Services_API_mainpage.dox file contains all file/group 
      descriptions that are in the output PDF generated using Doxygen and 
      Latex. To edit or update any of the file/group text in the PDF, edit 
      the Utility_Services_API_mainpage.dox file or contact Tech Pubs.

      The above description for this file is part of the "utils_memory" 
      group description in the Utility_Services_API_mainpage.dox file. 
===========================================================================*/
/*===========================================================================
 Note that these routines are FULLY re-entrant.  Furthermore, while
  performing memory allocation/deallocation calls on one heap, the routines
  may be interrupted to perform memory allocation/deallocation calls on
  different heaps without blocking or corruption.  However, should an
  interrupting task attempt to perform memory allocation/deallocation
  on the same heap that had a critical section interrupted, it will block
  allowing the first call to finish.  All this is accomplished by giving
  each heap its own semaphore.

FEATURE_MEMHEAP_MT
Activates multi threading support for the heap

  Usage Notes - Avoiding Fragmentation
 
1. If all bytes in the heap are freed, the heap is guaranteed to be returned
 to the same state as after a call to mem_init_heap, except that the
 values of maxUsed & maxRequest are not reset.  The order in which blocks
 are freed is irrelevant so long as they ALL are freed.
 
2. After n consecutive malloc/calloc calls, in a heap with non-fragmented
 free space (and no intervening realloc calls that return a new pointer),
 calling free in the reverse order on the n blocks guarantees that the heap
 will be returned to the exact same state as before the n alloc calls.
 
3. FEATURE_HEAP_SMALLER_OVERHEAD == 0
 (2) still applies, except the calls to free may be made in any order and
 after all n blocks are freed, the heap is guaranteed to be returned to the
 exact same state as prior to the n alloc calls.
 
4. FEATURE_HEAP_SMALLER_OVERHEAD == 1
 The overhead per heap block is 8 bytes.  However it's not possible to backup
 the next-block-to-start-searching-for-free-space pointer, so the heap MAY
 become more fragmented, but it MAY NOT -- it depends on the alloc/free
 calling patterns.
 
5. FEATURE_HEAP_SMALLER_OVERHEAD == 0
The overhead per heap block is 12 bytes.  Backing up is possible, so some
 fragmention that otherwise MIGHT occur can be prevented.  There is very little
 performance cost for this, the big expense is the additional 4 bytes of overhead
 per heap block.

===========================================================================*/
/*
Copyright (c) 1997-2014,2016 Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Confidential and Proprietary. 
*/
/*===========================================================================

                                 Edit History

$PVCSPath: O:/src/asw/COMMON/vcs/memheap.h_v   1.1   07 Mar 2002 18:48:56   rajeevg  $
$Header: //components/rel/core.mpss/3.5.c12.3/api/services/memheap.h#1 $ $DateTime: 2016/12/13 07:59:23 $ $Author: mplcsds1 $

when       who     what, where, why
--------   ---     --------------------------------------------------------
02/11/16   nk      Removal of 16byte blocks
11/12/14   ps      Remove Debug Array
01/15/14   rks     CR578502:dynamic heap design(heap sharing)
01/07/14   rks     CR491964:Add dynamic sections support in memheap
09/26/13   rks     CR524975:Fix bug in mem_memalign
02/05/13   ps      Add debug information to the block header
09/05/12  mg 	   enable usage of modem heap as memheap
08/30/12  rks      robust XOR logic and enable PRNG uses
05/10/12   rks     memheap2 
03/22/11   llg     (Tech Pubs) Edited/added Doxygen comments and markup.
11/11/10   EBR     Doxygenated File.
03/31/009  sri     amssassert.h is further featurised based on APPS/QDSP6
09/01/004   gr     Deleted the context argument to the debug versions of
                   the memheap functions; the context is no longer used.
11/07/03    gr     More debug support.
09/23/03    gr     Added functions to retrieve information about a heap.
09/17/03    gr     Mainlined FEATURE_HEAP_DEBUG. Added support for storing a
                   filename hash and a line number in the block header.
03/11/03    gr     Added support for a heap-specific locking mechanism. This
                   allows some heaps to be restricted to task-context use,
                   and others to be usable from ISRs.
10/01/01    gr     Added support for some basic heap statistics.
11/17/00   crr     Change stdlib.h to stddef.h for size_t def. Add forward
                     decl for struct mem_heap_struct.
11/09/00   jct     Match to coding convention, remove of semaphore use, replace
                   with REX critical sections, remove stddef.h inclusion
02/17/99   kjm     Added realloc function.  Minor additions to
                     mem_heap_struct.  Added giant function descriptions.
11/24/98   kjm     Ported to C-only code for use in phone software from
                     original SubAllocator.h file.
08/22/97   kjm     Original SubAllocator.h file created.
===========================================================================*/
/** @addtogroup utils_memory
@{ */

/* ------------------------------------------------------------------------
** Includes
** ------------------------------------------------------------------------ */

#include "comdef.h"
#ifndef FEATURE_WINCE
#if ((defined (IMAGE_MODEM_PROC)) || (! defined FEATURE_MULTIPROCESSOR) || \
     (defined (FEATURE_BMPOS_QNK)))
#include "amssassert.h"
#endif
#else
#error code not present
#endif
#include <stddef.h>

/* ------------------------------------------------------------------------
** Defines
** ------------------------------------------------------------------------ */

/** Memory heap Ver 2.0. */
#define MEMHEAP_VERSION 0x0200

// defining feature debug be default
#ifndef FEATURE_MBA_MEMHEAP_IMAGE
#define FEATURE_MEMHEAP2_USE_PRNG
#define FEATURE_MEM_DEBUG
//#define FEATURE_ENABLE_HEAP_PROFILING 
#endif
/** @cond 
*/


#ifndef FEATURE_HEAP_SMALLER_OVERHEAD
   #define FEATURE_HEAP_SMALLER_OVERHEAD 1
#endif
/** @endcond */

#ifndef MEMHEAP_CRIT_SECT_SIZE
   #define MEMHEAP_CRIT_SECT_SIZE 64
#endif

/** Character to which the pad field is set in the block header. This macro
  is useful for catching heap corruption.
*/
#define MEMHEAP_PAD_CHAR 0xaa

#define MEMHEAP_EOK                         0  /**< Operation successfully performed. */
#define MEMHEAP_EMEM                        1  /**< Not enough memory to perform operation.*/
#define MEMHEAP_EARGS                       2  /**< Invalid argument. */ 
#define MEMHEAP_EFAILED                     3  /**< Operation failed. */
#define MEMHEAP_ENOINIT                     4  /**< Parameter not Initialized. */
#define MEMHEAP_EUNSUPP                     5  /**< Operation unsupported */

/* ------------------------------------------------------------------------
** Types
** ------------------------------------------------------------------------ */

/* Doxygen comments for this struct are in typedef struct mem_heap_struct */
struct mem_heap_struct;
/** 
  Called when there is not enough 
  room in the I/O heap to satisfy a request for specified bytes. The function 
  frees up any memory that it can before returning. The request is then 
  tried again. There are no restrictions on what this function does, including 
  memory allocation/deallocation calls. 
  
  Before calling the function, calls to the allocator failed 
  procedure on the I/O heap are disabled. After this function returns, the 
  calls are re-enabled. This disabling does NOT affect other heaps, so if 
  multiple heaps share the same allocator failed procedure, the procedure 
  is to be re-entrant.
   
  @param[in] heap_ptr     Heap on which the allocation is attempted.
  @param[in] request_size Size of the failed request.

  @return
  None.

  @dependencies
  None.
*/
typedef void (*mem_allocator_failed_proc_type)(
   struct mem_heap_struct *heap_ptr,
   size_t                  request_size
);

/* Each heap can have its own function that is used to lock the heap and
** free the heap.  mem_lock_fnc_type and mem_free_fnc_type are the types
** of these functions.
*/
/**
  Provides an abstraction so each function can have its own function to 
  lock the heap.

  @param[in] ptr Pointer to what is to be locked.

  @return
  None.

  @dependencies
  None.
*/
typedef void (*mem_lock_fnc_type)( void * ptr);

/**
  Provides an abstraction so each function can have its own function to 
  free the heap.

  @param[in] ptr Pointer to what is to be freed.

  @return
  None.

  @dependencies
  None.
*/
typedef void (*mem_free_fnc_type)( void * ptr);

#ifdef FEATURE_MEM_DEBUG
typedef struct {
   void *caller_ptr;
   uint32 stats_index;
}mem_block_header_debug_info;
#endif



/** @brief Header for each memory block allocated. The header describes the 
  properties of the block allocated to the client. Note that the size of this 
  structure must be a multiple of the largest alignment size required by the 
  host CPU.
*/
typedef struct mem_block_header_struct {
  uint16        header_guard;

  unsigned char extra;        /**< Extra bytes at the end of a block. */
  unsigned char section_index:5;
  unsigned char          start_flag:1;
  unsigned char          free_flag:1;  /**< Flag to indicate if this memory block 
                                   is free. */
  unsigned char          last_flag:1;/**< Flag to indicate if this is the last block 
                                   in the allocated section. */
  unsigned long forw_offset; /**< Forward offset. The value of the offset 
                                   includes the size of the header and the 
                                   allocated block. */
#ifdef FEATURE_MEM_DEBUG
  mem_block_header_debug_info header_debug_info;
#endif
} mem_block_header_type;

typedef struct mem_block_header_free_struct {
  uint16        header_guard;

  unsigned char extra;        /**< Extra bytes at the end of a block. */
  unsigned char section_index:5;
  unsigned char          start_flag:1;
  unsigned char          free_flag:1;  /**< Flag to indicate if this memory block 
                                   is free. */
  unsigned char          last_flag:1;/**< Flag to indicate if this is the last block 
                                   in the allocated section. */
  unsigned long forw_offset; /**< Forward offset. The value of the offset 
                                   includes the size of the header and the 
                                   allocated block. */
} mem_block_header_free_struct;
/** @brief Used to maintain the information about a heap. This 
  information is used for determining the allocated memory.
*/
#define MEMHEAP2_BIN_COUNT 32

//FreeBlockList implimentation
typedef struct freeBlockList_struct {
   struct mem_block_header_free_struct freeBlock;
   struct freeBlockList_struct    *nextPtr;
}freeBlockList;

typedef struct _BIN{
  freeBlockList *firstNode;
  freeBlockList *lastNode;
  uint16 binToUSeForMalloc;
  uint32 totalNodes;
}binStruct;
#define MEM_HEAP_SECTIONS_MAX     (16)
typedef struct _mem_heap_section
{
   mem_block_header_type                 *start_addr;       /*!< start address of section */
   uint32                size;        /*!< size of the section */
} mem_heap_section;


#ifdef FEATURE_MEM_DEBUG
#define MEMHEAP_MAX_THREADS 384
#define MEMHEAP_MAX_QURT_THREADS 1024
#define MEMHEAP_THREAD_ID_MASK 0xFFF
typedef struct
{
  uint32 current_usage;
  uint32 max_usage;
  uint32 quota;
} memheap_task_stats_type; 


/** 
Callback function for the heap quota enforcing client 
   
  @param[in] heap_ptr     Heap on which the allocation is attempted.
  @param[in] thread_id    Thread ID of the thread exceeding the quota
  @param[in] max_used   Maximum bytes used on the heap.

  @return
  0-SUCCESS
  1 - FAILED and section wil not be added. 

  @dependencies
  None.
*/

typedef uint32 (*memheap_get_quota_func_type)(void);



typedef void (*memheap_quota_exceeded_cb_type)(
   struct mem_heap_struct *heap_ptr,
   uint32 tid,
   size_t max_used
);


typedef struct 
{
   uint32 task_quota;
}memheap_quota_type;
#endif

typedef struct mem_heap_struct {
  uint32                         magic_num;
  mem_block_header_type         *first_block;   
  /**< First block in the heap. */
  mem_block_header_type         *next_block;    
  /**< Next free block in the heap. */
  unsigned long                  total_blocks;  
  /**< Total blocks in the heap. */
  unsigned long                  total_bytes;   
  /**< Total bytes available in the heap. */
  unsigned long                  used_bytes;    
  /**< Amount of bytes in use in the heap. */
  unsigned long                  max_used;      
  /**< Maximum amount that has been used in the heap. */
  unsigned long                  max_request;   
  /**< Maximum amount that has been requested in the heap. */
  mem_allocator_failed_proc_type fail_fnc_ptr;  
  /**< Pointer to the failed function. */
  mem_lock_fnc_type              lock_fnc_ptr;
  mem_free_fnc_type              free_fnc_ptr;
  //Function registered by client to get heap quota

#ifdef FEATURE_MEM_DEBUG  
  memheap_get_quota_func_type mem_get_quota_fnc_ptr;
  // Heap quota callback
  memheap_quota_exceeded_cb_type quota_cb;
#endif
  uint8 memheap_crit_sect[MEMHEAP_CRIT_SECT_SIZE];
  binStruct BIN[MEMHEAP2_BIN_COUNT];
  uint32 legacy_check;
   /**< this is random number used in XOR(guard_bytes) 
    calculation of free memory block  */
  uint16 magic_num_free;
/**< this is random number used in XOR(guard_bytes) 
    calculation of used memory block  */
  uint16 magic_num_used;
#ifdef FEATURE_ENABLE_HEAP_PROFILING
  uint32 debug_heap_index;
#endif
  uint16 magic_num_index;
  mem_heap_section sections[MEM_HEAP_SECTIONS_MAX];
  uint16           number_of_sections;

#ifdef FEATURE_MEM_DEBUG
  memheap_task_stats_type *heapStatistics;
#endif
  unsigned int mem_region;
  void *incomingBlock; /*added to help in debugging issues occurred inside mem_free() 
                       sometimes its difficult to figure out incoming block's address*/

} mem_heap_type;

#ifdef FEATURE_ENABLE_HEAP_PROFILING
typedef struct _memheap_profile_table_type {
  void * heap_ptr;
  uint32 malloc_avg;
  uint32 malloc_cnt;
  uint32 realloc_avg;
  uint32 realloc_cnt;
  uint32 free_avg;
  uint32 free_cnt;
  uint32 pad;
}memheap_profile_table_type;
#endif

enum {
  kUseLegacyImpl = 0,
  kUseOnlyLLImpl = 1,
  kUseBINsImpl = 2,
};

enum
{
   MEM_TLS_CREATE_ERR = 0x1,
   MEM_TLS_SET_ERR    = 0x2,
   MEM_TLS_GET_ERR    = 0x4   
};


/* ------------------------------------------------------------------------
** Functions
** ------------------------------------------------------------------------ */

#ifdef __cplusplus
   extern "C"
   {
#endif


/**
  Initializes the I/O heap object and sets up heap_mem_ptr for use with 
  the I/O heap object. 
 
  The heap_mem_ptr parameter may be aligned on any boundary. Beginning bytes 
  are skipped until a paragraph boundary is reached. NULL pointers must not 
  be passed in for heap_mem_ptr. The fail_fnc_ptr parameter may be NULL; 
  in which case, no function is called if mem_malloc() or mem_calloc() 
  is about to fail. If fail_fnc_ptr is provided, it is called once and the 
  allocation is attempted again. See mem_allocator_failed_proc_type() 
  for details.
  
  There is no protection for initializing a heap more than once. If a heap
  is reinitialized, all pointers previously allocated from the heap are
  immediately invalidated and their contents possibly destroyed. If this is 
  the desired behavior, a heap may be initialized more than once.
 
  @param[in] heap_ptr         Pointer to the statically allocated heap 
                              structure.
  @param[in,out] heap_mem_ptr Pointer to the contiguous block of memory used 
                              for this heap.
  @param[in] heap_mem_size    Size in bytes of the memory pointed to by 
                              heap_mem_ptr.
  @param[in] fail_fnc_ptr     Function to call when allocation fails; can be 
                              NULL.
 
  @return
  None.

  @dependencies
  None.
*/
/*lint -sem(mem_init_heap,1p,2p,2P>=3n) */
void mem_init_heap(
   mem_heap_type                 *heap_ptr,
   void                          *heap_mem_ptr,
   unsigned long                  heap_mem_size,
   mem_allocator_failed_proc_type fail_fnc_ptr
);

/**
  Initializes the I/O heap object and sets up heap_mem_ptr for use with 
  the I/O heap object. 
 
  The heap_mem_ptr parameter may be aligned on any boundary. Beginning bytes 
  are skipped until a paragraph boundary is reached. NULL pointers must not 
  be passed in for heap_mem_ptr. The fail_fnc_ptr parameter may be NULL; 
  in which case, no function is called if mem_malloc() or mem_calloc() 
  is about to fail. If fail_fnc_ptr is provided, it is called once and the 
  allocation is attempted again. See mem_allocator_failed_proc_type() 
  for details.
  
  There is no protection for initializing a heap more than once. If a heap
  is reinitialized, all pointers previously allocated from the heap are
  immediately invalidated and their contents possibly destroyed. If this is 
  the desired behavior, a heap may be initialized more than once. The way this 
  function is different from above is that it will call prngml_lite to get
  random numbers
 
  @param[in] heap_ptr         Pointer to the statically allocated heap 
                              structure.
  @param[in,out] heap_mem_ptr Pointer to the contiguous block of memory used 
                              for this heap.
  @param[in] heap_mem_size    Size in bytes of the memory pointed to by 
                              heap_mem_ptr.
  @param[in] fail_fnc_ptr     Function to call when allocation fails; can be 
                              NULL.
 
  @return
  None.

  @dependencies
  None.
*/
/*lint -sem(mem_init_heap,1p,2p,2P>=3n) */
void mem_init_heap_lite(
   mem_heap_type                 *heap_ptr,
   void                          *heap_mem_ptr,
   unsigned long                  heap_mem_size,
   mem_allocator_failed_proc_type fail_fnc_ptr
);

/**
  Deinitializes the heap_ptr object only if the heap is in the Reset state.
  Users are responsible for freeing all allocated pointers before calling 
  this function.
  
  @param[in] heap_ptr  Pointer to the heap structure to be deinitialized.
  
  @return
  None.
  
  @dependencies
  None.
*/
void mem_deinit_heap(
   mem_heap_type                 *heap_ptr
);

/*===========================================================================
FUNCTION print_memheap_profile_table

DESCRIPTION

===========================================================================*/
#ifdef FEATURE_ENABLE_HEAP_PROFILING
void print_memheap_profile_table(void);
#endif

void print_memheap_free_error_log(void);

/*===========================================================================
  Allocates enough space for elt_count elements each of elt_size bytes
  from the heap and initializes the space to NULL bytes. If
  heap_ptr is NULL, or elt_count or elt_size is 0, the NULL pointer is 
  silently returned.
 
  @param[in] heap_ptr    Pointer to the heap from which to allocate.
  @param[in] elt_count   Number of elements to allocate.
  @param[in] elt_size    Size of each element.
  @param[in] file_name   Name of the file from which mem_calloc() was called 
                         (only used in Debug mode).
  @param[in] line_number Line number corresponding to the mem_calloc() call
                         (only used in Debug mode).

  @return
  Returns a pointer to the newly allocated block, or NULL if the block
  could not be allocated.
 
  @dependencies
  heap_ptr must not be NULL. \n
  elt_count must not be 0. \n
  elt_size must not be 0.
*/
/*lint -sem(mem_calloc,1p,2n>=0&&3n>=0&&(@p==0||@P==2n*3n)) */

void* mem_calloc(
  mem_heap_type *heap_ptr,
  size_t         elt_count,
  size_t         elt_size
);

#ifdef FEATURE_MEM_DEBUG
/*lint -save -e683 */
   #define  mem_calloc_debug(heap_ptr, elt_count, elt_size, file_name, line_number)\
      mem_calloc(heap_ptr,\
                       elt_count,\
                       elt_size)
/*lint -restore */
#endif

/**
  Allocates a block of size bytes from the heap. If heap_ptr is NULL
  or size is 0, the NULL pointer is silently returned.

  @param[in] heap_ptr    Pointer to the heap from which to allocate.
  @param[in] size        Number of bytes to allocate.
  @param[in] file_name   Name of the file from which mem_malloc() was called 
                         (only used in Debug mode).
  @param[in] line_number Line number corresponding to the mem_malloc() call 
                         (only used in Debug mode).

  @return
  Returns a pointer to the newly allocated block, or NULL if the block
  could not be allocated.
 
  @dependencies
  heap_ptr must not be NULL. \n
  size must not be 0.
*/
/*lint -sem(mem_malloc,1p,2n>=0&&(@p==0||@P==2n)) */

void* mem_malloc(
  mem_heap_type *heap_ptr,
  size_t         size
);

#ifdef FEATURE_MEM_DEBUG
/*lint -save -e683 */
   #define  mem_malloc_debug(heap_ptr, size, file_name, line_number)\
      mem_malloc(heap_ptr,\
                       size)
/*lint -restore */
#endif

/*===========================================================================
FUNCTION MEM_REALLOC

===========================================================================*/
/**
  Resizes the ptr block of memory to size bytes while preserving the
  block's contents. 
 
  If the block is shortened, the bytes are discarded from the end. If the block
  is lengthened, the new bytes added are not initialized and will have 
  unrecognizable values. 
 
  This function has the following criteria: \n
  - If heap_ptr is NULL, the contents of ptr are unchanged and the function 
    silently returns NULL. 
  - If ptr is NULL, the function behaves exactly like mem_malloc(). 
  - If ptr is not NULL and size is 0, the function behaves exactly 
    like mem_free(). 
 
  If the block cannot be resized (i.e., ptr is not NULL and size is not 0), 
  NULL is returned and the original block is left untouched. If the ptr 
  block is successfully resized and the returned value is different from 
  the ptr value passed in, the old block passed in must be considered 
  deallocated and no longer useable; do NOT use mem_free() on the old block.  
 
  This function will ASSERT if it can detect a bad pointer or a pointer to a 
  free block within the range of memory managed by heap_ptr. However, 
  detection is not always possible. Passing in a ptr block that is outside 
  the memory managed by heap_ptr results in a silent return of NULL with 
  the contents of ptr unchanged. The function calls mem_malloc() if it cannot
  increase the block in place, so mem_allocator_failed_proc_type() WILL 
  be called to increase the block if the heap is out of room.

  @param[in] heap_ptr    Pointer to the heap from which to allocate.
  @param[in] ptr         Pointer to a block previously allocated.
  @param[in] size        Number of bytes to allocate.
  @param[in] file_name   Name of the file from which mem_realloc() was called 
                         (only used in Debug mode).
  @param[in] line_number Line number corresponding to the mem_realloc() call 
                         (only used in Debug mode).

  @return
  Returns a pointer to the beginning of the resized block of memory (which
  may be different from ptr), or NULL if the block could not be resized.

  @dependencies
  None. However, read the description thoroughly for how to properly call the 
  function.
*/
/*lint -sem(mem_realloc,1p,3n>=0&&(@p==0||@P==3n)) */

void *mem_realloc(
  mem_heap_type *heap_ptr,
  void          *ptr,
  size_t         size
);

#ifdef FEATURE_MEM_DEBUG
/*lint -save -e683 */
   #define  mem_realloc_debug(heap_ptr, ptr,size, file_name, line_number)\
      mem_realloc(heap_ptr,\
					   ptr,\
                       size)
/*lint -restore */
#endif
/**
  Deallocates the ptr block of memory. If ptr or heap_ptr is NULL, or
  ptr is outside the range of memory managed by heap_ptr, the function
  call does nothing and is guaranteed to be harmless. This function will
  ASSERT if it can detect an attempt to free an already freed block. 
  However, detection is not always possible.

  @param[in] heap_ptr    Pointer to the heap from which to allocate.
  @param[in] ptr         Pointer to the memory to be freed.
  @param[in] file_name   Name of the file from which mem_free() was called 
                         (only used in Debug mode).
  @param[in] line_number Line number corresponding to the mem_free() call 
                         (only used in Debug mode).

  @return
  None.

  @dependencies
  None.
*/
/*lint -sem(mem_free,1p) */
void mem_free(
  mem_heap_type *heap_ptr,
  void          *ptr
);

#ifdef FEATURE_MEM_DEBUG
/*lint -save -e683 */
   #define  mem_free_debug(heap_ptr, ptr, file_name, line_number)\
      mem_free(heap_ptr,\
					   ptr)
/*lint -restore */
#endif


/**
  Returns the number of allocated bytes, excluding overhead.

  @param[in] heap_ptr Pointer to the heap to be queried.

  @return
  Number of bytes.

  @dependencies
  None.
*/
size_t mem_heap_used (mem_heap_type *heap_ptr);


/**
  Returns the number of bytes of overhead, per allocation, for the heap.

  @param[in] heap_ptr Pointer to the heap to be queried.

  @return
  Number of bytes.

  @dependencies
  None.
*/
size_t mem_heap_overhead (mem_heap_type *heap_ptr);


/**
  Returns the number of bytes consumed by the allocation and overhead.

  @param[in] heap_ptr Pointer to the heap to be queried.

  @return
  Number of bytes.

  @dependencies
  None.
*/
size_t mem_heap_consumed (mem_heap_type *heap_ptr);

/* ------------------------------------------------------------------------
** 
** Memory Heap Debug and Test Routines
**
** ------------------------------------------------------------------------ */

/** 
  Default value is NULL. If this variable is not NULL, a function is called
  whenever an allocation has failed, due to an out-of-heap space condition, 
  and is about to return NULL to the caller.
*/
extern mem_allocator_failed_proc_type mem_allocator_failed_hook;

#ifdef FEATURE_MEM_DEBUG
extern uint32 memheap_tid_to_tls[MEMHEAP_MAX_QURT_THREADS];
#endif

/** @cond
*/
/* Anonymous enum used for keeping tracking of memory. */
enum {
  kBlockFree = 1,/* needed some sapce for checksum in block header so reduced it to 1*/
  kBlockUsed = 0,
  kLastBlock = 1,/* needed some sapce for checksum in block header so reduced it to 1*/
  kStartBlock = 1,
  kMinChunkSize = 16,
  kMinBlockSize = 32,
};
/** @endcond */

/**
  Returns the block size from a assigned ptr in the heap.

  @param[in] void Pointer to the memory block to be queried.

  @return
  Returns the size (in bytes) of the block, excluding the block header 
  overhead and the unused bytes at the end of the block.
 
  @dependencies
  None.
*/
/*lint -sem(mem_get_block_size,1p) */

unsigned long mem_get_block_size (
	mem_heap_type *heap_ptr,   
	void          *ptr    
);

/**
  Returns the logical block size of a memory block in the heap.

  @param[in] block_hdr_ptr Pointer to the memory block to be queried.

  @return
  Returns the size (in bytes) of the block, excluding the block header 
  overhead and the unused bytes at the end of the block.
 
  @dependencies
  None.
*/
/*lint -sem(mem_get_block_logical_size,1p) */
unsigned long mem_get_block_logical_size(
   const mem_block_header_type *block_hdr_ptr,
   mem_heap_type *heap_ptr
);

/** @brief Used for walking through the blocks of a specified heap.
*/
typedef struct mem_heap_block_iterator_struct {
  const mem_heap_type   *mAllocator;  /**< Pointer to the heap over which 
                                           to be walked. */
  mem_block_header_type *mBlock;      /**< Current block the iterator is 
                                           iterating over. */
} mem_heap_block_iterator_type;

/** @brief Used to keep track of the memory heap.
*/
typedef struct mem_heap_totals_struct {
  unsigned long total_physical_bytes; /**< Total physical bytes in use. */
  unsigned long current_block_count;  /**< Current block count in use. */
  unsigned long used_blocks;          /**< Current blocks in use. */
  unsigned long header_bytes;         /**< Amount of header bytes in use. */
  unsigned long used_bytes;           /**< Amount of bytes in use. */
  unsigned long free_bytes;           /**< Amount of free bytes. */
  unsigned long wasted_bytes;         /**< Amount of extra unallocated 
                                           bytes in use that cannot be 
                                           allocated currently. */
  unsigned long largest_free_block;   /**< Size of the largest free block. */
  unsigned long max_logical_used;     /**< Maximum logical memory amount 
                                           used. */
  unsigned long max_logical_request;  /**< Maximum logical amount requested. */
} mem_heap_totals_type;


/**
  Initializes mem_heap_block_iterator_struct to be used for walking the blocks
  in a specified heap.
 
  @param[in,out] block_iter_ptr Pointer to mem_heap_block_iterator_struct to be 
                                initialized.
  @param[in] heap_ptr           Pointer to the heap this iterator must 
                                iterate over.

  @return
  None.

  @dependencies
  None.
*/
void mem_heap_block_iterator_init(
   mem_heap_block_iterator_type *block_iter_ptr,
   const mem_heap_type          *heap_ptr
);


/**
  Resets a heap block iterator to begin the iteration of the heap blocks from
  the beginning.

  @param[in] block_iter_ptr Pointer to the iterator.

  @return
  None.

  @dependencies
  None.
*/
void mem_heap_block_iterator_reset(
   mem_heap_block_iterator_type *block_iter_ptr
     /* The iterator structure to be reset
     */
);

/*===========================================================================
FUNCTION MEM_HEAP_BLOCK_ITERATOR_NEXT

===========================================================================*/
/**
  Returns a memory block header for the next block (or next virtual block)
  in the heap being iterated. 

  The heap being iterated must not be changed during the iteration because 
  the iterator may become lost or return invalid values. However, there 
  is no protection against changing the heap during the iteration.
 
  @param[in,out] block_iter_ptr  Iterator from which to return the next 
                                 iterated block.
  @param[out] out_block_ptr      Pointer to a location where a copy of the 
                                 memory block header is placed. This copy 
                                 describes the returned memory block. 
                                 Parameter is only valid if the function 
                                 returns a nonzero value.
  @param[in] fake_free_coalesced Input flag; 0 = return the next block 
                                 header from the heap exactly as it is; 
                                 nonzero = return the next virtual block 
                                 header from the heap. Virtual block headers 
                                 are created by collapsing all adjacent free 
                                 blocks into one.

  @return
  Nonzero -- Next heap block was returned in out_block successfully. \n
  0 -- No more heap blocks to return.

  @dependencies
  None.
*/
int mem_heap_block_iterator_next(
   mem_heap_block_iterator_type *block_iter_ptr,
   mem_block_header_type        *out_block_ptr,
   int                           fake_free_coalesced
);


/**
  Returns the heap totals. This function is thread safe.
 
  @param[in] heap_ptr Pointer to the heap to be queried.
  @param[out] totals  Pointer to mem_heap_totals_struct to receive the various
                      heap information.

  @return
  None.

  @dependencies
  The heap must have been initialized previously.
*/
void mem_heap_get_totals(
   mem_heap_type  *heap_ptr,
   mem_heap_totals_type *totals
);


/**
  Sets up the specified heap to use an interrupt's lock/free operation 
  as its locking mechanism.
 
  @param[in] heap_ptr Pointer to the heap to be set up.

  @return
  0 -- Heap is not set up. \n
  1 -- Heap is set up.

  @dependencies
  None.
*/
int
mem_heap_set_int_lock( mem_heap_type *heap_ptr );


/**
  Sets up the specified heap to use a task's lock/free operation as its 
  locking mechanism.
 
  @param[in] heap_ptr Pointer to the heap to be set up.

  @return
  0 -- Heap is not set up. \n
  1 -- Heap is set up.

  @dependencies
  None.
*/
int
mem_heap_set_task_lock( mem_heap_type *heap_ptr );


/**
  Sets up the specified heap to use no locking. This implies
  that the heap must only be used from the context of one task.

  @param[in] heap_ptr Pointer to the heap to be set up.

  @return
  0 -- Heap is not set up. \n
  1 -- Heap is set up.

  @dependencies
  None.
*/
int
mem_heap_set_no_lock( mem_heap_type *heap_ptr );

/** @cond
*/
/**
  Sets up the specified heap to use QUBE Mutex/REX crit_sect/
  WM CriticalSection for its locking mechanism.
 
  @param[in] heap_ptr Pointer to the heap to be set up.

  @return
  0 -- Heap is not set up. \n
  1 -- Heap is set up.

  @dependencies
  None.
*/
int
mem_heap_set_crit_sect( mem_heap_type *heap_ptr );
/** @endcond */


/**
  Returns information about the sizes of the largest number of free blocks 
  in the heap.
 
  @param[in] heap_ptr   Pointer to the heap to be queried.
  @param[in] num_blocks Number of blocks to be queried.
  @param[out] buf       Pointer to where the information is returned.

  @return
  None.

  @dependencies
  The heap must have been initialized previously. \n
  The buffer passed in must be large enough to hold the information.
*/
void
mem_heap_get_freeblock_info(
  mem_heap_type *heap_ptr,
  unsigned int   num_blocks,
  unsigned int  *buf
);
 
/**
  Returns the minimum chunk size used for allocations from a heap. All
  allocations from a specific heap are multiples of this size.
 
  @param[in] heap_ptr Pointer to the heap to be queried.

  @return
  Minimum chunk size.

  @dependencies
  None.
*/
unsigned int
mem_heap_get_chunk_size( mem_heap_type *heap_ptr );

#ifdef FEATURE_MEM_DEBUG
/**
  Enables collection of heap statistics for the heap. Memory is a
  allocated for the statistics internally and the client can use APIs 
  to get the heap statistics. 
 
  @param[in] heap_ptr   Pointer to the heap to be queried.

  @return
  0 -SUCCESS
-1- Allocation of array for heap statistics failed

  @dependencies
  The heap must have been initialized previously. \n
  The buffer passed in must be large enough to hold the information.
*/
int memheap_collect_heap_statistics(mem_heap_type *heap_ptr);

/**
  Returns the heap statistics for a thread with given memheap TLS index 

  @param[in]  heap_ptr     Pointer to the heap to be queried.
  @param[in]  thread_id    Thread index
  @param[out] stats double pointer to the heap statistics structure having the 
              statistics for the given thread id. 

  @return
    0 -SUCCESS
  -1- Invalid arguments
  -2  Heap Statistics not enabled for this heap

  @dependencies
  The heap must have been initialized previously. \n
*/
static __inline int memheap_get_task_stats(mem_heap_type *heap_ptr, uint32 thread_id, memheap_task_stats_type **stats) \
{
   uint32 tls_index;
   if((NULL == stats) || (NULL == heap_ptr))
   {   return MEMHEAP_EARGS; }
   if (NULL == heap_ptr->heapStatistics)
   { return MEMHEAP_ENOINIT; }
   thread_id=thread_id&MEMHEAP_THREAD_ID_MASK;
   if(thread_id >= MEMHEAP_MAX_QURT_THREADS)
  {
     return MEMHEAP_EARGS;
   }
   /* Get the tls index to index into the actual heap statistics array */
   tls_index = memheap_tid_to_tls[thread_id];
   if(tls_index >= MEMHEAP_MAX_THREADS)
   {
      return MEMHEAP_EFAILED;
   }
   
   *stats = &heap_ptr->heapStatistics[tls_index];
   return MEMHEAP_EOK;
}


/**
  Returns a pointer to the task name for a thread with given thread ID. 

  @param[in]  heap_ptr   Pointer to the heap to be queried.
  @param[in]  thread_id  Thread Index of the thread
  @param[out] tname double pointer to return the task name

  @return
    0 -SUCCESS
  -1- Invalid arguments

  @dependencies
  The heap must have been initialized previously. \n  
*/
int memheap_get_task_name(mem_heap_type *heap_ptr, uint32 client_id,char **tname);

#endif //#FEATURE_MEM_DEBUG
   
/**
  This function allocate a memory block from the heap(heap_ptr) of size(size)
  having the alocated memory block address aligned with block_size.

  @param[in] heap_ptr to the memory block to be queried.
  @param[in] block_size, need to aligned with
  @param[in] size requested memory size

  @return
  Returns the allocated memory block pointer
 
  @dependencies
  None.
*/
void* mem_memalign(
  mem_heap_type    *heap_ptr,
  size_t           block_size,
  size_t           size
);

/**
  API to add a section of memory to the heap..
 
  @param[in] section_start     start address of the memory chunk.
  @param[in] section_size      size of the section

  @return
  SUCCESS 

  @dependencies
  None.
*/
void mem_heap_add_section(
   /* Statically allocated heap structure   */
   mem_heap_type                 *heap_ptr,
   /* Pointer to contiguous block of memory used for this section  */
   void                          *section_start,
   /* Size of the section  */
   unsigned long                  section_size);

#ifdef __cplusplus
   }
#endif

/** @} */ /* end_addtogroup utils_services */
#endif /* MEMHEAP_H */
