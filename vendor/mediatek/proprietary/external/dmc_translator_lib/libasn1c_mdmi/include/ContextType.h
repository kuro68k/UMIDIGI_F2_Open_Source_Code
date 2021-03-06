/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _ContextType_H_
#define _ContextType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ContextType {
    ContextType_default = 0,
    ContextType_dedicated   = 1
} e_ContextType;

/* ContextType */
typedef long     ContextType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ContextType;
asn_struct_free_f ContextType_free;
asn_struct_print_f ContextType_print;
asn_constr_check_f ContextType_constraint;
ber_type_decoder_f ContextType_decode_ber;
der_type_encoder_f ContextType_encode_der;
xer_type_decoder_f ContextType_decode_xer;
xer_type_encoder_f ContextType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _ContextType_H_ */
#include <asn_internal.h>
