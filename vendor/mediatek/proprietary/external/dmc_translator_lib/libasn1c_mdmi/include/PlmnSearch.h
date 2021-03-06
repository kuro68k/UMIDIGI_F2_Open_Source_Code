/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PlmnSearch_H_
#define _PlmnSearch_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PlmnScan;

/* PlmnSearch */
typedef struct PlmnSearch {
    A_SEQUENCE_OF(struct PlmnScan) list;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} PlmnSearch_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PlmnSearch;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PlmnScan.h"

#endif  /* _PlmnSearch_H_ */
#include <asn_internal.h>
