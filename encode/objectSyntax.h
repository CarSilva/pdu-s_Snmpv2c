#ifndef object_syntax_h
#define object_syntax_h

#include <ObjectSyntax.h>

ObjectSyntax_t* create_simple_object(SimpleSyntax_t*, ObjectSyntax_t*);

ObjectSyntax_t* create_application_object(ApplicationSyntax_t*, ObjectSyntax_t*);

ObjectSyntax_t* create_empty_object(ObjectSyntax_t*);

#endif
