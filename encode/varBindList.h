#ifndef var_bind_list_h
#define var_bind_list_h

#include <stdio.h>
#include <stdint.h>
#include <VarBind.h>
#include <VarBindList.h>

VarBindList_t* create_varBindList(VarBind_t*, VarBindList_t*);

VarBindList_t* add_to_varBindList(VarBind_t*, VarBindList_t*);

#endif
