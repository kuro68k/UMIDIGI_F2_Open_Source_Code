/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPISIBType_H_
#define _MAPISIBType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MAPISIBType {
    MAPISIBType_masterInformationBlock  = 0,
    MAPISIBType_schedulingBlock1    = 1,
    MAPISIBType_schedulingBlock2    = 2,
    MAPISIBType_systemInformationBlock1 = 3,
    MAPISIBType_systemInformationBlock10    = 4,
    MAPISIBType_systemInformationBlock11    = 5,
    MAPISIBType_systemInformationBlock11bis = 6,
    MAPISIBType_systemInformationBlock12    = 7,
    MAPISIBType_systemInformationBlock13    = 8,
    MAPISIBType_systemInformationBlock13_1  = 9,
    MAPISIBType_systemInformationBlock13_2  = 10,
    MAPISIBType_systemInformationBlock13_3  = 11,
    MAPISIBType_systemInformationBlock13_4  = 12,
    MAPISIBType_systemInformationBlock14    = 13,
    MAPISIBType_systemInformationBlock15    = 14,
    MAPISIBType_systemInformationBlock15_1  = 15,
    MAPISIBType_systemInformationBlock15_1bis   = 16,
    MAPISIBType_systemInformationBlock15_2  = 17,
    MAPISIBType_systemInformationBlock15_2bis   = 18,
    MAPISIBType_systemInformationBlock15_3  = 19,
    MAPISIBType_systemInformationBlock15_3bis   = 20,
    MAPISIBType_systemInformationBlock15_4  = 21,
    MAPISIBType_systemInformationBlock15_5  = 22,
    MAPISIBType_systemInformationBlock15_6  = 23,
    MAPISIBType_systemInformationBlock15_7  = 24,
    MAPISIBType_systemInformationBlock15_8  = 25,
    MAPISIBType_systemInformationBlock15bis = 26,
    MAPISIBType_systemInformationBlock16    = 27,
    MAPISIBType_systemInformationBlock17    = 28,
    MAPISIBType_systemInformationBlock18    = 29,
    MAPISIBType_systemInformationBlock19    = 30,
    MAPISIBType_systemInformationBlock2 = 31,
    MAPISIBType_systemInformationBlock20    = 32,
    MAPISIBType_systemInformationBlock3 = 33,
    MAPISIBType_systemInformationBlock4 = 34,
    MAPISIBType_systemInformationBlock5 = 35,
    MAPISIBType_systemInformationBlock5bis  = 36,
    MAPISIBType_systemInformationBlock6 = 37,
    MAPISIBType_systemInformationBlock7 = 38,
    MAPISIBType_systemInformationBlock8 = 39,
    MAPISIBType_systemInformationBlock9 = 40
	/*
	 * Enumeration is extensible
	 */
} e_MAPISIBType;

/* MAPISIBType */
typedef long     MAPISIBType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPISIBType;
asn_struct_free_f MAPISIBType_free;
asn_struct_print_f MAPISIBType_print;
asn_constr_check_f MAPISIBType_constraint;
ber_type_decoder_f MAPISIBType_decode_ber;
der_type_encoder_f MAPISIBType_encode_der;
xer_type_decoder_f MAPISIBType_decode_xer;
xer_type_encoder_f MAPISIBType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPISIBType_H_ */
#include <asn_internal.h>