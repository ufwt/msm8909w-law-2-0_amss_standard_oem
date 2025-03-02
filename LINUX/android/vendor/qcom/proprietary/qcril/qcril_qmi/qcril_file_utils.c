/******************************************************************************

  @file    qcril_file_utils.c
  @brief   Provides interface to communicate with files

  DESCRIPTION

  ---------------------------------------------------------------------------

  Copyright (c) 2015 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

  ---------------------------------------------------------------------------
******************************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#include "qcril_log.h"

/*===========================================================================

  FUNCTION qcril_file_open_file

===========================================================================*/
/*!
    @brief
    open file.

    @return
    file descriptor or NULL
*/
/*=========================================================================*/
FILE *qcril_file_open_file
(
    char *file_name,
    char *mode
)
{
    FILE *file_desc = NULL;

    if (file_name && mode)
    {
        file_desc = fopen(file_name, mode);

        if (!file_desc)
        {
            QCRIL_LOG_DEBUG("file %s open for mode %s failed with error %d",
                             file_name, mode, errno);
        }
    }

    return file_desc;
}

/*===========================================================================

  FUNCTION qcril_file_open_file_for_read

===========================================================================*/
/*!
    @brief
    open file for reading.

    @return
    file identifier or NULL
*/
/*=========================================================================*/
void *qcril_file_open_file_for_read
(
    char *file_name
)
{
    return qcril_file_open_file(file_name, "r");
}

/*===========================================================================

  FUNCTION qcril_file_open_file_for_write

===========================================================================*/
/*!
    @brief
    open file for writing.

    @return
    file identifier or NULL
*/
/*=========================================================================*/
void *qcril_file_open_file_for_write
(
    char *file_name
)
{
    return qcril_file_open_file(file_name, "rw");
}

/*===========================================================================

  FUNCTION qcril_file_create_file

===========================================================================*/
/*!
    @brief
    Create File.

    @return
    file identifier or NULL
*/
/*=========================================================================*/
void *qcril_file_create_file
(
    char *file_name
)
{
    return qcril_file_open_file(file_name, "w+");
}

/*===========================================================================

  FUNCTION qcril_file_write_bytes

===========================================================================*/
/*!
    @brief
    write bytes to file.

    @return
    number of bytes written.
*/
/*=========================================================================*/
int qcril_file_write_data
(
    void *file_desc,
    void *content,
    int   length,
    int   whence,
    int   offset,
    int   size_of_data_type
)
{
    int bytes_written = -1;

    if (file_desc && content && length)
    {
        if (!fseek(file_desc, offset, whence))
        {
            bytes_written = fwrite(content,
                                  size_of_data_type,
                                  length,
                                  file_desc);

            if (bytes_written != length)
            {
                QCRIL_LOG_DEBUG("Hit error in reading");
            }
        }
        else
        {
            QCRIL_LOG_DEBUG("file seek failed with error %d",
                             errno);
        }
    }

    return bytes_written;
}
/*===========================================================================

  FUNCTION qcril_file_read_bytes

===========================================================================*/
/*!
    @brief
    read lentgth number of bytes from file.

    @return
    number of bytes read.
*/
/*=========================================================================*/
int qcril_file_read_data
(
    void *file_desc,
    void *destination,
    int   length,
    int   whence,
    int   offset,
    int   size_of_data_type
)
{
    int bytes_read = -1;

    if (file_desc && destination && length)
    {
        if (!fseek(file_desc, offset, whence))
        {
            bytes_read = fread(destination,
                               size_of_data_type,
                               length,
                               file_desc);

            if (bytes_read != length)
            {
                if (!feof(file_desc))
                {
                    QCRIL_LOG_DEBUG("Hit error in reading");
                    bytes_read = -1;
                }
                else
                {
                    QCRIL_LOG_DEBUG("Hit end of file in reading");
                }

                QCRIL_LOG_DEBUG("read %d instead of %d",
                                 bytes_read, length);
            }
        }
        else
        {
            QCRIL_LOG_DEBUG("file seek failed with error %d",
                             errno);
        }
    }

    return bytes_read;
}

/*===========================================================================

  FUNCTION qcril_file_read_next_bytes

===========================================================================*/
/*!
    @brief
    reads the next byte from file

    @return
    file descriptor.
*/
/*=========================================================================*/
int qcril_file_read_next_bytes
(
    void *file_desc,
    void *destination,
    int   length
)
{
    int bytes_read = 0;

    if (file_desc && destination && length)
    {
        bytes_read = qcril_file_read_data(file_desc, destination,
                                          length, SEEK_CUR, 0, 1);
    }

    return bytes_read;
}

/*===========================================================================

  FUNCTION qcril_file_read_bytes_from_front

===========================================================================*/
/*!
    @brief
    reads bytes from the beginning of the file.

    @return
    number of bytes read.
*/
/*=========================================================================*/
int qcril_file_read_bytes_from_front
(
    void *file_desc,
    void *destination,
    int   length
)
{
    int bytes_read = 0;

    if (file_desc && destination && length)
    {
        bytes_read = qcril_file_read_data(file_desc, destination,
                                          length, SEEK_SET, 0, 1);
    }

    return bytes_read;
}

/*===========================================================================

  FUNCTION qcril_file_write_bytes_from_front

===========================================================================*/
/*!
    @brief
    writes bytes from the beginning of the file.

    @return
    file descriptor.
*/
/*=========================================================================*/
int qcril_file_write_bytes_from_front
(
    void          *file_desc,
    unsigned char *content,
    int            length
)
{
    int bytes_written = 0;

    if (file_desc && content && length)
    {
        bytes_written = qcril_file_write_data(file_desc, content,
                                             length, SEEK_SET, 0, 1);
    }

    return bytes_written;
}

/*===========================================================================

  FUNCTION qcril_file_read_bytes_till_end

===========================================================================*/
/*!
    @brief
    reads bytes from the end - length of the file.

    @return
    file descriptor.
*/
/*=========================================================================*/
int qcril_file_read_bytes_till_end
(
    void *file_desc,
    void *destination,
    int   offset,
    int   length
)
{
    int bytes_read = 0;

    if (file_desc && destination && length)
    {
        bytes_read = qcril_file_read_data(file_desc, destination,
                                          length, SEEK_END,
                                          (-1 * offset), 1);
    }

    return bytes_read;
}

/*===========================================================================

  FUNCTION qcril_file_get_size

===========================================================================*/
/*!
    @brief
    get file size.

    @return
    size on success
    -1 on error
*/
/*=========================================================================*/
int qcril_file_get_size
(
    void *file_desc
)
{
    int  size = -1;
    int  tmp  = -1;
    FILE *fd  = file_desc;

    if (fd)
    {
        tmp = ftell(fd);
        fseek(fd, 0, SEEK_END);
        size = ftell(fd);
        fseek(fd, tmp, SEEK_SET);
    }

    return size;
}

/*===========================================================================

  FUNCTION qcril_file_close_file

===========================================================================*/
/*!
    @brief
    close file.

    @return
    0 on success
    -1 on error
*/
/*=========================================================================*/
int qcril_file_close_file
(
    void *file_desc
)
{
    int error;
    error = fclose(file_desc);

    if (error)
    {
        /* log errno */
        QCRIL_LOG_DEBUG(" file close failed with error %d", errno);

        error = -1;
    }

    return error;
}

/*===========================================================================

  FUNCTION qcril_file_write_a_string_to_file

===========================================================================*/
/*!
    @brief
    Utility to write a string given file name

    @return
    0 on success
    -1 on error
*/
/*=========================================================================*/
int qcril_file_write_a_string_to_file
(
    char *file_name,
    char *string
)
{
    int   ret = -1;
    void *file_fd = NULL;

    do {

        if (!file_name || !string)
        {
            break;
        }

        file_fd = qcril_file_create_file(file_name);

        if (!file_fd)
        {
            break;
        }

        qcril_file_write_bytes_from_front(file_fd, (unsigned char *)string,
                                          strlen(string) + 1);

        qcril_file_close_file(file_fd);
    } while (0);

    return ret;
}

/*===========================================================================

  FUNCTION qcril_file_read_string_from_file

===========================================================================*/
/*!
    @brief
    Read upto the requested number of bytes. If the length of the string buffer
    to read into is less than the number of bytes read, the bytes read are
    null-terminated.

    @return
    0 on success
    -1 on error
*/
/*=========================================================================*/
int qcril_file_read_string_from_file
(
    char    *file_name,
    char    *string,
    uint32_t string_len,
    uint32_t bytes_to_read
)
{
    int   ret = -1;
    void *file_fd = NULL;

    do {

        if (!file_name || !string || !string_len)
        {
            break;
        }

        if (bytes_to_read > string_len) {
            QCRIL_LOG_DEBUG("Number of bytes to read cannot be greater"
                            " than the length of the string.");
            break;
        }

        file_fd = qcril_file_open_file_for_read(file_name);

        if (!file_fd)
        {
            break;
        }

        int bytes_read = qcril_file_read_bytes_from_front(file_fd, string,
                                                          bytes_to_read);
        qcril_file_close_file(file_fd);

        if (bytes_read < 0) {
            break;
        }

        // Null-terminate the string if the length of the string is greater
        // than the number of bytes read.
        if ((uint32_t) bytes_read < string_len) {
            *(string + bytes_read) = '\0';
        }

        ret = 0;
    } while (0);

    return ret;
}
