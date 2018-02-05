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

OBJECT_IDENTIFIER_t* encode_OID(OBJECT_IDENTIFIER_t *oid, char *oid_text) {
  oid = calloc(1, sizeof(OBJECT_IDENTIFIER_t));
  asn_oid_arc_t fixed_arcs[10];
  asn_oid_arc_t *arcs = fixed_arcs;
  size_t arc_slots = sizeof(fixed_arcs)/sizeof(fixed_arcs[0]);
  ssize_t count;
  count = OBJECT_IDENTIFIER_get_arcs(oid, arcs, arc_slots);
  int error;
  if(count > arc_slots) {
    arc_slots = count;
   	arcs = malloc(sizeof(asn_oid_arc_t) * arc_slots);
   	if(!arcs) {
      printf("%s\n", "Erro");
    }
   	count = OBJECT_IDENTIFIER_get_arcs(oid, arcs, arc_slots);
 		assert(count == arc_slots);
  }
  error = OBJECT_IDENTIFIER_set_arcs(oid,arcs,count);
  if (error < 0) {
    printf("%s\n", "Erro na criação do OBJECT_IDENTIFIER_t necessário para codificar OID");
  }
  return oid;
}

SimpleSyntax_t* create_simple(int flag, char* string, SimpleSyntax_t* simple) {
  long value;
  OCTET_STRING_t *str;
  OBJECT_IDENTIFIER_t *oid;
  simple = calloc(1, sizeof(SimpleSyntax_t));
  switch(flag) {
   case 1:
      value = atol(string);
      simple = insert_value(value, simple);
      break;
   case 2:
      str = calloc(1, sizeof(OCTET_STRING_t));
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
