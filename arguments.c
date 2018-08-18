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
	int i = 0;
	int status = 1;
	int read;
	size_t size = BUFSIZE;
	char *buffer;
	char f_av[BUFSIZE] = "/bin/";
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
				{
					for (i = 0; arguments[0][i] != '\0'; i++)
						f_av[i + 5] = arguments[0][i];
					f_av[i + 5] = '\0';
					printf("%s", f_av);
					if (execve(f_av, arguments, NULL) == -1)
						perror("Error:");
				}
			}
			else
				wait(NULL);
			free(arguments);
		}
	}
	return (0);
}
