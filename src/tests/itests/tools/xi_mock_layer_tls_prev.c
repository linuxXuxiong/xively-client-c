// Copyright (c) 2003-2015, LogMeIn, Inc. All rights reserved.

#include "xi_mock_layer_tls_prev.h"
#include "xi_layer_macros.h"
#include "xi_itest_helpers.h"


#ifdef __cplusplus
extern "C" {
#endif

xi_state_t xi_mock_layer_tls_prev_push(
      void* context
    , void* data
    , xi_state_t in_out_state )
{
    XI_LAYER_FUNCTION_PRINT_FUNCTION_DIGEST();

    XI_UNUSED( data );

    check_expected( in_out_state );
    const xi_mock_layer_tls_prev_control_t mock_control_directive =
        mock_type( xi_mock_layer_tls_prev_control_t );

    switch ( mock_control_directive )
    {
        case CONTROL_TLS_PREV_CONTINUE:
        break;
        case CONTROL_TLS_PREV_PUSH__RETURN_MESSAGE:
        {
            const char* string_to_send_back = mock_type( const char* );

            if ( string_to_send_back != 0 )
            {
                xi_data_desc_t* message_to_send_back = xi_make_desc_from_string_copy( string_to_send_back );

                XI_PROCESS_PULL_ON_THIS_LAYER( context, message_to_send_back, XI_STATE_OK );
            }
        }
        break;
        case CONTROL_TLS_PREV_CLOSE:
            return XI_PROCESS_CLOSE_ON_THIS_LAYER( context, NULL, mock_type( xi_state_t ) );
        break;
        default:
        break;
    }

    // pretend always successful send
    return XI_PROCESS_PUSH_ON_NEXT_LAYER( context, NULL, XI_STATE_WRITTEN );
}

xi_state_t xi_mock_layer_tls_prev_pull(
      void* context
    , void* data
    , xi_state_t in_out_state )
{
    XI_LAYER_FUNCTION_PRINT_FUNCTION_DIGEST();

    check_expected( in_out_state );

    return XI_PROCESS_PULL_ON_NEXT_LAYER( context, data, in_out_state );
}

xi_state_t xi_mock_layer_tls_prev_close(
      void* context
    , void* data
    , xi_state_t in_out_state )
{
    XI_LAYER_FUNCTION_PRINT_FUNCTION_DIGEST();

    check_expected( in_out_state );

    return XI_PROCESS_CLOSE_EXTERNALLY_ON_THIS_LAYER( context, data
        , in_out_state );
}

xi_state_t xi_mock_layer_tls_prev_close_externally(
      void* context
    , void* data
    , xi_state_t in_out_state )
{
    XI_LAYER_FUNCTION_PRINT_FUNCTION_DIGEST();

    check_expected( in_out_state );

    return XI_PROCESS_CLOSE_EXTERNALLY_ON_NEXT_LAYER( context, data
        , in_out_state );
}

xi_state_t xi_mock_layer_tls_prev_init(
      void* context
    , void* data
    , xi_state_t in_out_state )
{
    XI_LAYER_FUNCTION_PRINT_FUNCTION_DIGEST();

    check_expected( in_out_state );

    return XI_PROCESS_CONNECT_ON_THIS_LAYER( context, data, in_out_state );
}

xi_state_t xi_mock_layer_tls_prev_connect(
      void* context
    , void* data
    , xi_state_t in_out_state )
{
    XI_LAYER_FUNCTION_PRINT_FUNCTION_DIGEST();

    check_expected( in_out_state );

    return XI_PROCESS_CONNECT_ON_NEXT_LAYER( context, data, in_out_state );
}

#ifdef __cplusplus
}
#endif