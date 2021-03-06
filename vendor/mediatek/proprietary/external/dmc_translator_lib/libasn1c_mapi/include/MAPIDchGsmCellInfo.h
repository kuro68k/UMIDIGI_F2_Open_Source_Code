/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPIDchGsmCellInfo_H_
#define _MAPIDchGsmCellInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAPIDchGsmCellInfo */
typedef struct MAPIDchGsmCellInfo {
    long    *arfcn  /* OPTIONAL */;
    long    *bsic   /* OPTIONAL */;
    long    *rssi   /* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPIDchGsmCellInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIDchGsmCellInfo;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPIDchGsmCellInfo_H_ */
#include <asn_internal.h>
