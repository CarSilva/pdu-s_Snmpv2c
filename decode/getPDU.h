#ifndef _GetPDU_H_
#define _GetPDU_H_

#include <Message.h>
#include <PDUs.h>

PDUs_t *buffer_to_PDU(uint8_t *buffer_final);

const char *getVersion(Message_t *message);
const char *getComm(Message_t *message);


#endif