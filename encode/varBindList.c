#include <varBindList.h>

VarBindList_t* create_varBindList(VarBind_t* var_bind, VarBindList_t* varlist) {
  varlist = calloc(1, sizeof(VarBindList_t));
  int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
  return varlist;
}

VarBindList_t* add_to_varBindList(VarBind_t* var_bind, VarBindList_t* varlist) {
  int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
  return varlist;
}
