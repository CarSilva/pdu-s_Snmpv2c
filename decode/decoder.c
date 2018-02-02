#include <stdlib.h>     
#include <string.h>
#include <VarBindList.h>
#include <Message.h>
#include <PDUs.h>

int main(int argc, char const *argv[]) {
    int i;
    uint8_t buffer_final[] = {30,21,02,01,02,04};

    Message_t *message = 0;
    
    asn_dec_rval_t rval1 = asn_decode(0, ATS_BER, &asn_DEF_Message,
                                    (void **)&message, buffer_final, sizeof(buffer_final)); //tratar erro se der -1
    if(rval1.code ==  RC_FAIL){ //significa que a descodificaçaºo falhou, está a entrar no if nao sei bem porque
        printf("iosdj\n");
    }
    printf("%d\n",message->data.size );

    PDUs_t* pdu = 0;
    asn_dec_rval_t rval2 = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
                                    (void **)&pdu, message->data.buf, message->data.size); //tratar erro se der -1
    if(rval2.code ==  RC_WMORE){ //significa que a descodificaçaºo falhou, está a entrar no if nao sei bem porque
        printf("ok\n");
    }
    VarBindList_t var_bindings = pdu->choice.set_request.variable_bindings;
    int var_list_size = var_bindings.list.count;
    printf("%d\n", var_bindings.list.count);
    VarBind_t* var_bind = var_bindings.list.array[0];
    ObjectName_t* object_name = &(var_bind->name);
    ObjectSyntax_t* object_syntax = &(var_bind->choice.choice.value);
    printf("skdhd%s\n", object_name->buf);
    //Ainda falta ir buscar os campos todos, é só um print para ver se esta a decodificar bem algo
    

}