/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PbchDecode_H_
#define _PbchDecode_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Earfcn.h"
#include "CrcResult.h"
#include <NativeInteger.h>
#include "SystemFrameNumber.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PbchDecode */
typedef struct PbchDecode {
    Earfcn_t     earfcn;
    CrcResult_t  crcResult;
    long     pbchPayload;
    long     numAntennas;
    SystemFrameNumber_t  sfn;
    long     freqOffset;
    long     dlBandwidth;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} PbchDecode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PbchDecode;

#ifdef __cplusplus
}
#endif

#endif  /* _PbchDecode_H_ */
#include <asn_internal.h>
