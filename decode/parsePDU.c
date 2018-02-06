#include <VarBindList.h>
#include <PDUs.h>
#include <parsePDU.h>

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

Pdu_Field exploreVarBind(VarBind_t *var_bind, Pdu_Field *field){
	ObjectSyntax_t* object_syntax;
	SimpleSyntax_t *simple;
	ApplicationSyntax_t *appSyn;
	switch(var_bind->choice.present){
		case choice_PR_NOTHING:
			field->present = Nothing;
			break;
		case choice_PR_value:
			object_syntax = &(var_bind->choice.choice.value);
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
			break;
		case choice_PR_unSpecified:
			field->present = UnSpecified;
			field->fields.unSpecified = var_bind->choice.choice.unSpecified;
			break;

		case choice_PR_noSuchObject:
			field->present = NoSuchObject;
			field->fields.noSuchObject = var_bind->choice.choice.noSuchObject;
			break;

		case choice_PR_noSuchInstance:
			field->present = NoSuchInstance;
			field->fields.noSuchInstance = var_bind->choice.choice.noSuchInstance;
			break;

		case choice_PR_endOfMibView:
			field->present = EndOfMibView;
			field->fields.endOfMibView = var_bind->choice.choice.endOfMibView;
	}
}

VarBindList_t getVarBindings(PDUs_t *pdu, Decoded *decoded){
	VarBindList_t var_bindings;
	VarBind_t* var_bind;
	switch(pdu->present){
		case PDUs_PR_get_request:
			var_bindings = pdu->choice.get_request.variable_bindings;
			decoded->request_id = pdu->choice.get_request.request_id;
			decoded->error_status = pdu->choice.get_request.error_status;
			decoded->error_index = pdu->choice.get_request.error_index;
			break;
		case PDUs_PR_get_next_request:
			var_bindings = pdu->choice.get_next_request.variable_bindings;
			decoded->request_id = pdu->choice.get_next_request.request_id;
			decoded->error_status = pdu->choice.get_next_request.error_status;
			decoded->error_index = pdu->choice.get_next_request.error_index;
			break;
		case PDUs_PR_get_bulk_request:
			var_bindings = pdu->choice.get_bulk_request.variable_bindings;
			decoded->request_id = pdu->choice.get_bulk_request.request_id;
			decoded->non_repeaters = pdu->choice.get_bulk_request.non_repeaters;
			decoded->max_repetitions = pdu->choice.get_bulk_request.max_repetitions;
			break;
		case PDUs_PR_response:
			var_bindings = pdu->choice.response.variable_bindings;
			decoded->request_id = pdu->choice.response.request_id;
			decoded->error_status = pdu->choice.response.error_status;
			decoded->error_index = pdu->choice.response.error_index;
			break;
		case PDUs_PR_set_request:
			var_bindings = pdu->choice.set_request.variable_bindings;
			decoded->request_id = pdu->choice.set_request.request_id;
			decoded->error_status = pdu->choice.set_request.error_status;
			decoded->error_index = pdu->choice.set_request.error_index;
			break;
		case PDUs_PR_inform_request:
			var_bindings = pdu->choice.inform_request.variable_bindings;
			decoded->request_id = pdu->choice.inform_request.request_id;
			decoded->error_status = pdu->choice.inform_request.error_status;
			decoded->error_index = pdu->choice.inform_request.error_index;
			break;	
		case PDUs_PR_snmpV2_trap:
			var_bindings = pdu->choice.snmpV2_trap.variable_bindings;
			decoded->request_id = pdu->choice.snmpV2_trap.request_id;
			decoded->error_status = pdu->choice.snmpV2_trap.error_status;
			decoded->error_index = pdu->choice.snmpV2_trap.error_index;
			break;	
		case PDUs_PR_report:
			var_bindings = pdu->choice.report.variable_bindings;
			decoded->request_id = pdu->choice.report.request_id;
			decoded->error_status = pdu->choice.report.error_status;
			decoded->error_index = pdu->choice.report.error_index;
			break;
	}	

    return var_bindings;
}

VarBind_t *getVarBind(VarBindList_t var_bindings, int index){
	return var_bindings.list.array[index];
}

void getOid(VarBind_t *var_bind, Pdu_Field *field){
	field->oid = &var_bind->name;
}

void parsePdu(PDUs_t *pdu, Decoded *decoded){
	int i;
	Pdu_Field *fields = malloc(1024 * sizeof(struct pdu_field));
	VarBindList_t var_bindings = getVarBindings(pdu, decoded);
	for(i = 0; i < var_bindings.list.count; i++){
		VarBind_t *var_bind = getVarBind(var_bindings, i);
		getOid(var_bind, &fields[i]);
		exploreVarBind(var_bind, &fields[i]);
	}
	decoded->nFields = i;
	decoded->decoded = fields;
}

