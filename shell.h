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

/* global variables */
extern char **environ;
extern char *prev_cwd;
extern int count;
extern char *name;

/* string manipulation */
int string_split(char *buffer, char **array, int read);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _stoi(char *s);
int string_mod(char *str);
int _strlen(char *s);
char *_memset(char *s, char b, unsigned int n);

/* printing helper function */
int _putchar(char c);
int _putstring(char *str);
void print_num(void);

/* program executing fucntion */
int exec_function(char *buffer, int read);

/* helper functions for executing program / command */
void argv_check(char *av0, char *f_av);
int built_in(char *av1, char *av2, char **av);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
void change_dir(char *av2);
void free_helper(char *av1, char *cwd, char **av);

#endif
