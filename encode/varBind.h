#ifndef SR_H_
#define SR_H_

VarBind_t* add_oid_to_varbind(const char* oid, VarBind_t* var_bind);

VarBind_t* create_varbind_value(ObjectSyntax_t* object_syntax, const char* oid, VarBind_t* var_bind);

VarBind_t* create_varbind_unspecified(const char* oid, VarBind_t* var_bind);

VarBind_t* create_varbind_noSuchObject(const char* oid, VarBind_t* var_bind);

VarBind_t* create_varbind_noSuchInstance(const char* oid, VarBind_t* var_bind);

VarBind_t* create_varbind_endOfMibView(const char* oid, VarBind_t* var_bind);

VarBind_t* create_varbind_empty(const char* oid, VarBind_t* var_bind);

#endif
