#include <VarBindList.h>
#include <PDUs.h>
#include <parsePDU.h>


//ver a cena de ter mais que um oid ?!

void parseSimple(SimpleSyntax_t *simple, Pdu_Field *field){
	switch(simple->present){
		case SimpleSyntax_PR_integer_value:
			field->present = Long;
			field->fields.value = simple->choice.integer_value;
			break;
		case SimpleSyntax_PR_string_value:
			field->present = String;
			field->fields.string = simple->choice.string_value;
			break;
		case SimpleSyntax_PR_objectID_value:
			field->present = OID;
			field->fields.oid = simple->choice.objectID_value;
			break;
		case SimpleSyntax_PR_NOTHING:
			field->present = Nothing;
	}
}

void parseApplicationSyntax(ApplicationSyntax_t *appSyn, Pdu_Field *field){
	switch(appSyn->present){
		case ApplicationSyntax_PR_ipAddress_value:
			field->present = IpAddress;
			field->fields.ip = appSyn->choice.ipAddress_value;
			break;
		case ApplicationSyntax_PR_counter_value:
			field->present = Counter;
			field->fields.counter32 = appSyn->choice.counter_value;
			break;
		case ApplicationSyntax_PR_timeticks_value:
			field->present = Time;
			field->fields.time = appSyn->choice.timeticks_value;
			break;
		case ApplicationSyntax_PR_arbitrary_value:
			field->present = Arbitraty;
			field->fields.opaque = appSyn->choice.arbitrary_value;
			break;
		case ApplicationSyntax_PR_big_counter_value:
			field->present = Big_Counter;
			field->fields.counter64 = appSyn->choice.big_counter_value;
			break;
		case ApplicationSyntax_PR_unsigned_integer_value:
			field->present = Unsign32;
			field->fields.unsign32 = appSyn->choice.unsigned_integer_value;
			break;
		case ApplicationSyntax_PR_NOTHING:
			field->present = Nothing;

	}
}

Pdu_Field getObjectSyntax(VarBind_t *var_bind, Pdu_Field *field){
	ObjectSyntax_t* object_syntax = &(var_bind->choice.choice.value);
	SimpleSyntax_t *simple;
	ApplicationSyntax_t *appSyn;
	switch(object_syntax->present){
		case ObjectSyntax_PR_simple:
			simple = &(object_syntax->choice.simple);
			parseSimple(simple, field);
			break;
		case ObjectSyntax_PR_application_wide:
			appSyn = &(object_syntax->choice.application_wide);
			parseApplicationSyntax(appSyn, field);
			break;
	}
}


VarBind_t *getVarBind(PDUs_t *pdu){
	VarBindList_t var_bindings;
	VarBind_t* var_bind;
	switch(pdu->present){
		case PDUs_PR_get_request:
			var_bindings = pdu->choice.get_request.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;
		case PDUs_PR_get_next_request:
			var_bindings = pdu->choice.get_next_request.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;
		case PDUs_PR_get_bulk_request:
			var_bindings = pdu->choice.get_bulk_request.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;
		case PDUs_PR_response:
			var_bindings = pdu->choice.response.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;
		case PDUs_PR_set_request:
			var_bindings = pdu->choice.set_request.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;
		case PDUs_PR_inform_request:
			var_bindings = pdu->choice.inform_request.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;	
		case PDUs_PR_snmpV2_trap:
			var_bindings = pdu->choice.snmpV2_trap.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;	
		case PDUs_PR_report:
			var_bindings = pdu->choice.report.variable_bindings;
			var_bind = var_bindings.list.array[0];
			break;
	}	

    return var_bind;
}

void getOid(VarBind_t *var_bind, Pdu_Field *field){
	field->oid = var_bind->name.buf;
}

void parsePdu(PDUs_t *pdu, Pdu_Field *field){
	VarBind_t *var_bind = getVarBind(pdu);
	getOid(var_bind, field);
	getObjectSyntax(var_bind, field);
}

