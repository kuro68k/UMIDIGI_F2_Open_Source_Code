/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PdschReport_H_
#define _PdschReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PdschReportInfo;

/* PdschReport */
typedef struct PdschReport {
    A_SEQUENCE_OF(struct PdschReportInfo) list;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} PdschReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PdschReport;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PdschReportInfo.h"

#endif  /* _PdschReport_H_ */
#include <asn_internal.h>