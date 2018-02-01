#include <ApplicationSyntax.h>

ApplicationSyntax_t* insert_ipAdress(IpAddress_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_ipAddress_value;
  application->choice.ipAddress_value = value;
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

ApplicationSyntax_t* insert_arbitrary_value(Opaque_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_arbitrary_value;
  application->choice.arbitrary_value = value;
  return application;
}

ApplicationSyntax_t* insert_big_counter_value(Counter64_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_big_counter_value;
  application->choice.big_counter_value = value;
  return application;
}

ApplicationSyntax_t* insert_unsigned_integer_value(Unsigned32_t value, ApplicationSyntax_t* application) {
  application->present = ApplicationSyntax_PR_unsigned_integer_value;
  application->choice.unsigned_integer_value = value;
  return application;
}
