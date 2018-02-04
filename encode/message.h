#ifndef SR_H_
#define SR_H_

ANY_t* create_data(uint8_t *buffer, asn_enc_rval_t ret, ANY_t *data);

Message_t* create_message(ANY_t* data, const char* version, const char* community, Message_t* message);

#endif
