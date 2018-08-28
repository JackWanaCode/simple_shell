#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, prev_cwd[200];
	int rd = 0, ct = 0;
	size_t size = 0;
	int status = 1;
	char *name;

	(void)argc;
	name = &(argv[0][2]);
	_memset(prev_cwd, 0, 200);
	_strcpy(prev_cwd, _getenv(env, "PWD"));

	while (status)
	{
		ct++;
		_putstring("$ ");
		rd = getline(&buffer, &size, stdin);
		if (rd != 1 && rd != -1)
			exec_func(buffer, rd, name, prev_cwd, ct, env);
		else if (rd == 1)
			continue;
		else if (rd == -1)
			status = 0;
	}
	if (buffer)
		free(buffer);
/*	free(prev_cwd);
 */	return (0);
}
