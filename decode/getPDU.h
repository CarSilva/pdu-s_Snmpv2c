#ifndef _GetPDU_H_
#define _GetPDU_H_

#include <Message.h>
#include <PDUs.h>

/*
 * Struct that store decode's result.
 * Stores if the process of decoding was a sucess or not,
 * the version that came out in the message, the community 
 * string and finally the PDU itself.
 */

typedef struct pdu_info{
	PDUs_t *pdu;
	long version;
	char *comm;	
	int error; // -1  == Fail || 0 == Want More || 1 == Sucess
}Pdu_Info;

/*
 * Turns the received buffer of bytes into a PDU, extracting also, the version and
 * community string. Basically decodes the buffer received.
 */
void buffer_to_PDU(uint8_t *buffer_final, Pdu_Info *info);

#endif