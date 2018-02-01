#ifdef    HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>   
#include <getopt.h>   
#include <string.h>   
#include <sysexits.h> 
#include <errno.h>   
#include <unistd.h> 


int main(int argc, char const *argv[]) {
    int i;
    u_int8_t *buffer_final = calloc (1024, sizeof(u_int8_t)); // Este buffer tem de vir já preenchido, 
                                                        //com os bytes de um request qualquer
    Message_t *message = 0;

    asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_Message,
                                    (void **)&message, buffer_final, 1024); //tratar erro se der -1

    PDUs_t* pdu = 0;
    asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
                                    (void **)&pdu, message->data.buf, message->data.size); //tratar erro se der -1

    PDUs_t* pdu = decodePDUS();
    VarBindList_t var_bindings = pdu->choice.set_request.variable_bindings;
    int var_list_size = var_bindings.list.count;

    for(i = 0; i < var_list_size; i++){
        VarBind_t* var_bind = var_bindings.list.array[i]; //fazer algo com isto que ainda nao faço ideia como xD

    }
}