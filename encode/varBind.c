#include <varBind.h>
#include <objectName.h>

VarBind_t* add_oid_to_varbind(char* oid, VarBind_t* var_bind) {
  ObjectName_t* object_name;
  object_name = create_object_name(object_name, oid);
  var_bind = calloc(1, sizeof(VarBind_t));
  var_bind->name = *object_name;
}

VarBind_t* create_varbind_value(ObjectSyntax_t* object_syntax, char* oid, VarBind_t* var_bind) {
  var_bind = add_oid_to_varbind(oid, var_bind);
  var_bind->choice.present = choice_PR_value;
  var_bind->choice.choice.value = *object_syntax;
  return var_bind;
}

VarBind_t* create_varbind_unspecified(char* oid, VarBind_t* var_bind) {
  var_bind = add_oid_to_varbind(oid, var_bind);
  var_bind->choice.present = choice_PR_unSpecified;
  var_bind->choice.choice.unSpecified = 1;
  return var_bind;
}

VarBind_t* create_varbind_noSuchObject(char* oid, VarBind_t* var_bind) {
  var_bind = add_oid_to_varbind(oid, var_bind);
  var_bind->choice.present = choice_PR_noSuchObject;
  var_bind->choice.choice.noSuchObject = 1;
  return var_bind;
}

VarBind_t* create_varbind_noSuchInstance(char* oid, VarBind_t* var_bind) {
  var_bind = add_oid_to_varbind(oid, var_bind);
  var_bind->choice.present = choice_PR_noSuchInstance;
  var_bind->choice.choice.noSuchInstance = 1;
  return var_bind;
}


VarBind_t* create_varbind_endOfMibView(char* oid, VarBind_t* var_bind) {
  var_bind = add_oid_to_varbind(oid, var_bind);
  var_bind->choice.present = choice_PR_endOfMibView;
  var_bind->choice.choice.endOfMibView = 1;
  return var_bind;
}

VarBind_t* create_varbind_empty(char* oid, VarBind_t* var_bind) {
  var_bind = add_oid_to_varbind(oid, var_bind);
  var_bind->choice.present = choice_PR_NOTHING;
  return var_bind;
}
