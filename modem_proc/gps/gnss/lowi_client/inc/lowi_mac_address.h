#ifndef __LOWI_MAC_ADDRESS_H__
#define __LOWI_MAC_ADDRESS_H__

/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

        LOWI Mac Address Interface Header file

GENERAL DESCRIPTION
  This file contains the structure definitions and function prototypes for
  LOWI SSID

  Copyright (c) 2012 Qualcomm Technologies Incorporated.
  Qualcomm Confidential and Proprietary. All Rights Reserved.
  Copyright (c) 2013 - 2014 Qualcomm Atheros, Inc.
  Qualcomm Atheros Confidential and Proprietary. All Rights Reserved. 

Export of this technology or software is regulated by the U.S. Government.
Diversion contrary to U.S. law prohibited.
=============================================================================*/

#if APSS
#include <inc/lowi_defines.h>
#include <inc/lowi_const.h>
#else
#include "comdef.h"
#include "lowi_const.h"
#endif


namespace qc_loc_fw
{
/**
 * Class for LOWIMacAddress
 */
class LOWIMacAddress
{
public:
  /**
   * Default Constructor
   */
  LOWIMacAddress();

  /**
   * Constructor
   * @param unsigned char* Mac address
   */
  LOWIMacAddress(const unsigned char * const pAddr);

  /**
   * Constructor
   * @param uint8 first byte of the address
   * @param uint8 second byte of the address
   * @param uint8 third byte of the address
   * @param uint8 fourth byte of the address
   * @param uint8 fifth byte of the address
   * @param uint8 sixth byte of the address
   */
  LOWIMacAddress (uint8 a0, uint8 a1, uint8 a2,
      uint8 a3, uint8 a4, uint8 a5);

  /**
   * Copy Constructor
   * @param LOWIMacAddress& Mac address
   */
  LOWIMacAddress(const LOWIMacAddress& rhs);

  /**
   * Returns the Lower 24 bits
   * @return integer containing lower 24 bits of the Mac address
   */
  unsigned int getLo24() const;
  /**
   * Returns the Upper 24 bits
   * @return integer containing upper 24 bits of the Mac address
   */
  unsigned int getHi24() const;
  /**
   * Returns the Full 48 bits of the Mac Address
   * @return long long containing full 48 bits of the Mac address
   */
  unsigned long long getFull48() const;

  /**
   * Returns the Full 48 bits of the Mac Address in reverse order
   * @return long long containing full 48 bits of the Mac address
   */
  unsigned long long getReversed48() const;

  /**
   * Sets the Mac Address
   * @param LOWIMacAddress& LOWIMacAddress
   */
  int setMac(const LOWIMacAddress& rhs);

  /**
   * Sets the Mac Address
   * @param unsigned char* Mac address
   */
  int setMac(const unsigned char * const pAddr);

  /**
   * Sets the Mac Address
   * @param int Upper 24 bits of the mac address
   * @param int Lower 24 bits of the mac address
   */
  int setMac(const int addr_hi24, const int addr_lo24);

  /**
   * Compares Mac Addresses
   * @param void* LOWIMacAddress
   * @param void* LOWIMacAddress
   * @return comparison results (0 for equal)
   */
  static int compareTo(const void * pLhs, const void * pRhs);

  /**
   * Compares Mac Addresses
   * @param LOWIMacAddress& LOWIMacAddress
   * @return comparison results (0 for equal)
   */
  int compareTo (const LOWIMacAddress & mac);

  /**
   * Returns the value at the index passed
   * @param int Index of the element required
   * @return value corresponding to the index
   */
  unsigned char operator [](const int index) const;

  /**
   * Prints the Mac Address in the correct form
   */
  void print ();

  /**
   * Copies the values from passed LOWIMacAddress
   * @param LOWIMacAddress& LOWIMacAddress
   * @return LOWIMacAddress&
   */
  LOWIMacAddress & operator =(const LOWIMacAddress & rhs);
private:
  static const char* const TAG;
  int m_lo24;
  int m_hi24;
};

} // namespace qc_loc_fw

#endif //#ifndef __LOWI_MAC_ADDRESS_H__
