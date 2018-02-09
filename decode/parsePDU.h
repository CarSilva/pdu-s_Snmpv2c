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
	Unsign32,
	UnSpecified,
	NoSuchObject,
	NoSuchInstance,
	EndOfMibView
} Present;

typedef struct pdu_field {
	ObjectName_t *oid;
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
		NULL_t	 unSpecified;
		NULL_t	 noSuchObject;
		NULL_t	 noSuchInstance;
		NULL_t	 endOfMibView;
	} fields;
}Pdu_Field;

typedef struct decoded{
	int nFields;
	long request_id;
	long error_status;
	long error_index;
	long non_repeaters;
	long max_repetitions;
	char *primitiveName;
	Pdu_Field *decoded;
}Decoded;


void parsePdu(PDUs_t *pdu, Decoded *decoded);

#endif