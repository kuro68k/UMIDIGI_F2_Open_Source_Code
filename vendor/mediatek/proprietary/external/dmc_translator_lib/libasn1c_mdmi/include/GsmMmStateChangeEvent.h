/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _GsmMmStateChangeEvent_H_
#define _GsmMmStateChangeEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GsmMmStates.h"

#ifdef __cplusplus
extern "C" {
#endif

/* GsmMmStateChangeEvent */
typedef GsmMmStates_t    GsmMmStateChangeEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GsmMmStateChangeEvent;
asn_struct_free_f GsmMmStateChangeEvent_free;
asn_struct_print_f GsmMmStateChangeEvent_print;
asn_constr_check_f GsmMmStateChangeEvent_constraint;
ber_type_decoder_f GsmMmStateChangeEvent_decode_ber;
der_type_encoder_f GsmMmStateChangeEvent_encode_der;
xer_type_decoder_f GsmMmStateChangeEvent_decode_xer;
xer_type_encoder_f GsmMmStateChangeEvent_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _GsmMmStateChangeEvent_H_ */
#include <asn_internal.h>
