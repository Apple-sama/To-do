#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int gcount = 0;
int lcount = 3;

void printlist(char** list) {

  if (gcount==0) {
    printf("Don't have any task in here! Add them using \'a\' :) \n");
  } else {
    printf("The appended tasks are...\n");
    for (int i = 0; i < gcount; i++) {
      printf("%d. %s", i+1, list[i]);
    }
  }
}

char** addfn(char** list) {
  char* input = NULL;
  size_t size = 0;

  printf("Enter the Tasks...\n");
  printf("$ ");
  getline(&input, &size, stdin);

  list = dynamic_append(input, list);
  
  return list;
  free(input);
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

  char *cmd= NULL;
  size_t size = 0;
 
  while(1) {
    printf("\nchoose the command u wanna use...\nAdd (a) || Print the list (p) || quit (ctrl+d)\n>>");
    if (getline(&cmd, &size, stdin) == -1){break;};
    if (!strcmp(cmd, "a\n")) {list = addfn(list);}
    if (!strcmp(cmd, "p\n")) {printlist(list);}
  }

  printf("\nThx for using!!\n");

  for (int i = 0; i < gcount; i++) {
    free(list[i]);
  }
  
  free(list);
  free(cmd);

}


