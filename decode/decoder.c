#include <stdlib.h>
#include <string.h>
#include <VarBindList.h>
#include <PDUs.h>
#include <getPDU.h>
#include <parsePDU.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<linux/net.h>

void initDecoded(Decoded *decoded){
    decoded->nFields = -1;
    decoded->request_id = -1;
    decoded->error_status = -1;
    decoded->error_index = -1;
    decoded->non_repeaters = -1;
    decoded->max_repetitions = -1;
}

void decode(uint8_t *buffer, char*filename){
    long *l = malloc(sizeof(long));
    FILE *f = fopen(filename, "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
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
    initDecoded(decoded);
    parsePdu(info->pdu, decoded);
    fprintf(f, "Version : %ld  ", info->version);
    fprintf(f, "Community String : %s\n", info->comm);
    if(decoded->error_status > -1){
        fprintf(f, "error status:%ld error index:%ld\n",decoded->error_status, decoded->error_index);
    }
    fprintf(f, "%s ", decoded->primitiveName);
    if(decoded->non_repeaters > 0){
        fprintf(f, "%ld %ld ",decoded->non_repeaters, decoded->max_repetitions);
    }
    Pdu_Field *fields = decoded->decoded;
    for(i = 0; i < decoded->nFields; i++){
        for(j = 0; j < fields[i].oid->size-1; j++ ){
            fprintf(f, "%d.",  (int)fields[i].oid->buf[j]);
        }
        fprintf(f, "%d",(int)fields[i].oid->buf[j]);
        fprintf(f, " ");
         switch(fields[i].present){
            case Nothing:
                fprintf(f, "Nothing\n");
                break;
            case Long:
                fprintf(f, "%ld ",fields[i].fields.value);
                break;
            case String:
                fprintf(f, "%s ",(char *)fields[i].fields.string.buf);
                break;
            case OID:
                for(j = 0; j < fields[i].fields.oid.size-1; j++ ){
                    fprintf(f, "%d.", (int)fields[i].fields.oid.buf[j]);
                }
                fprintf(f, "%d ", (int)fields[i].fields.oid.buf[j]);
                break;
            case IpAddress:
                for(j = 0; j < fields[i].fields.ip.size - 1; j++)
                    fprintf(f, "%d.",(int)fields[i].fields.ip.buf[j]);
                fprintf(f, "%d ",(int)fields[i].fields.ip.buf[j]);
                break;
            case Counter:
                fprintf(f, "%ld ", fields[i].fields.counter32);
                break;
            case Time:
                fprintf(f, "%ld ",fields[i].fields.time);
                break;
            case Arbitraty:
                fprintf(f, "%s ",(char *) fields[i].fields.opaque.buf);
                break;
            case Big_Counter:
                asn_INTEGER2long(&(fields[i].fields.counter64), l);
                fprintf(f, "%ld ",*l);
                break;
            case Unsign32:
                fprintf(f, "%d ",fields[i].fields.unsign32);
                break;
            case UnSpecified:
                fprintf(f, " ");
                fprintf(f, "UnSpecified ");
                break;
            case NoSuchObject:
                fprintf(f, "No Such Object ");
                break;
            case NoSuchInstance:
                fprintf(f, "No Such Instance ");
                break;
            case EndOfMibView:
                fprintf(f, "End of Mib View ");
                break;
         }
    }
    fclose(f);
}


void main(int argc, char const *argv[]) {
    if(argc != 3){
        printf("Wrong number of arguments;\nFormat: ./decode [PORT] [FILENAME]\n");
        return;
    }
    int port = atoi(argv[1]);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    socklen_t udp_socket_size = sizeof(addr);
    bind(sock, (struct sockaddr *)&addr, udp_socket_size);
    uint8_t *buffer = malloc(1024*sizeof(uint8_t));
    int recv = recvfrom(sock, buffer, 1024, 0,
            (struct sockaddr *)&addr,&udp_socket_size);
    decode(buffer, (char*)argv[2]);
}
