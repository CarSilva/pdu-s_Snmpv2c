#ifndef pdu_h
#define pdu_h

#include <stdio.h>
#include <stdint.h>
#include <PDU.h>
#include <BulkPDU.h>
#include <VarBindList.h>

PDU_t* create_pdu(PDU_t*, long, long, long, VarBindList_t*);

BulkPDU_t* create_bulk_pdu(BulkPDU_t*, long, long, long, VarBindList_t* varlist);

#endif
