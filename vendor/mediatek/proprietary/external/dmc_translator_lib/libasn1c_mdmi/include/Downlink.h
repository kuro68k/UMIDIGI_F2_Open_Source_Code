/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _Downlink_H_
#define _Downlink_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Downlink {
    Downlink_pch    = 1,
    Downlink_agch   = 2
} e_Downlink;

/* Downlink */
typedef long     Downlink_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Downlink;
asn_struct_free_f Downlink_free;
asn_struct_print_f Downlink_print;
asn_constr_check_f Downlink_constraint;
ber_type_decoder_f Downlink_decode_ber;
der_type_encoder_f Downlink_encode_der;
xer_type_decoder_f Downlink_decode_xer;
xer_type_encoder_f Downlink_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _Downlink_H_ */
#include <asn_internal.h>
