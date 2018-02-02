#ifndef SR_H_
#define SR_H_

ApplicationSyntax_t* insert_ipAdress(IpAddress_t *value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_counter_value(Counter32_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_timeticks_value(TimeTicks_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_arbitrary_value(Opaque_t *value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_big_counter_value(Counter64_t *value, ApplicationSyntax_t* application);

ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t value, ApplicationSyntax_t* application);

ApplicationSyntax_t* create_application(int flag, const char* string);

#endif
