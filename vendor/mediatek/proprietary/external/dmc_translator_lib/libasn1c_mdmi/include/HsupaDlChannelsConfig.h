/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _HsupaDlChannelsConfig_H_
#define _HsupaDlChannelsConfig_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AgchUse.h"
#include <NativeInteger.h>
#include <BOOLEAN.h>
#include "Tti.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* HsupaDlChannelsConfig */
typedef struct HsupaDlChannelsConfig {
    AgchUse_t    agchUse;
    long     agchOvsf;
    long     agchStart;
    long     agchEnd;
    long     agchDpchOffset;
    BOOLEAN_t    pErntiValid;
    BOOLEAN_t    sErntiValid;
    long     servingCellIndex;
    Tti_t    tti;
    long     servingGrantType;
    BOOLEAN_t    sttdOnAgch;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} HsupaDlChannelsConfig_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HsupaDlChannelsConfig;

#ifdef __cplusplus
}
#endif

#endif  /* _HsupaDlChannelsConfig_H_ */
#include <asn_internal.h>
