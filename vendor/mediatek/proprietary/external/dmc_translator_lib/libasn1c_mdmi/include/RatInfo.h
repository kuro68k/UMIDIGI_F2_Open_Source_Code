/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RatInfo_H_
#define _RatInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RatInfo {
    RatInfo_noService   = 0,
    RatInfo_gsm = 1,
    RatInfo_umts    = 2,
    RatInfo_lte = 3,
    RatInfo_cdma    = 4,
    RatInfo_wifi    = 5
} e_RatInfo;

/* RatInfo */
typedef long     RatInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RatInfo;
asn_struct_free_f RatInfo_free;
asn_struct_print_f RatInfo_print;
asn_constr_check_f RatInfo_constraint;
ber_type_decoder_f RatInfo_decode_ber;
der_type_encoder_f RatInfo_encode_der;
xer_type_decoder_f RatInfo_decode_xer;
xer_type_encoder_f RatInfo_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _RatInfo_H_ */
#include <asn_internal.h>
