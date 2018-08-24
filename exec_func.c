#include "shell.h"

/**
 * exec_function - Entry point
 * Description: Execute's program. All programs located in
 * /bin/ /usr/bin, and the functions cd, exit, env.
 * @buffer: a string of arguments.
 * @read: number of character reading.
 * Return: 0. 1 if error.
 */

int exec_function(char *buffer, int read)
{
	char *f_av = NULL;
	char f_av1[500], f_av2[500];
	char **av = NULL;
	pid_t child_pid;
	char *cdtemp = NULL;

	av = malloc(sizeof(char) * 500);
	if (av == NULL)
	{
		return (1);
	}
	string_split(buffer, av, read);

	/* check cd */
	if (_strcmp(av[0], "cd") == 0)
	{
		cdtemp = change_dir(av[1]);
		free(av);
/*		printf("cdtemp bf free: %s\n", cdtemp);
		free(cdtemp);
		printf("cdtemp af free: %s\n", cdtemp);
*/		return (0);
	} /* check exit and env */
	else if (_strcmp(av[0], "exit") == 0)
	{
		/*	free(buffer);
			free(av); */
		built_in(av[0], av[1]);
	}
	else if (built_in(av[0], av[1]) == 1)
	{
		free(av);
		return (0);
	}

	/* check the valid of command */
	_strcpy(f_av1, "/bin/");
	_strcpy(f_av2, "/usr/bin/");
	f_av = argv_check(av[0], f_av1, f_av2);

	/* fork the program */
	child_pid = fork();
	if (child_pid == -1)
	{
		free(av);
		perror("fork Error:");
		return (1);
	}
	else if (child_pid == 0)
	{
		/* run the valid command */
		if (execve(f_av, av, NULL) == -1)
		{
			free(av);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
	}
	free(av);
	return (0);
}
