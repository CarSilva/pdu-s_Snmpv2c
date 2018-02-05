#include <Message.h>
#include <PDUs.h>
#include <getPDU.h>


Pdu_Info *buffer_to_PDU(uint8_t *buffer_final){
	Message_t *message = calloc(1, sizeof(Message_t));
	printf("%d\n", message->data.size);
	asn_dec_rval_t rval1 = asn_decode(0, ATS_BER, &asn_DEF_Message,
                                    (void **)&message, buffer_final, sizeof(buffer_final));
	switch(rval1.code){
		case RC_FAIL:
		case RC_WMORE:
			return NULL;
	}
    PDUs_t* pdu = calloc(1, sizeof(PDUs_t));
    asn_dec_rval_t rval2 = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
                                    (void **)&pdu, message->data.buf, message->data.size);
    switch(rval2.code){
		case RC_FAIL:
		case RC_WMORE:
			return NULL;
	}
	Pdu_Info *info = malloc(sizeof(struct pdu_info));
	info->pdu = pdu;
	info->version = getVersion(message);
	info->comm = getComm(message);
    return info;
}

char *getVersion(Message_t *message){
	return (char *)message->version;
}

char * getComm(Message_t *message){
	char *str = (char *) message->community.buf;
	char *final = malloc(1024);

	snprintf(final, 1024, "%s%c", str, '\0');
	return final;
}


