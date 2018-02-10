#ifndef pdus_h
#define pdus_h

#include <stdio.h>
#include <stdint.h>
#include <PDUs.h>
#include <PDU.h>
#include <BulkPDU.h>

/*
 * Creates a get pdu and returns the PDUs_t struct filled with 
 * the information about the GetRequest_PDU_t
 */
PDUs_t* create_getRequest_pdu(PDUs_t*, GetRequest_PDU_t*);

/*
 * Creates a getnext pdu and returns the PDUs_t struct filled with 
 * the information about the GetNextRequest_PDU_t
 */
PDUs_t* create_getNextRequest_pdu(PDUs_t*, GetNextRequest_PDU_t*);

/*
 * Creates a response pdu and returns the PDUs_t struct filled with 
 * the information about the Response_PDU_t
 */
PDUs_t* create_response_pdu(PDUs_t*, Response_PDU_t*);

/*
 * Creates a getbulk pdu and returns the PDUs_t struct filled with 
 * the information about the BulkPDU_t
 */
PDUs_t* create_getBulkRequest_pdu(PDUs_t*, BulkPDU_t*);

/*
 * Creates a set pdu and returns the PDUs_t struct filled with 
 * the information about the SetRequest_PDU_t
 */
PDUs_t* create_setRequest_pdu(PDUs_t*, SetRequest_PDU_t*);

/*
 * Creates a inform pdu and returns the PDUs_t struct filled with 
 * the information about the InformRequest_PDU_t
 */
PDUs_t* create_informRequest_pdu(PDUs_t*, InformRequest_PDU_t*);

/*
 * Creates a trap pdu and returns the PDUs_t struct filled with 
 * the information about the SNMP2_TRAP_PDU_t
 */
PDUs_t* create_snmpV2Trap_pdu(PDUs_t*, SNMPv2_Trap_PDU_t*);

/*
 * Creates a report pdu and returns the PDUs_t struct filled with 
 * the information about the Report_PDU_t
 */
PDUs_t* create_report_pdu(PDUs_t*, Report_PDU_t*);

#endif
