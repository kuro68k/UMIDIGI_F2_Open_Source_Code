/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WcdmaRachParameters_H_
#define _WcdmaRachParameters_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "AichReport.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* WcdmaRachParameters */
typedef struct WcdmaRachParameters {
    long     msgLength;
    long     numPreamble;
    AichReport_t     aichReport;
    long     preambleSignature;
    long     numAccessSlot;
    long     sfn;
    long     aichTiming;
    long     rachTxPower;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} WcdmaRachParameters_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WcdmaRachParameters;

#ifdef __cplusplus
}
#endif

#endif  /* _WcdmaRachParameters_H_ */
#include <asn_internal.h>
