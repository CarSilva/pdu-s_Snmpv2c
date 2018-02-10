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

/*
 * Creates a get pdu with given arguments.
 * The arguments are: Version, Community String, request_id, set of OID's, 
 * and a buffer to store the encoded pdu 
 */
long getRequest(long, char*, long, char**, uint8_t*);

/*
 * Creates a getNext pdu with given arguments.
 * The arguments are: Version, Community String, request_id, set of OID's, 
 * and a buffer to store the encoded pdu 
 */
long getNextRequest(long, char*, long, char**, uint8_t*);

/*
 * Creates a getbulk pdu with given arguments.
 * The arguments are: Version, Community String, request_id, set of OID's, 
 * numbers of non repeaters, max repetitions and a buffer to store the encoded pdu 
 */
long getBulkRequest(long, char*, long, char**,long, long, uint8_t*);

/*
 * Creates a response pdu that express success with given arguments.
 * The arguments are: set of flags that indicates the type of value, Version, 
 * Community String, request_id, set of OID's, integer that show error status,
 * integer that shows error index, set of values (this one synced with the set of flags) 
 * and a buffer to store the encoded pdu 
 */
long responseSuccess(int*, long , char* , long , char**, long, long, char**, uint8_t*);

/*
 * Creates a response pdu that express Unspecified with given arguments.
 * The arguments are: set of flags that indicates the type of value, Version, 
 * Community String, request_id, set of OID's, integer that show error status,
 * integer that shows error index, set of values (this one synced with the set of flags) 
 * and a buffer to store the encoded pdu 
 */
long responseUnspecified(int*, long , char* , long , char**, long, long, char**, uint8_t*);

/*
 * Creates a response pdu that express no such object with given arguments.
 * The arguments are: set of flags that indicates the type of value, Version, 
 * Community String, request_id, set of OID's, integer that show error status,
 * integer that shows error index, set of values (this one synced with the set of flags) 
 * and a buffer to store the encoded pdu 
 */
long responseNoSuchObject(int*, long , char* , long , char**, long, long, char**, uint8_t*);

/*
 * Creates a response pdu that express no such instance with given arguments.
 * The arguments are: set of flags that indicates the type of value, Version, 
 * Community String, request_id, set of OID's, integer that show error status,
 * integer that shows error index, set of values (this one synced with the set of flags) 
 * and a buffer to store the encoded pdu 
 */
long responseNoSuchInstance(int*, long , char* , long , char**, long, long, char**, uint8_t*);

/*
 * Creates a response pdu that express end of mib view with given arguments.
 * The arguments are: set of flags that indicates the type of value, Version, 
 * Community String, request_id, set of OID's, integer that show error status,
 * integer that shows error index, set of values (this one synced with the set of flags) 
 * and a buffer to store the encoded pdu 
 */
long responseEndOfMibView(int*, long , char* , long , char**, long, long, char**, uint8_t*);

/*
 * Creates a set pdu with given arguments.
 * The arguments are: set of flags that indicates the type of value, Version, 
 * Community String, request_id, set of OID's, set of values (this one synced with the set of flags) 
 * and a buffer to store the encoded pdu
 */
long setRequest(int*, long, char*, long, char**, char**, uint8_t *);

/*
 * Creates a inform pdu with given arguments.
 * The arguments are: Version, Community String, request_id, set of OID's, 
 * and a buffer to store the encoded pdu 
 */
long informRequest(long, char* , long, char**, uint8_t*);

/*
 * Creates a trap pdu with given arguments.
 * The arguments are: Version, Community String, request_id, set of OID's, 
 * and a buffer to store the encoded pdu 
 */
long trap(long, char*, long, char**, uint8_t *);

#endif
