#include "shell.h"
#include "holberton.h"

/**
 * main - Entry point
 * Description: Entry point for our shell. Prompts user for input and decides
 * how to handle the incoming commands.
 * @argc: The count of arguments passed.
 * @argv: The arguments passed.
 * @env: Gets the enviornment.
 * Return: 0 upon successful completion.
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, prev_cwd[200];
	int rd = 0, ct = 0;
	size_t size = 0;
	int status = 1, i = 0, check;
	char *name;

	(void)argc;
	name = &(argv[0][2]);
	_memset(prev_cwd, 0, 200);
	_strcpy(prev_cwd, _getenv(env, "PWD"));
	signal(SIGINT, sigintHandler);
	while (status)
	{
		ct++;
		check = 0;
		_printf("%s$ ", &argv[0][2]);
		rd = getline(&buffer, &size, stdin);
		for (i = 0; buffer[i] != '\0'; i++)
			if (buffer[i] == ' ' || buffer[i] == '\t')
				check++;
		if (rd == 1 || rd == check + 1)
			continue;
		else if (rd == -1)
			status = 0;
		else
			exec_func(buffer, rd, name, prev_cwd, ct, env);
	}
	if (buffer)
		free(buffer);
	_printf("\n");
	return (0);
}
