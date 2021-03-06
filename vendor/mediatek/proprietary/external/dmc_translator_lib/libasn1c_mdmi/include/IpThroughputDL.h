/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _IpThroughputDL_H_
#define _IpThroughputDL_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ThroughputObject.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IpThroughputDL */
typedef ThroughputObject_t   IpThroughputDL_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IpThroughputDL;
asn_struct_free_f IpThroughputDL_free;
asn_struct_print_f IpThroughputDL_print;
asn_constr_check_f IpThroughputDL_constraint;
ber_type_decoder_f IpThroughputDL_decode_ber;
der_type_encoder_f IpThroughputDL_encode_der;
xer_type_decoder_f IpThroughputDL_decode_xer;
xer_type_encoder_f IpThroughputDL_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _IpThroughputDL_H_ */
#include <asn_internal.h>
