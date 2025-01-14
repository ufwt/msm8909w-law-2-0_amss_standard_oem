/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*


             M M G S D I   S E 1 3  A D D L  L A N G  T A B L E


GENERAL DESCRIPTION

  This source file contains a hardcoded array of PLMN names in additional
  languages such as Chinese. The names are stored in UNICODE format.


                        COPYRIGHT INFORMATION

Copyright (c) 2013, 2015-2016 QUALCOMM Technologies, Inc (QTI) and its licensors.
All Rights Reserved.  QUALCOMM Technologies Proprietary.  
Export of this technology or software
is regulated by the U.S. Government. Diversion contrary to U.S. law prohibited.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/*===========================================================================
                        EDIT HISTORY FOR MODULE

$Header: //commercial/MPSS.JO.2.0.c1.4/Main/modem_proc/uim/mmgsdi/src/mmgsdi_se13_addl_lang_table.h#1 $$ $DateTime: 2016/12/13 08:00:05 $

===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "customer.h"
#include "mmgsdi_eons.h"

/*=========================================================================== n

           THE ARRAY

===========================================================================*/

/* Additional languages (such as Chinese) PLMN names table.
   zh_hant == Traditional Chinese
   zh_hans == Simplified Chinese */
mmgsdi_eons_network_info_addl_lang_data_type mmgsdi_addl_lang_network_table[] = {
  /* Traditional Chinese */
  { "zh_hant", 454, 12, MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    12, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5, 0x99, 0x99, 0x6E, 0x2F}, 12, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5, 0x99, 0x99, 0x6E, 0x2F}},
  { "zh_hant", 455, 02, MMGSDI_PLMN_NETWK_TYPE_LTE_MASK,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x75, 0x35, 0x4F, 0xE1}},
  { "zh_hant", 460, 00, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK,
    8, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5}, 8, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5}},
  { "zh_hant", 460, 01, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK|MMGSDI_PLMN_NETWK_TYPE_UMTS_MASK,
    8, {0x4E, 0x2D, 0x57, 0x0B, 0x80, 0x6F, 0x90, 0x1A}, 8, {0x4E, 0x2D, 0x57, 0x0B, 0x80, 0x6F, 0x90, 0x1A}},
  { "zh_hant", 460, 02, 0xFF,
    8, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5}, 8, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5}},
  { "zh_hant", 460, 05, 0xFF,
    8, {0x4E, 0x2D, 0x57, 0x0B, 0x96, 0xFB, 0x4F, 0xE1}, 8, {0x4E, 0x2D, 0x57, 0x0B, 0x96, 0xFB, 0x4F, 0xE1}},
  { "zh_hant", 460, 06, 0xFF,
    8, {0x4E, 0x2D, 0x57, 0x0B, 0x80, 0x6F, 0x90, 0x1A}, 8, {0x4E, 0x2D, 0x57, 0x0B, 0x80, 0x6F, 0x90, 0x1A}},
  { "zh_hant", 460, 07, 0xFF,
    8, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5}, 8, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5}},
  { "zh_hant", 460, 20, 0xFF,
    14, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5, 0x00, 0x2D, 0x00, 0x33, 0x00, 0x47}, 14, {0x4E, 0x2D, 0x57, 0x0B, 0x79, 0xFB, 0x52, 0xD5, 0x00, 0x2D, 0x00, 0x33, 0x00, 0x47}},
  { "zh_hant", 466, 01, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK|MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    8, {0x90, 0x60, 0x50, 0xB3, 0x96, 0xFB, 0x4F, 0xE1}, 8, {0x90, 0x60, 0x50, 0xB3, 0x96, 0xFB, 0x4F, 0xE1}}, /* FET */
  { "zh_hant", 466, 06, 0xFF,
    8, {0x54, 0x8C, 0x4F, 0xE1, 0x96, 0xFB, 0x8A, 0x0A}, 8, {0x54, 0x8C, 0x4F, 0xE1, 0x96, 0xFB, 0x8A, 0x0A}},
  { "zh_hant", 466, 88, MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    8, {0x54, 0x8C, 0x4F, 0xE1, 0x96, 0xFB, 0x8A, 0x0A}, 8, {0x54, 0x8C, 0x4F, 0xE1, 0x96, 0xFB, 0x8A, 0x0A}}, /* KGT-Online */
  { "zh_hant", 466, 89, MMGSDI_PLMN_NETWK_TYPE_UMTS_MASK,
    8, {0x5A, 0x01, 0x5B, 0xF6, 0x96, 0xFB, 0x4F, 0xE1}, 8, {0x5A, 0x01, 0x5B, 0xF6, 0x96, 0xFB, 0x4F, 0xE1}}, /* Vibo Telecom */
  { "zh_hant", 466, 92, MMGSDI_PLMN_NETWK_TYPE_UMTS_MASK|MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK|MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    8, {0x4E, 0x2D, 0x83, 0xEF, 0x96, 0xFB, 0x4F, 0xE1}, 8, {0x4E, 0x2D, 0x83, 0xEF, 0x96, 0xFB, 0x4F, 0xE1}}, /* Chungwa Telecom */
  { "zh_hant", 466, 97, MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    10, {0x53, 0xF0, 0x70, 0x63, 0x59, 0x27, 0x54, 0xE5, 0x59, 0x27}, 10, {0x53, 0xF0, 0x70, 0x63, 0x59, 0x27, 0x54, 0xE5, 0x59, 0x27}}, /* Taiwan Mobile */
  { "zh_hant", 466, 99, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK,
    8, {0x6C, 0xDB, 0x4E, 0x9E, 0x96, 0xFB, 0x4F, 0xE1}, 8, {0x6C, 0xDB, 0x4E, 0x9E, 0x96, 0xFB, 0x4F, 0xE1}},
  { "zh_hant", 466, 93, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK,
    8, {0x67, 0x71, 0x4F, 0xE1, 0x96, 0xFB, 0x8A, 0x0A}, 8, {0x67, 0x71, 0x4F, 0xE1, 0x96, 0xFB, 0x8A, 0x0A}}, /* TW MOB */

  /* Simplified Chinese */
  { "zh_hans", 454, 12, MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    12, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8, 0x99, 0x99, 0x6E, 0x2F}, 12, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8, 0x99, 0x99, 0x6E, 0x2F}},
  { "zh_hans", 455, 02, MMGSDI_PLMN_NETWK_TYPE_LTE_MASK,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x75, 0x35, 0x4F, 0xE1}},
  { "zh_hans", 460, 00, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8}},
  { "zh_hans", 460, 01, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK|MMGSDI_PLMN_NETWK_TYPE_UMTS_MASK,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x80, 0x54, 0x90, 0x1A}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x80, 0x54, 0x90, 0x1A}},
  { "zh_hans", 460, 02, 0xFF,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8}},
  { "zh_hans", 460, 05, 0xFF,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x75, 0x35, 0x4F, 0xE1}},
  { "zh_hans", 460, 06, 0xFF,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x80, 0x54, 0x90, 0x1A}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x80, 0x54, 0x90, 0x1A}},
  { "zh_hans", 460, 07, 0xFF,
    8, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8}, 8, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8}},
  { "zh_hans", 460, 20, 0xFF,
    14, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8, 0x00, 0x2D, 0x00, 0x33, 0x00, 0x47}, 14, {0x4E, 0x2D, 0x56, 0xFD, 0x79, 0xFB, 0x52, 0xA8, 0x00, 0x2D, 0x00, 0x33, 0x00, 0x47}},
  { "zh_hans", 466, 01, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK|MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    8, {0x8F, 0xDC, 0x4F, 0x20, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x8F, 0xDC, 0x4F, 0x20, 0x75, 0x35, 0x4F, 0xE1}}, /* FET */
  { "zh_hans", 466, 06, 0xFF,
    8, {0x54, 0x8C, 0x4F, 0xE1, 0x75, 0x35, 0x8B, 0xAF}, 8, {0x54, 0x8C, 0x4F, 0xE1, 0x75, 0x35, 0x8B, 0xAF}},
  { "zh_hans", 466, 88, MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    8, {0x54, 0x8C, 0x4F, 0xE1, 0x75, 0x35, 0x8B, 0xAF}, 8, {0x54, 0x8C, 0x4F, 0xE1, 0x75, 0x35, 0x8B, 0xAF}}, /* KGT-Online */
  { "zh_hans", 466, 89, MMGSDI_PLMN_NETWK_TYPE_UMTS_MASK,
    8, {0x5A, 0x01, 0x5B, 0x9D, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x5A, 0x01, 0x5B, 0x9D, 0x75, 0x35, 0x4F, 0xE1}}, /* Vibo Telecom */
  { "zh_hans", 466, 92, MMGSDI_PLMN_NETWK_TYPE_UMTS_MASK|MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK|MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    8, {0x4E, 0x2D, 0x53, 0x4E, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x4E, 0x2D, 0x53, 0x4E, 0x75, 0x35, 0x4F, 0xE1}}, /* Chungwa Telecom */
  { "zh_hans", 466, 97, MMGSDI_PLMN_NETWK_TYPE_DCS_1800_MASK,
    10, {0x53, 0xF0, 0x6E, 0x7E, 0x59, 0x27, 0x54, 0xE5, 0x59, 0x27}, 10, {0x53, 0xF0, 0x6E, 0x7E, 0x59, 0x27, 0x54, 0xE5, 0x59, 0x27}}, /* Taiwan Mobile */
  { "zh_hans", 466, 99, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK,
    8, {0x6C, 0xDB, 0x4E, 0x9A, 0x75, 0x35, 0x4F, 0xE1}, 8, {0x6C, 0xDB, 0x4E, 0x9A, 0x75, 0x35, 0x4F, 0xE1}},
  { "zh_hans", 466, 93, MMGSDI_PLMN_NETWK_TYPE_GSM_900_MASK,
    8, {0x4E, 0x1C, 0x4F, 0xE1, 0x75, 0x35, 0x8B, 0xAF}, 8, {0x4E, 0x1C, 0x4F, 0xE1, 0x75, 0x35, 0x8B, 0xAF}} /* TW MOB */
}; /* mmgsdi_addl_lang_network_table */
