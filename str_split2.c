#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 *
 *
 *

int string_split(char *buffer, char **array)
{
	int i = 0;
	char *token = strtok(buffer, " \n");
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	array[i] = NULL;
	return (i);
}
*/
int main(void)
{
	char *buff = "What's your name?";
	char *arguments[3];
	int i, j, k, len;

	for (len = 0; buff[len] != '\0'; len++)
		;
	for (i = 0; i < len; i++)
		buff[i] = '\0';
	*arguments = malloc(sizeof(char) * (len + 1));

	for (j = 0, k = 0, i = 0; j <= len; j++)
	{
		if (arguments[j] == '\0')
		{
			*arguments[i] = buff[j - k];
			k = j;
			i++;
		}
	}
	return (0);
}
