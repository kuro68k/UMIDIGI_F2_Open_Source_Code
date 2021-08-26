/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _CellReselectionStartEvent_H_
#define _CellReselectionStartEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CellReselectionStart.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CellReselectionStartEvent */
typedef CellReselectionStart_t   CellReselectionStartEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CellReselectionStartEvent;
asn_struct_free_f CellReselectionStartEvent_free;
asn_struct_print_f CellReselectionStartEvent_print;
asn_constr_check_f CellReselectionStartEvent_constraint;
ber_type_decoder_f CellReselectionStartEvent_decode_ber;
der_type_encoder_f CellReselectionStartEvent_encode_der;
xer_type_decoder_f CellReselectionStartEvent_decode_xer;
xer_type_encoder_f CellReselectionStartEvent_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _CellReselectionStartEvent_H_ */
#include <asn_internal.h>