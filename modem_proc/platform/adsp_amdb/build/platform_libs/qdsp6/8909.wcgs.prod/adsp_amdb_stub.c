#ifndef _ADSP_AMDB_STUB_H
#define _ADSP_AMDB_STUB_H
#include "adsp_amdb.h"
#ifndef _QAIC_ENV_H
#define _QAIC_ENV_H

#ifdef __GNUC__
#ifdef __clang__
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#else
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

#ifndef _ATTRIBUTE_UNUSED

#ifdef _WIN32
#define _ATTRIBUTE_UNUSED
#else
#define _ATTRIBUTE_UNUSED __attribute__ ((unused))
#endif

#endif // _ATTRIBUTE_UNUSED

#ifndef __QAIC_REMOTE
#define __QAIC_REMOTE(ff) ff
#endif //__QAIC_REMOTE

#ifndef __QAIC_HEADER
#define __QAIC_HEADER(ff) ff
#endif //__QAIC_HEADER

#ifndef __QAIC_HEADER_EXPORT
#define __QAIC_HEADER_EXPORT
#endif // __QAIC_HEADER_EXPORT

#ifndef __QAIC_HEADER_ATTRIBUTE
#define __QAIC_HEADER_ATTRIBUTE
#endif // __QAIC_HEADER_ATTRIBUTE

#ifndef __QAIC_IMPL
#define __QAIC_IMPL(ff) ff
#endif //__QAIC_IMPL

#ifndef __QAIC_IMPL_EXPORT
#define __QAIC_IMPL_EXPORT
#endif // __QAIC_IMPL_EXPORT

#ifndef __QAIC_IMPL_ATTRIBUTE
#define __QAIC_IMPL_ATTRIBUTE
#endif // __QAIC_IMPL_ATTRIBUTE

#ifndef __QAIC_STUB
#define __QAIC_STUB(ff) ff
#endif //__QAIC_STUB

#ifndef __QAIC_STUB_EXPORT
#define __QAIC_STUB_EXPORT
#endif // __QAIC_STUB_EXPORT

#ifndef __QAIC_STUB_ATTRIBUTE
#define __QAIC_STUB_ATTRIBUTE
#endif // __QAIC_STUB_ATTRIBUTE

#ifndef __QAIC_SKEL
#define __QAIC_SKEL(ff) ff
#endif //__QAIC_SKEL__

#ifndef __QAIC_SKEL_EXPORT
#define __QAIC_SKEL_EXPORT
#endif // __QAIC_SKEL_EXPORT

#ifndef __QAIC_SKEL_ATTRIBUTE
#define __QAIC_SKEL_ATTRIBUTE
#endif // __QAIC_SKEL_ATTRIBUTE

#ifdef __QAIC_DEBUG__
   #ifndef __QAIC_DBG_PRINTF__
   #define __QAIC_DBG_PRINTF__( ee ) do { printf ee ; } while(0)
   #endif
#else
   #define __QAIC_DBG_PRINTF__( ee ) (void)0
#endif


#define _OFFSET(src, sof)  ((void*)(((char*)(src)) + (sof)))

#define _COPY(dst, dof, src, sof, sz)  \
   do {\
         struct __copy { \
            char ar[sz]; \
         };\
         *(struct __copy*)_OFFSET(dst, dof) = *(struct __copy*)_OFFSET(src, sof);\
   } while (0)

#define _COPYIF(dst, dof, src, sof, sz)  \
   do {\
      if(_OFFSET(dst, dof) != _OFFSET(src, sof)) {\
         _COPY(dst, dof, src, sof, sz); \
      } \
   } while (0)

_ATTRIBUTE_UNUSED 
static __inline void _qaic_memmove(void* dst, void* src, int size) {
   int i;
   for(i = 0; i < size; ++i) {
      ((char*)dst)[i] = ((char*)src)[i];
   }
}

#define _MEMMOVEIF(dst, src, sz)  \
   do {\
      if(dst != src) {\
         _qaic_memmove(dst, src, sz);\
      } \
   } while (0)


#define _ASSIGN(dst, src, sof)  \
   do {\
      dst = OFFSET(src, sof); \
   } while (0)

#define _STD_STRLEN_IF(str) (str == 0 ? 0 : strlen(str))

#include "AEEStdErr.h"

#define _TRY(ee, func) \
   do { \
      if (AEE_SUCCESS != ((ee) = func)) {\
         __QAIC_DBG_PRINTF__((__FILE_LINE__  ": error: %d\n", (int)(ee)));\
         goto ee##bail;\
      } \
   } while (0)

#define _CATCH(exception) exception##bail: if (exception != AEE_SUCCESS)

#define _ASSERT(nErr, ff) _TRY(nErr, 0 == (ff) ? AEE_EBADPARM : AEE_SUCCESS)

#ifdef __QAIC_DEBUG__
#define _ALLOCATE(nErr, pal, size, alignment, pv) _TRY(nErr, _allocator_alloc(pal, __FILE_LINE__, size, alignment, (void**)&pv))
#else
#define _ALLOCATE(nErr, pal, size, alignment, pv) _TRY(nErr, _allocator_alloc(pal, 0, size, alignment, (void**)&pv))
#endif

#endif // _QAIC_ENV_H

#include "remote.h"
#include <string.h>
#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

#include <stdlib.h>
#include <stdint.h>

typedef struct _heap _heap;
struct _heap {
   _heap* pPrev;
   const char* loc;
   uint64_t buf;
};

typedef struct _allocator {
   _heap* pheap;
   uint8_t* stack;
   uint8_t* stackEnd;
   int nSize;
} _allocator;

_ATTRIBUTE_UNUSED 
static __inline int _heap_alloc(_heap** ppa, const char* loc, int size, void** ppbuf) {
   _heap* pn = 0;
   pn = malloc(size + sizeof(_heap) - sizeof(uint64_t));
   if(pn != 0) {
      pn->pPrev = *ppa;
      pn->loc = loc;
      *ppa = pn;
      *ppbuf = (void*)&(pn->buf);
      return 0;
   } else {
      return -1;
   }
}
#define _ALIGN_SIZE(x, y) (((x) + (y-1)) & ~(y-1))

_ATTRIBUTE_UNUSED 
static __inline int _allocator_alloc(_allocator* me,
                                    const char* loc,
                                    int size,
                                    unsigned int al,
                                    void** ppbuf) {
   if(size < 0) {
      return -1;
   } else if (size == 0) {
      *ppbuf = 0;
      return 0;
   }
   if((_ALIGN_SIZE((uintptr_t)me->stackEnd, al) + size) < (uintptr_t)me->stack + me->nSize) {
      *ppbuf = (uint8_t*)_ALIGN_SIZE((uintptr_t)me->stackEnd, al);
      me->stackEnd = (uint8_t*)_ALIGN_SIZE((uintptr_t)me->stackEnd, al) + size;
      return 0;
   } else {
      return _heap_alloc(&me->pheap, loc, size, ppbuf);
   }
}

_ATTRIBUTE_UNUSED 
static __inline void _allocator_deinit(_allocator* me) {
   _heap* pa = me->pheap;
   while(pa != 0) {
      _heap* pn = pa;
      const char* loc = pn->loc;
      (void)loc;
      pa = pn->pPrev;
      free(pn);
   }
}

_ATTRIBUTE_UNUSED 
static __inline void _allocator_init(_allocator* me, uint8_t* stack, int stackSize) {
   me->stack =  stack;
   me->stackEnd =  stack + stackSize;
   me->nSize = stackSize;
   me->pheap = 0;
}


#endif // _ALLOCATOR_H

#ifndef SLIM_H
#define SLIM_H

#include <stdint.h>

//a C data structure for the idl types that can be used to implement
//static and dynamic language bindings fairly efficiently.
//
//the goal is to have a minimal ROM and RAM footprint and without
//doing too many allocations.  A good way to package these things seemed
//like the module boundary, so all the idls within  one module can share
//all the type references.


#define PARAMETER_IN       0x0
#define PARAMETER_OUT      0x1
#define PARAMETER_INOUT    0x2
#define PARAMETER_ROUT     0x3
#define PARAMETER_INROUT   0x4

//the types that we get from idl
#define TYPE_OBJECT             0x0
#define TYPE_INTERFACE          0x1
#define TYPE_PRIMITIVE          0x2
#define TYPE_ENUM               0x3
#define TYPE_STRING             0x4
#define TYPE_WSTRING            0x5
#define TYPE_STRUCTURE          0x6
#define TYPE_UNION              0x7
#define TYPE_ARRAY              0x8
#define TYPE_SEQUENCE           0x9

//these require the pack/unpack to recurse
//so it's a hint to those languages that can optimize in cases where
//recursion isn't necessary.
#define TYPE_COMPLEX_STRUCTURE  (0x10 | TYPE_STRUCTURE)
#define TYPE_COMPLEX_UNION      (0x10 | TYPE_UNION)
#define TYPE_COMPLEX_ARRAY      (0x10 | TYPE_ARRAY)
#define TYPE_COMPLEX_SEQUENCE   (0x10 | TYPE_SEQUENCE)


typedef struct Type Type;

#define INHERIT_TYPE\
   int32_t nativeSize;                /*in the simple case its the same as wire size and alignment*/\
   union {\
      struct {\
         const uintptr_t         p1;\
         const uintptr_t         p2;\
      } _cast;\
      struct {\
         uint32_t  iid;\
         uint32_t  bNotNil;\
      } object;\
      struct {\
         const Type  *arrayType;\
         int32_t      nItems;\
      } array;\
      struct {\
         const Type *seqType;\
         int32_t      nMaxLen;\
      } seqSimple; \
      struct {\
         uint32_t bFloating;\
         uint32_t bSigned;\
      } prim; \
      const SequenceType* seqComplex;\
      const UnionType  *unionType;\
      const StructType *structType;\
      int32_t         stringMaxLen;\
      uint8_t        bInterfaceNotNil;\
   } param;\
   uint8_t    type;\
   uint8_t    nativeAlignment\

typedef struct UnionType UnionType;
typedef struct StructType StructType;
typedef struct SequenceType SequenceType;
struct Type {
   INHERIT_TYPE;
};

struct SequenceType {
   const Type *         seqType;
   uint32_t               nMaxLen;
   uint32_t               inSize;
   uint32_t               routSizePrimIn;
   uint32_t               routSizePrimROut;
};

//byte offset from the start of the case values for
//this unions case value array.  it MUST be aligned
//at the alignment requrements for the descriptor
//
//if negative it means that the unions cases are
//simple enumerators, so the value read from the descriptor
//can be used directly to find the correct case
typedef union CaseValuePtr CaseValuePtr;
union CaseValuePtr {
   const uint8_t*   value8s;
   const uint16_t*  value16s;
   const uint32_t*  value32s;
   const uint64_t*  value64s;
};

//these are only used in complex cases
//so I pulled them out of the type definition as references to make
//the type smaller
struct UnionType {
   const Type           *descriptor;
   uint32_t               nCases;
   const CaseValuePtr   caseValues;
   const Type * const   *cases;
   int32_t               inSize;
   int32_t               routSizePrimIn;
   int32_t               routSizePrimROut;
   uint8_t                inAlignment;
   uint8_t                routAlignmentPrimIn;
   uint8_t                routAlignmentPrimROut;
   uint8_t                inCaseAlignment;
   uint8_t                routCaseAlignmentPrimIn;
   uint8_t                routCaseAlignmentPrimROut;
   uint8_t                nativeCaseAlignment;
   uint8_t              bDefaultCase;
};

struct StructType {
   uint32_t               nMembers;
   const Type * const   *members;
   int32_t               inSize;
   int32_t               routSizePrimIn;
   int32_t               routSizePrimROut;
   uint8_t                inAlignment;
   uint8_t                routAlignmentPrimIn;
   uint8_t                routAlignmentPrimROut;
};

typedef struct Parameter Parameter;
struct Parameter {
   INHERIT_TYPE;
   uint8_t    mode;
   uint8_t  bNotNil;
};

#define SLIM_SCALARS_IS_DYNAMIC(u) (((u) & 0x00ffffff) == 0x00ffffff)

typedef struct Method Method;
struct Method {
   uint32_t                    uScalars;            //no method index
   int32_t                     primInSize;
   int32_t                     primROutSize;
   int                         maxArgs;
   int                         numParams;
   const Parameter * const     *params;
   uint8_t                       primInAlignment;
   uint8_t                       primROutAlignment;
};

typedef struct Interface Interface;

struct Interface {
   int                            nMethods;
   const Method  * const          *methodArray;
   int                            nIIds;
   const uint32_t                   *iids;
   const uint16_t*                  methodStringArray;
   const uint16_t*                  methodStrings;
   const char*                    strings;
};


#endif //SLIM_H


#ifndef _ADSP_AMDB_SLIM_H
#define _ADSP_AMDB_SLIM_H
#include "remote.h"
#include <stdint.h>

#ifndef __QAIC_SLIM
#define __QAIC_SLIM(ff) ff
#endif
#ifndef __QAIC_SLIM_EXPORT
#define __QAIC_SLIM_EXPORT
#endif

static const Parameter parameters[3] = {{0x4,{{(const uintptr_t)0,(const uintptr_t)1}}, 2,0x4,0,0},{0x1,{{(const uintptr_t)0,(const uintptr_t)0}}, 2,0x1,0,0},{0x8,{{(const uintptr_t)0x0,0}}, 4,0x4,0,0}};
static const Parameter* const parameterArrays[11] = {(&(parameters[0])),(&(parameters[0])),(&(parameters[0])),(&(parameters[1])),(&(parameters[2])),(&(parameters[2])),(&(parameters[2])),(&(parameters[0])),(&(parameters[0])),(&(parameters[0])),(&(parameters[2]))};
static const Method methods[5] = {{REMOTE_SCALARS_MAKEX(0,0,0x4,0x0,0x0,0x0),0x14,0x0,5,5,(&(parameterArrays[2])),0x4,0x0},{REMOTE_SCALARS_MAKEX(0,0,0x2,0x0,0x0,0x0),0x8,0x0,2,2,(&(parameterArrays[9])),0x4,0x0},{REMOTE_SCALARS_MAKEX(0,0,0x0,0x0,0x0,0x0),0x0,0x0,0,0,0,0x0,0x0},{REMOTE_SCALARS_MAKEX(0,0,0x4,0x0,0x0,0x0),0x1c,0x0,7,7,(&(parameterArrays[0])),0x4,0x0},{REMOTE_SCALARS_MAKEX(0,0,0x2,0x0,0x0,0x0),0x10,0x0,4,4,(&(parameterArrays[7])),0x4,0x0}};
static const Method* const methodArrays[14] = {&(methods[0]),&(methods[0]),&(methods[1]),&(methods[1]),&(methods[2]),&(methods[2]),&(methods[2]),&(methods[2]),&(methods[3]),&(methods[3]),&(methods[4]),&(methods[4]),&(methods[2]),&(methods[2])};
static const char strings[292] = "get_static_properties_str\0remove_all_capi_v2\0print_all_capi_v2\0remove_all_appi\0remove_all_capi\0remove_capi_v2\0remove_capi_ex\0print_all_appi\0print_all_capi\0filename_str\0add_capi_v2\0add_capi_ex\0remove_appi\0remove_capi\0getsize_str\0init_str\0add_appi\0ctor_str\0add_capi\0preload\0type\0idt\0id2\0id1\0id\0";
static const uint16_t methodStrings[50] = {168,272,285,281,264,155,0,228,180,272,285,281,264,155,216,246,237,289,264,155,216,228,255,289,264,155,216,246,95,272,285,281,155,110,272,285,277,155,192,289,155,204,289,155,45,26,125,140,63,79};
static const uint16_t methodStringsArrays[14] = {22,16,41,38,49,48,47,46,8,0,33,28,45,44};
__QAIC_SLIM_EXPORT const Interface __QAIC_SLIM(adsp_amdb_slim) = {14,&(methodArrays[0]),0,0,&(methodStringsArrays [0]),methodStrings,strings};
#endif //_ADSP_AMDB_SLIM_H
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _const_adsp_amdb_handle
#define _const_adsp_amdb_handle ((remote_handle)-1)
#endif //_const_adsp_amdb_handle

static void _adsp_amdb_pls_dtor(void* data) {
   remote_handle* ph = (remote_handle*)data;
   if(_const_adsp_amdb_handle != *ph) {
      (void)__QAIC_REMOTE(remote_handle_close)(*ph);
      *ph = _const_adsp_amdb_handle;
   }
}

static int _adsp_amdb_pls_ctor(void* ctx, void* data) {
   remote_handle* ph = (remote_handle*)data;
   *ph = _const_adsp_amdb_handle;
   if(*ph == (remote_handle)-1) {
      return __QAIC_REMOTE(remote_handle_open)((const char*)ctx, ph);
   }
   return 0;
}

#if (defined __qdsp6__) || (defined __hexagon__)
#pragma weak  adsp_pls_add_lookup
extern int adsp_pls_add_lookup(uint32_t type, uint32_t key, int size, int (*ctor)(void* ctx, void* data), void* ctx, void (*dtor)(void* ctx), void** ppo);
#pragma weak  HAP_pls_add_lookup
extern int HAP_pls_add_lookup(uint32_t type, uint32_t key, int size, int (*ctor)(void* ctx, void* data), void* ctx, void (*dtor)(void* ctx), void** ppo);

__QAIC_STUB_EXPORT remote_handle _adsp_amdb_handle(void) {
   remote_handle* ph;
   if(adsp_pls_add_lookup) {
      if(0 == adsp_pls_add_lookup((uint32_t)_adsp_amdb_handle, 0, sizeof(*ph),  _adsp_amdb_pls_ctor, "adsp_amdb",  _adsp_amdb_pls_dtor, (void**)&ph))  {
         return *ph;
      }
      return (remote_handle)-1;
   } else if(HAP_pls_add_lookup) {
      if(0 == HAP_pls_add_lookup((uint32_t)_adsp_amdb_handle, 0, sizeof(*ph),  _adsp_amdb_pls_ctor, "adsp_amdb",  _adsp_amdb_pls_dtor, (void**)&ph))  {
         return *ph;
      }
      return (remote_handle)-1;
   }
   return(remote_handle)-1;
}

#else //__qdsp6__ || __hexagon__

uint32_t _adsp_amdb_atomic_CompareAndExchange(uint32_t * volatile puDest, uint32_t uExchange, uint32_t uCompare);

#ifdef _WIN32
#include "Windows.h"
uint32_t _adsp_amdb_atomic_CompareAndExchange(uint32_t * volatile puDest, uint32_t uExchange, uint32_t uCompare) {
   return (uint32_t)InterlockedCompareExchange((volatile LONG*)puDest, (LONG)uExchange, (LONG)uCompare);
}
#elif __GNUC__
uint32_t _adsp_amdb_atomic_CompareAndExchange(uint32_t * volatile puDest, uint32_t uExchange, uint32_t uCompare) {
   return __sync_val_compare_and_swap(puDest, uCompare, uExchange);
}
#endif //_WIN32


__QAIC_STUB_EXPORT remote_handle _adsp_amdb_handle(void) {
   static remote_handle handle = _const_adsp_amdb_handle;
   if((remote_handle)-1 != handle) {
      return handle;
   } else {
      remote_handle tmp;
      int nErr = _adsp_amdb_pls_ctor("adsp_amdb", (void*)&tmp);
      if(nErr) {
         return (remote_handle)-1;
      }
      if(((remote_handle)-1 != handle) || ((remote_handle)-1 != (remote_handle)_adsp_amdb_atomic_CompareAndExchange((uint32_t*)&handle, (uint32_t)tmp, (uint32_t)-1))) {
         _adsp_amdb_pls_dtor(&tmp);
      }
      return handle;
   }
}

#endif //__qdsp6__

__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_skel_invoke)(uint32_t _sc, remote_arg* _pra) __QAIC_STUB_ATTRIBUTE {
   return __QAIC_REMOTE(remote_handle_invoke)(_adsp_amdb_handle(), _sc, _pra);
}

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
static __inline int _stub_method(remote_handle _handle, uint32_t _mid, uint32_t _in0[1], uint8_t _in1[1], char* _in2[1], char* _in3[1], char* _in4[1]) {
   uint32_t _in2Len[1];
   uint32_t _in3Len[1];
   uint32_t _in4Len[1];
   remote_arg _pra[4];
   uint32_t _primIn[5];
   remote_arg* _praIn;
   int _nErr = 0;
   _pra[0].buf.pv = (void*)_primIn;
   _pra[0].buf.nLen = sizeof(_primIn);
   _COPY(_primIn, 0, _in0, 0, 4);
   _COPY(_primIn, 4, _in1, 0, 1);
   _in2Len[0] = (1 + strlen(_in2[0]));
   _COPY(_primIn, 8, _in2Len, 0, 4);
   _praIn = (_pra + 1);
   _praIn[0].buf.pv = _in2[0];
   _praIn[0].buf.nLen = (1 * _in2Len[0]);
   _in3Len[0] = (1 + strlen(_in3[0]));
   _COPY(_primIn, 12, _in3Len, 0, 4);
   _praIn[1].buf.pv = _in3[0];
   _praIn[1].buf.nLen = (1 * _in3Len[0]);
   _in4Len[0] = (1 + strlen(_in4[0]));
   _COPY(_primIn, 16, _in4Len, 0, 4);
   _praIn[2].buf.pv = _in4[0];
   _praIn[2].buf.nLen = (1 * _in4Len[0]);
   _TRY(_nErr, __QAIC_REMOTE(remote_handle_invoke)(_handle, REMOTE_SCALARS_MAKEX(0, _mid, 4, 0, 0, 0), _pra));
   _CATCH(_nErr) {}
   return _nErr;
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_add_capi)(int id, boolean preload, const char* filename_str, const char* getsize_str, const char* ctor_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 0;
   return _stub_method(_adsp_amdb_handle(), _mid, (uint32_t*)&id, (uint8_t*)&preload, (char**)&filename_str, (char**)&getsize_str, (char**)&ctor_str);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_add_appi)(int id, boolean preload, const char* filename_str, const char* getsize_str, const char* init_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 1;
   return _stub_method(_adsp_amdb_handle(), _mid, (uint32_t*)&id, (uint8_t*)&preload, (char**)&filename_str, (char**)&getsize_str, (char**)&init_str);
}
static __inline int _stub_method_1(remote_handle _handle, uint32_t _mid, uint32_t _in0[1], char* _in1[1]) {
   uint32_t _in1Len[1];
   remote_arg _pra[2];
   uint32_t _primIn[2];
   remote_arg* _praIn;
   int _nErr = 0;
   _pra[0].buf.pv = (void*)_primIn;
   _pra[0].buf.nLen = sizeof(_primIn);
   _COPY(_primIn, 0, _in0, 0, 4);
   _in1Len[0] = (1 + strlen(_in1[0]));
   _COPY(_primIn, 4, _in1Len, 0, 4);
   _praIn = (_pra + 1);
   _praIn[0].buf.pv = _in1[0];
   _praIn[0].buf.nLen = (1 * _in1Len[0]);
   _TRY(_nErr, __QAIC_REMOTE(remote_handle_invoke)(_handle, REMOTE_SCALARS_MAKEX(0, _mid, 2, 0, 0, 0), _pra));
   _CATCH(_nErr) {}
   return _nErr;
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_capi)(int id, const char* filename_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 2;
   return _stub_method_1(_adsp_amdb_handle(), _mid, (uint32_t*)&id, (char**)&filename_str);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_appi)(int id, const char* filename_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 3;
   return _stub_method_1(_adsp_amdb_handle(), _mid, (uint32_t*)&id, (char**)&filename_str);
}
static __inline int _stub_method_2(remote_handle _handle, uint32_t _mid) {
   remote_arg* _pra = 0;
   int _nErr = 0;
   _TRY(_nErr, __QAIC_REMOTE(remote_handle_invoke)(_handle, REMOTE_SCALARS_MAKEX(0, _mid, 0, 0, 0, 0), _pra));
   _CATCH(_nErr) {}
   return _nErr;
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_all_capi)(void) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 4;
   return _stub_method_2(_adsp_amdb_handle(), _mid);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_all_appi)(void) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 5;
   return _stub_method_2(_adsp_amdb_handle(), _mid);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_print_all_capi)(void) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 6;
   return _stub_method_2(_adsp_amdb_handle(), _mid);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_print_all_appi)(void) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 7;
   return _stub_method_2(_adsp_amdb_handle(), _mid);
}
static __inline int _stub_method_3(remote_handle _handle, uint32_t _mid, uint32_t _in0[1], uint32_t _in1[1], uint32_t _in2[1], uint8_t _in3[1], char* _in4[1], char* _in5[1], char* _in6[1]) {
   uint32_t _in4Len[1];
   uint32_t _in5Len[1];
   uint32_t _in6Len[1];
   remote_arg _pra[4];
   uint32_t _primIn[7];
   remote_arg* _praIn;
   int _nErr = 0;
   _pra[0].buf.pv = (void*)_primIn;
   _pra[0].buf.nLen = sizeof(_primIn);
   _COPY(_primIn, 0, _in0, 0, 4);
   _COPY(_primIn, 4, _in1, 0, 4);
   _COPY(_primIn, 8, _in2, 0, 4);
   _COPY(_primIn, 12, _in3, 0, 1);
   _in4Len[0] = (1 + strlen(_in4[0]));
   _COPY(_primIn, 16, _in4Len, 0, 4);
   _praIn = (_pra + 1);
   _praIn[0].buf.pv = _in4[0];
   _praIn[0].buf.nLen = (1 * _in4Len[0]);
   _in5Len[0] = (1 + strlen(_in5[0]));
   _COPY(_primIn, 20, _in5Len, 0, 4);
   _praIn[1].buf.pv = _in5[0];
   _praIn[1].buf.nLen = (1 * _in5Len[0]);
   _in6Len[0] = (1 + strlen(_in6[0]));
   _COPY(_primIn, 24, _in6Len, 0, 4);
   _praIn[2].buf.pv = _in6[0];
   _praIn[2].buf.nLen = (1 * _in6Len[0]);
   _TRY(_nErr, __QAIC_REMOTE(remote_handle_invoke)(_handle, REMOTE_SCALARS_MAKEX(0, _mid, 4, 0, 0, 0), _pra));
   _CATCH(_nErr) {}
   return _nErr;
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_add_capi_ex)(int type, int id1, int id2, boolean preload, const char* filename_str, const char* getsize_str, const char* ctor_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 8;
   return _stub_method_3(_adsp_amdb_handle(), _mid, (uint32_t*)&type, (uint32_t*)&id1, (uint32_t*)&id2, (uint8_t*)&preload, (char**)&filename_str, (char**)&getsize_str, (char**)&ctor_str);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_add_capi_v2)(int type, int id1, int id2, boolean preload, const char* filename_str, const char* get_static_properties_str, const char* init_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 9;
   return _stub_method_3(_adsp_amdb_handle(), _mid, (uint32_t*)&type, (uint32_t*)&id1, (uint32_t*)&id2, (uint8_t*)&preload, (char**)&filename_str, (char**)&get_static_properties_str, (char**)&init_str);
}
static __inline int _stub_method_4(remote_handle _handle, uint32_t _mid, uint32_t _in0[1], uint32_t _in1[1], uint32_t _in2[1], char* _in3[1]) {
   uint32_t _in3Len[1];
   remote_arg _pra[2];
   uint32_t _primIn[4];
   remote_arg* _praIn;
   int _nErr = 0;
   _pra[0].buf.pv = (void*)_primIn;
   _pra[0].buf.nLen = sizeof(_primIn);
   _COPY(_primIn, 0, _in0, 0, 4);
   _COPY(_primIn, 4, _in1, 0, 4);
   _COPY(_primIn, 8, _in2, 0, 4);
   _in3Len[0] = (1 + strlen(_in3[0]));
   _COPY(_primIn, 12, _in3Len, 0, 4);
   _praIn = (_pra + 1);
   _praIn[0].buf.pv = _in3[0];
   _praIn[0].buf.nLen = (1 * _in3Len[0]);
   _TRY(_nErr, __QAIC_REMOTE(remote_handle_invoke)(_handle, REMOTE_SCALARS_MAKEX(0, _mid, 2, 0, 0, 0), _pra));
   _CATCH(_nErr) {}
   return _nErr;
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_capi_ex)(int type, int id1, int idt, const char* filename_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 10;
   return _stub_method_4(_adsp_amdb_handle(), _mid, (uint32_t*)&type, (uint32_t*)&id1, (uint32_t*)&idt, (char**)&filename_str);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_capi_v2)(int type, int id1, int id2, const char* filename_str) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 11;
   return _stub_method_4(_adsp_amdb_handle(), _mid, (uint32_t*)&type, (uint32_t*)&id1, (uint32_t*)&id2, (char**)&filename_str);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_remove_all_capi_v2)(void) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 12;
   return _stub_method_2(_adsp_amdb_handle(), _mid);
}
__QAIC_STUB_EXPORT int __QAIC_STUB(adsp_amdb_print_all_capi_v2)(void) __QAIC_STUB_ATTRIBUTE {
   uint32_t _mid = 13;
   return _stub_method_2(_adsp_amdb_handle(), _mid);
}
#ifdef __cplusplus
}
#endif
#endif //_ADSP_AMDB_STUB_H
