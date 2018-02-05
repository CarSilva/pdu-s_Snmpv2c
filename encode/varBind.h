#ifndef var_bind_h
#define var_bind_h

#include <stdio.h>
#include <stdint.h>
#include <ObjectName.h>
#include <ObjectSyntax.h>
#include <VarBind.h>

VarBind_t* add_oid_to_varbind(char*, VarBind_t*);

VarBind_t* create_varbind_value(ObjectSyntax_t*, char*, VarBind_t*);

VarBind_t* create_varbind_unspecified(char*, VarBind_t*);

VarBind_t* create_varbind_noSuchObject(char*, VarBind_t*);

VarBind_t* create_varbind_noSuchInstance(char*, VarBind_t*);

VarBind_t* create_varbind_endOfMibView(char*, VarBind_t*);

VarBind_t* create_varbind_empty(char*, VarBind_t*);

#endif
