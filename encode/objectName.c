#include <stdio.h>
#include <stdint.h>
#include <ObjectName.h>

uint8_t* fill_oid(const char* oid, uint8_t* name) {
  char *oidentifier = strdup(oid);
  char *string;
  int id;
  int i;
  i = 0;
  name = calloc(1024, sizeof(uint8_t));
  string = strtok(oidentifier,".");
  while (string != NULL) {
    id = atoi(string);
    name[i] = id;
    i++;
    string = strtok(NULL, ".");
  }
  return name;
}

ObjectName_t* create_object_name(ObjectName_t* object_name, const char* oid) {
  uint8_t* name;
  name = fill_oid(oid, name);
  object_name = calloc(1, sizeof(ObjectName_t));
  object_name->buf = name;
  object_name->size = sizeof(name);
  return object_name;
}
