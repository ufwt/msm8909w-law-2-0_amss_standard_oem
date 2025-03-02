/***********************************************************************
 * fs_unicode_utf.h
 *
 * Unicode UTF conversion functions
 * Copyright (C) 2007-2008 QUALCOMM Technologies, Inc.
 *
 * This code converts strings between UTF8 and other encoding formats.
 *
 * This file was originally copied from Unicode.org:
 * http://www.unicode.org/Public/PROGRAMS/CVTUTF/
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/core.mpss/3.5.c12.3/storage/efs/inc/fs_convert_utf.h#1 $ $DateTime: 2016/12/13 07:59:23 $ $Author: mplcsds1 $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2008-05-23   rp    Introducing /inc folder as per new SCM.
2007-03-20   sh    Prefix all function calls to avoid collisions.
2007-03-11   sh    Simpler copyright.
2007-02-07   sh    Cleanup
2007-01-25   sh    Created from Unicode.org file ConvertUTF.h

===========================================================================*/

#ifndef __FS_UNICODE_UTF_H__
#define __FS_UNICODE_UTF_H__

/*
 * Copyright 2001-2004 Unicode, Inc.
 *
 * Disclaimer
 *
 * This source code is provided as is by Unicode, Inc. No claims are
 * made as to fitness for any particular purpose. No warranties of any
 * kind are expressed or implied. The recipient agrees to determine
 * applicability of information provided. If this file has been
 * purchased on magnetic or optical media from Unicode, Inc., the
 * sole remedy for any claim will be exchange of defective media
 * within 90 days of receipt.
 *
 * Limitations on Rights to Redistribute This Code
 *
 * Unicode, Inc. hereby grants the right to freely use the information
 * supplied in this file in the creation of products supporting the
 * Unicode Standard, and to make copies of this file in any form
 * for internal or external distribution as long as this notice
 * remains attached.
 */

/* ---------------------------------------------------------------------

    Conversions between UTF32, UTF-16, and UTF-8.  Header file.

    Several funtions are included here, forming a complete set of
    conversions between the three formats.  UTF-7 is not included
    here, but is handled in a separate source file.

    Each of these routines takes pointers to input buffers and output
    buffers.  The input buffers are const.

    Each routine converts the text between *sourceStart and sourceEnd,
    putting the result into the buffer between *targetStart and
    targetEnd. Note: the end pointers are *after* the last item: e.g.
    *(sourceEnd - 1) is the last item.

    The return result indicates whether the conversion was successful,
    and if not, whether the problem was in the source or target buffers.
    (Only the first encountered problem is indicated.)

    After the conversion, *sourceStart and *targetStart are both
    updated to point to the end of last text successfully converted in
    the respective buffers.

    Input parameters:
  sourceStart - pointer to a pointer to the source buffer.
    The contents of this are modified on return so that
    it points at the next thing to be converted.
  targetStart - similarly, pointer to pointer to the target buffer.
  sourceEnd, targetEnd - respectively pointers to the ends of the
    two buffers, for overflow checking only.

    These conversion functions take a ConversionFlags argument. When this
    flag is set to strict, both irregular sequences and isolated surrogates
    will cause an error.  When the flag is set to lenient, both irregular
    sequences and isolated surrogates are converted.

    Whether the flag is strict or lenient, all illegal sequences will cause
    an error return. This includes sequences such as: <F4 90 80 80>, <C0 80>,
    or <A0> in UTF-8, and values above 0x10FFFF in UTF-32. Conformant code
    must check for illegal sequences.

    When the flag is set to lenient, characters over 0x10FFFF are converted
    to the replacement character; otherwise (when the flag is set to strict)
    they constitute an error.

    Output parameters:
  The value "sourceIllegal" is returned from some routines if the input
  sequence is malformed.  When "sourceIllegal" is returned, the source
  value will point to the illegal value that caused the problem. E.g.,
  in UTF-8 when a sequence is malformed, it points to the start of the
  malformed sequence.

    Author: Mark E. Davis, 1994.
    Rev History: Rick McGowan, fixes & updates May 2001.
     Fixes & updates, Sept 2001.

------------------------------------------------------------------------ */

/* ---------------------------------------------------------------------
    The following 4 definitions are compiler-specific.
    The C standard does not guarantee that wchar_t has at least
    16 bits, so wchar_t is no less portable than unsigned short!
    All should be unsigned values to avoid sign extension during
    bit mask & shift operations.
------------------------------------------------------------------------ */

typedef unsigned long  UTF32;   /* at least 32 bits */
typedef unsigned short UTF16;   /* at least 16 bits */
typedef unsigned char  UTF8;    /* typically 8 bits */
typedef unsigned char  Boolean; /* 0 or 1 */

/* Some fundamental constants */
#define UNI_REPLACEMENT_CHAR    (UTF32)0x0000FFFD
#define UNI_MAX_BMP             (UTF32)0x0000FFFF
#define UNI_MAX_UTF16           (UTF32)0x0010FFFF
#define UNI_MAX_UTF32           (UTF32)0x7FFFFFFF
#define UNI_MAX_LEGAL_UTF32     (UTF32)0x0010FFFF

typedef enum
{
  conversionOK,                 /* conversion successful */
  sourceExhausted,              /* partial character in source, but hit end */
  targetExhausted,              /* insuff. room in target for conversion */
  sourceIllegal                 /* source sequence is illegal/malformed */
} ConversionResult;

typedef enum
{
  strictConversion = 0,
  lenientConversion
} ConversionFlags;

ConversionResult fs_ConvertUTF8toUTF16 (const UTF8 ** sourceStart,
                                        const UTF8 * sourceEnd,
                                        UTF16 ** targetStart,
                                        UTF16 * targetEnd,
                                        ConversionFlags flags);

ConversionResult fs_ConvertUTF16toUTF8 (const UTF16 ** sourceStart,
                                        const UTF16 * sourceEnd,
                                        UTF8 ** targetStart,
                                        UTF8 * targetEnd,
                                        ConversionFlags flags);

ConversionResult fs_ConvertUTF8toUTF32 (const UTF8 ** sourceStart,
                                        const UTF8 * sourceEnd,
                                        UTF32 ** targetStart,
                                        UTF32 * targetEnd,
                                        ConversionFlags flags);

ConversionResult fs_ConvertUTF32toUTF8 (const UTF32 ** sourceStart,
                                        const UTF32 * sourceEnd,
                                        UTF8 ** targetStart,
                                        UTF8 * targetEnd,
                                        ConversionFlags flags);

ConversionResult fs_ConvertUTF16toUTF32 (const UTF16 ** sourceStart,
                                         const UTF16 * sourceEnd,
                                         UTF32 ** targetStart,
                                         UTF32 * targetEnd,
                                         ConversionFlags flags);

ConversionResult fs_ConvertUTF32toUTF16 (const UTF32 ** sourceStart,
                                         const UTF32 * sourceEnd,
                                         UTF16 ** targetStart,
                                         UTF16 * targetEnd,
                                         ConversionFlags flags);

Boolean fs_isLegalUTF8 (const UTF8 * source, int length);

/* --------------------------------------------------------------------- */


#endif /* not __FS_UNICODE_UTF_H__ */
