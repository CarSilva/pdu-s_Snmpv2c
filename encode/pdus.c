#include <pdus.h>

PDUs_t* create_getRequest_pdu(PDUs_t* pdus, GetRequest_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_get_request;
  pdus->choice.get_request = *pdu;
  return pdus;
}

PDUs_t* create_getNextRequest_pdu(PDUs_t* pdus, GetNextRequest_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_get_next_request;
  pdus->choice.get_next_request = *pdu;
  return pdus;
}

PDUs_t* create_response_pdu(PDUs_t* pdus, Response_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_response;
  pdus->choice.response = *pdu;
  return pdus;
}

PDUs_t* create_getBulkRequest_pdu(PDUs_t* pdus, BulkPDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_get_bulk_request;
  pdus->choice.get_bulk_request = *pdu;
  return pdus;
}

PDUs_t* create_setRequest_pdu(PDUs_t* pdus, SetRequest_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_set_request;
  pdus->choice.set_request = *pdu;
  return pdus;
}

PDUs_t* create_informRequest_pdu(PDUs_t* pdus, InformRequest_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_inform_request;
  pdus->choice.inform_request = *pdu;
  return pdus;
}

PDUs_t* create_snmpV2Trap_pdu(PDUs_t* pdus, SNMPv2_Trap_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_snmpV2_trap;
  pdus->choice.snmpV2_trap = *pdu;
  return pdus;
}

PDUs_t* create_report_pdu(PDUs_t* pdus, Report_PDU_t* pdu) {
  pdus = calloc(1, sizeof(PDUs_t));
  pdus->present = PDUs_PR_report;
  pdus->choice.report = *pdu;
  return pdus;
}
