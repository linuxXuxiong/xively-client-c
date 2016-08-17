# Xivelt Client version 1.x.x
#### MM DD YYYY

- User Guide file added to Xively C Client's doc directory in markdown format.
- Xively C Client README.md file has been updated serving as a first-step introduction.

# Xivelt Client version 1.1.6
#### Jul 08 2016

## Features

- The sources for WolfSSL and CyaSSL are no longer part of the Xively Client repository.
  WolfSSL has to be downloaded and compiled manually. Please follow the building
  Xively Client Library chapter in Porting Guide for more details.
- Custom server address support with two new API functions: xi_connect_to and
  xi_connect_with_lastwill_to. These functions accept two additional parameters
  (host and port) which determine the target address the Xively C Client connects to.


# Xivelt Client version 1.1.5
#### Jun 09 2016

## Features

- [Porting Guide](include/bsp/PORTING-GUIDE.md) is added. Describes the porting process in detail.
- Separated Example Applications. Examples are separated from Xively C Client internal sources and make system. This eases new example creation process for a new customer.
- Internal make-system rationalization. CONFIG flags now share unified style. Config presets are introduced: POSIX\_DEV, POSIX\_REL
- Added new Makefile option to define BSP root folder outside the Xively C Client's directory structure for custom BSP implementations. Just call make BSP_DIR=/your\_path/bsp\_root\_directory

## Notes

- Removed functionality related to reading the username and password from the file.


# Xivelt Client version 1.1.4
#### May 12 2016

## Features

- BSP TIME API added. Reference implementations for POSIX, Microchip and WMSDK. New function ```xi_bsp_time_getcurrenttime_milliseconds``` has been added to new BSP file ```xi_bsp_time.h```.
- BSP MEMORY API added. Now applications can customise memory management of the Xively C Client. For instance a custom implementation can use static memory on devices where heap isn't desired. New functions ```xi_bsp_mem_alloc```, ```xi_bsp_mem_realloc``` and ```xi_bsp_mem_free``` has been introduced within ```xi_bsp_mem.h``` file.

## Bugfixes

- Fixed duplication of msg IDs when sending new messages during continuous session while unacked messages present
- Zero Length Client IDs are now supported and will not cause errors in the client
- Resource management system will now correctly pass-through errors via callbacks
- Added password 'should be unset if username is not' set rule to meet the MQTT 3.1.1 specification

# Xively Client version 1.1.3
#### May 6 2016

## Bugfixes

- Fixed timeout calculation for xi_bsp_io_net_select select function.

# Xivelt Client version 1.1.2
#### April 28th 2016

## Features

- Board Support Package (BSP)
    - New function xi_bsp_io_net_select is now part of the BSP networking package. Two reference implementations of this function for posix and microchip were added. Declaration can be found in xi_bsp_io_net.h and definitions resides in xi_bsp_io_net_posix.c and xi_bsp_io_net_microchip.c.
    - New BSP Random Number Generator API added. API is declared in new xi_bsp_rng.h file. Reference implementation for posix and wolfssl are located in xi_bsp_rng_posix.c and xi_bsp_rng_wolfssl.c.

## Known Bugs

- Msg id duplication when new messages sent in continious session while unacked messages are present.

# Xivelt Client version 1.1.1
#### April 14th 2016

## Features

- Mqtt Clean Session - client side support
    - Xively C Client re-delivers unacknowledged SUBSCRIBEs, QoS 1 and 2 PUBLISHes across
      separate connections if CLEAN SESSION flag is not set. See details on page
      <http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718030>
    - Xively Client keeps messages in memory. This means restart of Xively Client library
      or the device itself will still result in loss of messages waiting for re-delivery.
- BSP NET API documentation.
- Local developer builds are extended with cross compilation ability which accelerates
  and validates portable code development.

## Bugfixes

- XCL-2028: memory leak fix in case of unsuccessful control topic subscription

# Xively Client version 1.1.0
#### March 22nd 2016

## Features

- __v1.1.0 API Update__

  The Xively Client API has received an update to clean up header file dependencies and to increase ease of use.  The following significant changes have been made to the API:

    - Client Application Include Path has been simplified.  We've moved all Client Application header file dependencies to "include" and "include\_senml". These directories contain all dependencies for examples and for any application using the Xively C Client.
        - "include" contains dependencies for a client application to build a Xively connection, manage subscriptions and to publish messages.
        - "include\_senml" is the API of the SenML module.  This functionality is independent of the main Xively API in the "include" directory (only error codes in xively_error.h are shared).
        - Users of previous libxively versions may adapt to these changes by including only "include/xively.h"
    - The structures xi\_data\_desc\_t and xi\_mqtt\_message_t have been removed from the public API
    - The subscription callback function signature has been reworked.  MQTT message data, such as topic, payload, etc, has been broken out into discrete parameters instead of passed in as an abstract structure.  Please see the xively.h documentation and our examples for more information.
    - SenML API reworked in order to clear up header file dependencies.
        - Most of the usage is the same as before, though XI\_CREATE\_SENML\_STRUCT now requires at least one base value initializer (name, unit or time). If no base value is required then the usage of XI\_CREATE\_SENML\_EMPTY\_STRUCT is required.

- __Further Feature Changes__

    - Added xi\_client\_version\_str declared in xively.h. This can be used as a string representation of the Xively Client Library version numbers (xi\_major, xi\_minor, xi\_revision) for debug output purposes and for examining library binary files to determine the version.  The string format is:  "Xively C Client Version: <major>.<minor>.<revision>"
    - Header Files now have a standard format via the use of Clang format.
    - Client examples are formatted with Clang format.
    - Client examples have a standard command line argument parser using mosquitto nomenclature whenever possible.
    - Client examples all have a --help option to print usage.
    - Microchip Platforms: Added Dynamic File System Support to the Microchip Builds.
    - Microchip Platforms: Enforce KeepAlive MQTT packet regardless of publish traffic in order to better detect physical LAN disconnects.
    - TLS: Added support for OCSP Stapling support with WolfSSL
    - TLS: Upgraded supported WolfSSL implementation to 3.7.0
    - Cleaned up header file dependencies of our examples.
    - Replaced xi\_evtd\_stop( event\_dispatcher ) with xi\_events\_stop()
    - Replaced xi\_platform\_loop() with xi\_events\_process\_blocking()
    - Added xi\_events\_process\_tick() for No OS or RTOS devices who can't use xi\_events\_process\_blocking()
    - BSP NET API and its posix implementation released as a first step of the full BSP portfolio. Now porting the network stack should be much easier than before.

## Bugfixes
- XCL-1546: Fixed a Bug in  Microchip IO platforms where there could potentially be a crash in Debug Logging Mode when a critical and unexpected error state occurred. This problem did not occur in Release Builds of the Xively Client Library.

## Known Bugs
- There is a memory leak for each time the control topic subscription is unsuccessful. This bug is fixed in *v1.1.1*.

# Xively Client version 1.0.0
#### August 13th 2015

## Features
- Simplified the API
    - Removed Default Contexts
    - Collapsed multiple publish, subscribe, and connection functions
    - All Xively API functions now take callbacks
- Added Publish Formatted Timeseries Function for publishing float and string timeseries values with an optional category tag.
    - Formatted timeseries can be published with a null time value.  In this configuration the Xively Service's server time will be used to timestamp the message.
- Added Version Numbering
    - Version Numbers are extern integers xi\_major, xi\_minor, xi\_revision and should be available in your source when you include xively.h
- Reduced Memory Usage during the TLS encryption process when transmitting messages. Previously message payloads were being duplicated in memory.
- Reduced Memory Usage of PUBLISH MQTT message during message serialization. Previously PUBLISH message payloads were duplicated before they were sent.
- New API functions to register user event callbacks with a delay and to cancel previously registered functions.

## Bugfixes
- XCL-1229: Fixed a bug where the fifth or higher mqtt topic subscription would not properly register the callback function for the topic.
- XCL-1325: Attempting to invoke shutdown\_connection() on a disconnected context will now result in the XI\_SOCKET\_NO\_ACTIVE\_CONNECTION\_ERROR return code instead of XI\_STATE_OK.
- XCL-1412: Fixed a memory leak on Microchip TCP platforms when a disconnection occurred during a read or a write from a socket.