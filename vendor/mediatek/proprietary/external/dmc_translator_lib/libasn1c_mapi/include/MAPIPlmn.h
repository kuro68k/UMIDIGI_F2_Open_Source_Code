/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPIPlmn_H_
#define _MAPIPlmn_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAPIPlmn */
typedef struct MAPIPlmn {
    struct MAPIPlmn__mcc {
        A_SEQUENCE_OF(long) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } *mcc;
    struct MAPIPlmn__mnc {
        A_SEQUENCE_OF(long) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } *mnc;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPIPlmn_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIPlmn;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPIPlmn_H_ */
#include <asn_internal.h>
