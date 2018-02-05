#include <stdio.h>
#include <stdint.h>
#include <ObjectSyntax.h>
#include <PDUs.h>
#include <primitives.h>

const char* id;
const char* ip;
const char* porta;
const char* community;
const char* oid;
const char* version;
const char* value;
const char* flag;

int menu_values() {
  char str[80];
  int temp;
  int choice;
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
        flag = "1";
        break;
      case 2:
        flag = "2";
        break;
      case 3:
        flag = "3";
        break;
      case 4:
        flag = "4";
        break;
      case 5:
        flag = "5";
        break;
      case 6:
        flag = "6";
        break;
      case 7:
        flag = "7";
        break;
      case 8:
        flag = "8";
        break;
      case 9:
        flag = "9";
        break;
      case 10:
        printf("Programa terminado\n");
        break;
      default:
        printf("Opção errada\n");
        break;
   }
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
  printf("OID: ");
  fgets(str, 80, stdin);
  oid = str;
  temp = menu_values();
  uint8_t *buffer_final;
  buffer_final = setRequest(flag,version,community,id,oid,"123", buffer_final);
  printf("Tamanho do buffer final: %d\n", sizeof(buffer_final));
  printf("Codificação buffer final: \n%02x %02x %02x %02x %02x %02x %02x %02x\n",
         buffer_final[0] & 0xff, buffer_final[1] & 0xff, buffer_final[2] & 0xff,
         buffer_final[3] & 0xff, buffer_final[4] & 0xff, buffer_final[5] & 0xff,
         buffer_final[6] & 0xff, buffer_final[7]);
  printf("\n");
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
      id = "1";
      //temp = menu_getRequest();
      break;
    case 2:
      id = "2";
      //temp = menu_getNextRequest();
      break;
    case 3:
      id = "3";
      //temp = menu_getBulkRequest();
      break;
    case 4:
      id = "4";
      //temp = menu_Response();
      break;
    case 5:
      id = "5";
      temp = menu_setRequest();
      break;
    case 6:
      id = "6";
      //temp = menu_informRequest();
      break;
    case 7:
      id = "7";
      //temp = menu_snmpv2();
      break;
    case 8:
      id = "8";
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
      version = "1";
      //temp = menu_terminal_v1();
      break;
    case 2:
      version = "2";
      temp = menu_terminal_v2();
      break;
    case 3:
      version = "3";
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


int main() {
  int temp;
  temp = menu_principal();
}
