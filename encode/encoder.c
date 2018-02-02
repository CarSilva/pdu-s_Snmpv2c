#include <stdio.h>
#include <stdint.h>
#include <SimpleSyntax.h>
#include <ObjectSyntax.h>
#include <SetRequest-PDU.h>
#include <PDUs.h>
#include <ANY.h>
#include <Message.h>
#include <VarBindList.h>
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
  SetRequest_PDU_t* setRequestPDU;
  setRequestPDU = calloc(1, sizeof(SetRequest_PDU_t));
  setRequestPDU =  setRequestPdu_create(object_syntax, "1.2.3.4.0", setRequestPDU, 1);

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


  /*TESTE DECODE

    Message_t *messaged = 0;

    asn_dec_rval_t rval1 = asn_decode(0, ATS_BER, &asn_DEF_Message,
                                    (void **)&messaged, buffer_final, sizeof(buffer_final)); //tratar erro se der -1
    if(rval1.code ==  RC_FAIL){ //significa que a descodificaçaºo falhou, está a entrar no if nao sei bem porque
        printf("fail\n");
    }
    printf("Message_SIZE = %d\n",messaged->data.size );

    PDUs_t* pdud = 0;
    asn_dec_rval_t rval2 = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
                                    (void **)&pdud, messaged->data.buf, messaged->data.size); //tratar erro se der -1
    if(rval2.code ==  RC_WMORE){ //significa que a descodificaçaºo falhou, está a entrar no if nao sei bem porque
        printf("Want More info\n");
    }
    VarBindList_t var_bindingsd = pdud->choice.set_request.variable_bindings;

    printf("List_VarBindings_Size = %d\n", var_bindingsd.list.count);

    VarBind_t* var_bindd = var_bindingsd.list.array[0];

    ObjectName_t* object_named = &(var_bindd->name);
    ObjectSyntax_t* object_syntaxd = &(var_bindd->choice.choice.value);
    printf("Object-name-> buf  = %s\n", object_named->buf);



  return 0;
  */
}
