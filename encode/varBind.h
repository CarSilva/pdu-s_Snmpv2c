#ifndef var_bind_h
#define var_bind_h

#include <stdio.h>
#include <stdint.h>
#include <ObjectName.h>
#include <ObjectSyntax.h>
#include <VarBind.h>

/*
 * Adds the oid value to the field VarBind->name the object_name 
 * containing the oid value
 */
VarBind_t* add_oid_to_varbind(char*, VarBind_t*);

/*
 * Creates a VarBind and fills it with a ObjectSyntax and the OID value
 */
VarBind_t* create_varbind_value(ObjectSyntax_t*, char*, VarBind_t*);

/*
 * Creates a VarBind and fills it with a unspecified response and the OID value
 */
VarBind_t* create_varbind_unspecified(char*, VarBind_t*);

/*
 * Creates a VarBind and fills it with a no such object response and the OID value
 */
VarBind_t* create_varbind_noSuchObject(char*, VarBind_t*);

/*
 * Creates a VarBind and fills it with a no such instance response and the OID value
 */
VarBind_t* create_varbind_noSuchInstance(char*, VarBind_t*);

/*
 * Creates a VarBind and fills it with a end of mub view response and the OID value
 */
VarBind_t* create_varbind_endOfMibView(char*, VarBind_t*);

/*
 * Creates a VarBind and fills it with a empty response and the OID value
 */
VarBind_t* create_varbind_empty(char*, VarBind_t*);

#endif
