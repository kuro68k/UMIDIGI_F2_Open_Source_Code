/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _UlDciGrantInfo_H_
#define _UlDciGrantInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "ModulationType.h"
#include "HoppingFlag.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UlDciGrantInfo */
typedef struct UlDciGrantInfo {
    long     mcsIndex;
    long     cqiRequest;
    long     startResourceBlock;
    long     numResourceBlock;
    long     tbSizeIndex;
    ModulationType_t     modulationType;
    HoppingFlag_t    hoppingFlag;
    long     ndi;
    long     tpc;
    long     demodulationRefSignalCyclicShift;
    long     dci0KPusch;
    long     redundancyVersionIndex;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} UlDciGrantInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UlDciGrantInfo;

#ifdef __cplusplus
}
#endif

#endif  /* _UlDciGrantInfo_H_ */
#include <asn_internal.h>
