/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _LppType_H_
#define _LppType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LppType {
    LppType_request_capabilities    = 0,
    LppType_provide_capabilities    = 1,
    LppType_provide_assistance_data = 2,
    LppType_request_location_info   = 3,
    LppType_provide_location_info   = 4,
    LppType_request_assistance_data = 5,
    LppType_acknowledgment  = 6
} e_LppType;

/* LppType */
typedef long     LppType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LppType;
asn_struct_free_f LppType_free;
asn_struct_print_f LppType_print;
asn_constr_check_f LppType_constraint;
ber_type_decoder_f LppType_decode_ber;
der_type_encoder_f LppType_encode_der;
xer_type_decoder_f LppType_decode_xer;
xer_type_encoder_f LppType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _LppType_H_ */
#include <asn_internal.h>
