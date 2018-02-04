#include <stdio.h>
#include <stdint.h>
#include <SimpleSyntax.h>
#include <ApplicationSyntax.h>
#include <ObjectSyntax.h>
#include <VarBind.h>
#include <VarBindList.h>
#include <PDU.h>
#include <PDUs.h>
#include <ANY.h>
#include <Message.h>
#include <asn_application.h>
#include <simpleSyntax.h>
#include <applicationSyntax.h>
#include <varBind.h>
#include <varBindList.h>
#include <pdu.h>
#include <pdus.h>
#include <message.h>

ObjectSyntax_t* decide_object(const char* flag, const char* value, ObjectSyntax_t* object_syntax) {
  int f = atoi(flag);
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
  return object_syntax;
}

uint8_t* encoding(PDUs_t* pdu, const char* version, const char* community, uint8_t* buffer_final) {
  uint8_t* buffer;
  ANY_t* data;
  Message_t* message;
  buffer = calloc(1024, sizeof(uint8_t));
  asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu,
                                            buffer, sizeof(buffer));
  data = create_data(buffer, ret, data);
  message = create_message(data, version, community, message);
  buffer_final = calloc(1024, sizeof(uint8_t));
  asn_enc_rval_t ret2 = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message,
                                             buffer_final, sizeof(buffer_final));
  return buffer_final;
}


//id = 5
uint8_t* setRequest(const char* flag, const char* version, const char* community, const char* tag,
                    const char* oid, const char* value, uint8_t *buffer_final) {
  ObjectSyntax_t* object_syntax;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  SetRequest_PDU_t* setRequestPDU;
  PDUs_t* pdu;
  object_syntax = decide_object(flag, value, object_syntax);
  var_bind = create_varbind_value(object_syntax, oid, var_bind);
  varlist = create_varBindList(var_bind, varlist);
  setRequestPDU =  create_pdu(setRequestPDU, 5, 0, 0, varlist);
  pdu = create_setRequest_pdu(pdu, setRequestPDU);
  buffer_final = encoding(pdu, version, community, buffer_final);
  return buffer_final;
}
