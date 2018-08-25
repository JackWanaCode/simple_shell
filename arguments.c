#include "shell.h"

int count;
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
		count++;
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
			status = 0;
		}
	}
	if (buffer)
		free(buffer);
	free(prev_cwd);
	return (0);
}
