#ifndef SR_H_
#define SR_H_

SimpleSyntax_t* insert_value(long value, SimpleSyntax_t* simple);

SimpleSyntax_t* insert_string(OCTET_STRING_t value, SimpleSyntax_t* simple);

SimpleSyntax_t* insert_oid(OBJECT_IDENTIFIER_t value, SimpleSyntax_t* simple);

OBJECT_IDENTIFIER_t* encode_OID(OBJECT_IDENTIFIER_t *oid, const char *oid_text);

SimpleSyntax_t* create_simple(int flag, const char* string, SimpleSyntax_t* simple);

#endif
