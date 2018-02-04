#ifndef SR_H_
#define SR_H_

uint8_t* fill_oid(const char* oid, uint8_t* name);

ObjectName_t* create_object_name(ObjectName_t* object_name, const char* oid);

#endif
