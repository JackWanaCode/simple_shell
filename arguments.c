#include "shell.h"

char *prev_cwd = NULL;
int count = 0;
char *name = NULL;

int main(int argc, char **argv)
{
	char *buffer = NULL;
	int read = 0;
	size_t size = 0;
	int status = 1;

	(void)argc;
	name = &(argv[0][2]);
	prev_cwd = getcwd(NULL, 150);

	while (status)
	{
		count++;
		_putstring("$ ");
		read = getline(&buffer, &size, stdin);
		if (read != 1 && read != -1)
			exec_function(buffer, read);
		else if (read == 1)
			continue;
		else if (read == -1)
			status = 0;
	}
	if (buffer)
		free(buffer);
	free(prev_cwd);
	return (0);
}
