#ifndef SR_H_
#define SR_H_

PDU_t* create_pdu(PDU_t* pdu, int requestID, int index, int status, VarBindList_t* varlist);

BulkPDU_t* create_bulk_pdu(BulkPDU_t* pdu, int requestID, int nonRepeaters, int maxRepetitions, VarBindList_t* varlist);

#endif
