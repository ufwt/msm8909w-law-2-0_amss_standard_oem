/*
   Copyright (C) 2014-2015 QUALCOMM Technologies, Inc.
   All Rights Reserved.
   Confidential and Proprietary - Qualcomm Technologies, Inc.

   $Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/avs/vsd/common/utils/src/voice_utility.c#1 $
   $Author: mplcsds1 $
*/

/****************************************************************************
 * INCLUDE HEADER FILES                                                     *
 ****************************************************************************/

#include "msg.h"
#include "mmstd.h"
#include "apr_comdef.h"
#include "apr_errcodes.h"
#include "vs.h"
#include "voice_util_api.h"


#define VOICE_UTIL_AMR_MAX_NUM_CODEC_MODE_V ( 8 )
#define VOICE_UTIL_AMRWB_MAX_NUM_CODEC_MODE_V ( 9 )

/* Size is in bytes, size is of AMR Core Frame( speech or comfort noice data), which 
 * includes size of class A, class B and class C bits. 
 * Note: Maximum AMR frame size is 31 bytes, but padded it to 34 bytes for legacy reasons. 
 * Specs : 3GPP TS 26.101 and 3GPP TS 26.201.
 */
#define VOICE_UTIL_AMR_FRAME_SIZE_V ( 34 )
#define VOICE_UTIL_AMRWB_FRAME_SIZE_V ( 60 )


/* Homing frame is in if1 format. Frames have only AMR Core Frame( speech or comfort noise data ), which 
 * includes class A, class B and class C bits. Note we have to append header( frame type and codec rate ). 
 * to make its format similar to the packets received from VSM. 
 * Maximum number of class A, class B, class C bits in AMR will be 244 bits, which equals 31 bytes. 
 * However, there is padding of 3 bytes for frame, for legacy reasons. 
 * Referred docs: Specs : 3GPP TS 26.101. and "Vocoder media types" document - 80-N8828-1.
 */
 static uint8_t voice_util_amr_if1_homing_frame[ VOICE_UTIL_AMR_MAX_NUM_CODEC_MODE_V ]
                                               [ VOICE_UTIL_AMR_FRAME_SIZE_V ] = 
 {
   { 0xf8, 0x9d, 0x67, 0xf1, 0x16, 0x09, 0x35, 0xbd, 0xe1, 0x99, 0x68, 0x40, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 }, 
   { 0x1f, 0xb9, 0x67, 0xf7, 0xf1, 0xfd, 0xf5, 0x47, 0xbf, 0x2e, 0x61, 0xc0, 0x60, 0x00, 0x00, 0x00, 
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 }, 
   { 0xe9, 0x59, 0xf3, 0x5f, 0xdf, 0xe5, 0xe9, 0x66, 0x7f, 0xfb, 0xc0, 0x88, 0x81, 0x80, 0x88, 0x00, 
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 }, 
   { 0xf0, 0xb9, 0xe6, 0xbf, 0x68, 0x00, 0x72, 0x09, 0xc3, 0xd3, 0xcb, 0xc8, 0x08, 0x48, 0xa1, 0x55,
     0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 }, 
   { 0xf8, 0x71, 0xcf, 0x48, 0x80, 0x1e, 0xc4, 0x27, 0xf0, 0xfc, 0x3f, 0x73, 0x18, 0x89, 0x86, 0x22,
     0x06, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 },
   { 0x42, 0xb3, 0x32, 0x08, 0x18, 0x13, 0xd7, 0xe9, 0x16, 0xe7, 0xaa, 0x5e, 0x80, 0xd7, 0xfd, 0xe8,
     0x12, 0xb8, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 },
   { 0x1f, 0xc7, 0x22, 0xc7, 0x88, 0x03, 0x28, 0xa9, 0xc2, 0x80, 0x03, 0x0b, 0xc9, 0x75, 0x5c, 0x3e,
     0xf5, 0x19, 0xf8, 0x00, 0x00, 0x29, 0x53, 0x23, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x00, 0x00 }, 
   { 0x08, 0x55, 0x6d, 0x94, 0x4c, 0x71, 0xa1, 0xa0, 0x81, 0xe7, 0xea, 0xd2, 0x04, 0x24, 0x44, 0x80,
     0x00, 0x0e, 0xcd, 0x82, 0xb8, 0x11, 0x18, 0x00, 0x00, 0x97, 0xc4, 0x79, 0x4e, 0x77, 0x40, 0x00,
     0x00, 0x00 }
 };
 
/* Homing frame is in if1 format. Frames have only AMRWB Core Frame( speech or comfort noise data ), which 
 * includes class A, class B and class C bits. Note we have to append header( frame type and codec rate ) 
 * to make its format similar to the packets received from VSM. 
 * Maximum number of class A, class B, class C bits in AMRWB will be 477 bits, which equals 60 bytes. 
 * Referred docs: Specs : 3GPP TS 26.201. and "Vocoder media types" document - 80-N8828-1 
 */
static uint8_t voice_util_awb_if1_homing_frame[ VOICE_UTIL_AMRWB_MAX_NUM_CODEC_MODE_V ]
                                              [ VOICE_UTIL_AMRWB_FRAME_SIZE_V ] = 
{
  { 0x00, 0x31, 0x00, 0x38, 0x9c, 0x10, 0x30, 0x01, 0xf2, 0x07, 0x22, 0xfa, 0x89, 0xeb, 0xdb, 0x8a,
    0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x44, 0x00, 0x0f, 0x00, 0x0a, 0x55, 0xf1, 0x5d, 0x22, 0x0f, 0x94, 0xd7, 0x01, 0xfa, 0xa4, 0x85,
    0xa7, 0x44, 0x46, 0xc5, 0xe6, 0xe5, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x50, 0x46, 0x00, 0x77, 0xff, 0xde, 0x05, 0xf1, 0x5b, 0x67, 0x8f, 0x8c, 0xf7, 0x70, 0x07, 0xda,
    0x82, 0xca, 0xd1, 0x5a, 0x42, 0xde, 0x5a, 0xc0, 0x44, 0xee, 0xd3, 0x5a, 0xe6, 0x44, 0xd1, 0xd8,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x50, 0x46, 0x00, 0x33, 0xbe, 0xce, 0x05, 0xf1, 0x59, 0x63, 0x9f, 0x84, 0xc7, 0x50, 0x29, 0x13,
    0x91, 0x9a, 0x9a, 0x64, 0xf2, 0x3a, 0x0c, 0xd6, 0xa5, 0x85, 0x5e, 0xc5, 0x74, 0x44, 0xc5, 0x8d,
    0x5c, 0xc7, 0xed, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x50, 0x46, 0x00, 0x33, 0xb6, 0xce, 0x45, 0xf1, 0x5b, 0xe7, 0x9f, 0x84, 0xf7, 0x53, 0x91, 0x99,
    0x31, 0x10, 0x29, 0x9e, 0x4c, 0x76, 0x0c, 0x59, 0xfc, 0x25, 0x42, 0x06, 0x0c, 0x6a, 0x86, 0x3d,
    0xf3, 0xdc, 0x04, 0x42, 0x46, 0x3d, 0xf1, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x50, 0x46, 0x00, 0x22, 0xa6, 0x8a, 0x05, 0xf1, 0x59, 0x23, 0x0f, 0x84, 0xc7, 0x77, 0x9f, 0x36,
    0xc7, 0xf9, 0xe6, 0x82, 0x48, 0x89, 0xb9, 0x13, 0x83, 0xee, 0xcd, 0x22, 0x06, 0xd5, 0x64, 0x08,
    0xfe, 0x16, 0x46, 0x12, 0xbe, 0x01, 0x1e, 0xc0, 0x8a, 0xd5, 0xa4, 0x87, 0x27, 0x88, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x50, 0x46, 0x00, 0x22, 0xa6, 0x8a, 0x05, 0xf1, 0x59, 0xe3, 0x1f, 0x8c, 0xe7, 0x70, 0x99, 0xab,
    0xbf, 0x10, 0x6e, 0x38, 0x11, 0x7b, 0x69, 0x89, 0x42, 0x1b, 0x22, 0x71, 0x82, 0x41, 0xb9, 0x46,
    0x88, 0x62, 0xc0, 0xb8, 0xfb, 0xb5, 0x6a, 0x5b, 0x6a, 0xa2, 0x32, 0x83, 0x20, 0xa7, 0xb7, 0xb3,
    0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x50, 0x46, 0x10, 0x33, 0xb6, 0xce, 0x55, 0xf1, 0x5b, 0xe3, 0x17, 0x84, 0xf7, 0x7b, 0xf9, 0x5e,
    0x65, 0x50, 0x75, 0x07, 0xec, 0x48, 0x01, 0x79, 0x92, 0x12, 0x1a, 0xd5, 0xb8, 0x2d, 0xd9, 0xf5,
    0x70, 0x95, 0xe0, 0x21, 0x40, 0xe3, 0x24, 0x58, 0x54, 0x22, 0x5b, 0x34, 0xa6, 0xbe, 0x22, 0x31,
    0x64, 0xd7, 0x9d, 0x9d, 0xfa, 0xcf, 0xac, 0x4b, 0x97, 0xe8, 0x00, 0x00 },
  { 0x50, 0x46, 0x00, 0x33, 0xba, 0xce, 0x25, 0xf1, 0x59, 0x20, 0x00, 0xa3, 0x1f, 0x84, 0xd7, 0x77,
    0xf3, 0x6a, 0x13, 0x13, 0xa0, 0x93, 0xe5, 0x0c, 0x29, 0x21, 0x72, 0xf1, 0xc3, 0x83, 0xec, 0x66,
    0x35, 0x89, 0x3e, 0x80, 0xe8, 0x89, 0x52, 0xc0, 0x25, 0xb5, 0x1c, 0x6d, 0xe6, 0x3c, 0x07, 0xbc,
    0x33, 0x55, 0xe9, 0xc0, 0x6d, 0x2c, 0xaf, 0xb3, 0xaf, 0x43, 0x31, 0xd0 }
};

/**
  Functions take media_id and meta-data of media_id and copies the corresponding 
  homing vector to frame location. 
 
  @par Payload

  INPUT PARAM:
  @param[in] media_id : Supported media id is VOICEAPP_MEDIA_ID_AMR and VOICEAPP_MEDIA_ID_AMRWB. 
  @param[in] frame_info: media_id determines the frame_info, it contains meta-data for media_id.
  @param[in,out] frame : Location at which ( header + homing frame ) has to be copied. 
  @param[in,out] frame_size: Size of ( header + homing frame ) that was copied to location frame. 
  
  @return 
  APR_EOK on success.

  @dependencies
  none

*/
APR_INTERNAL uint32_t voice_util_get_homing_frame 
(
  uint32_t media_id,
  void* frame_info,
  uint8_t* frame,
  uint32_t* frame_size
)
{
  uint32_t rc = APR_EOK;
  vs_vocamr_frame_info_t* amr_info;
  vs_vocamrwb_frame_info_t* amrwb_info;

  if ( ( frame_info == NULL ) || ( frame == NULL) ||
       ( frame_size == NULL ) )
  {
    MSG( MSG_SSID_DFLT, MSG_LEGACY_ERROR, "voice_util_get_homing_frame(): " \
         "Invalid parameter" );
    return APR_EBADPARAM;
  }
  
  switch( media_id )
  {
  case VS_COMMON_MEDIA_ID_AMR:
    {  
      amr_info = ( ( vs_vocamr_frame_info_t* )frame_info );

      if( ( amr_info->codec_mode < VS_VOCAMR_CODEC_MODE_0475 ) || 
          ( amr_info->codec_mode > VS_VOCAMR_CODEC_MODE_1220 ) )
      {
        MSG_1( MSG_SSID_DFLT, MSG_LEGACY_ERROR, "voice_util_get_homing_frame(): " \
               "Invalid mode (%d)", amr_info->codec_mode );
        *frame_size = 0; 
        return APR_EFAILED; 
      }

      /* Homing frame should be copied starting at an offset of 1 byte.
	     * First byte will be populated with the header.
	     */ 
      mmstd_memcpy( &frame[1], VOICE_UTIL_AMR_FRAME_SIZE_V,
                    voice_util_amr_if1_homing_frame[ amr_info->codec_mode ], 
                    VOICE_UTIL_AMR_FRAME_SIZE_V );

      *frame_size = VOICE_UTIL_AMR_FRAME_SIZE_V + 1;
      rc = APR_EOK;
    }
    break;
  
  case VS_COMMON_MEDIA_ID_AMRWB: 
    {
      amrwb_info = ( ( vs_vocamrwb_frame_info_t* )frame_info );
      
      if( ( amrwb_info->codec_mode < VS_VOCAMRWB_CODEC_MODE_0660 ) ||
          ( amrwb_info->codec_mode > VS_VOCAMRWB_CODEC_MODE_2385 ) )
      {
        MSG_1( MSG_SSID_DFLT, MSG_LEGACY_ERROR, "voice_util_get_homing_frame(): " \
               "Invalid mode (%d)", amrwb_info->codec_mode );
        *frame_size = 0; 
        return APR_EFAILED;
      }

      /* Homing frame should be copied starting at an offset of 1 byte.
	     * First byte will be populated with the header.
	     */ 
      mmstd_memcpy( &frame[1], VOICE_UTIL_AMRWB_FRAME_SIZE_V,
                    voice_util_awb_if1_homing_frame[ amrwb_info->codec_mode ], 
                    VOICE_UTIL_AMRWB_FRAME_SIZE_V );

      *frame_size = VOICE_UTIL_AMRWB_FRAME_SIZE_V + 1;
      rc = APR_EOK;
    }
    break;
  
  default: 
    {
      MSG_1( MSG_SSID_DFLT, MSG_LEGACY_ERROR,
             "voice_util_get_homing_frame(): Media ID (0x%08x) not supported", media_id );
      rc  = APR_EUNSUPPORTED;
    }
    break;
  }
  
  return rc;
}

