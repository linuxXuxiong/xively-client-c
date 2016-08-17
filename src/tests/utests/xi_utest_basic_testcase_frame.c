#include "xi_utest_basic_testcase_frame.h"
#include "xively.h"
#include "tinytest_macros.h"
#include "xi_memory_checks.h"
#include "xi_macros.h"
#include <stdio.h>

void* xi_utest_setup_basic( const struct testcase_t* testcase )
{
    XI_UNUSED( testcase );

    xi_memory_limiter_tearup();

    xi_initialize( "utest-account-id", "utest-device-id", NULL );

    return ( intptr_t* )1;
}

int xi_utest_teardown_basic( const struct testcase_t* testcase, void* fixture )
{
    XI_UNUSED( testcase );
    XI_UNUSED( fixture );

    xi_shutdown();

    xi_memory_limiter_teardown();

    return 1; //OK
}