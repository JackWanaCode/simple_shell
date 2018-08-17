#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define BUFSIZE 1024

int main()
{
	int i = 0, j = 0;
	int status = 1;
	int read;
	size_t size = BUFSIZE;
	char *buffer;
	char **arguments = NULL;

	while(status)
	{
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			puts ("ERROR!");
			status = 0;
		}
		else if (read == 0)
			status = 0;
		else
		{
			arguments = malloc(sizeof(char) * size);
			j = string_split(buffer, arguments);
			for (i = 0; i < j; i++)
				printf("%s\n", arguments[i]);
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror("Error:");
			}
			printf("after excution");
			free(arguments);
		}
	}
	return (0);
}
