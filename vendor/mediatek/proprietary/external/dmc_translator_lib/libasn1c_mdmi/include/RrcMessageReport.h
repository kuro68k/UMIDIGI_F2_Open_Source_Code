/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RrcMessageReport_H_
#define _RrcMessageReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Version3gpp.h"
#include "RrcPduType.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RrcMessageReport */
typedef struct RrcMessageReport {
    Version3gpp_t    rrc_version;
    RrcPduType_t     pdu_type;
    OCTET_STRING_t   rrcPayload;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} RrcMessageReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RrcMessageReport;

#ifdef __cplusplus
}
#endif

#endif  /* _RrcMessageReport_H_ */
#include <asn_internal.h>
