#ifndef SR_H_
#define SR_H_

ObjectSyntax_t* decide_object(const char* flag, const char* value, ObjectSyntax_t* object_syntax);
uint8_t* encoding(PDUs_t* pdu, const char* version, const char* community, uint8_t* buffer_final);
uint8_t* setRequest(const char* flag, const char* version, const char* community, const char* tag,
                    const char* oid, const char* value, uint8_t *buffer_final);

#endif
