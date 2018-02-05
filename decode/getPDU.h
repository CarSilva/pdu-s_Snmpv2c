#ifndef _GetPDU_H_
#define _GetPDU_H_

#include <Message.h>
#include <PDUs.h>

typedef struct pdu_info{
	PDUs_t *pdu;
	char *version;
	char *comm;	
}Pdu_Info;

Pdu_Info *buffer_to_PDU(uint8_t *buffer_final);

char *getVersion(Message_t *message);
char *getComm(Message_t *message);


#endif