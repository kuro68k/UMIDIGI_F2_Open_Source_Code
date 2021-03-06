/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _SrsTriggerType_H_
#define _SrsTriggerType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SrsTriggerType {
    SrsTriggerType_type0    = 0,
    SrsTriggerType_type1dci0    = 1,
    SrsTriggerType_type1dci1a2b2c   = 2,
    SrsTriggerType_type1dci4    = 3
} e_SrsTriggerType;

/* SrsTriggerType */
typedef long     SrsTriggerType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SrsTriggerType;
asn_struct_free_f SrsTriggerType_free;
asn_struct_print_f SrsTriggerType_print;
asn_constr_check_f SrsTriggerType_constraint;
ber_type_decoder_f SrsTriggerType_decode_ber;
der_type_encoder_f SrsTriggerType_encode_der;
xer_type_decoder_f SrsTriggerType_decode_xer;
xer_type_encoder_f SrsTriggerType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _SrsTriggerType_H_ */
#include <asn_internal.h>
