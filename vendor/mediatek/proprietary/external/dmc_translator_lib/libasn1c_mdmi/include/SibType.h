/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _SibType_H_
#define _SibType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SibType {
    SibType_sib2    = 2,
    SibType_sib3    = 3,
    SibType_sib4    = 4,
    SibType_sib5    = 5,
    SibType_sib6    = 6,
    SibType_sib7    = 7,
    SibType_sib8    = 8,
    SibType_sib9    = 9,
    SibType_sib10   = 10,
    SibType_sib11   = 11,
    SibType_sib12   = 12,
    SibType_sib13   = 13,
    SibType_sib14   = 14,
    SibType_sib15   = 15,
    SibType_sib16   = 16,
    SibType_sib17   = 17,
    SibType_sib18   = 18,
    SibType_sib19   = 19
} e_SibType;

/* SibType */
typedef long     SibType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SibType;
asn_struct_free_f SibType_free;
asn_struct_print_f SibType_print;
asn_constr_check_f SibType_constraint;
ber_type_decoder_f SibType_decode_ber;
der_type_encoder_f SibType_encode_der;
xer_type_decoder_f SibType_decode_xer;
xer_type_encoder_f SibType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _SibType_H_ */
#include <asn_internal.h>
