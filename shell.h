#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__
#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>


/* string manipulation */
int string_split(char *buffer, char **array, int read);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
long _stoi(char *s);
int string_mod(char *str);
char *_memset(char *s, char b, unsigned int n);

/* program executing fucntion */
int exec_func(char *buf, int rd, char *name, char *p_cwd, int ct, char **env);

/* helper functions for executing program / command */
void argv_check(char *av0, char *f_av, char **env);
int built_in(char **av, char *prev_cwd, char **env, char *name, int count);
char *_getenv(char **env, const char *name);
int _setenv(char **env, const char *name, const char *value, int overwrite);
void change_dir(char *av2, char *prev_cwd, char **env);
void free_helper(char **av);
void sigintHandler(int sig_num);
void print_num(int count);

#endif
