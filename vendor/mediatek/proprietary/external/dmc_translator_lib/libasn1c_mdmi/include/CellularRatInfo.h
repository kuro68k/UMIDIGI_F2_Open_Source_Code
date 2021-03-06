/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _CellularRatInfo_H_
#define _CellularRatInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CellularRatInfo {
    CellularRatInfo_gsm = 1,
    CellularRatInfo_umts    = 2,
    CellularRatInfo_lte = 3,
    CellularRatInfo_cdma    = 4
} e_CellularRatInfo;

/* CellularRatInfo */
typedef long     CellularRatInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CellularRatInfo;
asn_struct_free_f CellularRatInfo_free;
asn_struct_print_f CellularRatInfo_print;
asn_constr_check_f CellularRatInfo_constraint;
ber_type_decoder_f CellularRatInfo_decode_ber;
der_type_encoder_f CellularRatInfo_encode_der;
xer_type_decoder_f CellularRatInfo_decode_xer;
xer_type_encoder_f CellularRatInfo_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _CellularRatInfo_H_ */
#include <asn_internal.h>
