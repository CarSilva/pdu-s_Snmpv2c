#ifndef SR_H_
#define SR_H_

SetRequest_PDU_t* setRequestPdu_create(ObjectSyntax_t* object_syntax, const char* oid,
                                      SetRequest_PDU_t* setRequestPDU, int requestID);

#endif
