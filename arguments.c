#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#define BUFSIZE 1024

int main(void)
{
/*	int i = 0, j = 0;
 */	int status = 1;
	int read;
	size_t size = BUFSIZE;
	char *buffer;
	char **arguments = NULL;
	pid_t child_pid;

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
			string_split(buffer, arguments);
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}
			else if (child_pid == 0)
			{
				if (execve(arguments[0], arguments, NULL) == -1)
					perror("Error:");
			}
			else
				wait(NULL);
			free(arguments);
		}
	}
	return (0);
}
