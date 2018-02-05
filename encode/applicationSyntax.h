#ifndef application_syntax_h
#define application_syntax_h

#include <ApplicationSyntax.h>
#include <stdio.h>
#include <stdlib.h>

ApplicationSyntax_t* insert_ipAdress(IpAddress_t*, ApplicationSyntax_t*);

ApplicationSyntax_t* insert_counter_value(Counter32_t, ApplicationSyntax_t*);

ApplicationSyntax_t* insert_timeticks_value(TimeTicks_t, ApplicationSyntax_t*);

ApplicationSyntax_t* insert_arbitrary_value(Opaque_t*, ApplicationSyntax_t*);

ApplicationSyntax_t* insert_big_counter_value(Counter64_t*, ApplicationSyntax_t*);

ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t, ApplicationSyntax_t*);

int removeDots(char* oid, uint8_t* name);

OCTET_STRING_t* create_octet_string(OCTET_STRING_t* oct, char *oid_text);

ApplicationSyntax_t* create_application(int, char*, ApplicationSyntax_t*);

#endif
