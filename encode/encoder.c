#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ObjectSyntax.h>
#include <PDUs.h>
#include <primitives.h>


#define clear() printf("\033[H\033[J")

long id;
char* ip;
char* porta;
char* community;
char** oid;
long version;
char** value;
int flag[100];
uint8_t buffer_final[1024];

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

void aloca() {
  int i;
  value = (char**) malloc(100*sizeof(char *));
  oid = (char**) malloc(100*sizeof(char *));
  for(i = 0; i < 100; i++) {
    value[i] = (char *) malloc(20 * sizeof(char));
    oid[i] = (char *) malloc(20 * sizeof(char));
  }
}

int main() {
  int temp;
  //temp = menu_principal();
  int i, n;

  aloca();

  //testar com diferentes tipos de valores, necessita de o ultimo valor estar a NULL;
  value[0] = "10"; /*value[1] = "11";*/ value[1] = NULL;
  flag[0] = 1;            //flag[1] = 1;
  oid[0] = "1.2.3.4";     /*oid[1] = "5.6.7.8";*/     oid[1] = NULL;

  //testar getRequest
  //versão, community, tag, oid, buffer_final
  //n = getRequest(2, "public", 1, oid, buffer_final);

  n = setRequest(flag, 2, "public", 5, oid, value, buffer_final);

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8954);
  addr.sin_addr.s_addr = inet_addr("192.168.1.125");
  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  socklen_t udp_socket_size = sizeof(addr);
  int sent = sendto(sock, buffer_final, sizeof(buffer_final), 0, (struct sockaddr *)&addr,
                    udp_socket_size);
  printf("ola\n");
  //testar setRequest



  //imprime

  i = 0;
  printf("Codificação buffer final: \n\n");
  while (i != n) {
  printf("%02x ", buffer_final[i] & 0xff);
    i++;
  }


/*
Message_t *messaged = 0;
asn_dec_rval_t rval1 = asn_decode(0, ATS_BER, &asn_DEF_Message,
                              (void **)&messaged, buffer_final, sizeof(buffer_final)); //tratar erro se der -1
if(rval1.code ==  RC_FAIL){ //significa que a descodificaçaºo falhou, está a entrar no if nao sei bem porque
  printf("fail\n");
}
printf("Message_SIZE = %d\n",messaged->data.size );
PDUs_t* pdud = 0;
asn_dec_rval_t rval2 = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
                              (void **)&pdud, messaged->data.buf, messaged->data.size); //tratar erro se der -1
if(rval2.code ==  RC_WMORE){ //significa que a descodificaçaºo falhou, está a entrar no if nao sei bem porque
  printf("Want More info\n");
}
VarBindList_t var_bindingsd = pdud->choice.set_request.variable_bindings;
printf("List_VarBindings_Size = %d\n", var_bindingsd.list.count);
VarBind_t* var_bindd = var_bindingsd.list.array[0];
ObjectName_t* object_named = &(var_bindd->name);
ObjectSyntax_t* object_syntaxd = &(var_bindd->choice.choice.value);
/*char *str = (char *) object_named->buf;
char *final = malloc(1024);
snprintf(final, 1024, "%s%c", str, '\0');
printf("%s\n", final);
*/
}
