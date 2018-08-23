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

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
        char *str;
        struct list_s *next;
} list_t;

int string_split(char *buffer, char **array, int read);
char *argv_check(char *av1, char *f_av1, char *f_av2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _stoi(char *s);
int _putstring(char *str);
int built_in(char *av1, char *av2);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
void free_list(list_t *head);
list_t *add_node(list_t **head, char *str);
list_t *add_node_end(list_t **head, char *str);
size_t print_list(list_t *h);
int exec_function(char *buffer, int read);
char *change_dir(char *av2, char *prev_cwd);

#endif
