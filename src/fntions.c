#include "main.h"
#include <stdio.h>
#include <string.h>

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
  printf("\nwrote the content!");
  return 1;
}

void pop(char*** list, int *listlen, int *list_len) {
  int dnum;

  printf("No of Task u wanna delete $ ");
  if (scanf("%d", &dnum) != 1 || --dnum < 0 || dnum >= *listlen) {
    printf("Invalid index!\n");
    return;
    }
  
  char* ptask = (*list)[dnum];

  for (int i=dnum; i<*listlen-1; i++) {
    (*list)[i] = (*list)[i+1];
  }

  (*listlen)--;

  if (*listlen > 0) {
    char **tmp = realloc(*list, (*list_len) * sizeof(char*));
    if (tmp != NULL) {
      *list = tmp;
    }
  }
  ptask[strlen(ptask)-1] = 0;
  printf("deleted the Task [%s]\n", ptask);
  free(ptask);

}
