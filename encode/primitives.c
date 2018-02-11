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

long encoding(PDUs_t* pdu, long version, char* community, uint8_t buffer_final[]) {
  FILE* fout = stdout;
  uint8_t buffer[1010];
  ANY_t* data;
  Message_t* message;

  //teste
  printf("PUD: \n\n");
  xer_fprint(fout, &asn_DEF_PDUs, pdu);
  printf("\n\nEND PUD: \n\n");
  //end teste
  
  asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu,
                                            buffer, 1010);
  if(ret.encoded == -1) {
    printf("\n\nWarning: PDU truncated\n\n");
  }
  else if (ret.encoded > 1010) {
    printf("\n\nWarning: Too Big!\n\n");
  }
  data = create_data(buffer, ret, data);
  message = create_message(data, version, community, message);
  asn_enc_rval_t ret2 = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message,
                                             buffer_final, 1024);
  return ret2.encoded;
}

//id = 1
long getRequest(long version, char* community, long tag, char** oid, uint8_t buffer_final[]) {
  int size, i;
  long n;
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
  n = encoding(pdu, version, community, buffer_final);
  return n;
}

//id = 2
long getNextRequest(long version, char* community, long tag, char** oid, uint8_t buffer_final[]) {
  int size, i;
  long n;
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
  n = encoding(pdu, version, community, buffer_final);
  return n;
}


//id = 3
long getBulkRequest(long version, char* community, long tag, char** oid,
                    long non_repeaters, long	max_repetitions, uint8_t buffer_final[]) {
  int size, i;
  long n;
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
  n = encoding(pdu, version, community, buffer_final);
  return n;
}

//id = 4

long response(int flag[], long version, char* community, long tag, char**oid, long error_status,
              long index_error, char** value, int unSpecified, int noSuchObject, int noSuchInstance,
            	int endOfMibView, uint8_t buffer_final[]) {
  int size, i, j, sizeOID;
  long n;
  size = sizeArray(value);
  sizeOID = sizeArray(oid);
  i = j = 0;
  ObjectSyntax_t* object_syntax;
  VarBind_t* var_bind;
  VarBindList_t* varlist = malloc(sizeof(VarBindList_t));
  Response_PDU_t* ResponsePDU;
  PDUs_t* pdu;

  while(i != sizeOID){
      if (flag[i] == 11 ) {
        var_bind = create_varbind_unspecified(oid[i], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else if(flag[i] == 12) {
        var_bind = create_varbind_noSuchObject(oid[i], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else if(flag[i] == 13) {
        var_bind = create_varbind_noSuchInstance(oid[i], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else if(flag[i] == 14){
        var_bind = create_varbind_endOfMibView(oid[i], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else{
        object_syntax = decide_object(flag[i], value[i], object_syntax);
        var_bind = create_varbind_value(object_syntax, oid[i], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      i++;
  }/*

  if(size == 0) {
    while(j != sizeOID){
      if (unSpecified != 0) {
        var_bind = create_varbind_unspecified(oid[0], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else if(noSuchObject != 0) {
        var_bind = create_varbind_noSuchObject(oid[0], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else if(noSuchInstance != 0) {
        var_bind = create_varbind_noSuchInstance(oid[0], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      else {
        var_bind = create_varbind_endOfMibView(oid[0], var_bind);
        varlist = add_to_varBindList(var_bind, varlist);
      }
      j++;
    }
  }
  else {
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
  }*/
  ResponsePDU = create_pdu(ResponsePDU, tag, error_status, index_error, varlist);
  pdu = create_response_pdu(pdu, ResponsePDU);
  n = encoding(pdu, version, community, buffer_final);
  return n;
}

long responseSuccess(int flag[], long version, char* community, long tag, char**oid, long error_status,
              long index_error, char** value, uint8_t buffer_final[]) {
  long n;
  n = response(flag, version, community, tag, oid, error_status, index_error, value, 0, 0, 0, 0, buffer_final);
  return n;
}

long responseUnspecified(int flag[], long version, char* community, long tag, char**oid, long error_status,
              long index_error, char** value, uint8_t buffer_final[]) {
  long n;
  n = response(flag, version, community, tag, oid, error_status, index_error, value, 1, 0, 0, 0, buffer_final);
  return n;
}


long responseNoSuchObject(int flag[], long version, char* community, long tag, char**oid, long error_status,
              long index_error, char** value, uint8_t buffer_final[]) {
  long n;
  n = response(flag, version, community, tag, oid, error_status, index_error, value, 0, 2, 0, 0, buffer_final);
  return n;
}

long responseNoSuchInstance(int flag[], long version, char* community, long tag, char**oid, long error_status,
              long index_error, char** value, uint8_t buffer_final[]) {
  long n;
  n = response(flag, version, community, tag, oid, error_status, index_error, value, 0, 0, 3, 0, buffer_final);
  return n;
}

long responseEndOfMibView(int flag[], long version, char* community, long tag, char**oid, long error_status,
              long index_error, char** value, uint8_t buffer_final[]) {
  long n;
  n = response(flag, version, community, tag, oid, error_status, index_error, value, 0, 0, 0, 4, buffer_final);
  return n;
}


//id = 5
long setRequest(int flag[], long version, char* community, long tag,
                    char** oid, char** value, uint8_t buffer_final[]) {
  int size, i;
  long n;
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
  n = encoding(pdu, version, community, buffer_final);
  return n;
}


//id = 6
long informRequest(long version, char* community, long tag, char** oid, uint8_t buffer_final[]) {
  int size, i;
  long n;
  size = sizeArray(oid);
  i = 0;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  InformRequest_PDU_t* informRequestPDU;
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
  informRequestPDU = create_pdu(informRequestPDU, tag, 0, 0, varlist);
  pdu = create_getRequest_pdu(pdu, informRequestPDU);
  n = encoding(pdu, version, community, buffer_final);
  return n;
}

//id = 7

long trap(long version, char* community, long tag, char** oid, uint8_t buffer_final[]) {
  int size, i;
  long n;
  size = sizeArray(oid);
  i = 0;
  VarBind_t* var_bind;
  VarBindList_t* varlist;
  SNMPv2_Trap_PDU_t* snmpPDU;
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
  snmpPDU = create_pdu(snmpPDU, tag, 0, 0, varlist);
  pdu = create_getRequest_pdu(pdu, snmpPDU);
  n = encoding(pdu, version, community, buffer_final);
  return n;
}
