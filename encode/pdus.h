#ifndef pdus_h
#define pdus_h

#include <stdio.h>
#include <stdint.h>
#include <PDUs.h>
#include <PDU.h>
#include <BulkPDU.h>

PDUs_t* create_getRequest_pdu(PDUs_t*, GetRequest_PDU_t*);

PDUs_t* create_getNextRequest_pdu(PDUs_t*, GetNextRequest_PDU_t*);

PDUs_t* create_response_pdu(PDUs_t*, Response_PDU_t*);

PDUs_t* create_getBulkRequest_pdu(PDUs_t*, BulkPDU_t*);

PDUs_t* create_setRequest_pdu(PDUs_t*, SetRequest_PDU_t*);

PDUs_t* create_informRequest_pdu(PDUs_t*, InformRequest_PDU_t*);

PDUs_t* create_snmpV2Trap_pdu(PDUs_t*, SNMPv2_Trap_PDU_t*);

PDUs_t* create_report_pdu(PDUs_t*, Report_PDU_t*);

#endif
