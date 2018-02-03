#include <ApplicationSyntax.h>
#include <stdio.h>
#include <stdlib.h>

ApplicationSyntax_t* insert_ipAdress(IpAddress_t *value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_ipAddress_value;
  application->choice.ipAddress_value = *value;
  return application;
}

ApplicationSyntax_t* insert_counter_value(Counter32_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_counter_value;
  application->choice.counter_value = value;
  return application;
}

ApplicationSyntax_t* insert_timeticks_value(TimeTicks_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_timeticks_value;
  application->choice.timeticks_value = value;
  return application;
}

ApplicationSyntax_t* insert_arbitrary_value(Opaque_t *value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_arbitrary_value;
  application->choice.arbitrary_value = *value;
  return application;
}

ApplicationSyntax_t* insert_big_counter_value(Counter64_t *value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_big_counter_value;
  application->choice.big_counter_value = *value;
  return application;
}

ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_unsigned_integer_value;
  application->choice.unsigned_integer_value = value;
  return application;
}

ApplicationSyntax_t* create_application(int flag, const char* string, ApplicationSyntax_t* application) {
  unsigned long value;
  long valueLong;
  OCTET_STRING_t *str;
  INTEGER_t *i;
  int oc;
  application = calloc(1, sizeof(ApplicationSyntax_t));
  switch(flag) {
   case 4:
      str = calloc(1, sizeof(OCTET_STRING_t));
      oc = OCTET_STRING_fromBuf(str,string,-1);
      application = insert_ipAdress(str, application);
      break;
   case 5:
      value = strtoul(string, NULL, 0);
      application = insert_counter_value(value, application);
      break;
   case 6:
      value = strtoul(string, NULL, 0);
      application = insert_timeticks_value(value, application);
      break;
   case 7:
      str = calloc(1, sizeof(OCTET_STRING_t));
      oc = OCTET_STRING_fromBuf(str,string,-1);
      application = insert_arbitrary_value(str, application);
      break;
   case 8:
      i = calloc(1, sizeof(INTEGER_t));
      valueLong = atol(string);
      asn_long2INTEGER(i, valueLong);
      application = insert_big_counter_value(i, application);
      break;
    case 9:
      value = strtoul(string, NULL, 0);
      application = insert_unsigned_integer_value(value, application);
    }
    return application;
}
