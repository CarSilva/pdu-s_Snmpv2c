#include <simpleSyntax.h>
#include <applicationSyntax.h>
#include <objectSyntax.h>
#include <varBind.h>
#include <varBindList.h>
#include <pdu.h>
#include <pdus.h>
#include <message.h>
#include <primitives.h>

int sizeArray(char** array) {
  int count = 0;
  while (array[count] != NULL) count++;
  return count;
}

ObjectSyntax_t* decide_object(int flag, char* value, ObjectSyntax_t* object_syntax) {
  if (flag >=1 && flag <=3) {
    SimpleSyntax_t* simple;
    simple = create_simple(flag, value, simple);
    object_syntax = create_simple_object(simple, object_syntax);
  }
  else if (flag >=4 && flag <=9) {
    ApplicationSyntax_t* application;
    application = create_application(flag, value, application);
    object_syntax = create_application_object(application, object_syntax);
  }
  else {
    printf("%s\n", "Erro!");
  }
  return object_syntax;
}

uint8_t* encoding(PDUs_t* pdu, long version, char* community, uint8_t* buffer_final) {
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
  FILE* fout = stdout;
  xer_fprint(fout, &asn_DEF_Message, message);
  return buffer_final;
}

//id = 1
uint8_t* getRequest(long version, char* community, long tag, char** oid, uint8_t* buffer_final) {
  int size, i;
  size = sizeArray(oid);
  i = 0;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  GetRequest_PDU_t* getRequestPDU;
  PDUs_t* pdu;
  while(i != size) {
    var_bind = create_varbind_empty(oid[i], var_bind);
    if(i == 0) {
      varlist = create_varBindList(var_bind, varlist);
    }
    else {
      varlist = add_to_varBindList(var_bind, varlist);
    }
    i++;
  }
  getRequestPDU = create_pdu(getRequestPDU, tag, 0, 0, varlist);
  pdu = create_getRequest_pdu(pdu, getRequestPDU);
  buffer_final = encoding(pdu, version, community, buffer_final);
  return buffer_final;
}

//id = 2
/*
Questão: create_varbind_empty ????
*/
uint8_t* getNextRequest(long version, char* community, long tag, char** oid, uint8_t* buffer_final) {
  int size, i;
  size = sizeArray(oid);
  i = 0;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  GetNextRequest_PDU_t* getNextRequestPDU;
  PDUs_t* pdu;
  while(i != size) {
    var_bind = create_varbind_empty(oid[i], var_bind);
    if(i == 0) {
      varlist = create_varBindList(var_bind, varlist);
    }
    else {
      varlist = add_to_varBindList(var_bind, varlist);
    }
    i++;
  }
  getNextRequestPDU = create_pdu(getNextRequestPDU, tag, 0, 0, varlist);
  pdu = create_getNextRequest_pdu(pdu, getNextRequestPDU);
  buffer_final = encoding(pdu, version, community, buffer_final);
  return buffer_final;
}

//id = 3
uint8_t* getBulkRequest(long version, char* community, long tag, char** oid,
                        long non_repeaters, long	max_repetitions, uint8_t* buffer_final) {
  int size, i;
  size = sizeArray(oid);
  i = 0;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  GetBulkRequest_PDU_t* getBulkRequestPDU;
  PDUs_t* pdu;
  while(i != size) {
    var_bind = create_varbind_empty(oid[i], var_bind);
    if(i == 0) {
      varlist = create_varBindList(var_bind, varlist);
    }
    else {
      varlist = add_to_varBindList(var_bind, varlist);
    }
    i++;
  }
  getBulkRequestPDU = create_bulk_pdu(getBulkRequestPDU, tag, non_repeaters, max_repetitions, varlist);
  pdu = create_getBulkRequest_pdu(pdu, getBulkRequestPDU);
  buffer_final = encoding(pdu, version, community, buffer_final);
  return buffer_final;
}

//id = 4
/*
If the error-status field of the Response-PDU is non-zero, the value
fields of the variable bindings in the variable binding list are
ignored.

If both the error-status field and the error-index field of the
Response-PDU are non-zero
Questão: Temos que fazer uma api apropriada para cada caso, ou um response geral capaz de receber todos os valores
*/
uint8_t* response(int flag[], long version, char* community, long tag, char**oid, long error_status,
                  long index_error, char** value, uint8_t* buffer_final) {
  int size, i;
  size = sizeArray(value);
  i = 0;
  ObjectSyntax_t* object_syntax;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  Response_PDU_t* ResponsePDU;
  PDUs_t* pdu;
  while(i != size) {
    object_syntax = decide_object(flag[i], value[i], object_syntax);
    var_bind = create_varbind_value(object_syntax, oid[i], var_bind);
    if(i == 0) {
      varlist = create_varBindList(var_bind, varlist);
    }
    else {
      varlist = add_to_varBindList(var_bind, varlist);
    }
    i++;
  }
  ResponsePDU = create_pdu(ResponsePDU, tag, error_status, index_error, varlist);
  pdu = create_response_pdu(pdu, ResponsePDU);
  buffer_final = encoding(pdu, version, community, buffer_final);
  return buffer_final;
}


//id = 5
uint8_t* setRequest(int flag[], long version, char* community, long tag,
                    char** oid, char** value, uint8_t *buffer_final) {
  int size, i;
  size = sizeArray(value);
  i = 0;
  ObjectSyntax_t* object_syntax;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  SetRequest_PDU_t* setRequestPDU;
  PDUs_t* pdu;
  while(i != size) {
    object_syntax = decide_object(flag[i], value[i], object_syntax);
    var_bind = create_varbind_value(object_syntax, oid[i], var_bind);
    if(i == 0) {
      varlist = create_varBindList(var_bind, varlist);
    }
    else {
      varlist = add_to_varBindList(var_bind, varlist);
    }
    i++;
  }
  setRequestPDU =  create_pdu(setRequestPDU, tag, 0, 0, varlist);
  pdu = create_setRequest_pdu(pdu, setRequestPDU);
  buffer_final = encoding(pdu, version, community, buffer_final);
  return buffer_final;
}

/*
InformRequest
Trap

PDU is sent is specified by the notification originator application.  The first two variable
bindings in the variable binding list of an InformRequest-PDU are
sysUpTime.0 [RFC3418] and snmpTrapOID.0
*/
//id = 6
