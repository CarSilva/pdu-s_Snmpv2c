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

ObjectSyntax_t* create_object(int flag, SimpleSyntax_t* simple, ApplicationSyntax_t* application_wide,
                              ObjectSyntax_t* object_syntax) {
  object_syntax = calloc(1, sizeof(ObjectSyntax_t));
  if (flag >=1 && flag <=3) {
    object_syntax = object_create_simple(simple, object_syntax);
  }
  else if (flag >=4 && flag <=9) {
    object_syntax = object_create_application(application_wide, object_syntax);
  }
  else {
    printf("%s\n", "Erro");
  }
  return object_syntax;
}
