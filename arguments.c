#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"
#define BUFSIZE 1024

int main(void)
{
	int status = 1;
	int read;
	size_t size = BUFSIZE;
	char *buffer;
	char *f_av;
	char f_av1[BUFSIZE];
	char f_av2[BUFSIZE];
	char **arguments = NULL;
	pid_t child_pid;

	while(status)
	{
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			perror ("ERROR!");
			status = 0;
		}
		else if (read == 0)
			status = 0;
		else
		{
			arguments = malloc(sizeof(char) * size);
			string_split(buffer, arguments, read);
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}
			else if (child_pid == 0)
			{
				_strcpy(f_av1, "/bin/");
				_strcpy(f_av2, "/usr/bin/");
				f_av = argv_check(arguments[0], f_av1, f_av2);
				if (execve(f_av, arguments, NULL) != -1)
					free(arguments);
				else
						perror("Error:");
			}
			else
			{
				wait(NULL);
			}
		}
	}
	return (0);
}
