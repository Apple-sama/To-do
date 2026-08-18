#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** dynamic_append(char *args, char **list);
void printlist(char** list);
char** addfn(char ** list);

char** readfile(char* filename, int *listlen, char** list);
int writefile(char* filename, int *listlen, char** file);
void pop(char*** list, int *listlen, int *global_len);

#endif // !MAIN_H
