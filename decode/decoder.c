#include <stdlib.h>
#include <string.h>
#include <VarBindList.h>
#include <PDUs.h>
#include <getPDU.h>
#include <parsePDU.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<linux/net.h>


void decode(uint8_t *buffer){
    int i,j;

    Pdu_Info *info = malloc(sizeof(struct pdu_info));
    buffer_to_PDU(buffer, info);
    if(info->error == -1) {
        printf("Error. Cannot decode. FAILED\n");
        return;
    }else if(info->error == 0){
        printf("Error. Cannot decode. Want More\n");
        return;
    }
    Decoded *decoded = malloc(sizeof(struct pdu_field));
    parsePdu(info->pdu, decoded);
    printf("Version : %ld  ", info->version);
    printf("Community String %s  ", info->comm);
    printf("Field number :%d\n", decoded->nFields);
    //return;
    //falta imprimir requestid, erros,...
    Pdu_Field *fields = decoded->decoded;
    for(i = 0; i < decoded->nFields; i++){
        printf("OID : ");
        for(j = 0; j <fields->oid->size; j++ ){
            printf("%x.",  fields->oid->buf[j]);
        }
        printf("\n");
         switch(fields->present){
            case Nothing:
                printf("Nothing\n");
                break;
            case Long:
                printf("Value = %ld\n",fields->fields.value);
                break;
            case String:
                printf("String = %s\n",(char *)fields->fields.string.buf);
                break;
            case OID:
                printf("OID = %s\n", (char *)fields->fields.oid.buf);
                break;
            case IpAddress:
                printf("IpAddress = %s\n", (char *)fields->fields.ip.buf);
                break;
            case Counter:
                printf("SmallCounter = %ld\n", fields->fields.counter32);
                break;
            case Time:
                printf("TimeTicks %ld\n",fields->fields.time);
                break;
            case Arbitraty:
                printf("Arbitraty = %s\n",(char *) fields->fields.opaque.buf);
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
        int recv = recvfrom(sock, buffer, 1024, 0,
                (struct sockaddr *)&addr,&udp_socket_size);
        decode(buffer);
    }

}
