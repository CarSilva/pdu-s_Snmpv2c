#ifndef SR_H_
#define SR_H_

PDUs_t* create_getRequest_pdu(PDUs_t* pdus, GetRequest_PDU_t* pdu);

PDUs_t* create_getNextRequest_pdu(PDUs_t* pdus, GetNextRequest_PDU_t* pdu);

PDUs_t* create_response_pdu(PDUs_t* pdus, Response_PDU_t* pdu);

PDUs_t* create_getBulkRequest_pdu(PDUs_t* pdus, BulkPDU_t* pdu);

PDUs_t* create_setRequest_pdu(PDUs_t* pdus, SetRequest_PDU_t* pdu);

PDUs_t* create_informRequest_pdu(PDUs_t* pdus, InformRequest_PDU_t* pdu);

PDUs_t* create_snmpV2Trap_pdu(PDUs_t* pdus, SNMPv2_Trap_PDU_t* pdu);

PDUs_t* create_report_pdu(PDUs_t* pdus, Report_PDU_t* pdu);

#endif
