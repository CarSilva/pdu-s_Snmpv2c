#ifndef object_name_h
#define object_name_h

#include <stdio.h>
#include <stdint.h>
#include <ObjectName.h>

uint8_t* fill_oid(char*, uint8_t*);

ObjectName_t* create_object_name(ObjectName_t*, char*);

#endif
