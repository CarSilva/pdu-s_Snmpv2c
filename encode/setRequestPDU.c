#include <stdio.h>
#include <stdint.h>
#include <SetRequest-PDU.h>
#include <ObjectSyntax.h>

SetRequest_PDU_t* setRequestPdu_create(ObjectSyntax_t* object_syntax, const char* oid,
                                      SetRequest_PDU_t* setRequestPDU, int requestID) {
  uint8_t* name;
  name = calloc(1024, sizeof(uint8_t));
  name = (uint8_t*) oid;
  ObjectName_t* object_name;
  object_name = calloc(1, sizeof(ObjectName_t));
  object_name->buf = name;
  object_name->size = sizeof(name);
  VarBind_t* var_bind;
  var_bind = calloc(1, sizeof(VarBind_t));
  var_bind->name = *object_name;
  var_bind->choice.present = choice_PR_value;
  var_bind->choice.choice.value = *object_syntax;
  VarBindList_t* varlist;
  varlist = calloc(1, sizeof(VarBindList_t));
  int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
  setRequestPDU->request_id = requestID;
  setRequestPDU->error_index = 0;
  setRequestPDU->error_status = 0;
  setRequestPDU->variable_bindings = *varlist;
}
