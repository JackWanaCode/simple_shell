#include "shell.h"

#define BUFSIZE 1024

int main(int argc, char **argv)
{
	int read = 0, count = 0;
	size_t size = BUFSIZE;
	char *buffer = NULL;
	char *f_av = NULL;
	char f_av1[BUFSIZE], f_av2[BUFSIZE];
	char **av = NULL;
	pid_t child_pid;
	char *readcwd = NULL, *prev_cwd = NULL, *cur_cwd = NULL;
	(void)argc;

	while (++count)
	{
		readcwd = getcwd(NULL, BUFSIZE);
		prev_cwd = cur_cwd;
		cur_cwd = readcwd;
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			_putstring("\n");
			free(readcwd);
			break;
		}
		/* If user hits enter, just prompt again */
		else if (read == 1)
		{
			free(readcwd);
			continue;
		}
		else
		{
			av = malloc(sizeof(char) * size);
			if (av == NULL)
			{
				free(readcwd);
				free(buffer);
				return (1);
			}
			string_split(buffer, av, read);
			/* check with built_in funcs */
			if (built_in(av[0], av[1], prev_cwd) == 1)
			{
/*				free(readcwd);
                                free(buffer);
				free(av);
*/				continue;
			}
			/* check the valid of command */
			_strcpy(f_av1, "/bin/");
			_strcpy(f_av2, "/usr/bin/");
			f_av = argv_check(av[0], f_av1, f_av2);

			/* fork the program */
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork Error:");
				free(av);
				free(buffer);
				free(readcwd);
				return (1);
			}
			else if (child_pid == 0)
			{
				/* run the valid command */
				if (execve(f_av, av, NULL) == -1)
				{
					printf("%s: %d: %s: not found\n", argv[0], count, av[0]);
					free(av);
					free(buffer);
					free(readcwd);
					exit(0);
				}
			}
			else
				wait(NULL);
		}
		free(av);
		free(readcwd);
	}
	free(buffer);
	return (0);
}
