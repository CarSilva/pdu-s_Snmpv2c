#ifndef application_syntax_h
#define application_syntax_h

#include <ApplicationSyntax.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * Function that given a ApplicationSyntax and a IpAddress
 * fills the ApplicationSyntax variable with the IpAddress value
 */
ApplicationSyntax_t* insert_ipAdress(IpAddress_t*, ApplicationSyntax_t*);

/*
 * Function that given a ApplicationSyntax and a Counter32
 * fills the ApplicationSyntax variable with the Counter32 value
 */
ApplicationSyntax_t* insert_counter_value(Counter32_t, ApplicationSyntax_t*);

/*
 * Function that given a ApplicationSyntax and a TimeTicks
 * fills the ApplicationSyntax variable with the TimeTicks value
 */
ApplicationSyntax_t* insert_timeticks_value(TimeTicks_t, ApplicationSyntax_t*);

/*
 * Function that given a ApplicationSyntax and a Opaque
 * fills the ApplicationSyntax variable with the Opaque value
 */
ApplicationSyntax_t* insert_arbitrary_value(Opaque_t*, ApplicationSyntax_t*);

/*
 * Function that given a ApplicationSyntax and a Counter64
 * fills the ApplicationSyntax variable with the Counter64 value
 */
ApplicationSyntax_t* insert_big_counter_value(Counter64_t*, ApplicationSyntax_t*);

/*
 * Function that given a ApplicationSyntax and a Unsigned32
 * fills the ApplicationSyntax variable with the Unsigned32 value
 */
ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t, ApplicationSyntax_t*);

/*
 * Function that removes the dots from a OID string
 * and fills the uint8 array with the proper OID values
 */
int removeDots(char* oid, uint8_t* name);

/* 
 * Creates a OCTET_STRING and sets the fields buf and size with the oid string
 * information
 */
OCTET_STRING_t* create_octet_string(OCTET_STRING_t* oct, char *oid_text);

/*
 * Makes space for a new ApplicationSyntax instance.
 * Uses the int argument as a flag that tells 
 * what type of value to insert. The second argument
 * is the value itself and finaly the ApplicationSyntax variable
 */
ApplicationSyntax_t* create_application(int, char*, ApplicationSyntax_t*);

#endif
