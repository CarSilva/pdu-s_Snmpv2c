#ifndef SR_H_
#define SR_H_

PDUs_t* create_pdu(SetRequest_PDU_t* setRequestPDU, PDUs_t *pdu);

ANY_t* create_data(uint8_t *buffer, asn_enc_rval_t ret, ANY_t *data);

Message_t* create_message(ANY_t* data, long version, OCTET_STRING_t community, Message_t* message);

#endif
