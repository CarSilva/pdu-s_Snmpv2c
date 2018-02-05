#include <pdu.h>

PDU_t* create_pdu(PDU_t* pdu, long requestID, long index, long status, VarBindList_t* varlist) {
  pdu = calloc(1, sizeof(PDU_t));
  pdu->request_id = requestID;
  pdu->error_index = index;
  pdu->error_status = status;
  pdu->variable_bindings = *varlist;
  return pdu;
}

BulkPDU_t* create_bulk_pdu(BulkPDU_t* pdu, long requestID, long nonRepeaters,
                          long maxRepetitions, VarBindList_t* varlist) {
  pdu = calloc(1, sizeof(BulkPDU_t));
  pdu->request_id = requestID;
  pdu->non_repeaters = nonRepeaters;
  pdu->max_repetitions = maxRepetitions;
  pdu->variable_bindings = *varlist;
  return pdu;
}
