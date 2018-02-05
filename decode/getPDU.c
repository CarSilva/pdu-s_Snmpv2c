#include <Message.h>
#include <PDUs.h>


PDUs_t *buffer_to_PDU(uint8_t *buffer_final){
	Message_t *message = calloc(1, sizeof(Message_t));
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
    return pdu;
}

const char *getVersion(Message_t *message){
	return (const char *)message->version;
}

OCTET_STRING_t getComm(Message_t *message){
	return message->community;
}


