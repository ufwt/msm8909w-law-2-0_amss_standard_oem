/*
===========================================================================
*/
/**
  @file ClockRPMNPA.c

  DCVS NPA node definitions for the MDM9x45 RPM clock driver.
*/
/*
  ====================================================================

  Copyright (c) 2014 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/rpm.bf/2.1.1/core/systemdrivers/clock/hw/mdm9x45/ClockRPMNPA.c#1 $
  $DateTime: 2015/02/25 02:53:43 $
  $Author: pwbldsvc $

  when       who     what, where, why
  --------   ---     -------------------------------------------------
  07/14/14   pbitra     Created from 9x35.

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockRPMNPA.h"
#include "mpm.h"
#include "ddr_drivers.h"
#include "swevent.h"
#include "QDSSLite.h"
#include "ClockRPMBIMC.h"


/*=========================================================================
      Macros
==========================================================================*/
#define NOMINAL_VOLTAGE 900000

/*=========================================================================
      Prototypes
==========================================================================*/
extern unsigned int qdss_fuse_trace_access(void);
extern void sleep_update_xo_stats(const npa_client *, const npa_client *);

static npa_resource_state Clock_NPANodeCXOFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);


static npa_resource_state Clock_NPANodeDCVSEnaFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);


static npa_resource_state Clock_NPANodeCPUFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);

static npa_resource_state Clock_NPANodeGenericFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);

static npa_resource_state Clock_NPANodeBIMCFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);


static npa_resource_state Clock_NPANodeQPICFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);

static npa_resource_state Clock_NPANodeIPAFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);

static npa_resource_state Clock_NPANodeCryptoFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);

static npa_resource_state Clock_NPANodeQDSSFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
);


static npa_query_status Clock_NPAResourceQuery
(
  npa_resource   *pResource,
  unsigned int   nId,
  npa_query_type *pResult
);

static void Clock_QDSS_PreChangedCB
(
  const railway_settings *settings,
  void                   *cookie
);

static void Clock_QDSS_PostChangedCB
(
  const railway_settings *settings,
  void                   *cookie
);


/*=========================================================================
      Data
==========================================================================*/

/*
 * Define the local clock resources.
 */
Clock_NPAResourcesType Clock_Resources =
{
  .CXONPANode =
  {
    /* CXO Resource */
    .Resource =
    {
      "/xo/cxo",                                                    /* Name of resource */
      "Enable",                                                     /* Units for this resource */
      1,                                                            /* Maximum state */
      &npa_max_plugin,                                              /* Plugin */
      (NPA_RESOURCE_REMOTE_ACCESS_ALLOWED | NPA_RESOURCE_DRIVER_UNCONDITIONAL),
                                                                    /* Resource Attributes */
    },

    /* CXO Node */
    .Node =
    {
      "/node/xo/cxo",                                               /* Name */
      Clock_NPANodeCXOFunc,                                         /* Driver function */
      NPA_RESOURCE_DEFAULT,                                         /* Attributes */
      NULL,                                                         /* Data */
      NPA_EMPTY_ARRAY,                                              /* Dep array */
      1,
      &Clock_Resources.CXONPANode.Resource                          /* Resource Array */
    }
  },

  .DCVSEnaNPANode =
  {
    /* DCVS Enable Resource */
    .Resource =
    {
      "/clk/dcvs.ena",                                              /* Name of resource */
      "Enable",                                                     /* Units for this resource */
      1,                                                            /* Maximum state */
      &npa_max_plugin,                                              /* Plugin */
      NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                           /* Resource Attributes */
    },

    /* CXO Node */
    .Node =
    {
      "/node/clk/dcvs.ena",                                         /* Name */
      Clock_NPANodeDCVSEnaFunc,                                     /* Driver function */
      NPA_RESOURCE_DEFAULT,                                         /* Attributes */
      NULL,                                                         /* Data */
      NPA_EMPTY_ARRAY,                                              /* Dep array */
      1,
      &Clock_Resources.DCVSEnaNPANode.Resource                      /* Resource Array */
    }
  },

  .CPUClockResource =
  {
    .NPANode =
    {
      /* CPU Resource */
      .Resource =
      {
        "/clk/cpu",                                                 /* Name of resource */
        "KHz",                                                      /* Units for this resource */
        0,                                                          /* Maximum state */
        &npa_max_plugin,                                            /* Plugin */
        NPA_RESOURCE_DEFAULT,                                       /* Resource Attributes */
      },

      /* CPU Node */
      .Node =
      {
        "/node/clk/cpu",                                            /* Name */
        Clock_NPANodeCPUFunc,                                       /* Driver function */
        NPA_RESOURCE_DEFAULT,                                       /* Attributes */
        &Clock_Resources.CPUClockResource,                          /* Data */
        NPA_EMPTY_ARRAY,                                            /* Dep array */
        1,
        &Clock_Resources.CPUClockResource.NPANode.Resource          /* Resource Array */
      }
    }
  },

  .SNOCClockResource =
  {
    .NPANode =
    {
      /* SNOC Resource */
      .Resource =
      {
        "/clk/snoc",                                                /* Name of resource */
        "KHz",                                                      /* Units for this resource */
        0,                                                          /* Maximum state */
        &npa_max_plugin,                                            /* Plugin */
        NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                         /* Resource Attributes */
        (npa_user_data)NULL,                                        /* User data field  */
        Clock_NPAResourceQuery                                      /* Query fcn */
      },

      /* SNOC Node */
      .Node =
      {
        "/node/clk/snoc",                                           /* Name */
        Clock_NPANodeGenericFunc,                                   /* Driver function */
        NPA_RESOURCE_DEFAULT,                                       /* Attributes */
        &Clock_Resources.SNOCClockResource,                         /* Data */
        NPA_EMPTY_ARRAY,                                            /* Dep array */
        1,
        &Clock_Resources.SNOCClockResource.NPANode.Resource         /* Resource Array */
      }
    }
  },

  .PCNOCClockResource =
  {
    .NPANode =
    {
      /* PCNOC Resource */
      .Resource =
      {
        "/clk/pcnoc",                                               /* Name of resource */
        "KHz",                                                      /* Units for this resource */
        0,                                                          /* Maximum state */
        &npa_max_plugin,                                            /* Plugin */
        NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                         /* Resource Attributes */
        (npa_user_data)NULL,                                        /* User data field  */
        Clock_NPAResourceQuery                                      /* Query fcn */
      },

      /* PCNOC Node */
      .Node =
      {
        "/node/clk/pcnoc",                                          /* Name */
        Clock_NPANodeGenericFunc,                                   /* Driver function */
        NPA_RESOURCE_DEFAULT,                                       /* Attributes */
        &Clock_Resources.PCNOCClockResource,                        /* Data */
        NPA_EMPTY_ARRAY,                                            /* Dep array */
        1,
        &Clock_Resources.PCNOCClockResource.NPANode.Resource        /* Resource Array */
      }
    }
  },

  .BIMCClockResource =
  {
    .NPANode =
    {
      /* BIMC Resource */
      .Resource =
      {
        "/clk/bimc",                                                /* Name of resource */
        "KHz",                                                      /* Units for this resource */
        0,                                                          /* Maximum state */
        &npa_bimc_max_plugin,                                       /* Plugin */
        (NPA_RESOURCE_DRIVER_UNCONDITIONAL | NPA_RESOURCE_REMOTE_ACCESS_ALLOWED),   /* Resource Attributes */
        (npa_user_data)NULL,                                        /* User data field  */
        Clock_NPAResourceQuery                                      /* Query fcn */
      },

      /* BIMC Node */
      .Node =
      {
        "/node/clk/bimc",                                           /* Name */
        Clock_NPANodeBIMCFunc,                                      /* Driver function */
        NPA_RESOURCE_DEFAULT,                                       /* Attributes */
        &Clock_Resources.BIMCClockResource,                         /* Data */
        NPA_EMPTY_ARRAY,                                            /* Dep array */
        1,
        &Clock_Resources.BIMCClockResource.NPANode.Resource /* Resource Array */
      }
    }
  },

  .QPICClockResource =
  {
    .NPANode =
    {
      /* QPIC Resource */
      .Resource =
      {
        "/clk/qpic",                                                  /* Name of resource */
        "KHz",                                                        /* Units for this resource */
        0,                                                            /* Maximum state */
        &npa_max_plugin,                                              /* Plugin */
        NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                           /* Resource Attributes */
        (npa_user_data)NULL,                                          /* User data field  */
        Clock_NPAResourceQuery                                        /* Query fcn */
      },

      /* QPIC Node */
      .Node =
      {
        "/node/clk/qpic",                                             /* Name */
        Clock_NPANodeQPICFunc,                                        /* Driver function */
        NPA_RESOURCE_DEFAULT,                                         /* Attributes */
        &Clock_Resources.QPICClockResource,                           /* Data */
        NPA_EMPTY_ARRAY,                                              /* Dep array */
        1,
        &Clock_Resources.QPICClockResource.NPANode.Resource           /* Resource Array */
      }
    }
  },

  .IPAClockResource =
  {
    .NPANode =
    {
      /* IPA Resource */
      .Resource =
      {
        "/clk/ipa",                                                 /* Name of resource */
        "KHz",                                                      /* Units for this resource */
        0,                                                          /* Maximum state */
        &npa_max_plugin,                                            /* Plugin */
        NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                         /* Resource Attributes */
        (npa_user_data)NULL,                                        /* User data field  */
        Clock_NPAResourceQuery                                      /* Query fcn */
      },

      /* IPA Node */
      .Node =
      {
        "/node/clk/ipa",                                            /* Name */
        Clock_NPANodeIPAFunc,                                       /* Driver function */
        NPA_RESOURCE_DEFAULT,                                       /* Attributes */
        &Clock_Resources.IPAClockResource,                          /* Data */
        NPA_EMPTY_ARRAY,                                            /* Dep array */
        1,
        &Clock_Resources.IPAClockResource.NPANode.Resource /* Resource Array */
      }
    }
  },
  .CEClockResource =
  {
    .ClkCE =
    {
      .NPANode =
      {
        /* CE Resource */
        .Resource =
        {
          "/clk/ce1",                                                 /* Name of resource */
          "KHz",                                                      /* Units for this resource */
          0,                                                          /* Maximum state */
          &npa_max_plugin,                                            /* Plugin */
          NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                         /* Resource Attributes */
          (npa_user_data)NULL,                                        /* User data field  */
          Clock_NPAResourceQuery                                      /* Query fcn */
        },

        /* CE Node */
        .Node =
        {
          "/node/clk/ce1",                                            /* Name */
          Clock_NPANodeCryptoFunc,                                    /* Driver function */
          NPA_RESOURCE_DEFAULT,                                       /* Attributes */
          &Clock_Resources.CEClockResource,                          /* Data */
          NPA_EMPTY_ARRAY,                                            /* Dep array */
          1,
          &Clock_Resources.CEClockResource.ClkCE.NPANode.Resource    /* Resource Array */
        }
      }
    }
  },
  .QDSSClockResource =
  {
    .NPANode =
    {
      /* QDSS Resource */
      .Resource =
      {
        "/clk/qdss",                                                /* Name of resource */
        "STATE",                                                    /* Units for this resource */
        CLOCK_QDSS_LEVEL_LOW,                                       /* Maximum state */
        &npa_max_plugin,                                            /* Plugin */
        NPA_RESOURCE_REMOTE_ACCESS_ALLOWED,                         /* Resource Attributes */
      },

      /* QDSS Node */
      .Node =
      {
        "/node/clk/qdss",                                           /* Name */
        Clock_NPANodeQDSSFunc,                                      /* Driver function */
        NPA_RESOURCE_DEFAULT,                                       /* Attributes */
        &Clock_Resources.QDSSClockResource,                         /* Data */
        NPA_EMPTY_ARRAY,                                            /* Dep array */
        1,
        &Clock_Resources.QDSSClockResource.NPANode.Resource         /* Resource Array */
      }
    }
  }
};


/*=========================================================================
      Functions
==========================================================================*/

/*===========================================================================

  FUNCTION      Clock_GetNPAResources

  DESCRIPTION   This function is for getting the point to all clocks NPA node

  PARAMETERS    None

  DEPENDENCIES  None.

  RETURN VALUE  Pointer to all clocks NPA resource

  SIDE EFFECTS  None.

===========================================================================*/
Clock_NPAResourcesType* Clock_GetNPAResources
(
  void
)
{
  return &Clock_Resources;
}


/*===========================================================================

  FUNCTION      Clock_SetClockSpeed

  DESCRIPTION   This function is for setting the clock speed

  PARAMETERS    pClockResource [in] - Clock to be change
                nFreqHz [in]        - New clock speed

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
npa_resource_state Clock_SetClockSpeed
(
  ClockResourceType   *pClockResource,
  uint32              nFreqHz
)
{
  uint32              nCfg;
  ClockMuxConfigType  *pNewConfig;

  /* Find new clock config that match to setting frequency */
  pNewConfig = pClockResource->pClock->pDomain->pBSPConfig;

  for ( nCfg = pClockResource->nMinLevel; nCfg < pClockResource->nMaxLevel; nCfg++ )
  {
    // Check frequency that supported in this HW version only
    if ( Clock_IsBSPSupported(&pNewConfig[nCfg]) &&
         (nFreqHz <= pNewConfig[nCfg].nFreqHz) )
    {
      break;
    }
  }

  /* Do nothing if clock is already in the same as active config */
  if ( &pNewConfig[nCfg] == pClockResource->pClock->pDomain->pActiveMuxConfig )
  {
    return pNewConfig[nCfg].nFreqHz;
  }

  /* Switch clock */
  Clock_SetClockConfig( pClockResource->pClock->pDomain, &pNewConfig[nCfg] );
  pClockResource->nCurLevel = nCfg;

  /* Log clock frequency */
  SWEVENT( CLOCK_EVENT_FREQ,
           HAL_clk_GetTestClockId(pClockResource->pClock->HALHandle),
           pNewConfig[nCfg].nFreqHz );

  return pNewConfig[nCfg].nFreqHz;
}


static void Clock_NPADefineNode
(
  ClockResourceType *pResource
)
{
  boolean             bEnabled;
  npa_resource_state  nInitialRequest = 0;

  Clock_IsClockEnabled((ClockIdType)pResource->pClock, &bEnabled);

  // Map support bsp index to whole BSP index
  pResource->NPANode.Resource.max =
        pResource->pClock->pDomain->pBSPConfig[pResource->nMaxLevel].nFreqHz / 1000;

  if ( bEnabled )
  {
  nInitialRequest =
        pResource->pClock->pDomain->pBSPConfig[pResource->nCurLevel].nFreqHz / 1000;
  }

  npa_define_node(&pResource->NPANode.Node, &nInitialRequest, NULL);
}


/*===========================================================================

  FUNCTION      Clock_InitNPA

  DESCRIPTION   This function is used setup NPA node to all the clock
                resource

  PARAMETERS    None.

  DEPENDENCIES  None.

  RETURN VALUE  None

  SIDE EFFECTS  None.

===========================================================================*/
DALResult Clock_InitNPA
(
  void
)
{
  int                nCXRailID;
  npa_resource_state nInitialRequest;
  ClockResourceType *pResource;
  ClockDrvCtxt      *pDrvCtxt;

  pDrvCtxt = Clock_GetDrvCtxt();

  /*-----------------------------------------------------------------------*/
  /* Init the NPA CXO resource/node                                        */
  /*-----------------------------------------------------------------------*/
  nInitialRequest = 1;
  npa_define_node(&Clock_Resources.CXONPANode.Node, &nInitialRequest, NULL);

  /*-----------------------------------------------------------------------*/
  /* Init the NPA DCVS enable resource/node                                */
  /*-----------------------------------------------------------------------*/
  nInitialRequest = (pDrvCtxt->bDCVSEnabled) ? 1 : 0;
  npa_define_node(&Clock_Resources.DCVSEnaNPANode.Node, &nInitialRequest, NULL);

  /*-----------------------------------------------------------------------*/
  /* Init the NPA CPU resource/node                                        */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.CPUClockResource;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the NPA System NOC resource/node                                 */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.SNOCClockResource;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the NPA Peripheral Config NOC resource/node                      */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.PCNOCClockResource;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the NPA BIMC resource/node                                       */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.BIMCClockResource;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the NPA QPIC resource/node                                       */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.QPICClockResource;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the IPA resource/node                                       */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.IPAClockResource;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the CE resource/node                                            */
  /*-----------------------------------------------------------------------*/
  pResource = &Clock_Resources.CEClockResource.ClkCE;
  Clock_NPADefineNode( pResource );

  /*-----------------------------------------------------------------------*/
  /* Init the NPA QDSS resource/node                                       */
  /*-----------------------------------------------------------------------*/
  nInitialRequest = 0;
  npa_define_node(&Clock_Resources.QDSSClockResource.NPANode.Node, &nInitialRequest, NULL);

  /*-----------------------------------------------------------------------*/
  /* Set call back function when CX rail change, so QDSS clock can track   */
  /* with CX voltage                                                       */
  /*-----------------------------------------------------------------------*/
  nCXRailID = rail_id("vddcx");
  railway_set_callback(nCXRailID, RAILWAY_PRECHANGE_CB,  Clock_QDSS_PreChangedCB,  NULL);
  railway_set_callback(nCXRailID, RAILWAY_POSTCHANGE_CB, Clock_QDSS_PostChangedCB, NULL);

  /*-----------------------------------------------------------------------*/
  /* Good to go.                                                           */
  /*-----------------------------------------------------------------------*/

  return DAL_SUCCESS;

} /* END Clock_InitNPA */


/*===========================================================================

  FUNCTION      Clock_NPANodeCXOFunc

  DESCRIPTION   This function is used for enable/disable CXO.
                Currently, sleep code will handle CXO enable/disable

  PARAMETERS    pResource [in] - CXO Resource
                nState [in]    - Request state.

  DEPENDENCIES  None.

  RETURN VALUE  New CXO state

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeCXOFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{

  /* Sleep code will update client CXO vote */
  sleep_update_xo_stats(pResource->clients, hClient);

  /* Sleep code will handle CXO enable/disable */
  return nState;
}


/*===========================================================================

  FUNCTION      Clock_RestoreClockSpeed

  DESCRIPTION   This function is used for setting clock speed and inform
                NPA about the new clock speed change.

  PARAMETERS    pResource    [in] - Clock Resource
                nNewSpeedKHz [in] - New clock speed that will switch to

  DEPENDENCIES  None.

  RETURN VALUE  None

  SIDE EFFECTS  None.

===========================================================================*/
static void Clock_RestoreClockSpeed( ClockResourceType *pResource, uint32 nNewSpeed )
{
  nNewSpeed = Clock_SetClockSpeed( pResource, nNewSpeed );

  /* Inform NPA new clock speed has been updated */
  npa_assign_resource_state( pResource->NPANode.Resource.handle, nNewSpeed / 1000 );
}


/*===========================================================================

  FUNCTION      Clock_EnableDCVS

  DESCRIPTION   This function is used for restore bus clocks to previous
                requested state when DCVS is enabled, or set bus clocks to max
                if DCVS is disable

  PARAMETERS    pClockResource [in] - Periph NOC Clock Resource
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static void Clock_EnableDCVS( boolean bEnable )
{
  ClockResourceType *pResource;
  uint32            nNewClk;

  if ( bEnable )  /* If DCVS is enable, set bus to previous requested state */
  {
    /************************************************************************
     * Switch Peripheral Config NOC clock to request speed during DCVS disable
     ***********************************************************************/
    pResource = &Clock_Resources.PCNOCClockResource;

    if ( pResource->NPANode.Resource.handle->request_state != 0 )
    {
      Clock_RestoreClockSpeed ( pResource,
                          pResource->NPANode.Resource.handle->request_state * 1000);
    }

    /************************************************************************
     * Switch System NOC clock to request speed during DCVS disable
     ***********************************************************************/
    pResource = &Clock_Resources.SNOCClockResource;

    if ( pResource->NPANode.Resource.handle->request_state != 0 )
    {
      Clock_RestoreClockSpeed ( pResource,
                         pResource->NPANode.Resource.handle->request_state * 1000);
    }

    /************************************************************************
     * Switch BIMC clock to request speed during DCVS disable
     ***********************************************************************/
    pResource = &Clock_Resources.BIMCClockResource;

    if ( pResource->NPANode.Resource.handle->request_state != 0 )
    {
      nNewClk = Clock_BIMCSetFrequency( pResource,
                                        pResource->NPANode.Resource.handle->request_state,
          FALSE );

      /* Inform NPA new clock speed has been updated */
      npa_assign_resource_state(pResource->NPANode.Resource.handle, nNewClk);
    }
  }
  else            /* DCVS is disable, set default bus to Max */
  {
    /* Switch System NOC clock to Max */
    pResource = &Clock_Resources.SNOCClockResource;
    Clock_RestoreClockSpeed( pResource,
                         pResource->pClock->pDomain->pBSPConfig[pResource->nMaxLevel].nFreqHz);

    /* Switch Peripheral Config NOC clock to Max */
    pResource = &Clock_Resources.PCNOCClockResource;
    Clock_RestoreClockSpeed( pResource,
                         pResource->pClock->pDomain->pBSPConfig[pResource->nMaxLevel].nFreqHz);
    /* Switch BIMC clock to Max */
    pResource = &Clock_Resources.BIMCClockResource;
    nNewClk = Clock_BIMCSetFrequency(
                      pResource,
                      pResource->pClock->pDomain->pBSPConfig[pResource->nMaxLevel].nFreqHz / 1000,
          FALSE );

    /* Inform NPA new clock speed has been updated */
    npa_assign_resource_state(pResource->NPANode.Resource.handle, nNewClk);
  }
}


/*===========================================================================

  FUNCTION      Clock_NPANodeDCVSEnaFunc

  DESCRIPTION   This function is used for enable or disable bus scaling.
                Disable - Bus clocks will be run at max
                Enable - Bus clocks will be set at the previous state request

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeDCVSEnaFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockDrvCtxt      *pDrvCtxt;

  pDrvCtxt = Clock_GetDrvCtxt();

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  /* Change DCVS status */
  if ( nState != pDrvCtxt->bDCVSEnabled )
  {
    pDrvCtxt->bDCVSEnabled = nState;
    Clock_EnableDCVS( nState );
  }
  return nState;

}


/*===========================================================================

  FUNCTION      Clock_NPANodeCPUFunc

  DESCRIPTION   Function for switching CPU clock where it does not depending on
                DCVS enabled or disabled

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeCPUFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockResourceType   *pClockRsc;
  pClockRsc = pResource->node->data;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  nState = Clock_SetClockSpeed( pClockRsc, nState * 1000);
  return nState / 1000;
}

/*===========================================================================

  FUNCTION      Clock_NPANodeGenericFunc

  DESCRIPTION   Generic function for switching to one of these clock speeds
                (SNOC/CNOC) depending on the node data

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeGenericFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockResourceType *pClockRsc;
  ClockDrvCtxt      *pDrvCtxt;
  pClockRsc = pResource->node->data;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  /* Do not scale clock if DCVS is disable. Return current speed */
  pDrvCtxt = Clock_GetDrvCtxt();
  if ( !pDrvCtxt->bDCVSEnabled )
  {
    return pClockRsc->pClock->pDomain->pBSPConfig[pClockRsc->nCurLevel].nFreqHz / 1000;
  }

  nState = Clock_SetClockSpeed( pClockRsc, nState * 1000);
  return nState / 1000;
}


/*===========================================================================

  FUNCTION      Clock_NPANodeBIMCFunc

  DESCRIPTION   This NPA call-back function is using for scaling BIMC clock.

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeBIMCFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockResourceType *pClockRsc;
  ClockDrvCtxt      *pDrvCtxt;
  boolean           bNoWait;


  pClockRsc = pResource->node->data;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  /* Do not scale clock if DCVS is disable. Return current speed */
  pDrvCtxt = Clock_GetDrvCtxt();
  if ( !pDrvCtxt->bDCVSEnabled )
  {
    return pClockRsc->pClock->pDomain->pBSPConfig[pClockRsc->nCurLevel].nFreqHz / 1000;
  }

  bNoWait = (hClient->resource_data != 0);
  return Clock_BIMCSetFrequency( pClockRsc, nState, bNoWait );
}


/*===========================================================================

  FUNCTION      Clock_NPANodeQPICFunc

  DESCRIPTION   This NPA call-back function is using for scaling QPIC clocks.

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeQPICFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockDrvCtxt      *pDrvCtxt;
  ClockResourceType *pClockRsc;
  boolean           bEnabled;

  pClockRsc = pResource->node->data;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  /* Do not scale clock if DCVS is disable. Return current speed */
  pDrvCtxt = Clock_GetDrvCtxt();
  if ( !pDrvCtxt->bDCVSEnabled )
  {
    return pClockRsc->pClock->pDomain->pBSPConfig[pClockRsc->nCurLevel].nFreqHz / 1000;
  }

  /* Do not set QPIC clocks for flashless build */
  if ( !Clock_Resources.bQPICEnable )
  {
    return 0;
  }

  Clock_IsClockEnabled((ClockIdType)pClockRsc->pClock, &bEnabled);

  if ( nState == 0 )
  {
    if ( bEnabled )
    {
      Clock_DisableClock( (ClockIdType)Clock_Resources.QPICClockResource.pClock );
      Clock_DisableClock( (ClockIdType)Clock_Resources.pQPICSysClk );
      Clock_DisableClock( (ClockIdType)Clock_Resources.pQPICAHBClk );
    }
    return 0;
  }
  else
  {
    if ( !bEnabled )
    {
      Clock_EnableClock( (ClockIdType)Clock_Resources.QPICClockResource.pClock );
      Clock_EnableClock( (ClockIdType)Clock_Resources.pQPICSysClk );
      Clock_EnableClock( (ClockIdType)Clock_Resources.pQPICAHBClk );
    }
    return Clock_SetClockSpeed( pClockRsc, nState * 1000) / 1000;
  }
}



/*===========================================================================

  FUNCTION      Clock_NPANodeIPAFunc

  DESCRIPTION   This NPA call-back function is using for scaling IPA clocks.

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeIPAFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockResourceType *pClockRsc;
  boolean           bEnabled;
  Clock_NPAResourcesType  *pNPAResources;

  pNPAResources = Clock_GetNPAResources();

  pClockRsc = pResource->node->data;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  Clock_IsClockEnabled((ClockIdType)pClockRsc->pClock, &bEnabled);
  if ( nState == 0 )
  {
    if ( bEnabled )
    {
      Clock_DisableClock( (ClockIdType)Clock_Resources.IPAClockResource.pClock );
      Clock_DisableClock( (ClockIdType)Clock_Resources.pIPAAHBClk );
      Clock_DisableClock( (ClockIdType)Clock_Resources.pIPASysAxiClk );
      Clock_DisableClock( (ClockIdType)Clock_Resources.pIPASleepClk );

      /* Release XO & BIMC vote */
      npa_complete_request(pNPAResources->XOHandle);
      npa_complete_request(pNPAResources->BIMCHandle);
    }
    return 0;
  }
  else
  {
    if ( !bEnabled )
    {
      /* Vote for XO and BIMC before turning IPA clocks ON */
      npa_issue_required_request(pNPAResources->XOHandle, 1);
      npa_issue_required_request(pNPAResources->BIMCHandle, 1);

      Clock_EnableClock( (ClockIdType)Clock_Resources.IPAClockResource.pClock );
      Clock_EnableClock( (ClockIdType)Clock_Resources.pIPAAHBClk );
      Clock_EnableClock( (ClockIdType)Clock_Resources.pIPASysAxiClk );
      Clock_EnableClock( (ClockIdType)Clock_Resources.pIPASleepClk );
    }
    return Clock_SetClockSpeed( pClockRsc, nState * 1000) / 1000;
  }
}



/*===========================================================================

  FUNCTION      Clock_NPANodeCryptoFunc

  DESCRIPTION   Generic fucntion for switch CE (crypto engine) clock.  If the
                requested speed is zero, turn the clock off.

  PARAMETERS    pResource [in] - Clock Resource
                hClient [in]   - NPA client handle
                nState [in]    - Request frequency.

  DEPENDENCIES  None.

  RETURN VALUE  New clock speed

  SIDE EFFECTS  None.

===========================================================================*/
static npa_resource_state Clock_NPANodeCryptoFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  boolean             bClockEnabled;
  ClockResourceType   *pClockResource;
  ClockCEResourceType *pClockCE;

  pClockResource = pResource->node->data;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    return nState;
  }

  Clock_IsClockEnabled((ClockIdType)pClockResource->pClock, &bClockEnabled );
  pClockCE = &Clock_Resources.CEClockResource;

  /* Turn off Peripheral bus if there is no request */
  if ( (nState == 0) && (bClockEnabled == TRUE) )
  {
    Clock_SetClockSpeed( pClockResource, nState * 1000);
    Clock_DisableClock( (ClockIdType)pClockResource->pClock );
    Clock_DisableClock( (ClockIdType)pClockCE->pCEAXIClk );
    Clock_DisableClock( (ClockIdType)pClockCE->pCEAHBClk );
    return 0;
  }
  /* Else enable bus back if it has been disabled */
  else if ( (nState != 0) && (bClockEnabled == FALSE) )
  {
    Clock_EnableClock( (ClockIdType)pClockResource->pClock );
    Clock_EnableClock( (ClockIdType)pClockCE->pCEAXIClk );
    Clock_EnableClock( (ClockIdType)pClockCE->pCEAHBClk );
  }

  nState = Clock_SetClockSpeed( pClockResource, nState * 1000) / 1000;

  return nState;

}



/*===========================================================================

  FUNCTION      Clock_QDSS_PreChangedCB

  DESCRIPTION   This callback function is invoked before CX voltage changed.
                Use this function for reducing QDSS clock speed before CX
                voltage drop.

  PARAMETERS    settings [in] - Current CX rail setting
                cookie   [in] - Not used

  DEPENDENCIES  None.

  RETURN VALUE  None

  SIDE EFFECTS  None.

===========================================================================*/
static void Clock_QDSS_PreChangedCB(const railway_settings *settings, void *cookie)
{
  ClockQDSSResourceType *pQDSSResource = &Clock_Resources.QDSSClockResource;

  Clock_Resources.eCXmicroVolts = settings->microvolts;

  /* Only allow VDDCX level tracking in "DEBUG" mode */
  if( pQDSSResource->nQDSSCurrLevel == CLOCK_QDSS_LEVEL_DEBUG)
  {
    /* Switch to low speed, if CX is in SVS, and current speed is not low */
    if ( (Clock_Resources.eCXmicroVolts < NOMINAL_VOLTAGE) &&
         (pQDSSResource->nQDSSCurrSpeed != CLOCK_QDSS_SPEED_LOW) )
    {
      Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_LOW);
    }
  }
}


/*===========================================================================

  FUNCTION      Clock_QDSS_PostChangedCB

  DESCRIPTION   This callback function is invoked after CX voltage changed.
                Use this function for increasing QDSS clock speed after CX
                voltage increased.

  PARAMETERS    settings [in] - Current CX rail setting
                cookie   [in] - Not used
  DEPENDENCIES  None.

  RETURN VALUE  None

  SIDE EFFECTS  None.

===========================================================================*/
static void Clock_QDSS_PostChangedCB(const railway_settings *settings, void *cookie)
{
  ClockQDSSResourceType *pQDSSResource = &Clock_Resources.QDSSClockResource;

  Clock_Resources.eCXmicroVolts = settings->microvolts;

  /* Only allow VDDCX level tracking in "DEBUG" mode */
  if( pQDSSResource->nQDSSCurrLevel == CLOCK_QDSS_LEVEL_DEBUG)
  {
    /* Switch to nominal speed, if CX is in SVS, and current speed is not nominal */
    if ( (Clock_Resources.eCXmicroVolts >= NOMINAL_VOLTAGE) &&
              (pQDSSResource->nQDSSCurrSpeed != CLOCK_QDSS_SPEED_NORMAL) )
    {
      Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_NORMAL);
    }
  }
}


/*===========================================================================

  FUNCTION      Clock_ToggleQDSSClocks

  DESCRIPTION   This QDSS function is used for toggle the QDSS clocks ON/OFF

  PARAMETERS    pQDSSResource - QDSS Resource
                bQDSSOn       - Turn QDSS ON/OFF
  DEPENDENCIES  None.

  RETURN VALUE  None

  SIDE EFFECTS  None.

===========================================================================*/
static void Clock_ToggleQDSSClocks
(
  ClockQDSSResourceType *pQDSSResource,
  boolean               bQDSSOn
)
{
  /* Do nothing if QDSS clocks are already at requested state */
  if ( pQDSSResource->bQDSSEnabled == bQDSSOn )
  {
    return;
  }

  pQDSSResource->bQDSSEnabled = bQDSSOn;

  /* Turn QDSS clocks ON */
  if ( bQDSSOn )
  {
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSCfgAHBClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSDapAHBClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSEtrUSBClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSRBCPRClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSTraceClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSSTMClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSSTMAXIClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSDapClk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv2Clk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv3Clk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv4Clk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv8Clk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv16Clk);
    Clock_EnableClock( (ClockIdType)pQDSSResource->pQDSSRBCPRMXClk);
  }
  /* Turn QDSS clocks OFF */
  else
  {
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSCfgAHBClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSDapAHBClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSEtrUSBClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSRBCPRClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSTraceClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSSTMClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSSTMAXIClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSDapClk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv2Clk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv3Clk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv4Clk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv8Clk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSTSCTRDiv16Clk);
    Clock_DisableClock( (ClockIdType)pQDSSResource->pQDSSRBCPRMXClk);
  }
}


/*===========================================================================

  FUNCTION      Clock_SetQDSSClocks

  DESCRIPTION   This QDSS function is used for setting the QDSS clock frequencies.
                Due to debug or HS debug mode, this API will handle setting clock
                voltage manually.

  PARAMETERS    nCurrentLevel - Current QDSS level
                nNewLevel - New QDSS level

  DEPENDENCIES  None.

  RETURN VALUE  None

  SIDE EFFECTS  None.

===========================================================================*/
void Clock_SetQDSSClocks
(
  ClockQDSSResourceType *pQDSSResource,
  ClockQDSSSpeedType eSpeed
)
{
  ClockDrvCtxt *pDrvCtxt;
  pDrvCtxt = Clock_GetDrvCtxt();

  /*
   * Manual set QDSS voltage based on QDSS level
   * LEVEL_DEBUG - QDSS based on CX voltage
   * LEVEL_HSDEBUG - Voltage NOMINAL
   */
  if ( pQDSSResource->nQDSSCurrLevel == CLOCK_QDSS_LEVEL_HSDEBUG )
  {
    Clock_VoltageRequest( pDrvCtxt, &pQDSSResource->nQDSSVoltageLevel, CLOCK_VREG_LEVEL_NOMINAL, FALSE);
  }
  else
  {
    Clock_VoltageRequest( pDrvCtxt, &pQDSSResource->nQDSSVoltageLevel, CLOCK_VREG_LEVEL_LOW, FALSE);
  }

  /* Set QDSS Trace Speed */
  Clock_SetClockConfig( pQDSSResource->pQDSSTraceClk->pDomain,
                        &pQDSSResource->pQDSSTraceClk->pDomain->pBSPConfig[eSpeed] );

  /* Set QDSS AT Speed */
  Clock_SetClockConfig( pQDSSResource->pQDSSATClk->pDomain,
                        &pQDSSResource->pQDSSATClk->pDomain->pBSPConfig[eSpeed] );

  /* Set QDSS TSCTR Speed */
  Clock_SetClockConfig( pQDSSResource->pQDSSTSCTRDiv2Clk->pDomain,
                        &pQDSSResource->pQDSSTSCTRDiv2Clk->pDomain->pBSPConfig[eSpeed] );

  /* Set QDSS STM Speed */
  Clock_SetClockConfig( pQDSSResource->pQDSSSTMClk->pDomain,
                        &pQDSSResource->pQDSSSTMClk->pDomain->pBSPConfig[eSpeed] );

  QDSSSTMSetTimestampFreq( pQDSSResource->pQDSSTSCTRDiv2Clk->pDomain->pBSPConfig[eSpeed].nFreqHz );

  pQDSSResource->nQDSSCurrSpeed = eSpeed;
}


/*===========================================================================

  FUNCTION      Clock_ChangeQDSSLevel

  DESCRIPTION   This function is used for change QDSS clock to new Level

  PARAMETERS    eCurLevel - (0=Off, 1=Debug, 2=High Speed)
                eNewLevel - (0=Off, 1=Debug, 2=High Speed)

  DEPENDENCIES  None.

  RETURN VALUE  New Level.

  SIDE EFFECTS  None.

===========================================================================*/
ClockQDSSLevelType Clock_ChangeQDSSLevel
(
  ClockQDSSResourceType *pQDSSResource,
  ClockQDSSLevelType    eCurLevel,
  ClockQDSSLevelType    eNewLevel
)
{
  boolean bQDSSOn;

  /* Do nothing if it is already at the same level */
  if ( eCurLevel == eNewLevel )
    return eNewLevel;

  if ( eNewLevel == CLOCK_QDSS_LEVEL_OFF )
  {
    bQDSSOn = FALSE;
  }
  else
  {
    bQDSSOn = TRUE;
  }

  pQDSSResource->nQDSSCurrLevel = eNewLevel;

  /* Because V1 is using TRACECLKIN as the source to AT_CLK, it must be enabled
   * before clock switch and disabled after clock switch.  This is why Toggle
   * is now mixed into the cases */
  switch (eNewLevel)
  {
    case CLOCK_QDSS_LEVEL_OFF:
      Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_XO);
      Clock_ToggleQDSSClocks (pQDSSResource, bQDSSOn);
      break;

    case CLOCK_QDSS_LEVEL_DEBUG:
      Clock_ToggleQDSSClocks (pQDSSResource, bQDSSOn);

      /* Set the QDSS clocks to match the VDDCX mode */
      if( Clock_Resources.eCXmicroVolts >= NOMINAL_VOLTAGE )
      {
        Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_NORMAL);
      }
      else
      {
        Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_LOW);
      }
      break;

    case CLOCK_QDSS_LEVEL_HSDEBUG:
      Clock_ToggleQDSSClocks (pQDSSResource, bQDSSOn);
      Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_NORMAL);
      break;

    case CLOCK_QDSS_LEVEL_LOW:
      Clock_ToggleQDSSClocks (pQDSSResource, bQDSSOn);
      Clock_SetQDSSClocks(pQDSSResource, CLOCK_QDSS_SPEED_LOW);
      break;

    default:
      break;
  }

  return eNewLevel;
}


/*===========================================================================

  FUNCTION      Clock_NPANodeQDSSFunc

  DESCRIPTION   This NPA node is for QDSS

  PARAMETERS    nState -(0=Off, 1=Debug, 2=High Speed)

  DEPENDENCIES  None.

  RETURN VALUE  The new active state for the resource.

  SIDE EFFECTS  None.

===========================================================================*/
npa_resource_state Clock_NPANodeQDSSFunc
(
  struct npa_resource *pResource,
  npa_client_handle    hClient,
  npa_resource_state   nState
)
{
  ClockQDSSResourceType *pQDSSResource = &Clock_Resources.QDSSClockResource;

  if ( hClient->type == NPA_CLIENT_INITIALIZE )
  {
    pQDSSResource->bTraceAccess = qdss_fuse_trace_access();
    return nState;
  }

  if ( pQDSSResource->bTraceAccess == TRUE )
  {
    /* Change QDSS clock to new level */
    pQDSSResource->nQDSSCurrLevel =
        Clock_ChangeQDSSLevel (pQDSSResource, pQDSSResource->nQDSSCurrLevel, (ClockQDSSLevelType)nState);
  }

  return nState;
}


/*===========================================================================

  FUNCTION      Clock_NPAResourceQuery

  DESCRIPTION   This function is called to get a list of supported clock frequencies.

  PARAMETERS    *pResource [in]  -- Pointer to the resource in question
                nId        [in]  -- ID of the query.
                *pResult   [out] -- Pointer to the data to be filled by this function.

  DEPENDENCIES  None.

  RETURN VALUE  npa_query_status
                      - NPA_QUERY_SUCCESS, if query supported.
                              - NPA_QUERY_UNSUPPORTED_QUERY_ID, if query not supported.

  SIDE EFFECTS  None.

===========================================================================*/
static npa_query_status Clock_NPAResourceQuery
(
  npa_resource   *pResource,
  unsigned int   nId,
  npa_query_type *pResult
)
{
  npa_query_status nStatus = NPA_QUERY_UNSUPPORTED_QUERY_ID;
  ClockResourceType   *pClockResource;
  ClockPlanType       *pClockPlan;
  ClockMuxConfigType  *pNewConfig;
  uint32              index, nCfg;

  pClockResource = pResource->node->data;
  pNewConfig = pClockResource->pClock->pDomain->pBSPConfig;

  /*-----------------------------------------------------------------------*/
  /* Get offset for any performance level requests.                        */
  /*-----------------------------------------------------------------------*/

  switch ( nId )
  {
  case CLOCK_NPA_QUERY_NUM_PERF_LEVELS:
    pResult->type = NPA_QUERY_TYPE_VALUE;

    // Loop to all BSP to find all supported BSP for this HW version
    nCfg = 0;
    for ( index = pClockResource->nMinLevel; index <= pClockResource->nMaxLevel; index++ )
    {
      if ( Clock_IsBSPSupported(&pNewConfig[index]) )
      {
        nCfg++;
      }
    }
    pResult->data.value = nCfg;
    nStatus = NPA_QUERY_SUCCESS;
    break;

  case CLOCK_NPA_QUERY_MIN_FREQ_KHZ:
    pResult->type = NPA_QUERY_TYPE_VALUE;
    pResult->data.value = pClockResource->pClock->pDomain->pBSPConfig[pClockResource->nMinLevel].nFreqHz / 1000;
    nStatus = NPA_QUERY_SUCCESS;

  case CLOCK_NPA_QUERY_ALL_FREQ_KHZ:
    pResult->type = NPA_QUERY_TYPE_REFERENCE;

    if ( pResult->data.reference == NULL )
    {
      nStatus = NPA_QUERY_UNKNOWN_RESOURCE;
    }
    else
    {
      pClockPlan = pResult->data.reference;

      // Loop to all BSP to find all supported BSP for this HW version
      nCfg = 0;
      for ( index = pClockResource->nMinLevel; index <= pClockResource->nMaxLevel; index++ )
      {
        if ( Clock_IsBSPSupported(&pNewConfig[index]) )
        {
          pClockPlan[nCfg].nFreqKHz = pNewConfig[index].nFreqHz / 1000; /* In KHz */
          pClockPlan[nCfg].eVRegLevel = pNewConfig[index].eVRegLevel;
          nCfg++;
        }
      }
      nStatus = NPA_QUERY_SUCCESS;
    }
    break;

  case CLOCK_NPA_QUERY_SETTLING_TIME:
    pResult->type = NPA_QUERY_TYPE_VALUE;
    pResult->data.value = 0;

    if ( (pClockResource == &Clock_Resources.BIMCClockResource) &&
         (Clock_Resources.BIMCResource.eBIMCState != BIMC_ON) &&
         (Clock_Resources.BIMCResource.eBIMCState != BIMC_COLLAPSED) )
    {
      pResult->data.value = BIMC_WAIT;
    }
    nStatus = NPA_QUERY_SUCCESS;
    break;
  }

  return nStatus;
}

