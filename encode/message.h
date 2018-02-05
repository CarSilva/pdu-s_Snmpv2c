#define message_h

#include <PDUs.h>
#include <ANY.h>
#include <Message.h>

ANY_t* create_data(uint8_t*, asn_enc_rval_t, ANY_t*);

Message_t* create_message(ANY_t*, long, char*, Message_t*);
