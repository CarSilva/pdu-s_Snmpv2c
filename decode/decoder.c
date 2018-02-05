#include <stdlib.h>     
#include <string.h>
#include <VarBindList.h>
#include <PDUs.h>
#include <getPDU.h>
#include <parsePDU.h>

void decode(uint8_t *buffer){
    int i;

    Pdu_Info *info = buffer_to_PDU(buffer);
    if(info == NULL) {
        printf("Error. Cannot decode.\n");
        return;
    }
    Decoded *decoded = malloc(sizeof(struct pdu_field));
    parsePdu(info->pdu, decoded);
    printf("Version : %s  ", info->version);
    printf("Community String %s", info->comm);
    printf("Field number :%d\n", decoded->nFields);
    //falta imprimir requestid, erros,...
    Pdu_Field *fields = decoded->decoded;
    for(i = 0; i < decoded->nFields; i++){
        printf("OID -> %s\n",fields->oid);
         switch(fields->present){
            case Nothing:
                printf("Nothing\n");
                break;
            case Long:
                printf("Value = %ld\n",fields->fields.value);
                break;
            case String:
                printf("String = %s\n",fields->fields.string);
                break;
            case OID:
                printf("OID = %s\n", fields->fields.oid);
                break;
            case IpAddress:
                printf("IpAddress = %s\n",fields->fields.ip);
                break;
            case Counter:
                printf("SmallCounter = %ld\n", fields->fields.counter32);
                break;
            case Time:
                printf("TimeTicks %ld\n",fields->fields.time);
                break;
            case Arbitraty:
                printf("Arbitraty = %s\n",fields->fields.opaque);
                break;
            case Big_Counter:
                printf("Big_Counter = %d\n",fields->fields.counter64);
                break;
            case Unsign32:
                printf("Unsign32 = %d\n",fields->fields.unsign32);
                break;
            case UnSpecified:
                printf("UnSpecified... %d\n",fields->fields.unSpecified);
                break;
            case NoSuchObject:
                printf("No Such Object %d\n", fields->fields.noSuchObject);
                break;
            case NoSuchInstance:
                printf("No Such Instance %d\n", fields->fields.noSuchInstance);
                break;         
            case EndOfMibView:
                printf("End of Mib View ... %d\n", fields->fields.endOfMibView);
                break;
         }
    }
}


int main(int argc, char const *argv[]) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8954);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    socklen_t udp_socket_size = sizeof(addr);
    bind(sock, (struct sockaddr *)&addr, udp_socket_size);
    uint8_t *buffer = malloc(1024*sizeof(uint8_t));
    while(1){
        int recv = recvfrom(sock, buffer, sizeof(buffer), 0,
                (struct sockaddr *)&addr,&udp_socket_size);
        printf("ola\n");
        decode(buffer);
        printf("ola2\n");
    }

}