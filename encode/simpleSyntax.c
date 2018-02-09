#include <simpleSyntax.h>

SimpleSyntax_t* insert_value(long value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_integer_value;
  simple->choice.integer_value = value;
  return simple;
}

SimpleSyntax_t* insert_string(OCTET_STRING_t* value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_string_value;
  simple->choice.string_value = *value;
  return simple;
}

SimpleSyntax_t* insert_oid(OBJECT_IDENTIFIER_t* value, SimpleSyntax_t* simple) {
  simple->present = SimpleSyntax_PR_objectID_value;
  simple->choice.objectID_value  = *value;
  return simple;
}

int fill(char* oid, uint8_t* name) {
  char *oidentifier = strdup(oid);
  char *string;
  int id;
  int i;
  i = 0;
  string = strtok(oidentifier,".");
  while (string != NULL) {
    id = atoi(string);
    name[i] = id;
    i++;
    string = strtok(NULL, ".");
  }
  return i;
}

OBJECT_IDENTIFIER_t* encode_OID(OBJECT_IDENTIFIER_t *oid, char *oid_text) {
  oid = malloc(sizeof(OBJECT_IDENTIFIER_t));
  uint8_t* name;
  int size;
  name = malloc(1024*sizeof(uint8_t));
  size = fill(oid_text, name);
  oid->buf = name;
  oid->size = size;
  return oid;
}

SimpleSyntax_t* create_simple(int flag, char* string, SimpleSyntax_t* simple) {
  long value;
  OCTET_STRING_t *str;
  OBJECT_IDENTIFIER_t *oid;
  simple = malloc(sizeof(SimpleSyntax_t));
  switch(flag) {
   case 1:
      value = atol(string);
      simple = insert_value(value, simple);
      break;
   case 2:
      str = malloc(sizeof(OCTET_STRING_t));
      int oc = OCTET_STRING_fromBuf(str,string,-1);
      simple = insert_string(str, simple);
      break;
   case 3:
      oid = encode_OID(oid, string);
      simple = insert_oid(oid, simple);
      break;
    }
    return simple;
}
