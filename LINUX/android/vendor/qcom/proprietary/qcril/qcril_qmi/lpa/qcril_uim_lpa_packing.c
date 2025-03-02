/******************************************************************************
#  @file    lpa_packing.c
#  @brief   Local profile assistant packing source file
#
#  ---------------------------------------------------------------------------
#
#  Copyright (c) 2016 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#  ---------------------------------------------------------------------------
#******************************************************************************/


#include <pb_decode.h>
#include <pb_encode.h>
#include "qcril_uim_lpa_packing.h"
#include "qcril_log.h"
#include "qcril_uim_lpa_msg_meta.h"
#include "qcril_qmi_npb_encode.h"
#include "qcril_qmi_npb_decode.h"

//===========================================================================
// qcril_uim_lpa_pack_msg_and_tag
//===========================================================================
size_t qcril_uim_lpa_pack_msg_and_tag(const void *msg,
                                                   bool has_token,
                                                   uint32_t token,
                                                   lpa_MessageType type,
                                                   lpa_MessageId message_id,
                                                   bool has_error,
                                                   lpa_Error error,
                                                   uint8_t *buf,
                                                   size_t buf_size)
{
    QCRIL_LOG_FUNC_ENTRY();
    if (NULL == buf)
    {
        QCRIL_LOG_ERROR("buf is NULL");
        return 0;
    }

    size_t packed_size = 0;
    if(qcril_uim_lpa_is_msg_valid(message_id, type))
    {
        QCRIL_LOG_INFO("Message is valid, encoding the message");

        lpa_MessageTag msg_tag;
        memset(&msg_tag, 0x00, sizeof(msg_tag));

        msg_tag.has_token = has_token;
        if(has_token)
        {
            msg_tag.token = token;
        }
        msg_tag.type = type;
        msg_tag.id = message_id;
        msg_tag.has_error = has_error;
        if(has_error)
        {
            msg_tag.error = error;
        }

        pb_ostream_t ostream;
        uint8_t *msg_pack_buf = NULL;
        const pb_field_t* fields = qcril_uim_lpa_get_msg_pb_fields(message_id, type);
        qcril_binary_data_type bin_data;
        if((msg == NULL) && (qcril_uim_lpa_get_msg_size(message_id, type) == 0))
        {
            QCRIL_LOG_INFO("Message payload is NULL, assign NULL to payload");
            msg_tag.payload.arg = NULL;
        }
        else if(fields != NULL)
        {
            QCRIL_LOG_INFO("Message payload exists, encode the payload");
            msg_pack_buf = qcril_malloc(buf_size);
            if (NULL == msg_pack_buf)
            {
                QCRIL_LOG_ERROR("malloc the buffer failed");
                return 0;
            }
            ostream = pb_ostream_from_buffer(msg_pack_buf, buf_size);
            if (qcril_qmi_encode_npb(&ostream, fields, msg))
            {
                bin_data.data = msg_pack_buf;
                bin_data.len = ostream.bytes_written;
                QCRIL_LOG_INFO("bin_data_len: %d", (int)bin_data.len);
                msg_tag.payload.arg = (void*)&bin_data;
            }
        }

        QCRIL_LOG_INFO("encoded the msg, encoding the tag");

        ostream = pb_ostream_from_buffer(buf, buf_size);
        if (qcril_qmi_encode_npb(&ostream, lpa_MessageTag_fields, &msg_tag))
        {
            packed_size = ostream.bytes_written;
            QCRIL_LOG_INFO("encoded the tag");
        }
        else
        {
            QCRIL_LOG_ERROR("pb_encode failed");
        }
        if(msg_pack_buf)
        {
            QCRIL_LOG_INFO("freeing buffer");
            qcril_free(msg_pack_buf);
        }
    }
    else
    {
        QCRIL_LOG_ERROR("Message id and type doesnt co-exist. Cannot encode the msg");
    }
    QCRIL_LOG_FUNC_RETURN_WITH_RET((int) packed_size);
    return packed_size;
} // qcril_uim_lpa_pack_msg_and_tag

//===========================================================================
// qcril_uim_lpa_unpack_msg_tag
//===========================================================================
lpa_MessageTag* qcril_uim_lpa_unpack_msg_tag(const uint8_t *buf, size_t buf_size)
{
    QCRIL_LOG_FUNC_ENTRY();

    lpa_MessageTag* msg_tag_ptr = NULL;

    if (NULL == buf)
    {
        QCRIL_LOG_ERROR("buf is NULL");
    }
    else
    {
        msg_tag_ptr = qcril_malloc(sizeof(*msg_tag_ptr));
        if (msg_tag_ptr)
        {
            pb_istream_t istream;
            istream = pb_istream_from_buffer((uint8_t *)buf, buf_size);
            if(!qcril_qmi_decode_npb(&istream, lpa_MessageTag_fields, msg_tag_ptr))
            {
                QCRIL_LOG_ERROR("pb_decode failed");
                qcril_free(msg_tag_ptr);
                return NULL;
            }
        }
        else
        {
            QCRIL_LOG_ERROR("malloc failed");
        }
    }

    QCRIL_LOG_FUNC_RETURN();
    return msg_tag_ptr;
} // qcril_uim_lpa_unpack_msg_tag

//===========================================================================
// qcril_uim_lpa_parse_packed_msg
//===========================================================================
void qcril_uim_lpa_parse_packed_msg(lpa_MessageType msg_type,
                                              lpa_MessageId msg_id,
                                              const pb_callback_t packed_msg, QCRIL_UNUSED(size_t msg_size),
                                              void** unpacked_msg, size_t*unpacked_msg_size_ptr,
                                              qcril_evt_e_type* event_ptr)
{
    QCRIL_LOG_FUNC_ENTRY();

    *unpacked_msg = NULL;
    *unpacked_msg_size_ptr = 0;
    *event_ptr = qcril_uim_lpa_get_msg_event(msg_id, msg_type);

    if (NULL == packed_msg.arg)
    {
        QCRIL_LOG_ERROR("packed_msg is NULL");
    }
    else
    {
        const pb_field_t* fields = qcril_uim_lpa_get_msg_pb_fields(msg_id, msg_type);
        if (fields && qcril_uim_lpa_get_msg_size(msg_id, msg_type))
        {
            *unpacked_msg = qcril_malloc(qcril_uim_lpa_get_msg_size(msg_id, msg_type));
            if (*unpacked_msg)
            {
                pb_istream_t istream;
                qcril_binary_data_type *bin_data_ptr = (qcril_binary_data_type*) packed_msg.arg;
                istream = pb_istream_from_buffer(bin_data_ptr->data, bin_data_ptr->len);
                if(qcril_qmi_decode_npb(&istream, fields, *unpacked_msg))
                {
                    *unpacked_msg_size_ptr = qcril_uim_lpa_get_msg_size(msg_id, msg_type);
                }
            }
        }
        else
        {
            QCRIL_LOG_INFO("no payload for mesage %s(%d)", qcril_uim_lpa_get_msg_log_str(msg_id, msg_type), msg_id);
        }
    }
    QCRIL_LOG_FUNC_RETURN();
} // qcril_uim_lpa_parse_packed_msg
