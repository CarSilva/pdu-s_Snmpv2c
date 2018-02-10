#ifndef pdu_h
#define pdu_h

#include <stdio.h>
#include <stdint.h>
#include <PDU.h>
#include <BulkPDU.h>
#include <VarBindList.h>


/*
 * Creates a PDU given the PDU_t itself, a request_id,
 * a error_status, a error_index and a VarBindList, already 
 * filled with the required values
 */
PDU_t* create_pdu(PDU_t*, long, long, long, VarBindList_t*);

/*
 * Creates a BulkPDU given the BulkPDU_t itself, a request_id,
 * a non repeaters value, a max_repetitions value and a VarBindList, already 
 * filled with the required values
 */
BulkPDU_t* create_bulk_pdu(BulkPDU_t*, long, long, long, VarBindList_t* varlist);

#endif
