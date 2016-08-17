/* Copyright (c) 2003-2015, LogMeIn, Inc. All rights reserved.
 * This is part of Xively C library. */

#ifndef __XI_EVENT_HANDLE_QUEUE_H__
#define __XI_EVENT_HANDLE_QUEUE_H__

#include "xi_event_handle.h"

typedef struct xi_event_handle_queue_s
{
    struct xi_event_handle_queue_s* __next;
    xi_event_handle_t handle;
} xi_event_handle_queue_t;

#endif /* __XI_EVENT_HANDLE_QUEUE_H__ */