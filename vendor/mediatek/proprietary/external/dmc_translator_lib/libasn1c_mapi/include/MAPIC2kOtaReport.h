/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v2.0.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPIC2kOtaReport_H_
#define _MAPIC2kOtaReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAPIC2kOtaReport */
typedef struct MAPIC2kOtaReport {
    long    *msgNumber  /* OPTIONAL */;
    long    *burstType  /* OPTIONAL */;
    long    *numOfMsgs  /* OPTIONAL */;
    struct MAPIC2kOtaReport__chari {
        A_SEQUENCE_OF(long) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } *chari;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPIC2kOtaReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIC2kOtaReport;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPIC2kOtaReport_H_ */
#include <asn_internal.h>
