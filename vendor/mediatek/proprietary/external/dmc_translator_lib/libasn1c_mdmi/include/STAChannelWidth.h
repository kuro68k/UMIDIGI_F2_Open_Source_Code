/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _STAChannelWidth_H_
#define _STAChannelWidth_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum STAChannelWidth {
    STAChannelWidth_channelwidth20mhz   = 0,
    STAChannelWidth_anychannelwidth = 1
} e_STAChannelWidth;

/* STAChannelWidth */
typedef long     STAChannelWidth_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_STAChannelWidth;
asn_struct_free_f STAChannelWidth_free;
asn_struct_print_f STAChannelWidth_print;
asn_constr_check_f STAChannelWidth_constraint;
ber_type_decoder_f STAChannelWidth_decode_ber;
der_type_encoder_f STAChannelWidth_encode_der;
xer_type_decoder_f STAChannelWidth_decode_xer;
xer_type_encoder_f STAChannelWidth_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _STAChannelWidth_H_ */
#include <asn_internal.h>
