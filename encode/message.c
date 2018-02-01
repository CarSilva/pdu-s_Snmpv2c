#include <PDUs.h>
#include <ANY.h>
#include <Message.h>

PDUs_t* create_pdu(SetRequest_PDU_t* setRequestPDU, PDUs_t *pdu) {
  pdu->present = PDUs_PR_set_request;
  pdu->choice.set_request = *setRequestPDU;
  return pdu;
}

ANY_t* create_data(uint8_t *buffer, asn_enc_rval_t ret, ANY_t *data){
  data->buf = buffer;
  data->size = ret.encoded;
  return data;
}

Message_t* create_message(ANY_t* data, long version, OCTET_STRING_t community, Message_t* message) {
  message->version = version;
  message->community = community;
  message->data = *data;
  return message;
}
