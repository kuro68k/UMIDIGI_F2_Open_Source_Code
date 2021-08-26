/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _CellReselectionStart_H_
#define _CellReselectionStart_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Earfcn.h"
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CellReselectionStart */
typedef struct CellReselectionStart {
    Earfcn_t     dlarfcn;
    long     cellId;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} CellReselectionStart_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CellReselectionStart;

#ifdef __cplusplus
}
#endif

#endif  /* _CellReselectionStart_H_ */
#include <asn_internal.h>