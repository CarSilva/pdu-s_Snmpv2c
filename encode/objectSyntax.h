#ifndef SR_H_
#define SR_H_

ObjectSyntax_t* object_create_simple(SimpleSyntax_t* simple, ObjectSyntax_t* object_syntax);

ObjectSyntax_t* object_create_application(ApplicationSyntax_t* application_wide, ObjectSyntax_t* object_syntax);

ObjectSyntax_t* create_object(int flag, SimpleSyntax_t* simple, ApplicationSyntax_t* application_wide, ObjectSyntax_t* object_syntax);

#endif
