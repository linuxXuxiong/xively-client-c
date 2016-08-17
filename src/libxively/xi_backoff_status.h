/* Copyright (c) 2003-2015, LogMeIn, Inc. All rights reserved.
 * This is part of Xively C library. */

#ifndef XI_BACKOFF_STATUS_H
#define XI_BACKOFF_STATUS_H

#include <stdint.h>

#include "xi_static_vector.h"
#include "xi_heap.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    XI_BACKOFF_CLASS_NONE = 0,
    XI_BACKOFF_CLASS_RECOVERABLE,
    XI_BACKOFF_CLASS_TERMINAL
} xi_backoff_class_t;

typedef xi_static_vector_index_type_t xi_backoff_lut_index_t;

typedef struct xi_backoff_status_s
{
    xi_heap_element_t* next_update;
    xi_static_vector_t* backoff_lut;
    xi_static_vector_t* decay_lut;
    xi_backoff_class_t backoff_class;
    xi_backoff_lut_index_t backoff_lut_i;
} xi_backoff_status_t;

#ifdef __cplusplus
}
#endif

#endif /* XI_BACKOFF_STATISTICS_H */