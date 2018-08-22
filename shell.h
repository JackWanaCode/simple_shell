#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
int string_split(char *buffer, char **array, int read);
char *argv_check(char *av1, char *f_av1, char *f_av2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _stoi(char *s);
int _putstring(char *str);
int built_in(char *av1, char *av2, char *prev_cwd);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);


#endif
