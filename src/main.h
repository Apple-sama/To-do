#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** dynamic_append(char *args, char **list);
void printlist(char** list);
char** addfn(char ** list);

char** readfile(char* filename, int *listlen, char** list);

#endif // !MAIN_H
