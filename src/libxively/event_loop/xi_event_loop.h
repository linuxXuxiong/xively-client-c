/* Copyright (c) 2003-2016, LogMeIn, Inc. All rights reserved.
 * This is part of Xively C library. */

#ifndef __XI_EVENT_LOOP_H__
#define __XI_EVENT_LOOP_H__

#include "xi_event_dispatcher_api.h"

#ifdef __cplusplus
extern "C" {
#endif

void xi_event_loop_with_evtds( uint32_t num_iterations,
                               xi_evtd_instance_t** event_dispatchers,
                               uint8_t num_evtds );

#ifdef __cplusplus
}
#endif

#endif /* __XI_EVENT_LOOP_H__ */