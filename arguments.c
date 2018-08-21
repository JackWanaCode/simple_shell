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
	char **av = NULL;
	pid_t child_pid;

	while (status)
	{
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			perror("getline ERROR!");
			status = 0;
		}
		else if (read == 0)
			status = 0;
/* If user hits enter, just prompt again */
		else if (read == 1)
			continue;
		else
		{
			av = malloc(sizeof(char) * size);
			string_split(buffer, av, read);
			if (_strcmp(av[0], "cd") == 0)
			{
				if (av[1] == NULL)
					perror("error");
				else
					if (chdir(av[1]) != 0)
						perror("Error");
				continue;
			}
			_strcpy(f_av1, "/bin/");
			_strcpy(f_av2, "/usr/bin/");
			printf("%s\n", av[0]);
			f_av = argv_check(av[0], av[1], f_av1, f_av2);

			/* fork the program */
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork Error:");
				return (1);
			}
			else if (child_pid == 0)
			{
				if (execve(f_av, av, NULL) == -1)
				{
					perror("execve error");
					exit(0);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		free(av);
	}
	free(buffer);
	return (0);

}
