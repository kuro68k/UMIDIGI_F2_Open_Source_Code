/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPIOtaMessageDirection_H_
#define _MAPIOtaMessageDirection_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MAPIOtaMessageDirection {
    MAPIOtaMessageDirection_upstream    = 1,
    MAPIOtaMessageDirection_downstream  = 2
} e_MAPIOtaMessageDirection;

/* MAPIOtaMessageDirection */
typedef long     MAPIOtaMessageDirection_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIOtaMessageDirection;
asn_struct_free_f MAPIOtaMessageDirection_free;
asn_struct_print_f MAPIOtaMessageDirection_print;
asn_constr_check_f MAPIOtaMessageDirection_constraint;
ber_type_decoder_f MAPIOtaMessageDirection_decode_ber;
der_type_encoder_f MAPIOtaMessageDirection_encode_der;
xer_type_decoder_f MAPIOtaMessageDirection_decode_xer;
xer_type_encoder_f MAPIOtaMessageDirection_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPIOtaMessageDirection_H_ */
#include <asn_internal.h>
