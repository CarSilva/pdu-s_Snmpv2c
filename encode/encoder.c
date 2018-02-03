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
#include <fcntl.h>
#include <stdio.h>


uint8_t* setRequest(const char* flag, const char* version, const char* community, const char* tag,
                    const char* oid, const char* value, uint8_t *buffer_final) {
  FILE* fout = stdout;
  ObjectSyntax_t* object_syntax;
  SetRequest_PDU_t* setRequestPDU;
  PDUs_t* pdu;
  uint8_t* buffer;
  ANY_t* data;
  Message_t* message;
  int f = atoi(flag);
  int t = atoi(tag);
  if (f >=1 && f <=3) {
    SimpleSyntax_t* simple;
    simple = create_simple(f, value, simple);
    object_syntax = create_object(f, simple, NULL, object_syntax);
  }
  else if (f >=4 && f <=9) {
    ApplicationSyntax_t* application;
    application = create_application(f, value, application);
    object_syntax = create_object(f, NULL, application, object_syntax);
  }
  else {
    printf("%s\n", "Erro Erro!");
  }
  setRequestPDU =  setRequestPdu_create(object_syntax, oid, setRequestPDU, tag);
  pdu = create_pdu(setRequestPDU, pdu);
  buffer = calloc(1024, sizeof(uint8_t));
  asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu,
                                            buffer, sizeof(buffer));
  data = create_data(buffer, ret, data);
  message = create_message(data, version, community, message);
  buffer_final = calloc(1024, sizeof(uint8_t));
  asn_enc_rval_t ret2 = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message,
                                             buffer_final, sizeof(buffer_final));
  printf("Codificação mensagem:\n");
  xer_fprint(fout, &asn_DEF_Message, message);
  return buffer_final;
}

int main() {
  uint8_t *buffer_final;
  buffer_final = setRequest("2","ola","public","0", "1.2.3.4.0", "1", buffer_final);
  printf("Tamanho do buffer final: %d\n", sizeof(buffer_final));
  printf("Codificação buffer final: \n%02x %02x %02x %02x %02x %02x %02x %02x\n",
         buffer_final[0] & 0xff, buffer_final[1] & 0xff, buffer_final[2] & 0xff,
         buffer_final[3] & 0xff, buffer_final[4] & 0xff, buffer_final[5] & 0xff,
         buffer_final[6] & 0xff, buffer_final[7]);



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
