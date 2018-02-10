#ifndef object_syntax_h
#define object_syntax_h

#include <ObjectSyntax.h>

/*
 * Creates a ObjectSyntax with a SimpleSyntax value
 */
ObjectSyntax_t* create_simple_object(SimpleSyntax_t*, ObjectSyntax_t*);

/*
 * Creates a ObjectSyntax with a ApplicationSyntax value
 */
ObjectSyntax_t* create_application_object(ApplicationSyntax_t*, ObjectSyntax_t*);

/*
 * Creates a ObjectSyntax with a empty flag
 */
ObjectSyntax_t* create_empty_object(ObjectSyntax_t*);

#endif
