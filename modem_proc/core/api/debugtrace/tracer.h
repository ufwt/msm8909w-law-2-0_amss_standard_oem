#ifndef TRACER_H
#define TRACER_H
/**
  @file tracer.h
  @brief QUALCOMM Debug Subsystem (QDSS) Tracer utility library
*/
/*=============================================================================
NOTE: The @brief description above does not appear in the PDF.

      The Tracer.h_Debug_Tool_API_mainpage_mainpage.dox file contains the
      group/module descriptions that are displayed in the output PDF generated
      using Doxygen and LaTeX. To edit or update any of the group/module text
      in the PDF, edit the _mainpage.dox file or contact Tech Pubs.
=============================================================================*/
/*=============================================================================
  Copyright (c) 2011-2013 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
/*=============================================================================
  $Header: //components/rel/core.mpss/3.5.c12.3/api/debugtrace/tracer.h#1 $

  when       who     what, where, why
  --------   ---    -----------------------------------------------------------
  02/25/12   llg    (Tech Pubs) Edited/added Doxygen comments and markup.

=============================================================================*/

/*---------------------------------------------------------------------------
 * Include Files
 * ------------------------------------------------------------------------*/

#include "comdef.h"
#include "tracer_entity.h"

/*---------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * ------------------------------------------------------------------------*/
/** @ingroup tracer_h_data_types
  Return values for a Tracer function call.
*/
typedef enum
{
   TRACER_RETURN_SUCCESS = 0, /**< Function completed successfully. */
   TRACER_RETURN_ERROR = 1    /**< Incomplete, failure, or an error occurred. */

} tracer_return_enum_t;

/** @addtogroup tracer_h_constants
@{ */
/** @name Tracer options

  Bitmask of the Tracer options available that maps to STM
  options. There are combined options for both data and flag STP packets.
*/
/** @{ */
/** No options. */
#define TRACER_OPT_NONE          0x00
/** Include timestamp. */
#define TRACER_OPT_TIMESTAMP     0x01
/** Guarantee delivery. */
#define TRACER_OPT_GUARANTEE     0x02
/** @} */ /* end_name_group Tracer options */
/** @} */ /* end_addtogroup tracer_h_constants */

/*---------------------------------------------------------------------------
 * Type Declarations
 * ------------------------------------------------------------------------*/
/** @addtogroup tracer_h_data_types
@{ */
/**
  Tracer options (values: TRACER_OPT_...); see Section
  @xref{dox:tracerConstants}.
*/
typedef uint8 tracer_options_t;

/**
  Data structure for managing registered clients.
*/
typedef struct tracer_node_s tracer_client_t;

/**
  Handle for registered clients.
*/
// need be volatile or not? ....
typedef tracer_client_t * volatile tracer_client_handle_t;

/**
  @name TDS fields for a registered client

  The sizes correspond to the TDS header fields.
*/
/** @{ */
typedef uint8 tracer_cpu_id_t;      /**< CPU ID as used by TDS. */
typedef uint8 tracer_process_id_t;  /**< Process ID as used by TDS. */
typedef uint16 tracer_thread_id_t;  /**< Thread ID as used by TDS. */
/** @} */ /* end_name_group TDS fields */

/**
  Tracer software events IDs (autogenerated enumeration).
*/
typedef enum tracer_event_id_enum tracer_event_id_t;
/** @} */ /* end_addtogroup tracer_h_data_types */

/*---------------------------------------------------------------------------
 * Function Declarations and Documentation
 * ------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/
/** @ingroup tracer_h_set_owner
  Changes the owner associated with the client handle.

  The thread ID associated with the client handle is changed to the value
  specified. The client must ensure that the value does not conflict
  with another thread ID on the processor. This is relevant only if the
  client is registered as a TDS entity (typically the default).

  @datatypes
  tracer_thread_id_t

  @param[in] hClient   Client's handle obtained when registered.
  @param[in] owner_id  Identifier to associate with the client handle.

  @return
  None.

  @dependencies
  None.
 */
void tracer_set_owner(tracer_client_handle_t hClient,
                      tracer_thread_id_t owner_id);

/*-------------------------------------------------------------------------*/
/* Entity IDs are defined in tracer_entity.h */
/** @ingroup tracer_h_register
  Registers with Tracer and obtains a handle to use the QDSS Tracer.

  @vertspace{-4}
  @datatypes
  #tracer_ost_entity_id_enum_t

  @param[in,out] phClient Location where the allocated client handle
                          is placed. This is valid on TRACER_RETURN_SUCCESS;
                          NULL on TRACER_RETURN_ERROR.
  @param[in]     eid      Entity ID for the encapsulation mode.
                          - For Tracer Data Stream mode, use TDS as the entity.
                            Also, the default (TRACER_ENTITY_DEFAULT) can be
                            used.
                          - For Independent mode, use the client's uniquely
                            defined ID.
                          - For Raw mode, use TRACER_ENTITY_NONE. @tablebulletend
  @param[in]     pid     Protocol ID of the entity (eid). This is not
                         applicable if eid is zero.

  @detdesc
  The caller registers as a trace source (Tracer SW client) to obtain
  a client handle for use when submitting trace data.
  @par
  The client specifies the data encapsulation mode employed via the
  entity ID (eid). This mode is used for all trace output. Based on the
  mode, the following occurs:
  - When the entity is TDS, a TDS stream is generated. A TDS stream is a
    TDS packet with OST base framing. This is the default.
  - When the entity is the client itself, an independent data
    stream is generated. This stream consists of the client's trace
    data with OST base framing. The TDS protocol is bypassed. This is
    a special case for OEMs or legacy clients, when required.
  - When the entity is zero, a raw data stream is generated, which is the
    client's trace data, and is placed directly into the STP trace output
    stream. Both the TDS and OST base framing protocols are bypassed. This is
    a special case for OEMs and, possibly, legacy clients.
  @par
  Memory to manage the client is allocated and initialized. This includes
  obtaining an STM port handle and, for TDS, obtaining the source identity
  information: CPU ID, process ID, and thread ID. Both the specified
  eid and pid parameters are conveyed in the OST header.
  @par
  The client is added to the list of registered clients.
  @par
  If Tracer has not been initialized, it is initialized first.

  @return
  TRACER_RETURN_SUCCESS -- Client was successfully registered.
  @par
  TRACER_RETURN_ERROR   -- Client has not been registered. Possible causes are
                           a failure to obtain an STM port or to assign a
                           client record.

  @dependencies
  None.

  @sa
  tracer_unregister
*/
tracer_return_enum_t tracer_register(tracer_client_handle_t *phClient,
                                     tracer_ost_entity_id_enum_t eid,
                                     tracer_ost_protocol_id_t pid);

/*-------------------------------------------------------------------------*/
/** @ingroup tracer_h_unregister
  Removes a registered client from using the QDSS Tracer library.

  All memory allocations and obtained resources for this client are cleared
  and freed. Once freed, resources may be reused by another client.

  @param[in]  phClient  Pointer to the client's handle.
  @param[out] phClient  Client's handle set to NULL.

  @return
  None.

  @dependencies
  None.

  @sa
  tracer_register
*/
void tracer_unregister(tracer_client_handle_t *phClient);

/*-------------------------------------------------------------------------*/
/** @ingroup tracer_h_data
  Sends trace data to the QDSS trace output stream.

  @datatypes
  #tracer_options_t

  @param[in] hClient    Client's handle obtained when registered.
  @param[in] options    Options for delivering trace data (timestamped and/or
                        guaranteed). See Section @xref{dox:tracerConstants}
                        for details.
  @param[in] uData_len  Number of bytes to be placed in the trace output
                        stream. When zero, it treats pData as pointing to a
                        printf type format string.
  @param[in] pData      When uData_len is nonzero, pData is the starting
                        (logical) address of the uData_len bytes of trace
                        data to be placed in the trace output stream. \n
                        @vertspace{3}
                        When uData_len is zero, pData is a pointer to a
                        printf type format string, and the variable argument
                        must match the count of format specifiers in the
                        format string.
  @param[in] ...        Parameters for when pData is a format string. The
                        number of variable arguments must match the count of
                        the format specifiers in the format string.

  @detdesc
  The client requests sending data into the trace output stream with
  the specified options. The trace data is encapsulated based on
  the mode selected when the client registered with Tracer. Ultimately,
  the data is sent to STM, whereby STP-formatted packets are output at the
  QDSS trace sinks.
  @par
  The trace data is typically a text string or a binary data block.
  @par
  Data may be silently discarded if Tracer is not initialized, Tracer
  output is disabled, or output for the client's associated entity is
  disabled.

  @return
  TRACER_RETURN_SUCCESS -- Function completed successfully.
  @par
  TRACER_RETURN_ERROR   -- Failed to complete. Likely invalid client handle
                           provided or data length too long.

  @dependencies
  None.
*/

tracer_return_enum_t tracer_data(tracer_client_handle_t hClient,
                                 tracer_options_t options,
                                 uint32 uData_len,
                                 const char *pData,
                                 ...);

/*-------------------------------------------------------------------------*/
/** @ingroup tracer_h_event
  Issues a software event indication from registered clients into the
  QDSS trace output stream.

  @param[in] hClient   Client's handle obtained from registration.
  @param[in] event_id  Value identifying the software event.

  @detdesc
  The client requests sending a software event indication containing an
  event ID into the trace output stream. All software events are
  timestamped and not guaranteed.
  @par
  Event ID values are dynamically assigned during the build. An event
  table is generated that maps the value with a descriptor of the event.
  @par
  The request may be silently discarded if Tracer is not initialized,
  Tracer output is disabled, output of the client's associated entity
  is disabled, or the output of the event ID is disabled.

  @return
  TRACER_RETURN_SUCCESS -- Function completed successfully. \n
  TRACER_RETURN_ERROR   -- Invalid handle.

  @dependencies
  None.
*/
tracer_return_enum_t tracer_event(tracer_client_handle_t hClient,
                                  tracer_event_id_t event_id);

/*-------------------------------------------------------------------------*/
/** @ingroup tracer_h_event_simple
  Issues a simple software event indication into the QDSS trace
  output stream.

  @param[in] event_id  Value identifying the software event.

  @detdesc
  The client requests sending a software event indication containing an
  event ID into the trace output stream. All software events are
  timestamped and not guaranteed.
  @par
  A simple software event request does not require a client handle. As such,
  the trace may occur on any one of several trace output channels that
  were allocated by Tracer.
  @par
  Event ID values are dynamically assigned during the build. An event
  table is generated that maps the value with a descriptor of the event.
  @par
  The request may be silently discarded if Tracer is not initialized,
  the Tracer port manager is not initialized, Tracer output is disabled,
  or the output of the event ID is disabled.

  @return
  None.

  @dependencies
  None.
*/
void tracer_event_simple(tracer_event_id_t event_id);

/*-------------------------------------------------------------------------*/
/** @ingroup tracer_h_event_simple_vargs
  Sends a simple software event with data to the QDSS trace output
  stream.

  @param[in] event_id  Value identifying the software event.
  @param[in] num_args  Number of parameters to placed in the trace
                       output stream.
  @param[in] ...       Parameters values of type uint32. There must be
                       num_args number of variable arguments.

  @detdesc
  The client requests sending a software event with associated parameters
  into the trace output stream. The event ID and parameters are encapsulated
  into an independent data stream from the SWEVT entity. All parameters
  must be a uint32 data type.
  @par
  This request does not require a client handle. As such, the trace
  may occur on any one of several trace output channels that were
  allocated by Tracer.
  @par
  Event ID values are dynamically assigned during the build. An event
  table is generated that maps the value with a descriptor of the event.
  @par
  The request may be silently discarded if Tracer is not initialized,
  the Tracer port manager is not initialized, Tracer output is disabled,
  or output of the event ID is disabled.

  @return
  None.

  @dependencies
  None.
*/
void tracer_event_simple_vargs(tracer_event_id_t event_id,
                               uint32 num_args,
                               ...);

#endif /* #ifndef TRACER_H */

