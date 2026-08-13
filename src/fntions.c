#include "main.h"

char** readfile(char* filename, int *listlen, char** list) {
  FILE *fptr = fopen(filename, "r");

  if (fptr == NULL) {
    // return -1;
    printf("file doesn't exist!");
    exit(1);
  }

  int count = 0;
  char data[200];
  while (fgets(data, 200, fptr) != NULL) {
    list = dynamic_append(data, list);
    count++;
  }
  
  fclose(fptr);

  *listlen = count;
  return list;
}
