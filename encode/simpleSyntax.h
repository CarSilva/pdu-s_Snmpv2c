#ifndef simple_syntax_h
#define simple_syntax_h

#include <SimpleSyntax.h>
#include <stdlib.h>

/*
 * Function that given a SimpleSyntax and a long value 
 * fills the SimpleSyntax variable with the long value
 */
SimpleSyntax_t* insert_value(long, SimpleSyntax_t*);

/*
 * Function that given a SimpleSyntax and a OCTET_STRING value 
 * fills the SimpleSyntax variable with the OCTET_STRING_t value
 */
SimpleSyntax_t* insert_string(OCTET_STRING_t*, SimpleSyntax_t*);

/*
 * Function that given a SimpleSyntax and a OBJECT_IDENTIFIER value 
 * fills the SimpleSyntax variable with the OID value
 */
SimpleSyntax_t* insert_oid(OBJECT_IDENTIFIER_t*, SimpleSyntax_t*);

/*
 * Given a string (char *) containing the OID value, this function
 * parses the string (takes out dots) and fills the uint8_t array with
 * the values
 */
int fill(char* oid, uint8_t* name);

/*
 * Encodes OID to a OBJECT_IDENTIFIER
 */
OBJECT_IDENTIFIER_t* encode_OID(OBJECT_IDENTIFIER_t*, char*);

/*
 * Makes space for a new SimpleSyntax instance.
 * Uses the int argument as a flag that tells 
 * what type of value to insert. The second argument
 * is the value itself and finaly the SimpleSyntax variable
 */
SimpleSyntax_t* create_simple(int, char*, SimpleSyntax_t*);

#endif
