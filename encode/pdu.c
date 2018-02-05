#include <stdio.h>
#include <stdint.h>
#include <PDU.h>
#include <BulkPDU.h>
#include <VarBindList.h>

PDU_t* create_pdu(PDU_t* pdu, int requestID, int index, int status, VarBindList_t* varlist) {
  pdu = calloc(1, sizeof(PDU_t));
  pdu->request_id = requestID;
  pdu->error_index = 0;
  pdu->error_status = 0;
  pdu->variable_bindings = *varlist;
  return pdu;
}

BulkPDU_t* create_bulk_pdu(BulkPDU_t* pdu, int requestID, int nonRepeaters,
                          int maxRepetitions, VarBindList_t* varlist) {
  pdu = calloc(1, sizeof(BulkPDU_t));
  pdu->request_id = requestID;
  pdu->non_repeaters = nonRepeaters;
  pdu->max_repetitions = maxRepetitions;
  pdu->variable_bindings = *varlist;
  return pdu;
}
