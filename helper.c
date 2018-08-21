#include "shell.h"
/**
 * string_split - Entry Point
 * Description: split a string of string into array of pointer
 * @buffer: source string
 * @array: array of string. Each substring will be stored here
 * @read: number of
 * Return: Returns the number of characters counted, - NULL.
 */
int string_split(char *buffer, char **array, int read)
{
	int i, j, k;

	for (i = 0, k = 0, j = 0; i <= read; i++)
	{
		if (buffer[i] == ' ' || buffer[i] == '\n')
		{
			buffer[i] = '\0';
			array[k] = &buffer[j];
			j = i + 1;
			k++;
		}
		array[k] = NULL;
	}
	return (k);
}
/**
 * argv_check - Entry Point
 * Description: check status of argument in /bin/ and /usr/bin
 * @av1: First argument from user.
 * @av2: Second argument from user.
 * @f_av1: string of path: /bin/
 * @f_av2: string of path: /usr/bin/
 * Return: pointer of str that contain valid path. Or, return str of command.
 */
char *argv_check(char *av1, char *av2, char *f_av1, char *f_av2)
{
	struct stat st;

	/* handle exit function */
	if (_strcmp(av1, "exit") == 0)
	{
		if (av2 == NULL)
			exit(0);
		else
			exit(_stoi(av2));
	}
	/* handle local functions */
	if (stat(av1, &st) == 0)
		return (av1);

	/* else case */
	_strcat(f_av1, av1);
	if (stat(f_av1, &st) == 0)
		return (f_av1);
	_strcat(f_av2, av1);
	if (stat(f_av2, &st) == 0)
		return (f_av2);

	/* return av1 by default */
	return (av1);
}
