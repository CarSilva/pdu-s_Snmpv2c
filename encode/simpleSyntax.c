#include <SimpleSyntax.h>
#include <stdlib.h>

SimpleSyntax_t* insert_value(long value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_integer_value;
  simple->choice.integer_value = value;
  return simple;
}

SimpleSyntax_t* insert_string(OCTET_STRING_t value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_string_value;
  simple->choice.string_value = value;
  return simple;
}

SimpleSyntax_t* insert_oid(OBJECT_IDENTIFIER_t value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_objectID_value;
  simple->choice.objectID_value  = value;
  return simple;
}

SimpleSyntax_t* create_simple(int flag, char* string) {
  long value;
  SimpleSyntax_t* simple;
  simple = calloc(1, sizeof(SimpleSyntax_t));
  switch(flag) {
   case 1:
      value = atol(string);
      simple = insert_value(value, simple);
      break;
   case 2:
      //caso para a string, formato OCTET_STRING_t
      break;
   case 3:
      //caso
      break;
    }
    return simple;
}
