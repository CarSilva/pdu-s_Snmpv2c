#define message_h

#include <PDUs.h>
#include <ANY.h>
#include <Message.h>

/*
 * Given a buffer that represents the PDUs_t struct
 * encoded, the size (in bytes) of the buffer and a ANY_t variable
 * that is the struct to assign the buffer and the size of the buffer,
 * fills the ANY_t variable with the respective fields
 */
ANY_t* create_data(uint8_t*, asn_enc_rval_t, ANY_t*);

/*
 * Given the data that represents the PDUs_T encoded, 
 * the version and the community string, the Message variable 
 * is built with the previous arguments
 */
Message_t* create_message(ANY_t*, long, char*, Message_t*);
