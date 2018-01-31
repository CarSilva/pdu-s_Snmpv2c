#ifndef SR_H_
#define SR_H_

SetRequest_PDU_t* setRequestPdu_create(ObjectSyntax_t* object_syntax, uint8_t* name, size_t name_size
                                      SetRequest_PDU_t* setRequestPDU, int requestID);

ObjectSyntax_t* object_c_simple(SimpleSyntax_t* simple, ObjectSyntax_t* object_syntax);

ObjectSyntax_t* object_create_application(ApplicationSintax_t* application, ObjectSyntax_t* object_syntax);

SimpleSyntax_t* insert_value(long value, SimpleSyntax_t* simple);

SimpleSyntax_t* insert_string(OCTET_STRING_t value, SimpleSyntax_t* simple);

SimpleSyntax_t* insert_string(OBJECT_IDENTIFIER_t value, SimpleSyntax_t* simple);

ApplicationSyntax_t* insert_ipAdress(IpAddress_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_counter_value(Counter32_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_timeticks_value(TimeTicks_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_arbitrary_value(Opaque_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_big_counter_value(Counter64_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t value, ApplicationSyntax_t* application);

#endif
