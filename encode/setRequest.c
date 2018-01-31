#include <SimpleSintax.h>
#include <ApplicationSintax.h>

//Eventualmente fará sentido criar um objectSintax.c, ApplicationSintax.c...
SetRequest_PDU_t* setRequestPdu_create(ObjectSyntax_t* object_syntax, uint8_t* name, size_t name_size
                                      SetRequest_PDU_t* setRequestPDU, int requestID) {
  ObjectName_t* object_name;
  object_name = calloc(1, sizeof(ObjectName_t));
  object_name->buf = name;
  object_name->size = name_size;
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

ObjectSyntax_t* object_c_simple(SimpleSyntax_t* simple, ObjectSyntax_t* object_syntax) {
  object_syntax->present = ObjectSyntax_PR_simple;
  object_syntax->choice.simple = *simple;
  return object_syntax;
}

ObjectSyntax_t* object_create_application(ApplicationSintax_t* application, ObjectSyntax_t* object_syntax) {
  object_syntax->present = ObjectSyntax_PR_application;
  object_syntax->choice.simple = *application;
  return object_syntax;
}

SimpleSyntax_t* insert_value(long value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_integer_value;
  simple->choice.integer_value = value;
  return simple;
}

SimpleSyntax_t* insert_string(OCTET_STRING_t value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_string_value;
  simple->choice.string_value = value;
  return simple;
}

SimpleSyntax_t* insert_string(OBJECT_IDENTIFIER_t value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_objectID_value;
  simple->choice.objectID_value  = value;
  return simple;
}

ApplicationSyntax_t* insert_ipAdress(IpAddress_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_ipAddress_value;
  application->choice.ipAddress_value = value;
  return application;
}

ApplicationSyntax_t* insert_counter_value(Counter32_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_counter_value;
  application->choice.counter_value = value;
  return application;
}

ApplicationSyntax_t* insert_timeticks_value(TimeTicks_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_timeticks_value;
  application->choice.timeticks_value = value;
  return application;
}

ApplicationSyntax_t* insert_arbitrary_value(Opaque_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_arbitrary_value;
  application->choice.arbitrary_value = value;
  return application;
}

ApplicationSyntax_t* insert_big_counter_value(Counter64_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_big_counter_value;
  application->choice.big_counter_value = value;
  return application;
}

ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_unsigned_integer_value;
  application->choice.unsigned_integer_value = value;
  return application;
}
