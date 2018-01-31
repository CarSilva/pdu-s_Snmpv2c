#include <stdio.h>
#include <setRequest.h>

int main() {
  //Exemplo simples para setRequest
  //Substituir nomes de algumas variáveis por o valor real
  SimpleSyntax_t* simple;
  simple = calloc(1, sizeof(SimpleSyntax_t));
  simple = insert_value(1, simple);

  ObjectSyntax_t* object_syntax;
  object_syntax = calloc(1, sizeof(ObjectSyntax_t));
  object_syntax = object_c_simple(simple, object_syntax);

  SetRequest_PDU_t* setRequestPDU;
  setRequestPDU = calloc(1, sizeof(GetRequest_PDU_t));
  setRequestPDU =  setRequestPdu_create(object_syntax, name, name_size, setRequestPDU, requestID);

  PDUs_t *pdu;
  pdu = calloc(1, sizeof(PDUs_t));
  pdu = create_pdu(setRequestPDU, pdu);

  uint8_t *buffer;
  buffer = calloc(1, sizeof(uint8_t));
  asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu,
                                            buffer, 1);

  ANY_t *data;
  data = calloc(1, sizeof(ANY_t));
  data = create_data(buffer, ret, data);

  Message_t* message;
  message = calloc(1, sizeof(Message_t));
  message = create_message(data, version, community, message)

  uint8_t *buffer_final;
  buffer_final = calloc(1, sizeof(uint8_t));
  asn_enc_rval_t ret2 = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message,
                                             buffer_final, buffer_final_size);
  printf(buffer_final);
  return 0;
}


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

Message_t* create_message(ANY_t* data, long version, OCTECT_STRING_t community, Message_t* message) {
  message->version = version;
  message->community = community;
  message->data = *data;
  return message;
}
