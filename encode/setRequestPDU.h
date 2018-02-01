#ifndef SR_H_
#define SR_H_

SetRequest_PDU_t* setRequestPdu_create(ObjectSyntax_t* object_syntax, uint8_t* name, size_t name_size,
                                      SetRequest_PDU_t* setRequestPDU, int requestID);

#endif
