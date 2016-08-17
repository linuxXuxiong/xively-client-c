/* Copyright (c) 2003-2015, LogMeIn, Inc. All rights reserved.
 * This is part of Xively C library. */

#include "xi_globals.h"

xi_globals_t xi_globals = {
    .network_timeout            = 1500,
    .globals_ref_count          = 0,
    .evtd_instance              = NULL,
    .default_context            = NULL,
    .default_context_handle     = XI_INVALID_CONTEXT_HANDLE,
    .context_handles_vector     = NULL,
    .timed_tasks_container      = NULL,
    .main_threadpool            = NULL,
    .str_account_id             = NULL,
    .str_device_unique_id       = NULL,
    .backoff_status             = { 0, 0, 0, XI_BACKOFF_CLASS_NONE, 0 }
};