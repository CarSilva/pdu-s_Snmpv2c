#ifndef simple_syntax_h
#define simple_syntax_h

#include <SimpleSyntax.h>
#include <stdlib.h>

SimpleSyntax_t* insert_value(long, SimpleSyntax_t*);

SimpleSyntax_t* insert_string(OCTET_STRING_t*, SimpleSyntax_t*);

SimpleSyntax_t* insert_oid(OBJECT_IDENTIFIER_t*, SimpleSyntax_t*);

int fill(char* oid, uint8_t* name);

OBJECT_IDENTIFIER_t* encode_OID(OBJECT_IDENTIFIER_t*, char*);

SimpleSyntax_t* create_simple(int, char*, SimpleSyntax_t*);

#endif
