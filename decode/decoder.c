#include <stdlib.h>     
#include <string.h>
#include <VarBindList.h>
#include <PDUs.h>
#include <getPDU.h>
#include <parsePDU.h>

int main(int argc, char const *argv[]) {
    int i;
    uint8_t buffer_final[] = {30,21,02,01,02,04};

    PDUs_t *pdu = buffer_to_PDU(buffer_final);

    if(pdu == NULL) {
        printf("Error. Cannot decode.\n");
        return 1;
    }

    Pdu_Field *field = calloc(1, sizeof(struct pdu_field));
    parsePdu(pdu, field);


}