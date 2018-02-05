#ifndef _ParsePDU_H_
#define _ParsePDU_H_

#include <PDUs.h>

typedef enum Present {
	Nothing,
	Long,
	String,
	OID,
	IpAddress,
	Counter,
	Time,
	Arbitraty,
	Big_Counter,
	Unsign32
} Present;

typedef struct pdu_field {
	uint8_t *oid;
	Present present;
	union Fields {
		long value;
		OCTET_STRING_t string;
		OBJECT_IDENTIFIER_t oid;
		IpAddress_t ip;
		Counter32_t counter32;
		TimeTicks_t time;
		Opaque_t opaque;
		Counter64_t counter64;
		Unsigned32_t unsign32;
	} fields;
}Pdu_Field;


void parsePdu(PDUs_t *pdu, Pdu_Field *field);

#endif