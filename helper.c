#include "shell.h"

/**
 * argv_check - Entry point
 * Description: Check status of argument in /bin/ and /usr/bin
 * @av1: First argument from user.
 * @f_av1: String of path: /bin/
 * @f_av2: String of path: /usr/bin/
 * Return: Pointer of str that contain valid path. Or, return str of command.
 */

char *argv_check(char *av1, char *f_av1, char *f_av2)
{
	struct stat st;

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

/**
 * built_in - Entry point.
 * Description: Check for valid built_in function and run it.
 * @av1: The first argument passed.
 * @av2: The second argument passed.
 * Return: 1 if valid, else 0;
 */

int built_in(char *av1, char *av2)
{

	/* exit function */
	if (_strcmp(av1, "exit") == 0)
	{
		if (av2 == NULL)
			exit(0);
		else
			exit(_stoi(av2));
		return (1);
	}

	/* env */
	if (_strcmp(av1, "env") == 0)
	{
		int i = 0;

		while (environ[i])
		{
			_putstring(environ[i++]);
			_putstring("\n");
		}
		return (1);
	}
	return (0);
}

/**
 * _getenv - Entry point
 * Description: Get the value of environment.
 * @name: Name of environment
 * Return: String of value of environment.
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0, len = 0;

	for (len = 0; name[len] != '\0'; len++)
		;
	while (environ[i])
	{
		for (j = 0; environ[i][j] == name[j]; j++)
			;
		if (j == len)
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}

/**
 * _setenv - Entry point
 * Description: Get the value of environment.
 * @name: Name of environment.
 * @value: String of the value.
 * @overwrite: Determines when to overwrite.
 * Return: String of value of environment.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0, len = 0;

	for (len = 0; name[len] != '\0'; len++)
		;
	while (environ[i] && overwrite > 0)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
			;
		if (j == len)
		{
			environ[i][len] = '=';
			for (j = 0; value[j] != '\0'; j++)
			{
				environ[i][len + j + 1] = value[j];
			}
			environ[i][len + j + 1] = '\0';
			break;
		}
		i++;
	}
	return (0);
}
/**
 * change_dir - Entry point
 * @av2: The second argument from the user.
 * @prev_cwd: The previous working directory
 * Return: Returns a pointer to the updated directory.
 */
char *prev_cwd;
char *change_dir(char *av2)
{
	char str[100];
	char *temp;

	temp = getcwd(NULL, 150);

	if (prev_cwd == NULL)
		prev_cwd = temp;

	_strcpy(str, _getenv("HOME"));
	if ((av2 == NULL) || (_strcmp(av2, "$HOME") == 0))
	{
		chdir(str);
		prev_cwd = temp;
		_setenv("PWD", str, 1);
		return (temp);
	}
	else if (_strcmp(av2, "-") == 0)
	{
		chdir(prev_cwd);
		prev_cwd = temp;
		_setenv("PWD", prev_cwd, 1);
		return (temp);
	}
	else if (chdir(av2) == 0)
	{
		prev_cwd = temp;
		_strcat(str, "/");
		_strcat(str, av2);
		_setenv("PWD", str, 1);
		return (temp);
	}
	else
		perror("Error");
	return (temp);
}
