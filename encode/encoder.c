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

/*
int menu_out(uint8_t buffer_final[], long n) {
  int temp;
  int choice, i;
  printf("\n");
  printf("Escolha para onde deve ser enviado o output:\n\n");
  printf("1. Terminal\n");
  printf("2. Ficheiro\n");
  printf("3. SocketUDP\n");
  printf("4. Sair\n");
  printf("\n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
      //clear();
      i = 0;
      printf("Codificação buffer final: \n\n");
      while (i != n) {
      printf("%02x ", buffer_final[i] & 0xff);
        i++;
      }
      printf("\n");
      printf("\n");
      printf("\n");
      break;
    case 2:

      break;
    case 3:

      break;
    case 4:
      printf("Programa terminado\n");
      break;
    default:
      printf("Opção errada\n");
      break;
   }
}

int menu_values() {
  int temp;
  int choice;
  int i;
  i = 0;
  do {
    printf("\n");
    printf("Escolha a primitiva que deseja testar:\n\n");
    printf("1. Long\n");
    printf("2. String\n");
    printf("3. OID\n");
    printf("4. IpAddress\n");
    printf("5. CounteValue\n");
    printf("6. TimeTicks\n");
    printf("7. Arbitrary_value\n");
    printf("8. BigCounterValue\n");
    printf("9. Unsigned_integer_value\n");
    printf("10. Sair\n");
    printf("\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        flag[i] = 1;
        break;
      case 2:
        flag[i] = 2;
        break;
      case 3:
        flag[i] = 3;
        break;
      case 4:
        flag[i] = 4;
        break;
      case 5:
        flag[i] = 5;
        break;
      case 6:
        flag[i] = 6;
        break;
      case 7:
        flag[i] = 7;
        break;
      case 8:
        flag[i] = 8;
        break;
      case 9:
        flag[i] = 9;
        break;
      case 10:
        value[i] = NULL;
        printf("Programa terminado\n");
        break;
      default:
        printf("Opção errada\n");
        break;
      }
      if(choice != 10) {
        char str[80];
        printf("OID: ");
        fgets(str, 80, stdin);
        fgets(str, 80, stdin);
        oid[i] = str;
        printf("Valor: ");
        fgets(str, 80, stdin);
        value[i] = str;
        i++;
      }
    }
 while(choice != 10);
}

int menu_setRequest() {
  int temp;
  char str[80];
  printf("Endereço ip: ");
  fgets(str, 80, stdin);
  fgets(str, 80, stdin);
  ip =  str;
  printf("\n");
  printf("Porta: ");
  fgets(str, 80, stdin);
  porta = str;
  printf("\n");
  printf("community string: ");
  fgets(str, 80, stdin);
  community = str;
  printf("\n");
  temp = menu_values();
  long n = setRequest(flag,version,community,id,oid,value,buffer_final);
  temp = menu_out(buffer_final, n);
  return 0;
}

int menu_terminal_v2() {
  int temp;
  int choice;
  printf("\n");
  printf("Escolha a primitiva que deseja testar:\n\n");
  printf("1. GetRequest\n");
  printf("2. GetNextRequest\n");
  printf("3. GetBulkRequest\n");
  printf("4. Response\n");
  printf("5. SetRequest\n");
  printf("6. InformRequest\n");
  printf("7. SNMPv2-Trap\n");
  printf("8. Report\n");
  printf("9. Sair\n");
  printf("\n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
      id = 1;
      //temp = menu_getRequest();
      break;
    case 2:
      id = 2;
      //temp = menu_getNextRequest();
      break;
    case 3:
      id = 3;
      //temp = menu_getBulkRequest();
      break;
    case 4:
      id = 4;
      //temp = menu_Response();
      break;
    case 5:
      id = 5;
      temp = menu_setRequest();
      break;
    case 6:
      id = 6;
      //temp = menu_informRequest();
      break;
    case 7:
      id = 7;
      //temp = menu_snmpv2();
      break;
    case 8:
      id = 8;
      //temp = menu_report();
      break;
    case 9:
      printf("Programa terminado\n");
      break;
    default:
        printf("Opção errada\n");
        break;
   }
}

int menu_terminal() {
  int temp;
  int choice;
  printf("Escolha a versão SNMP:\n\n");
  printf("1. Versão 1\n");
  printf("2. Versão 2\n");
  printf("3. Versão 3\n");
  printf("4. Sair\n");
  printf("\n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
      version = 1;
      //temp = menu_terminal_v1();
      break;
    case 2:
      version = 2;
      temp = menu_terminal_v2();
      break;
    case 3:
      version = 3;
      //temp = menu_terminal_v3();
      break;
    case 4:
        printf("Programa terminado\n");
        break;
      default:
        printf("Opção errada\n");
        break;
   }
}

int menu_principal() {
  int temp;
  int choice;
  int i;
  value = (char**) malloc(100*sizeof(char *));
  oid = (char**) malloc(100*sizeof(char *));
  for(i = 0; i < 100; i++) {
    value[i] = (char *) malloc(20 * sizeof(char));
    oid[i] = (char *) malloc(20 * sizeof(char));
  }
  do {
    printf("Menu\n\n");
    printf("1. Ler dados do terminal\n");
    printf("2. Ler dados de ficheiro\n");
    printf("3. Sair\n");
    printf("\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        temp = menu_terminal();
        break;
      case 2:
        //temp = menu_ficheiro();
        break;
      case 3:
        printf("Programa terminado\n");
        break;
      default:
        printf("Opção errada\n");
        break;
   }
 }
 while (choice != 3);
}
*/

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
            break;
        case 2:
            *responseType = 2;
            break;
        case 3:
            *responseType = 3;
            break;
        case 4:
            *responseType = 4;
            break;
        case 5:
            *responseType = 5;
            buildTypeValue(typeSave+2, value, flag, indexVal, indexflag);
            break;
    }
}


void buildPdu(char *line, char **oid, char **value, int *flag,
                uint8_t *buffer_final, int *indexflag, 
                int *indexOid, int *indexVal, int nFields, int *n){
    char *tok;
    char *error_status, *error_index, *non_repeaters, *max_repetitions;
    int *responseType = malloc(sizeof(int));
    char *type;
    tok = strtok(line, " ");
    switch(atoi(tok)){
        case 1:
            tok = strtok(NULL, " ");
            oid[(*indexOid)++] = tok;
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = getRequest(version, community, 1, oid, buffer_final);
            }
            break;
        case 2:
            tok = strtok(NULL, " ");
            oid[(*indexOid)++] = tok;
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = getNextRequest(version, community, 2, oid, buffer_final);
            }
            break;
        case 3:
            tok = strtok(NULL, " ");
            non_repeaters = strdup(tok);
            tok = strtok(NULL, " ");
            max_repetitions = strdup(tok);
            tok = strtok(NULL, " ");
            oid[(*indexOid)++] = strdup(tok);
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = getBulkRequest(version, community, 3, oid, atol(non_repeaters),
                       atol(max_repetitions), buffer_final);
            }
            break;
        case 4:
            tok = strtok(NULL, " ");
            error_status = strdup(tok);
            tok = strtok(NULL, " ");
            error_index = strdup(tok);
            tok = strtok(NULL, " ");
            oid[(*indexOid)++] = strdup(tok);
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
            break;
        case 5:
            tok = strtok(NULL, " ");
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
            tok = strtok(NULL, " ");
            oid[(*indexOid)++] = tok;
            if((*indexOid) == nFields){
                oid[*indexOid] = NULL;
                *n = informRequest(version, community, 6, oid, buffer_final);
            }
            break;
        case 7:
            tok = strtok(NULL, " ");
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

}

void readFromFile(char **oid, char **value, int *flag, uint8_t *buffer_final,
                   int *n, char *filename){
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
                n);
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

  //int temp;*/
  //temp = menu_principal();
  //int i, n;

  
/*
  //testar com diferentes tipos de valores, necessita de o ultimo valor estar a NULL;
  value[0] = "puat"; value[1] = "11"; value[2] = NULL;
  flag[0] = 2;            flag[1] = 1;
  oid[0] = "1.2.3.4";     oid[1] = "5.6.7.8";   oid[2] = NULL;

  //testar getRequest
  //versão, community, tag, oid, buffer_final
 // n = getRequest(2, "public", 1, oid, buffer_final);

  n = setRequest(flag, 2, "public", 5, oid, value, buffer_final);
*/
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    socklen_t udp_socket_size = sizeof(addr);
    int sent = sendto(sock, buffer_final, n, 0, (struct sockaddr *)&addr,
                    udp_socket_size);


    printf("Sended %d Bytes\n", sent);
  //testar setRequest



  //imprime
  /*
  i = 0;
  printf("Codificação buffer final: \n\n");
  while (i != n) {
  printf("%02x ", buffer_final[i] & 0xff);
    i++;
  }*/
}
