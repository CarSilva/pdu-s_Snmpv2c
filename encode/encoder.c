#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ObjectSyntax.h>
#include <PDUs.h>
#include <primitives.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<linux/net.h>


#define clear() printf("\033[H\033[J")
char* community;
long version;
int type;


void buildTypeValue(char *type, char **value, int *flag,
                    int *indexVal, int *indexflag){
    char *tok = strtok(type, ":");
    switch(atoi(tok)){
        case 1:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 1;
            break;
        case 2:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            printf("%s\n",value[(*indexVal)-1] );
            flag[(*indexflag)++] = 2;
            break;
        case 3:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 3;
            break;
        case 4:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 4;
            break;
        case 5:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 5;
            break;
        case 6:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 6;
            break;
        case 7:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 7;
            break;
        case 8:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 8;
            break;
        case 9:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 9;
            break;
        case 10:
            tok = strtok(NULL, ":\n");
            value[(*indexVal)++] = tok;
            flag[(*indexflag)++] = 10;
            break;
    }
}

void buildResponseType(char *type, int *responseType, char **value, int *flag,
                      int *indexVal, int *indexflag){
    char *typeSave = strdup(type);
    char *tok = strtok(type, ":");
    switch(atoi(type)){
        case 1:
            *responseType = 1;
            flag[(*indexflag)++] = 11;
            break;
        case 2:
            *responseType = 2;
            flag[(*indexflag)++] = 12;
            break;
        case 3:
            *responseType = 3;
            flag[(*indexflag)++] = 13;
            break;
        case 4:
            *responseType = 4;
            flag[(*indexflag)++] = 14;
            break;
        case 5:
            *responseType = 5;
            buildTypeValue(typeSave+2, value, flag, indexVal, indexflag);
            break;
    }
}


void buildPdu(char *line, char **oid, char **value, int *flag,
                uint8_t *buffer_final, int *indexflag,
                int *indexOid, int *indexVal, int nFields, int *n, int tp, int index){
    char *tok;
    char *error_status, *error_index, *non_repeaters, *max_repetitions;
    int *responseType = malloc(sizeof(int));
    char *type;
    switch(tp){
        case 1:
            tok = strtok(line, " ");
            oid[(*indexOid)++] = strdup(tok);
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = getRequest(version, community, 1, oid, buffer_final);
            }
            break;
        case 2:
            tok = strtok(line, " ");
            oid[(*indexOid)++] = strdup(tok);
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = getNextRequest(version, community, 2, oid, buffer_final);
            }
            break;
        case 3:
            if(index == 1) {
              tok = strtok(line, " ");
              non_repeaters = strdup(tok);
              tok = strtok(NULL, " ");
              max_repetitions = strdup(tok);
            }
            else {
              tok = strtok(line, " ");
              oid[(*indexOid)++] = strdup(tok);
              if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                //aqui fica a 0 nao sei porque
                *n = getBulkRequest(version, community, 3, oid, atol(non_repeaters),
                       atol(max_repetitions), buffer_final);
              }
            }
            break;
        case 4:
            if(index == 1) {
              tok = strtok(line, " ");
              error_status = strdup(tok);
              tok = strtok(NULL, " ");
              error_index = strdup(tok);
            }
            else {
              tok = strtok(line, " ");
              oid[(*indexOid)++] = strdup(tok);
              printf("%s\n",oid[(*indexOid)-1] );
              tok = strtok(NULL, " ");
              type = strdup(tok);
              buildResponseType(type, responseType, value, flag, indexVal, indexflag);
              if((*indexOid) == nFields){
                  oid[*indexOid] = NULL;
                  value[*indexVal] = NULL;
                  switch(*responseType){
                    case 1:
                        *n = responseUnspecified(flag, version, community, 4, oid,
                            atol(error_status), atol(error_index), value, buffer_final);
                        break;
                    case 2:
                        *n = responseNoSuchObject(flag, version, community, 4, oid,
                            atol(error_status), atol(error_index), value, buffer_final);
                        break;
                    case 3:
                        *n = responseNoSuchInstance(flag, version, community, 4, oid,
                            atol(error_status), atol(error_index), value, buffer_final);
                        break;
                    case 4:
                        *n = responseEndOfMibView(flag, version, community, 4, oid,
                            atol(error_status), atol(error_index), value, buffer_final);
                        break;
                    case 5:
                        *n = responseSuccess(flag, version, community, 4, oid, atol(error_status),
                                        atol(error_index), value, buffer_final);
                        break;
                }
              }
            }
            break;
        case 5:
            tok = strtok(line, " ");
            oid[(*indexOid)++] = strdup(tok);
            tok = strtok(NULL, " ");
            char *type = strdup(tok);
            buildTypeValue(type, value, flag, indexVal, indexflag);
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                value[*indexVal] = NULL;
                *n = setRequest(flag, version, community, 5, oid, value, buffer_final);
            }

            break;
        case 6:
            tok = strtok(line, " ");
            oid[(*indexOid)++] = tok;
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = informRequest(version, community, 6, oid, buffer_final);
            }
            break;
        case 7:
            tok = strtok(line, " ");
            oid[(*indexOid)++] = tok;
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = trap(version, community, 7, oid, buffer_final);
            }
            break;
        case 8:
            tok = strtok(NULL, " ");
            //TODO--NAO cobrir talvez
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
            }
            break;
        default:
            printf("Primitive not supported. Error\n");
    }
}

void parseVersionCommunity(char *line, int *nFields){
    char *tok = strtok(line, " ");
    *nFields = atoi(tok);
    tok = strtok(NULL, " ");
    version = atol(tok);
    tok = strtok(NULL, " ");
    community = strdup(tok);
    tok = strtok(NULL, " ");
    type = atoi(tok);
}

void readFromFile(char **oid, char **value, int *flag, uint8_t *buffer_final,
                   int *n, char *filename) {
    FILE * fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int indexOid, indexVal, indexflag, index, nFields;
    indexOid = indexVal = indexflag = index = 0;
    fp = fopen(filename, "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        if(index == 0){
            parseVersionCommunity(line, &nFields);
        }else{
            buildPdu(line, oid, value, flag, buffer_final,
                &indexflag, &indexOid, &indexVal, nFields,
                n, type, index);
        }
        index++;
    }
    fclose(fp);
    if (line)
        free(line);
}



void main(int argc, char const *argv[]) {
    if(argc != 4){
      printf("Wrong number of arguments;\nFormat: ./encode [IP] [PORT] [FILENANE]\n");
      return;
    }
    char *ip = strdup(argv[1]);
    int port = atoi(argv[2]);
    char **oid, **value;
    int *flag;
    uint8_t *buffer_final;
    int i, n;
    value = (char**) malloc(100*sizeof(char *));
    oid = (char**) malloc(100*sizeof(char *));
    for(i = 0; i < 100; i++) {
        value[i] = (char *) malloc(1024 * sizeof(char));
        oid[i] = (char *) malloc(1024 * sizeof(char));
    }
    flag = malloc(100*sizeof(int));
    buffer_final = malloc(1024*sizeof(uint8_t));
    readFromFile(oid, value, flag, buffer_final, &n, (char*)argv[3]);
    //imprime
    i = 0;
    if (n >= 1 && n <= 1024) {
      printf("Codificação buffer final: \n\n");
      while (i != n) {
        printf("%02x ", buffer_final[i] & 0xff);
        i++;
      }
      printf("\n\nFinal da codificação: \n\n");
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      addr.sin_addr.s_addr = inet_addr(ip);
      int sock = socket(AF_INET, SOCK_DGRAM, 0);
      socklen_t udp_socket_size = sizeof(addr);
      int sent = sendto(sock, buffer_final, n, 0, (struct sockaddr *)&addr,
                    udp_socket_size);
      printf("Sended %d Bytes\n", sent);
    }
}
