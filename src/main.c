#include "main.h"
#include <stdio.h>

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
  
  printf("got here");
  free(input);
  return list;
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
  printf("before : %d", lcount);
  printf("before : %d", gcount);
  char** list = calloc(lcount, sizeof(*list));

  char *cmd= NULL;
  size_t size = 0;
  
  char *filepath = "file.txt";
  FILE *fptr = fopen(filepath, "a");

  // reading from file for tasks.
  list = readfile(filepath, &gcount, list);
  printf("after : %d", lcount);
  printf("after : %d", gcount);

  while(1) {
    printf("\nchoose the command u wanna use...\nAdd (a) || Print the list (p) || quit (ctrl+d)\n>>");
    if (getline(&cmd, &size, stdin) == -1){break;}
    if (!strcmp(cmd, "q\n")) {break;}
    if (!strcmp(cmd, "a\n")) {list = addfn(list);}
    if (!strcmp(cmd, "p\n")) {printlist(list);}
    if (!strcmp(cmd, "d\n")) {pop(list, &lcount);}
  }

  // dumping the data in file
  writefile(filepath, &gcount, list);
  printf("\nThx for using!!\n");

  for (int i = 0; i < gcount; i++) {
    free(list[i]);
  }
  
  free(list);
  free(cmd);

}


