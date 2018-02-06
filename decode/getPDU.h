#ifndef _GetPDU_H_
#define _GetPDU_H_

#include <Message.h>
#include <PDUs.h>

typedef struct pdu_info{
	PDUs_t *pdu;
	long version;
	char *comm;	
	int error; // -1  == Fail || 0 == Want More || 1 == Sucess
}Pdu_Info;

void buffer_to_PDU(uint8_t *buffer_final, Pdu_Info *info);

long getVersion(Message_t *message);
char *getComm(Message_t *message);


#endif