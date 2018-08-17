#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 *
 *
 *
 */
int string_split(char *buffer, char **array)
{
	int i = 0;
	char *token = strtok(buffer, " ");
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	return (i);
}
