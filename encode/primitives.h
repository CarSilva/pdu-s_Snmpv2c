#ifndef primitives_h
#define primitives_h

#include <stdio.h>
#include <stdint.h>
#include <SimpleSyntax.h>
#include <ApplicationSyntax.h>
#include <ObjectSyntax.h>
#include <VarBind.h>
#include <VarBindList.h>
#include <PDU.h>
#include <PDUs.h>
#include <ANY.h>
#include <Message.h>
#include <asn_application.h>

int sizeArray(char**);

ObjectSyntax_t* decide_object(int, char*, ObjectSyntax_t*);

long encoding(PDUs_t*, long, char*, uint8_t*);

long getRequest(long, char*, long, char**, uint8_t*);

long getNextRequest(long, char*, long, char**, uint8_t*);

long getBulkRequest(long, char*, long, char**,long, long, uint8_t*);

long responseUnspecified(int*, long , char* , long , char**, long, long, char**, uint8_t*);

long responseNoSuchObject(int*, long , char* , long , char**, long, long, char**, uint8_t*);

long responseNoSuchInstance(int*, long , char* , long , char**, long, long, char**, uint8_t*);

long responseEndOfMibView(int*, long , char* , long , char**, long, long, char**, uint8_t*);

long setRequest(int*, long, char*, long, char**, char**, uint8_t *);

long informRequest(long, char* , long, char**, uint8_t*);

long trap(long, char*, long, char**, uint8_t *);

#endif
