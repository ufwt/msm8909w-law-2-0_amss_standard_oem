#===============================================================================
#
# CoreBSP SINGLE proc tool rules
#
# GENERAL DESCRIPTION
#    rules build script
#
# Copyright (c) 2009-2009 by Qualcomm Technologies, Incorporated.
# All Rights Reserved.
# QUALCOMM Proprietary/GTDR
#
#-------------------------------------------------------------------------------
#
#  $Header: //components/rel/rpm.bf/2.1.1/tools/build/scons/scripts/single_defs.py#1 $
#  $DateTime: 2015/02/25 02:53:43 $
#  $Author: pwbldsvc $
#  $Change: 7538753 $
#                      EDIT HISTORY FOR FILE
#                      
#  This section contains comments describing changes made to the module.
#  Notice that changes are listed in reverse chronological order.
#  
# when       who     what, where, why
# --------   ---     ---------------------------------------------------------
#
#===============================================================================
import sys
import os
import string

# Assembly compile flags (note first pass is through armcc using -E option then passed to armas, see 
# build rule below
asm_dflags = '-DCUST_H=\\"${CUST_H}\\" '

# standard MODEM compile flags
single_dflags = '-DCUST_H=\\"${CUST_H}\\" -DBUILD_TARGET=\\"${BUILD_ID}\\" ' \
   '-DBUILD_VER=\\"${BUILD_VER}\\" -DBUILD_ASIC=\\"${BUILD_ASIC}\\" -DAEE_STATIC'
   
#------------------------------------------------------------------------------
# Hooks for Scons
#------------------------------------------------------------------------------
def exists(env):
   return env.Detect('modemtools_defs')

def generate(env):
   # Assembly common flags
   env.Replace(ASM_DFLAGS = asm_dflags)
   
   # CC (apps) common compile flags
   env.Replace(CC_DFLAGS = single_dflags)
   
   if not env.has_key('BUILD_TOOL_CHAIN'):
      env.Append(ASM_DFLAGS = ' -DQC_MODIFIED -Dinline=__inline')
      env.Append(CC_DFLAGS = ' -DASSERT=ASSERT_FATAL -DQC_MODIFIED -Dinline=__inline')
