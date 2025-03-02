#ifndef QSEE_KEYPROV_H
#define QSEE_KEYPROV_H

/**
@file qsee_keyprov.h
@brief Provide Macchiato key provisioning API
*/

/*===========================================================================
   Copyright (c) 2014 by QUALCOMM Technologies Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

  $Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/securemsm/trustzone/qsee/qsee_keyprov.h#1 $
  $DateTime: 2016/06/17 14:31:11 $
  $Author: pwbldsvc $

when       who          what, where, why
--------   -------      ------------------------------------
08/12/14    cz          Initial version.

===========================================================================*/

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <comdef.h>
#include "qsee_ecc.h"
 
enum
{
/* Macchiato Return Error Codes */
  QSEE_MACC_KEYGEN_SUCCESS             = 0,  /* Success */
  QSEE_MACC_KEYGEN_INVALID_PARAM,
  QSEE_MACC_KEYGEN_CIPHER_ERROR,
  QSEE_MACC_KEYGEN_MAX_ERROR
};
  
/* 
 * bit 0: 0 = signing, 1 = encryption
 * bit 12: 00 = AUTO select 
 *         01 = HW key
 *         10 = SW key 
 */
#define MACCHIATO_KEY_TYPE_ECC_AUTO_SIGNING        (0x0)
#define MACCHIATO_KEY_TYPE_ECC_HWKEY_SIGNING       (0x1)
#define MACCHIATO_KEY_TYPE_ECC_SWKEY_SIGNING       (0x2)
#define MACCHIATO_KEY_TYPE_ECC_AUTO_ENCRYPTION     (0x3)
#define MACCHIATO_KEY_TYPE_ECC_HWKEY_ENCRYPTION    (0x4)
#define MACCHIATO_KEY_TYPE_ECC_SWKEY_ENCRYPTION    (0x5)


/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/

/**
 * Seed computation routine. Generates a ECC private key.
 * Output privkey is a pointer to a 256 bit number between 1 and the order of the underlying
 * elliptic curve. This number is generated deterministically from the BPK.
 * The public key is then generated by the following call:
 * ECDH_mult_basepoint(&public_point, &privkey);
 * where public_point is an elliptic curve point in affine coordinates.
 * 
 * The routine includes two different magic texts for the signing and encryption keys. The first four
 * bytes of the magic texts are in fact initially zero and represent counters. The key generator re-
 * peatedly encrypts the magic text using AES-CBC and the BPK as the AES-256 key, increasing
 * the counter, until a value is obtained that, as an integer represents an integer between 1 and the
 * order of the base point on the curve, minus one.
 * 
 * @param[in]    type   keytype	is used to establish whether the private key generated will be
 *						the one used for signing or for encryption.	
 * 						– MACCHIATO_KEY_TYPE_ECC_HWKEY_SIGNING, or
 * 						– MACCHIATO_KEY_TYPE_ECC_HWKEY_ENCRYPTION,
 * @param[out]   private key. Memory must be allocated by caller. Output privkey
 *  			is a pointer to a 256 bit number between 1 and the order of the
 * 				underlying elliptic curve. 
 *
 * @return 
 * 0     - Function executes successfully.
 * errors can depend on the actual implementation of the AES_set_key routine,
 * in general CE_ERROR_INVALID_ARG
 */
int qsee_macc_gen_ecc_privkey(int type, QSEE_bigval_t *privkey, uint32 key_buf_len);

#endif /*QSEE_KEYPROV_H*/

