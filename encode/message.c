#include <PDUs.h>
#include <ANY.h>
#include <Message.h>

PDUs_t* create_pdu(SetRequest_PDU_t* setRequestPDU, PDUs_t *pdu) {
  pdu = calloc(1, sizeof(PDUs_t));
  pdu->present = PDUs_PR_set_request;
  pdu->choice.set_request = *setRequestPDU;
  return pdu;
}

ANY_t* create_data(uint8_t *buffer, asn_enc_rval_t ret, ANY_t *data){
  data = calloc(1, sizeof(ANY_t));
  data->buf = buffer;
  data->size = ret.encoded;
  return data;
}

Message_t* create_message(ANY_t* data, const char* version, const char* community, Message_t* message) {
  long v;
  OCTET_STRING_t *comm;
  message = calloc(1, sizeof(Message_t));
  v = atol(version);
  comm = calloc(1, sizeof(OCTET_STRING_t));
  int oc = OCTET_STRING_fromBuf(comm,community,-1);
  message->version = v;
  message->community = *comm;
  message->data = *data;
  return message;
}
