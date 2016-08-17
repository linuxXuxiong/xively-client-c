/* Copyright (c) 2003-2015, LogMeIn, Inc. All rights reserved.
 * This is part of Xively C library. */

#ifndef __XI_LAYERS_IDS_H__
#define __XI_LAYERS_IDS_H__

#ifdef __cplusplus
extern "C" {
#endif

enum xi_layer_stack_order_e
{
    XI_LAYER_TYPE_IO = 0
#ifndef XI_DEBUG_NO_TLS
    ,
    XI_LAYER_TYPE_TLS
#endif
    ,
    XI_LAYER_TYPE_MQTT_CODEC,
    XI_LAYER_TYPE_MQTT_LOGIC,
    XI_LAYER_TYPE_CONTROL_TOPIC
};

#ifdef __cplusplus
}
#endif

#endif /* __XI_LAYERS_IDS_H__ */