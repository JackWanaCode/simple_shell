#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

int string_split(char *buffer, char **array, int read);
char *argv_check(char *av0, char *av1, char *f_av1, char *f_av2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _stoi(char *s);

#endif
