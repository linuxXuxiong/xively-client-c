/* Copyright (c) 2003-2015, LogMeIn, Inc. All rights reserved.
 * This is part of Xively C library. */

#ifndef __XI_FS_API_H__
#define __XI_FS_API_H__

#include <stdlib.h>
#include <stdint.h>

#include "xi_err.h"

typedef intptr_t xi_fs_resource_handle_t;

#define XI_FS_INVALID_RESOURCE_HANDLE -1
#define xi_fs_init_resource_handle() XI_FS_INVALID_RESOURCE_HANDLE

/**
 * @enum xi_fs_resource_type_t
 * @brief describes types of resources that are availible through fs API the
 * types were created in order to differenciate types based on their security
 * class
 */
typedef enum
{
    XI_FS_CERTIFICATE = 0,
    XI_FS_CREDENTIALS,
    XI_FS_CONFIG_DATA
} xi_fs_resource_type_t;

/**
 * @enum xi_fs_open_flags_t
 */
typedef enum
{
    XI_FS_OPEN_READ   = 1 << 0,
    XI_FS_OPEN_WRITE  = 1 << 1,
    XI_FS_OPEN_APPEND = 1 << 2,
} xi_fs_open_flags_t;

/*
 * @name xi_fs_stat_s
 * @brief information returned via stat call
 */
typedef struct xi_fs_stat_s
{
    size_t resource_size;
} xi_fs_stat_t;

#define xi_fs_init_stat()                                                                \
    {                                                                                    \
        0                                                                                \
    }

/* The size of the buffer to be used for reads */
extern const size_t xi_fs_buffer_size;

/**
 * @name xi_fs_stat_resource_t
 * @brief returns stats of a resource described via resource type and name
 *
 * @return xi_state_t XI_STATE_OK in case of a success and other in case of an
 * error
 */
typedef xi_state_t( xi_fs_stat_resource_t )( const void* context,
                                             const xi_fs_resource_type_t resource_type,
                                             const char* const resource_name,
                                             xi_fs_stat_t* resource_stat );

/**
 * @name xi_fs_open_resource_t
 * @brief opens the resource described via resource type and name with a given
 * flags, returns a handle to that resource
 *
 * @return xi_state_t XI_STATE_OK in case of a success and other values in case
 * of an error
 */
typedef xi_state_t( xi_fs_open_resource_t )( const void* context,
                                             const xi_fs_resource_type_t resource_type,
                                             const char* const resource_name,
                                             const xi_fs_open_flags_t open_flags,
                                             xi_fs_resource_handle_t* resource_handle );


/**
 * @name xi_fs_read_resource_t
 * @brief reads data using a given offset from the beginnig of the resource from
 * the previously opened resource described via resource handle, returns a
 * buffer
 * of data and a size of that buffer
 *
 *
 * @brief it is up to the implementation of this API to free the buffer, if
 * needed, either on the next call to read or when close is called on the file
 * descriptor. This allows the use of ReadOnly File Systems on devices that
 * cannot facilitate a full file system implementation.
 *
 * @note if the storage data is compiled in than this function should return
 * pure pointer to the memory where the data is located, this is perfect
 * solution for ReadOnly File Systems
 *
 * @return xi_state_t XI_STATE_OK in case of a success and other values in case
 * of an error
 */
typedef xi_state_t( xi_fs_read_resource_t )(
    const void* context,
    const xi_fs_resource_handle_t resource_handle,
    const size_t offset,
    const uint8_t** buffer,
    size_t* const buffer_size );

/**
 * @name xi_fs_write_resource_t
 * @brief writes the data from the provided buffer to the previously opened
 * resource described by resource_handle. The offset is the offset into the
 * destination file. bytes_written is a return parameter describing the number
 * of bytes that were committed to the file in this write operation.
 *
 * @return xi_state_t XI_STATE_OK in case of a success and other values in case
 * of an error
 */
typedef xi_state_t( xi_fs_write_resource_t )(
    const void* context,
    const xi_fs_resource_handle_t resource_handle,
    const uint8_t* const buffer,
    const size_t buffer_size,
    const size_t offset,
    size_t* const bytes_written );

/**
 * @name xi_fs_close_resource_t
 * @brief closes the previously opened resource represented via resource handle
 *
 * @note close function should also release all previously allocated memory on
 * behalf of the given resource
 *
 * @return xi_state_t XI_STATE_OK in case of a success and other values in case
 * of an error
 */
typedef xi_state_t( xi_fs_close_resource_t )(
    const void* context, const xi_fs_resource_handle_t resource_handle );

/**
 * @name xi_fs_remove_resource_t
 * @brief removes the resource described via resource type and name
 *
 * @return xi_state_t XI_STATE_OK in case of a success and other values in case
 * of an error
 */
typedef xi_state_t( xi_fs_remove_resource_t )( const void* context,
                                               const xi_fs_resource_type_t resource_type,
                                               const char* const resource_name );

/**
 * @name xi_fs_functions_t
 * @brief a function pointer table that serves as a runtime link between the
 * Xively Client and the implementing Resource Library API
 */
typedef struct xi_fs_functions_s
{
    size_t fs_functions_size;
    xi_fs_stat_resource_t* stat_resource;
    xi_fs_open_resource_t* open_resource;
    xi_fs_read_resource_t* read_resource;
    xi_fs_write_resource_t* write_resource;
    xi_fs_close_resource_t* close_resource;
    xi_fs_remove_resource_t* remove_resource;
} xi_fs_functions_t;

#endif /* __XI_FS_API_H__ */