#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

int main(int ac, char **av)
{
	int i;

	printf("Arguments: \n");
	printf("argc is: %d\n", ac);
	for (i = 0; av[i] != NULL; i++)
	{
		printf("Argument number %d: %s\n", i, av[i]);
	}

	printf("End of arguments:\n");

	int status = 1;
	size_t read;
	size_t size = BUFSIZE;
	char *buffer;

	while(status)
	{
		printf("$ ");
		buffer = malloc(sizeof(char) * size);
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			puts ("ERROR!");
			status = 0;
		}
		else if (read == 0)
			status = 0;
		else
		{
			printf("%s", buffer);
			free(buffer);
		}
	}
	return (0);
}
