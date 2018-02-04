#include <stdio.h>
#include <stdint.h>
#include <VarBind.h>
#include <VarBindList.h>

VarBindList_t* create_varBindList(VarBind_t* var_bind, VarBindList_t* varlist) {
  varlist = calloc(1, sizeof(VarBindList_t));
  int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
  return varlist;
}
