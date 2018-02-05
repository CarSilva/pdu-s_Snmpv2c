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

uint8_t* encoding(PDUs_t*, long, char*, uint8_t*);

uint8_t* getRequest(long, char*, long, char**, uint8_t*);

uint8_t* getNextRequest(long, char*, long, char**, uint8_t*);

uint8_t* getBulkRequest(long, char*, long, char**,long, long, uint8_t*);

uint8_t* response(int[], long, char*, long, char**, long,long, char**, uint8_t*);

uint8_t* setRequest(int[], long, char*, long, char**, char**, uint8_t *);

#endif
