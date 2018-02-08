#include <Message.h>
#include <PDUs.h>
#include <getPDU.h>


void buffer_to_PDU(uint8_t *buffer_final, Pdu_Info *info){
	Message_t *message = calloc(1, sizeof(Message_t));
	asn_dec_rval_t rval1 = asn_decode(0, ATS_BER, &asn_DEF_Message,
                                    (void **)&message, buffer_final, 1024);

	switch(rval1.code){
		case RC_FAIL:
			info->error = -1;
			return;
		case RC_WMORE:
			info->error = 0;
			return;
		case RC_OK:
			info->error = 1;
			break;
	}
    PDUs_t* pdu = calloc(1, sizeof(PDUs_t));
    asn_dec_rval_t rval2 = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
                                    (void **)&pdu, message->data.buf, message->data.size);
    switch(rval2.code){
		case RC_FAIL:
			info->error = -1;
			return;
		case RC_WMORE:
			info->error = 0;
			return;
		case RC_OK:
			info->error = 1;
			break;
	}
	info->pdu = pdu;
	//FILE* fout = stdout;
	//xer_fprint(fout, &asn_DEF_Message, message);
	info->version = getVersion(message);
	info->comm = getComm(message);
}

long getVersion(Message_t *message){
	return message->version;
}

char * getComm(Message_t *message){
	char *str = (char *) message->community.buf;
	return str;
}
