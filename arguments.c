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
	char *buffer = NULL;
	char *f_av = NULL;
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
			arguments = malloc(sizeof(char) * read);
			string_split(buffer, arguments, read);
			if (_strcmp(arguments[0], "cd") == 0)
			{
				if (arguments[1] == NULL)
					perror ("Error");
				else
					if (chdir(arguments[1]) != 0)
						perror("Error");
				continue;
			}
			_strcpy(f_av1, "/bin/");
			_strcpy(f_av2, "/usr/bin/");
			f_av = argv_check(arguments[0], arguments[1], f_av1, f_av2);
/* fork the program */
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}
			else if (child_pid == 0)
			{

				if (execve(f_av, arguments, NULL) == -1)
				{
					perror("execve error");
					free(av);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		free(arguments);
	}
	return (0);
}
