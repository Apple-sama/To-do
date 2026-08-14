#include "main.h"
#include <stdio.h>

char** readfile(char* filepath, int *listlen, char** list) {
  FILE *fptr = fopen(filepath, "r");

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

int writefile(char* filepath, int *listlen, char** file) {

  FILE *fptr = fopen(filepath, "w");
  
  if (fptr == NULL) {
    printf("wasn't able to write");
    return 0;
  }

  for (int i = 0; i < *listlen; i++) {
    fputs(file[i], fptr);
  }
  
  fclose(fptr);
  printf("wrote the content!");
  return 1;
}
