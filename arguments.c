#include "shell.h"

char *prev_cwd;
int main()
{
	char *buffer = NULL;
	int read = 0;
	size_t size = 1024;
	int status = 1;
	prev_cwd = getcwd(NULL, 150);

	while (status)
	{
		_putstring("$ ");
		read = getline(&buffer, &size, stdin);
		if (read != 1 && read != -1)
		{
			exec_function(buffer, read);
		}
		else if (read == 1)
		{
			continue;
		}
		else if (read == -1)
		{
			printf("read is %i\n", read);
			_putstring("read = -1: Error\n");
			status = 0;
		}
	}
	if (buffer)
		free(buffer);
	free(prev_cwd);
	return (0);
}
