#include "shell.h"
/**
 * exec_function - Entry point
 * Description: Execute's program. All programs located in
 * /bin/ /usr/bin, and the functions cd, exit, env.
 * @buffer: A string of arguments.
 * @read: Number of character reading.
 * Return: 0. 1 if error.
 */

int exec_func(char *buf, int rd, char *name, char *p_cwd, int ct, char **env)
{
	char f_av[100] = {'\0'};
	char **av = NULL;
	pid_t child_pid;
	int n = 0;

	/* make a string is dilimeted by whitespace */
	n = string_mod(buf);
	/* tokenized string */
	av = malloc(sizeof(char *) * (n + 1));
	if (av == NULL)
		return (1);
	string_split(buf, av, rd);
	/* check if the command for running local program or other built-in func*/
	if (built_in(av, p_cwd, env, name, ct) == 1)
	{
		return (0);
	}
	/* check if the command located in PATH */
	_strcpy(f_av, av[0]);
	argv_check(av[0], f_av, env);
        child_pid = fork();

	if (child_pid == -1)
	{
		free(av);
		perror("fork Error:");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(f_av, av, NULL) == -1)
		{
			write(1, name, _strlen(name));
			write(1, ": ", 2);
			print_num(ct);
			write(1, ": ", 2);
			write(1, av[0], rd);
			write(1, ": ", 2);
			_putstring("not found\n");
			free(av);
			exit(0);
		}
	}
	else
		wait(NULL);
	free(av);
	return (0);
}
