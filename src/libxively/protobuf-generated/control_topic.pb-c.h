/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: control_topic.proto */

#ifndef PROTOBUF_C_control_5ftopic_2eproto__INCLUDED
#define PROTOBUF_C_control_5ftopic_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1001001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _CTRPC CTRPC;
typedef struct _CTRPC__Header CTRPC__Header;
typedef struct _CTRPC__Response CTRPC__Response;
typedef struct _CTRPC__SndCreds CTRPC__SndCreds;
typedef struct _CTRPC__ReqAscNonce CTRPC__ReqAscNonce;
typedef struct _CTRPC__ReqAscNonceResp CTRPC__ReqAscNonceResp;
typedef struct _CTRPC__AscWindow CTRPC__AscWindow;
typedef struct _CTRPC__SetCerts CTRPC__SetCerts;
typedef struct _CTRPC__AddCert CTRPC__AddCert;
typedef struct _CTRPC__SetBckoff CTRPC__SetBckoff;
typedef struct _CTRPC__SetServList CTRPC__SetServList;
typedef struct _CTRPC__LogMode CTRPC__LogMode;


/* --- enums --- */

typedef enum _CTRPC__FuncType {
  /*
   * Structure with a standard set of response data.
   * Most RPCs will use this to communicate success or failure.
   * Some other RPCs will have their own specific Response Message Type.
   */
  CT__RPC__FUNC_TYPE__RESPONSE = 1,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__SND_CREDS = 2,
  CT__RPC__FUNC_TYPE__REQ_ASC_NONCE = 3,
  CT__RPC__FUNC_TYPE__REQ_ASC_NONCE_RESP = 4,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__ASC_WINDOW = 5,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__SET_CERTS = 6,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__ADD_CERT = 7,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__SET_BCKOFF = 8,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__SET_SERV_LIST = 9,
  /*
   * Uses Standard Response
   */
  CT__RPC__FUNC_TYPE__LOG_MODE = 10
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CT__RPC__FUNC_TYPE)
} CTRPC__FuncType;
/*
 * Success / Failure Codes used on Responses
 */
typedef enum _CTRPC__FuncResult {
  /*
   * success
   */
  CT__RPC__FUNC_RESULT__OK = 1,
  /*
   * checksum mismatch error
   */
  CT__RPC__FUNC_RESULT__CHKSUM_ERR = 2,
  /*
   * could not store provided values
   */
  CT__RPC__FUNC_RESULT__STORE_ERR = 3,
  /*
   * general error
   */
  CT__RPC__FUNC_RESULT__GEN_ERR = 4
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CT__RPC__FUNC_RESULT)
} CTRPC__FuncResult;

/* --- messages --- */

/*
 * Standard Data Across all message types
 */
struct  _CTRPC__Header
{
  ProtobufCMessage base;
  char *msgid;
  CTRPC__FuncType functype;
  ProtobufCBinaryData checksum;
};
#define CT__RPC__HEADER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__header__descriptor) \
    , NULL, 0, {0,NULL} }


/*
 * Standard Response Data that tracks success or failure
 */
struct  _CTRPC__Response
{
  ProtobufCMessage base;
  CTRPC__FuncResult result;
  char *resultmsg;
};
#define CT__RPC__RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__response__descriptor) \
    , 0, NULL }


/*
 * Service Provides a new MQTT password to the client.
 */
struct  _CTRPC__SndCreds
{
  ProtobufCMessage base;
  char *cred;
};
#define CT__RPC__SND_CREDS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__snd_creds__descriptor) \
    , NULL }


/*
 * Server Requests that the Client Provide a Nonce
 */
struct  _CTRPC__ReqAscNonce
{
  ProtobufCMessage base;
  char *devid;
};
#define CT__RPC__REQ_ASC_NONCE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__req_asc_nonce__descriptor) \
    , NULL }


/*
 * Client Response for Nonce Request.
 */
struct  _CTRPC__ReqAscNonceResp
{
  ProtobufCMessage base;
  CTRPC__FuncResult result;
  char *nonce;
};
#define CT__RPC__REQ_ASC_NONCE_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__req_asc_nonce_resp__descriptor) \
    , 0, NULL }


/*
 * Service Requests An Association Signal
 * Trigger (Flashing Lights) for a Duration
 * of Time to Affirm that the Proper Device
 * is being Reassociated.
 */
struct  _CTRPC__AscWindow
{
  ProtobufCMessage base;
  uint32_t seconds;
};
#define CT__RPC__ASC_WINDOW__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__asc_window__descriptor) \
    , 0 }


/*
 * Service Provides New Certificates
 * to the Client.  This overwrites all
 * Existing Certificates on the Client.
 */
struct  _CTRPC__SetCerts
{
  ProtobufCMessage base;
  ProtobufCBinaryData certs;
};
#define CT__RPC__SET_CERTS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__set_certs__descriptor) \
    , {0,NULL} }


/*
 * Service Provides A Certificate to Append
 * to the Current List of Certificates
 */
struct  _CTRPC__AddCert
{
  ProtobufCMessage base;
  ProtobufCBinaryData cert;
};
#define CT__RPC__ADD_CERT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__add_cert__descriptor) \
    , {0,NULL} }


/*
 * Service Sets a New BackOff Look Up Tab and BackOff Decay
 * Table.
 */
struct  _CTRPC__SetBckoff
{
  ProtobufCMessage base;
  size_t n_lut;
  uint32_t *lut;
  size_t n_lut_decay;
  uint32_t *lut_decay;
};
#define CT__RPC__SET_BCKOFF__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__set_bckoff__descriptor) \
    , 0,NULL, 0,NULL }


/*
 * Service Sets the List of Domains that the
 * Client uses to connect to the Xively Service
 */
struct  _CTRPC__SetServList
{
  ProtobufCMessage base;
  size_t n_domain;
  char **domain;
};
#define CT__RPC__SET_SERV_LIST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__set_serv_list__descriptor) \
    , 0,NULL }


/*
 * Toggles Logging Mode on the Device
 */
struct  _CTRPC__LogMode
{
  ProtobufCMessage base;
  protobuf_c_boolean isenabled;
};
#define CT__RPC__LOG_MODE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__log_mode__descriptor) \
    , 0 }


struct  _CTRPC
{
  ProtobufCMessage base;
  CTRPC__Header *header;
  CTRPC__Response *response;
  CTRPC__SndCreds *sndcreds;
  CTRPC__ReqAscNonce *reqascnonce;
  CTRPC__ReqAscNonceResp *reqascnonceresp;
  CTRPC__AscWindow *ascwindow;
  CTRPC__SetCerts *setcerts;
  CTRPC__AddCert *addcert;
  CTRPC__SetBckoff *setbckoff;
  CTRPC__SetServList *setservlist;
  CTRPC__LogMode *logmode;
};
#define CT__RPC__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ct__rpc__descriptor) \
    , NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }


/* CTRPC__Header methods */
void   ct__rpc__header__init
                     (CTRPC__Header         *message);
/* CTRPC__Response methods */
void   ct__rpc__response__init
                     (CTRPC__Response         *message);
/* CTRPC__SndCreds methods */
void   ct__rpc__snd_creds__init
                     (CTRPC__SndCreds         *message);
/* CTRPC__ReqAscNonce methods */
void   ct__rpc__req_asc_nonce__init
                     (CTRPC__ReqAscNonce         *message);
/* CTRPC__ReqAscNonceResp methods */
void   ct__rpc__req_asc_nonce_resp__init
                     (CTRPC__ReqAscNonceResp         *message);
/* CTRPC__AscWindow methods */
void   ct__rpc__asc_window__init
                     (CTRPC__AscWindow         *message);
/* CTRPC__SetCerts methods */
void   ct__rpc__set_certs__init
                     (CTRPC__SetCerts         *message);
/* CTRPC__AddCert methods */
void   ct__rpc__add_cert__init
                     (CTRPC__AddCert         *message);
/* CTRPC__SetBckoff methods */
void   ct__rpc__set_bckoff__init
                     (CTRPC__SetBckoff         *message);
/* CTRPC__SetServList methods */
void   ct__rpc__set_serv_list__init
                     (CTRPC__SetServList         *message);
/* CTRPC__LogMode methods */
void   ct__rpc__log_mode__init
                     (CTRPC__LogMode         *message);
/* CTRPC methods */
void   ct__rpc__init
                     (CTRPC         *message);
size_t ct__rpc__get_packed_size
                     (const CTRPC   *message);
size_t ct__rpc__pack
                     (const CTRPC   *message,
                      uint8_t             *out);
size_t ct__rpc__pack_to_buffer
                     (const CTRPC   *message,
                      ProtobufCBuffer     *buffer);
CTRPC *
       ct__rpc__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ct__rpc__free_unpacked
                     (CTRPC *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*CTRPC__Header_Closure)
                 (const CTRPC__Header *message,
                  void *closure_data);
typedef void (*CTRPC__Response_Closure)
                 (const CTRPC__Response *message,
                  void *closure_data);
typedef void (*CTRPC__SndCreds_Closure)
                 (const CTRPC__SndCreds *message,
                  void *closure_data);
typedef void (*CTRPC__ReqAscNonce_Closure)
                 (const CTRPC__ReqAscNonce *message,
                  void *closure_data);
typedef void (*CTRPC__ReqAscNonceResp_Closure)
                 (const CTRPC__ReqAscNonceResp *message,
                  void *closure_data);
typedef void (*CTRPC__AscWindow_Closure)
                 (const CTRPC__AscWindow *message,
                  void *closure_data);
typedef void (*CTRPC__SetCerts_Closure)
                 (const CTRPC__SetCerts *message,
                  void *closure_data);
typedef void (*CTRPC__AddCert_Closure)
                 (const CTRPC__AddCert *message,
                  void *closure_data);
typedef void (*CTRPC__SetBckoff_Closure)
                 (const CTRPC__SetBckoff *message,
                  void *closure_data);
typedef void (*CTRPC__SetServList_Closure)
                 (const CTRPC__SetServList *message,
                  void *closure_data);
typedef void (*CTRPC__LogMode_Closure)
                 (const CTRPC__LogMode *message,
                  void *closure_data);
typedef void (*CTRPC_Closure)
                 (const CTRPC *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor ct__rpc__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__header__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__response__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__snd_creds__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__req_asc_nonce__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__req_asc_nonce_resp__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__asc_window__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__set_certs__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__add_cert__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__set_bckoff__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__set_serv_list__descriptor;
extern const ProtobufCMessageDescriptor ct__rpc__log_mode__descriptor;
extern const ProtobufCEnumDescriptor    ct__rpc__func_type__descriptor;
extern const ProtobufCEnumDescriptor    ct__rpc__func_result__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_control_5ftopic_2eproto__INCLUDED */