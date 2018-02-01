#include <stdio.h>
#include <stdint.h>
#include <SimpleSyntax.h>
#include <ObjectSyntax.h>
#include <SetRequest-PDU.h>
#include <PDUs.h>
#include <ANY.h>
#include <Message.h>
#include <asn_application.h>
#include <asn_bit_data.h>
#include <string.h>
#include <simpleSyntax.h>
#include <applicationSyntax.h>
#include <objectSyntax.h>
#include <setRequestPDU.h>
#include <message.h>


int main() {
  //Exemplo simples para setRequest
  //Substituir nomes de algumas variáveis por o valor real
  SimpleSyntax_t* simple;
  simple = calloc(1, sizeof(SimpleSyntax_t));
  simple = insert_value(1, simple);

  ObjectSyntax_t* object_syntax;
  object_syntax = calloc(1, sizeof(ObjectSyntax_t));
  object_syntax = object_create_simple(simple, object_syntax);

  //arranjar maneira de string->uint8_t, assim acho que isto nao está bem.
  uint8_t* name;
  name = "1.2.3.4.0";
  SetRequest_PDU_t* setRequestPDU;
  setRequestPDU = calloc(1, sizeof(SetRequest_PDU_t));
  setRequestPDU =  setRequestPdu_create(object_syntax, name, sizeof(name), setRequestPDU, 1);

  PDUs_t* pdu;
  pdu = calloc(1, sizeof(PDUs_t));
  pdu = create_pdu(setRequestPDU, pdu);

  uint8_t* buffer;
  buffer = calloc(1024, sizeof(uint8_t));
  asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu,
                                            buffer, sizeof(buffer));

  ANY_t* data;
  data = calloc(1, sizeof(ANY_t));
  data = create_data(buffer, ret, data);

  //arranjar maneira de "public"-> OCTET_STRING_t, assim acho que isto nao está bem.
  Message_t* message;
  OCTET_STRING_t community;
  message = calloc(1, sizeof(Message_t));
  message = create_message(data, 2, community, message);

  uint8_t *buffer_final;
  buffer_final = calloc(1024, sizeof(uint8_t));
  asn_enc_rval_t ret2 = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message,
                                             buffer_final, sizeof(buffer_final));

  printf("%02x %02x %02x %02x %02x %02x\n",
            buffer_final[0] & 0xff, buffer_final[1] & 0xff, buffer_final[2] & 0xff,
            buffer_final[3] & 0xff, buffer_final[4] & 0xff, buffer_final[5] & 0xff);

  return 0;
}
