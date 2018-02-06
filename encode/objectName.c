#include <objectName.h>

int fill_oid(char* oid, uint8_t* name) {
  char *oidentifier = strdup(oid);
  char *string;
  int id;
  int i;
  name[0] = 29;
  i = 1;
  string = strtok(oidentifier,".");
  while (string != NULL) {
    id = atoi(string);
    name[i] = id;
    i++;
    string = strtok(NULL, ".");
  }
  return i;
}

ObjectName_t* create_object_name(ObjectName_t* object_name, char* oid) {
  uint8_t* name;
  int size;
  name = malloc(1024*sizeof(uint8_t));
  size = fill_oid(oid, name);
  object_name = malloc(sizeof(ObjectName_t));
  object_name->buf = name;
  object_name->size = size;
  return object_name;
}
