#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcount = 0;
int lcount = 3;

void printlist(char** list) {
  
  printf("\n\nThe appended tasks are...\n");
  for (int i = 0; i < gcount; i++) {
    printf(">> %s", list[i]);
  }
}

char** dynamic_append(char *args, char **list) {

  list[gcount++] = strdup(args);
  lcount++;
  // increasing the size of list
  char** temp = realloc(list, lcount * sizeof(*list));

  if (temp == NULL) {
    for (int i = 0; i < gcount; i++) {
      free(list[i]);}
    free(list);
    perror("realloc");
    exit(1);
  }

  return temp;

}

int main() {
  char** list = calloc(lcount, sizeof(*list));

  char *input = NULL;
  size_t size = 0;
  
  printf("Enter the Tasks...\n");
  while(1) {
    printf("$ ");
    if (getline(&input, &size, stdin) == -1){break;};

    list = dynamic_append(input, list);
  }
  
  printlist(list);

  for (int i = 0; i < gcount; i++) {
    free(list[i]);
  }
  
  free(list);
  free(input);

}


