/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WifiToLTEHandoverEvent_H_
#define _WifiToLTEHandoverEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "WifiToLteHandover.h"

#ifdef __cplusplus
extern "C" {
#endif

/* WifiToLTEHandoverEvent */
typedef WifiToLteHandover_t  WifiToLTEHandoverEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WifiToLTEHandoverEvent;
asn_struct_free_f WifiToLTEHandoverEvent_free;
asn_struct_print_f WifiToLTEHandoverEvent_print;
asn_constr_check_f WifiToLTEHandoverEvent_constraint;
ber_type_decoder_f WifiToLTEHandoverEvent_decode_ber;
der_type_encoder_f WifiToLTEHandoverEvent_encode_der;
xer_type_decoder_f WifiToLTEHandoverEvent_decode_xer;
xer_type_encoder_f WifiToLTEHandoverEvent_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _WifiToLTEHandoverEvent_H_ */
#include <asn_internal.h>
