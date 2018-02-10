#ifndef object_name_h
#define object_name_h

#include <stdio.h>
#include <stdint.h>
#include <ObjectName.h>
/*
 * Given a string (char *) containing the OID value, this function
 * parses the string (takes out dots) and fills the uint8_t array with
 * the values
 */
int fill_oid(char*, uint8_t*);

/*
 * Creates a object Name, given a char* (string).
 * Normally this string is the OID value
 */
ObjectName_t* create_object_name(ObjectName_t*, char*);

#endif
