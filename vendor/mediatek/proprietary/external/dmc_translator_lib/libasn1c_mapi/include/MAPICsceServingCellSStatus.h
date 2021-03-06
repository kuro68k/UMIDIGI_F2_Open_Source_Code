/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPICsceServingCellSStatus_H_
#define _MAPICsceServingCellSStatus_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAPICsceServingCellSStatus */
typedef struct MAPICsceServingCellSStatus {
    long    *uarfcnDL   /* OPTIONAL */;
    long    *psc    /* OPTIONAL */;
    long    *rscp   /* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
    long    *sib19CellFachMeasInd   /* OPTIONAL */;
    long    *eutraRachReportNumBits /* OPTIONAL */;
    long    *eutraRachReportStringData  /* OPTIONAL */;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPICsceServingCellSStatus_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPICsceServingCellSStatus;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPICsceServingCellSStatus_H_ */
#include <asn_internal.h>
