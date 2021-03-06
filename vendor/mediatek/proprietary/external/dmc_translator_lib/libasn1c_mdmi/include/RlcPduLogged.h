/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RlcPduLogged_H_
#define _RlcPduLogged_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "RlcPduStatus.h"
#include <BOOLEAN.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RlcPduLogged */
typedef struct RlcPduLogged {
    long     pduSize;
    long     numBytesLogged;
    RlcPduStatus_t   status;
    BOOLEAN_t    extensionBit;
    long     lengthIndicator;
    long     framingInfo;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} RlcPduLogged_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RlcPduLogged;

#ifdef __cplusplus
}
#endif

#endif  /* _RlcPduLogged_H_ */
#include <asn_internal.h>
