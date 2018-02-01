#include <ObjectSyntax.h>

ObjectSyntax_t* object_create_simple(SimpleSyntax_t* simple, ObjectSyntax_t* object_syntax) {
  object_syntax->present = ObjectSyntax_PR_simple;
  object_syntax->choice.simple = *simple;
  return object_syntax;
}

ObjectSyntax_t* object_create_application(ApplicationSyntax_t* application_wide, ObjectSyntax_t* object_syntax) {
  object_syntax->present = ObjectSyntax_PR_application_wide;
  object_syntax->choice.application_wide = *application_wide;
  return object_syntax;
}
