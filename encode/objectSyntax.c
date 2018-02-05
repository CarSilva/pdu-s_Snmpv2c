#include <objectSyntax.h>

ObjectSyntax_t* create_simple_object(SimpleSyntax_t* simple, ObjectSyntax_t* object_syntax) {
  object_syntax = calloc(1, sizeof(ObjectSyntax_t));
  object_syntax->present = ObjectSyntax_PR_simple;
  object_syntax->choice.simple = *simple;
  return object_syntax;
}

ObjectSyntax_t* create_application_object(ApplicationSyntax_t* application_wide, ObjectSyntax_t* object_syntax) {
  object_syntax = calloc(1, sizeof(ObjectSyntax_t));
  object_syntax->present = ObjectSyntax_PR_application_wide;
  object_syntax->choice.application_wide = *application_wide;
  return object_syntax;
}


ObjectSyntax_t* create_empty_object(ObjectSyntax_t* object_syntax) {
  object_syntax = calloc(1, sizeof(ObjectSyntax_t));
  object_syntax->present = ObjectSyntax_PR_NOTHING;
  return object_syntax;
}
