#include <message.h>


ANY_t* create_data(uint8_t *buffer, asn_enc_rval_t ret, ANY_t *data){
  data = calloc(1, sizeof(ANY_t));
  data->buf = buffer;
  data->size = ret.encoded;
  return data;
}

Message_t* create_message(ANY_t* data, long version, char* community, Message_t* message) {
  OCTET_STRING_t *comm;
  message = calloc(1, sizeof(Message_t));
  comm = calloc(1, sizeof(OCTET_STRING_t));
  int oc = OCTET_STRING_fromBuf(comm,community,-1);
  message->version = version;
  message->community = *comm;
  message->data = *data;
  return message;
}
