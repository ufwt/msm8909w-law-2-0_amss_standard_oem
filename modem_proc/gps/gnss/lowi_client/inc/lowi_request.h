#ifndef __LOWI_REQUEST_H__
#define __LOWI_REQUEST_H__

/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

        LOWI Request Interface Header file

GENERAL DESCRIPTION
  This file contains the structure definitions and function prototypes for
  LOWIRequest

  Copyright (c) 2012 Qualcomm Technologies Incorporated.
  Qualcomm Confidential and Proprietary. All Rights Reserved.
  Copyright (c) 2013 - 2014 Qualcomm Atheros, Inc.
  Qualcomm Atheros Confidential and Proprietary. All Rights Reserved. 

Export of this technology or software is regulated by the U.S. Government.
Diversion contrary to U.S. law prohibited.
=============================================================================*/
#if APSS
#include <inc/lowi_const.h>
#include <inc/lowi_mac_address.h>
#else
#include "lowi_const.h"
#include "lowi_mac_address.h"
#include "vector.h"
#endif

namespace qc_loc_fw
{
class LOWIUtils;
/**
 * Base class for all requests LOWI can handle
 */
class LOWIRequest
{
protected:
  static const char* const TAG;
private:
  /** Identity of request originator*/
  char* mRequestOriginator;
  uint32 mRequestId;
public:
  /** Type of Request*/
  enum eRequestType
  {
    DISCOVERY_SCAN,
    RANGING_SCAN,
    CAPABILITY,
    RESET_CACHE,
    ASYNC_DISCOVERY_SCAN_RESULTS,
#if !APSS
    WLAN_EVENTS_SUBSCRIPTION,
    WLAN_EVENTS_QUERY
#endif
  };

  /**
   * Constructor
   * @param uint32 Request Id generated by the client
   */
  LOWIRequest (uint32 requestId);
  /** Destructor*/
  virtual ~LOWIRequest () = 0;

  /** Copy Constructor */
  LOWIRequest( const LOWIRequest& rhs );
  /** Assignment operator */
  LOWIRequest& operator=( const LOWIRequest& rhs );

  /**
   * Returns the Request Originator
   * @return char* Request originator's id
   */
  const char* getRequestOriginator () const;

  /**
   * Sets the Request originator for the request.
   * Used internally by LOWI to identify the originator
   * of the request and send the responses back to the originator.
   *
   * Note: Clients of LOWI API do not need to set the originator as
   * there is no affect of doing so.
   */
  void setRequestOriginator (const char* const request_originator);

  /**
   * Returns the RequestId
   * @return RequestId generated by the user of the API
   */
  uint32 getRequestId () const;

  /**
   * Returns the request type
   * @return eRequestType type of request
   */
  virtual eRequestType getRequestType () const = 0;
};

///////////////////////////
// Capability Request
///////////////////////////

/**
 * Capability Request
 */
class LOWICapabilityRequest: public LOWIRequest
{
public:
  /**
   * Constructor
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   */
  LOWICapabilityRequest (uint32 requestId);
  /** Destructor*/
  virtual ~LOWICapabilityRequest ();

  /**
   * Returns the request type
   * @return eRequestType type of request
   */
  virtual eRequestType getRequestType () const;
};

///////////////////////////
// Cache Reset Request
///////////////////////////
/**
 * Cache Reset Request
 */
class LOWICacheResetRequest: public LOWIRequest
{
public:
  /**
   * Constructor
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   */
  LOWICacheResetRequest (uint32 requestId);
  /** Destructor*/
  virtual ~LOWICacheResetRequest ();

  /**
   * Returns the request type
   * @return eRequestType type of request
   */
  virtual eRequestType getRequestType () const;
};

///////////////////////////
// Discovery scan Request
///////////////////////////
// Forward declaration
class LOWIChannelInfo;

/**
 * Class to make a Discovery scan request
 */
class LOWIDiscoveryScanRequest: public LOWIRequest
{
public:
  /** Defines the available type of Discovery Scan*/
  enum eScanType
  {
    /**Passive Scan*/
    PASSIVE_SCAN,
    /**Active Scan*/
    ACTIVE_SCAN
  };

  /** Defines the available mode of Discovery Scan Request*/
  enum eRequestMode
  {
    /** Request to perform a Fresh scan. The request will trigger a Request
     * being sent to WifiDriver for fresh scan */
    FORCED_FRESH,
    /** Request to perform Fresh scan with throttling. If the last fresh
     * scan results are relatively fresh then this Request will be serviced
     * from Cache. Criteria to determine freshness is
     * current time < last scan time + threshold (defined in config file)
     */
    NORMAL,
    /** Request to return the result from Cache*/
    CACHE_ONLY,
    /** Request to provide the result from Cache but if results
     * are not found in cache then start the fresh scan*/
    CACHE_FALLBACK
  };

  /** Defines the bands for which the Discovery Scan Request can be made*/
  enum eBand
  {
    /** 2.4 Ghz only*/
    TWO_POINT_FOUR_GHZ,
    /** 5 Ghz only*/
    FIVE_GHZ,
    /** Both (2.5 & 5 Ghz)*/
    BAND_ALL
  };

  /**
   * Returns the scan type
   * @return Passive scan or Active scan
   */
  eScanType getScanType () const;
  /**
   * Returns the request mode
   * @return Mode of request
   */
  eRequestMode getRequestMode () const;
  /**
   * Returns Measurement age filter in seconds.
   * For Cache Request, at the time of generating the
   *  response for the request, all the measurements which
   *  are older than Current time - filter age,
   *  will be filtered out from the response.
   *  So '0' age filter could potentially
   *  return no measurements from the cache.
   *
   * For Fresh scan Request, at the time of generating the
   *  response for the request, all the measurements which
   *  are older than Request time to WLAN driver - filter age,
   *  will be filtered out from the response.
   * @return Measurement Age filter in seconds
   */
  uint32 getMeasAgeFilterSec () const;
  /**
   * Returns fallback tolerance in seconds.
   * Only valid when eRequestMode is CACHE_FALLBACK.
   * At the time of evaluating this request, all the
   * requested channels should have last measurement
   * timestamp equal to or greater than Current time -
   * Fallback tolerance. If not, then fallback to
   * trigger a fresh scan. Client can provide 0 if they
   * want to trigger a fresh scan as well.
   * @return Cache fallback tolerance
   */
  uint32 getFallbackToleranceSec () const;
  /**
   * Returns the band
   * @return RF band to scan.
   */
  eBand getBand () const;
  /**
   * Returns the dynamic array containing the ChannelInfo to be scanned.
   * Number of entries in the vector should not be more than
   * MAX_CHAN_INFO_SIZE as that's the max LOWI supports as of
   * now. Any ChannelInfo more than MAX_CHAN_INFO_SIZE will be
   * ignored.
   * @return Dynamic array containing channel specific information
   */
  vector <LOWIChannelInfo> & getChannels ();
  /**
   * Returns absolute timestamp on which the request will be dropped
   * if not processed already. Value should be -1 if the
   * timeoutTimestamp is not valid.
   * @return Request timeout timestamp
   */
  int64 getTimeoutTimestamp () const;
  /**
   * Returns cache request buffer preference.
   * This is set to true if the cache request has to be buffered until the
   * existing transaction is finished.
   * Will be ignored if there is no ongoing transaction.
   * Will be ignored for FRESH_ONLY requestMode
   * This can be used to get the latest results included in the cache request.
   */
  bool getBufferCacheRequest () const;

  /** Destructor*/
  virtual ~LOWIDiscoveryScanRequest ();

  /**
   * Returns the request type
   * @return eRequestType type of the Request
   */
  virtual eRequestType getRequestType () const;

  /**
   * Helper function to create a DiscoveryScanRequest for CACHE_ONLY Request
   * mode. This API could be used to perform CACHE_ONLY discovery scan on any
   * band.
   *
   * @param uint32 Request ID generated by the client to track the response.
   *                Response for this Request will contain the same request Id.
   * @param eBand Band in which the scan is to be performed
   * @param uint32 Measurement age filter in seconds.
   *               For Cache Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Current time - filter age,
   *               will be filtered out from the response.
   *               So '0' age filter could potentially
   *               return no measurements from the cache.
   * @param int64 Timestamp at which this request should be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   * @param bool The request will be cached and processed after the current
   *             fresh scan completes if this flag is on. Will be honoured only
   *             if there is an ongoing fresh scan at the time of receiving this
   *             request
   */
  static LOWIDiscoveryScanRequest* createCacheOnlyRequest (uint32 requestId,
      eBand band, uint32 meas_age_filter_sec,
      int64 timeoutTimestamp, bool bufferCacheRequest);

  /**
   * Helper function to create a DiscoveryScanRequest for CACHE_FALLBACK
   * Request mode. This API could be used to perform CACHE_ONLY discovery
   * scan on any band.
   *
   * @param uint32 Request ID generated by the client to track the response.
   *                Response for this Request will contain the same request Id.
   * @param eBand Band in which the scan is to be performed
   * @param eScanType Type of discovery scan Active / Passive. Only
   *                  applicable if the request fallsback to trigger a
   *                  fresh scan.
   * @param uint32 Measurement age filter in seconds.
   *               For Cache Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Current time - filter age,
   *               will be filtered out from the response.
   *               So '0' age filter could potentially
   *               return no measurements from the cache.
   *
   *               For Fresh scan Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Request time to WLAN driver - filter age,
   *               will be filtered out from the response.
   * @param uint32 Fallback tolerance in seconds.
   *               At the time of evaluating this request, all the
   *               requested channels should have last measurement
   *               timestamp equal to or greater than Current time -
   *               Fallback tolerance. If not, then fallback to
   *               trigger a fresh scan. Client can provide 0 if they
   *               want to trigger a fresh scan as well.
   * @param int64 Timestamp at which this request should be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   * @param bool The request will be cached and processed after the current
   *             fresh scan completes if this flag is on. Will be honoured only
   *             if there is an ongoing fresh scan at the time of receiving
   *             this request
   */
  static LOWIDiscoveryScanRequest* createCacheFallbackRequest (
      uint32 requestId,
      eBand band, eScanType type, uint32 meas_age_filter_sec,
      uint32 fallbackToleranceSec,
      int64 timeoutTimestamp, bool bufferCacheRequest);

  /**
   * Helper function to create a DiscoveryScanRequest for NORMAL / FORCED_FRESH
   * Request mode. This API could be used to perform a NORMAL / FORCED_FRESH
   * discovery scan on any band.
   *
   * @param uint32 Request ID generated by the client to track the response.
   *                Response for this Request will contain the same request Id.
   * @param eBand Band in which the scan is to be performed
   * @param eScanType Type of discovery scan Active / Passive.
   * @param uint32 Measurement age filter in seconds.
   *               For Fresh scan Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Request time to WLAN driver - filter age,
   *               will be filtered out from the response.
   * @param int64 Timestamp at which this request should be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   * @param eRequestMode Mode of request NORMAL / FORCED_FRESH
   */
  static LOWIDiscoveryScanRequest* createFreshScanRequest (uint32 requestId,
      eBand band, eScanType type, uint32 meas_age_filter_sec,
      int64 timeoutTimestamp, eRequestMode mode);

  /**
   * Helper function to create a DiscoveryScanRequest for CACHE_ONLY Request
   * mode. This API could be used to perform CACHE_ONLY discovery scan on
   * specific channels.
   *
   * @param uint32 Request ID generated by the client to track the response.
   *                Response for this Request will contain the same request Id.
   * @param vector <LOWIChannelInfo> Vector should contain the ChannelInfo
   *               of the Channels that need to be scanned.
   *               Maximum channels supported by LOWI right now are 16 and
   *               any thing more than that is ignored.
   * @param uint32 Measurement age filter in seconds.
   *               For Cache Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Current time - filter age,
   *               will be filtered out from the response.
   *               So '0' age filter could potentially
   *               return no measurements from the cache.
   * @param int64 Timestamp at which this request should be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   * @param bool The request will be cached and processed after the current
   *             fresh scan completes if this flag is on. Will be honoured only
   *             if there is an ongoing fresh scan at the time of receiving this
   *             request
   */
  static LOWIDiscoveryScanRequest* createCacheOnlyRequest (uint32 requestId,
      vector <LOWIChannelInfo>& chanInfo,
      uint32 meas_age_filter_sec, int64 timeoutTimestamp,
      bool bufferCacheRequest);

  /**
   * Helper function to create a DiscoveryScanRequest for CACHE_FALLBACK
   * Request mode. This API could be used to perform CACHE_ONLY discovery
   * scan on specific channels.
   *
   * @param uint32 Request ID generated by the client to track the response.
   *                Response for this Request will contain the same request Id.
   * @param vector <LOWIChannelInfo> Vector should contain the ChannelInfo
   *               of the Channels that need to be scanned.
   *               Maximum channels supported by LOWI right now are 16 and
   *               any thing more than that is ignored.
   * @param eScanType Type of discovery scan Active / Passive. Only
   *                  applicable if the request falls back to trigger a
   *                  fresh scan.
   * @param uint32 Measurement age filter in seconds.
   *               For Cache Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Current time - filter age,
   *               will be filtered out from the response.
   *               So '0' age filter could potentially
   *               return no measurements from the cache.
   *
   *               For Fresh scan Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Request time to WLAN driver - filter age,
   *               will be filtered out from the response.
   * @param uint32 Fallback tolerance in seconds.
   *               At the time of evaluating this request, all the
   *               requested channels should have last measurement
   *               timestamp equal to or greater than Current time -
   *               Fallback tolerance. If not, then fallback to
   *               trigger a fresh scan. Client can provide 0 if they
   *               want to trigger a fresh scan as well.
   * @param int64 Timestamp at which this request should be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   * @param bool The request will be cached and processed after the current
   *             fresh scan completes if this flag is on. Will be honoured only
   *             if there is an ongoing fresh scan at the time of receiving
   *             this request
   */
  static LOWIDiscoveryScanRequest* createCacheFallbackRequest (
      uint32 requestId,
      vector <LOWIChannelInfo>& chanInfo,
      eScanType type, uint32 meas_age_filter_sec,
      uint32 fallbackToleranceSec,
      int64 timeoutTimestamp, bool bufferCacheRequest);

  /**
   * Helper function to create a DiscoveryScanRequest for NORMAL / FORCED_FRESH
   * Request mode. This API could be used to perform a NORMAL / FORCED_FRESH
   * discovery scan on specific channels.
   *
   * @param uint32 Request ID generated by the client to track the response.
   *                Response for this Request will contain the same request Id.
   * @param vector <LOWIChannelInfo> Vector should contain the ChannelInfo
   *               of the Channels that need to be scanned.
   *               Maximum channels supported by LOWI right now are 16 and
   *               any thing more than that is ignored.
   * @param eScanType Type of discovery scan Active / Passive.
   * @param uint32 Measurement age filter in seconds.
   *               For Fresh scan Request, at the time of generating the
   *               response for the request, all the measurements which
   *               are older than Request time to WLAN driver - filter age,
   *               will be filtered out from the response.
   * @param int64 Timestamp at which this request should be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   * @param eRequestMode Mode of request NORMAL / FORCED_FRESH
   */
  static LOWIDiscoveryScanRequest* createFreshScanRequest (uint32 requestId,
      vector <LOWIChannelInfo>& chanInfo,
      eScanType type, uint32 meas_age_filter_sec,
      int64 timeoutTimestamp, eRequestMode mode);

private:
  /**
   * Constructor
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   */
  LOWIDiscoveryScanRequest (uint32 requestId);

  /** Passive scan or Active scan*/
  eScanType         scanType;
  /** Mode of request*/
  eRequestMode      requestMode;

  /**
   * Measurement age filter in seconds.
   * For Cache Request, at the time of generating the
   *  response for the request, all the measurements which
   *  are older than Current time - filter age,
   *  will be filtered out from the response.
   *  So '0' age filter could potentially
   *  return no measurements from the cache.
   *
   * For Fresh scan Request, at the time of generating the
   *  response for the request, all the measurements which
   *  are older than Request time to WLAN driver - filter age,
   *  will be filtered out from the response.
   */
  uint32             measAgeFilterSec;
  /**
   * Fallback tolerance in seconds.
   * Only valid when eRequestMode is CACHE_FALLBACK.
   * At the time of evaluating this request, all the
   * requested channels should have last measurement
   * timestamp equal to or greater than Current time -
   * Fallback tolerance. If not, then fallback to
   * trigger a fresh scan. Client can provide 0 if they
   * want to trigger a fresh scan as well.
   */
  uint32             fallbackToleranceSec;
  /** RF band to scan.*/
  eBand             band;
  /**
   * Dynamic array containing the ChannelInfo to be scanned.
   * Number of entries in the vector should not be more than
   * MAX_CHAN_INFO_SIZE as that's the max LOWI supports as of
   * now. Any ChannelInfo more than MAX_CHAN_INFO_SIZE will be
   * ignored.
   */
  vector <LOWIChannelInfo> chanInfo;
  /** Absolute timestamp on which the request will be dropped if not processed
   * value should be 0 if the timeoutTimestamp is not valid.
   */
  int64             timeoutTimestamp;
  /** Set this to true if the cache request has to be buffered until the
   * existing transaction is finished.
   * Will be ignored if there is no ongoing transaction.
   * Will be ignored for FRESH_ONLY requestMode
   * This can be used to get the latest results included in the cache request.
   */
  bool           bufferCacheRequest;
  friend class LOWIUtils;
};

/**
 * Defines the info for a Channel
 */
class LOWIChannelInfo
{
private:
  /** Frequency in Mhz*/
  uint32 frequency;
public:
  LOWIChannelInfo ();
  /**
   * Constructor
   * @param uint32 frequency of the channel
   */
  LOWIChannelInfo (uint32 freq);

  /**
   * Constructor
   * @param uint32 Channel number
   * @param LOWIDiscoveryScanRequest::eBand Band of the channel
   */
  LOWIChannelInfo (uint32 channel, LOWIDiscoveryScanRequest::eBand band);

  ~LOWIChannelInfo ();
  /**
   * Returns the band associated with the channel.
   * @return Band for the channel.
   */
  LOWIDiscoveryScanRequest::eBand getBand () const;
  /**
   * Returns the Frequency associated with the channel.
   * @return Frequency of the channel
   */
  uint32 getFrequency () const;
  /**
   * Returns the Channel number for the Channel Info.
   * Channel number corresponds to the Band
   *
   * @return Channel Number
   */
  uint32 getChannel () const;
};


///////////////////////////
// Ranging scan Request
///////////////////////////

/** Defines available type of Wifi Nodes*/
enum eNodeType
{
  NODE_TYPE_UNKNOWN = 0,
  ACCESS_POINT,
  PEER_DEVICE
};
/** Defines supported RTT types for Ranging scan request */
enum eRttType
{
  RTT1_RANGING = 0,    /* Ranging with no Multipath correction */
  RTT2_RANGING,        /* Ranging with Multipath correction */
  RTT3_RANGING,        /* Two-sided Ranging as defined in 802.11mc spec */
  BEST_EFFORT_RANGING  /* One of the above, which ever the peer supports */
};

/** Defines RTT report types for Ranging scan */
enum eRttReportType
{
  RTT_REPORT_1_FRAME_CFR = 0,  /* Responses sent on a per frame basis with CFR capture */
  RTT_REPORT_1_FRAME_NO_CFR,   /* Responses sent on a per frame basis without CFR captiure */
  RTT_REPORT_AGGREGATE         /* Single responses containing results for all requested APs and frames*/
};

/**
 * Defines the information for a Wifi Node
 */
struct LOWINodeInfo
{
  /** MacId of the Node*/
  LOWIMacAddress bssid;
  /** Frequency in Mhz, which the node is transmitting*/
  uint32 frequency;
  /** Either PEER_DEVICE or ACCESS_POINT*/
  eNodeType nodeType;
  /* Spoof MacId needed for peer device ranging.
   * Only valid if nodeType is PEER_DEVICE*/
  LOWIMacAddress spoofMacId;

  /** The Type Of RTT to be performed */
  eRttType rttType;
};

/**
 * Class to make a Ranging scan request.
 */
class LOWIRangingScanRequest: public LOWIRequest
{
private:
  /**
   * Dynamic array containing the wifi Node Info to be scanned.
   * Currently LOWI only supports 16 wifi nodes to be scanned
   * with Ranging scan. Any thing more than 16 will be ignored.
   */
  vector <LOWINodeInfo> nodeInfo;

  /** Absolute timestamp on which the request will be dropped if not processed
   * value should be 0 if the timeoutTimestamp is not valid.
   */
  int64             timeoutTimestamp;

  /** The Type Of RTT Report the FW should provide */
  eRttReportType rttReportType;

public:

  /**
   * Returns the Dynamic array containing the LOWINodeInfo
   * @return Dynamic array containing the LOWINodeInfo
   */
  vector <LOWINodeInfo> & getNodes ();

  /**
   * Returns the timestamp at which the request expires
   * @return timestamp at which the request expires
   */
  int64 getTimeoutTimestamp () const;

  /**
   * Sets the RTT report type for the request
   * @return void
   */
  void setReportType(eRttReportType report_type);

  /**
   * Returns the RTT Report Type for this Request
   * @return eRttReportType RTT Report type
   */
  eRttReportType getReportType() const;


  /**
   * Constructor
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   * @param vector<LOWINodeInfo> Dynamic array containing wifi nodes
   *                           that need to be scanned.
   * @param int64 Timestamp at which the request will be dropped if not
   *              processed already. Should be 0 if this is to be ignored.
   */
  LOWIRangingScanRequest (uint32 requestId, vector <LOWINodeInfo>& node_info,
      int64 timestamp);
  /** Destructor*/
  virtual ~LOWIRangingScanRequest ();

  /**
   * Returns the request type
   * @return eRequestType type of the Request
   */
  virtual eRequestType getRequestType () const;
};

/**
 * Class to make a Request for Async discovery scan results.
*/
class LOWIAsyncDiscoveryScanResultRequest : public LOWIRequest
{
private:
  /**
   * Number of seconds for which the request should be active.
   * Request will be dropped after this time.
   * requestExpirySec can not be more than
   * ASYNC_DISCOVERY_REQ_VALIDITY_PERIOD_SEC
   */
  uint32             requestExpirySec;

  /**
   * Internally calculated based on the time the request
   * was received and the requested expiry
   */
  int64              timeoutTimestamp;

#if !APSS
  boolean             mSubscribe;
  boolean             mAllResults;
#endif

public:
#if APSS
  /**
   * Constructor
   * A client registers this request to receive the discovery
   * scan results as and when they are available.
   * LOWI provides the async results to the client for as long
   * as the request is valid or for a max period
   * (ASYNC_DISCOVERY_REQ_VALIDITY_PERIOD_SEC), after which it
   * drops the request assuming that the client is no longer
   * interested in the scan results. There is no indication to
   * the client when this happens. If the client is interested
   * in listening for the async scan results, it should keep
   * refreshing it's registration by issung the same request
   * before the expiry of previous request.
   * Issuing the same request again even when it's not yet expired,
   * just refreshes the request and LOWI resets the expiry timer
   * for the request.
   * If the client is no longer interested in listening for the
   * async results, it can refresh this request with 0 timeout value.
   *
   * Client will not get the results / response to this request
   * if there was a discovery scan result available but was
   * triggered by a discovery scan request from the same client.
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   * @param uint32 Number of seconds for which the request should
   *               be active. requestExpirySec can not be more than
   *               ASYNC_DISCOVERY_REQ_VALIDITY_PERIOD_SEC
   */
  LOWIAsyncDiscoveryScanResultRequest (uint32 requestId,
      uint32 request_timer_sec);
#else
  /**
   * Constructor
   * A client registers this request to receive the discovery
   * scan results as and when they are available.
   * LOWI provides the async results to the client for as long
   * as the request is valid.
   * Request is valid if the client has not canceled it and the
   * request timeout has not expired. Client can set the request
   * timeout to 0 and the request will be treated valid as long
   * as not explicitly cancelled by the client.
   *
   * Client will not get the results / response to this request
   * if there was a discovery scan result available but was
   * triggered by a discovery scan request from the same client.
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   * @param uint32 Number of seconds for which the request should
   *               be active.
   * @param boolean True for subscription, false to cancel subscription
   * @param boolean True for all scan results, false to get only those
   *        scan results, not sent to APSS
   */
  LOWIAsyncDiscoveryScanResultRequest (uint32 requestId,
      uint32 request_timer_sec, boolean subscribe, boolean all_results);
#endif
  /**
   * Returns the expiry time of the Request.
   * @return uint32 Request expiry time
   */
  uint32 getRequestExpiryTime ();

  /**
   * Returns the request type
   * @return eRequestType type of the Request
   */
  virtual eRequestType getRequestType () const;

  /**
   * Returns the Timeout timestamp
   * @return int64 Timeout timestamp
   */
  int64 getTimeoutTimestamp () const;

  /**
   * Sets the timeout timestamp
   * Client does not have to call this API.
   * Calling this API from client side does not affect
   * the internal usage.
   * This is internally calculated based on the
   * request timer in the constructor.
   * @param int64 Timeout timestamp
   */
  void setTimeoutTimestamp (int64 timeout);

#if !APSS
  /**
   * Returns the state (Subscribe / Cancel subscribe request)
   * @return true for subscription, false for cancel subscription
   */
  bool isSubscriptionRequest () const;

  /**
   * Checks if only scans are to be sent, not sent to APSS.
   * @return bool true to only send scans not sent to APSS,
   *  false to send all scans
   */
  bool isSendScansNotSentToApss () const;
#endif
};

#if !APSS
/**
 * Valid interfaces for which the client wants to get events notifications
 */
enum eLowiWlanInterface
{
  LOWI_DEV_STA = 0, /**<  WLAN device is in Station mode  */
  LOWI_DEV_P2P_CLI = 1, /**<  WLAN device is in P2P Client mode  */
  LOWI_WLAN_DEV_ANY = 2 /**<  WLAN device is in any mode */
};

/**
 * Request to query WLAN state.
*/
class LOWIWLANStateQueryRequest : public LOWIRequest
{
private:
  eLowiWlanInterface interface;
public:
  /**
   * A client uses this request to query the wlan state
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   * @param eLowiWlanInterface interface for which the client wants
   *                     to get the events (wlan0 / p2p0)
   */
  LOWIWLANStateQueryRequest (uint32 requestId, eLowiWlanInterface iface);

  /**
   * Returns the request type
   * @return eRequestType type of the Request
   */
  virtual eRequestType getRequestType () const;

  /**
   * Returns the interface
   * @return eLowiWlanInterface Interface
   */
  virtual eLowiWlanInterface getInterface () const;

};

/**
 * Class to make a subscription Request for WLAN Events.
*/
class LOWIWLANEventsSubscriptionRequest : public LOWIWLANStateQueryRequest
{
private:
  boolean mSubscribe;
public:

  /**
   * A client registers this request to receive the wlan events
   * LOWI provides the WLAN events to the clients for as long
   * as the subscriptions is not canceled.
   * @param uint32 Request id generated by the client
   *        This will be echoed back in the corresponding response.
   * @param eLowiWlanInterface interface for which the client wants
   *                     to get the events (wlan0 / p2p0)
   * @param boolean True for subscription, false to cancel subscription
   */
  LOWIWLANEventsSubscriptionRequest (uint32 requestId,
      eLowiWlanInterface iface, boolean subscribe);

  /**
   * Returns the request type
   * @return eRequestType type of the Request
   */
  virtual eRequestType getRequestType () const;

  /**
   * Returns the state (Subscribe / Cancel subscribe request)
   * @return true for subscription, false for cancel subscription
   */
  bool isSubscriptionRequest () const;

};

#endif

} // namespace qc_loc_fw

#endif //#ifndef __LOWI_REQUEST_H__
