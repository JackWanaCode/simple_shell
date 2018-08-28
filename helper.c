#include "shell.h"

/**
 * argv_check - Entry point
 * Description: Check status of argument in /bin/ and /usr/bin
 * @av0: First argument from user.
 * @f_av: pointer to a full path of command.
 * Return: nothing
 */

void argv_check(char *av0, char *f_av)
{
	struct stat st;
	int i = 0, j = 0;
	char *str;

/* handle local functions */
	if (stat(av0, &st) == 0)
	{
		f_av = av0;
		return;
	}
/* else case */
	str = _getenv("PATH");
        do
        {
                if (str[i] == ':' || str[i] == '\0')
                {
                        _strcat(f_av, "/");
                        _strcat(f_av, av0);
                        if (access(f_av, X_OK) == 0)
                                return;
                        _memset(f_av, 0, _strlen(f_av));
			j = 0;
                }
                else
                        f_av[j++] = str[i];
        } while (str[i++] != '\0');
/* return av1 by default */
	_strcat(f_av, av0);
}

/**
 * built_in - Entry point
 * Description: Check for valid built_in function and run it.
 * @av1: The first argument passed.
 * @av2: The second argument passed.
 * Return: 1 if valid, else 0.
 */

int built_in(char *av1, char *av2, char **av)
{
	long i = 0;
	int j = 0;

	if (_strcmp(av1, "cd") == 0)
        {
                change_dir(av2);
                free(av);
                return (1);
        }
	if (_strcmp(av1, "exit") == 0)
	{
		if (av2 == NULL)
		{
			free_helper(av1, prev_cwd, av);
			exit(0);
		}
		else
		{
			i = _stoi(av2);
			if (i > INT_MAX || i < 0)
			{
				write(1, name, _strlen(name));
				write(1, ": ", 2);
				print_num();
				write(1, ": ", 2);
				_putstring(av1);
				write(1, ": ", 2);
				_putstring("Illegal number: ");
				_putstring(av2);
				_putstring("\n");
				free(av);
				return (1);
			}
			else if (i >= 0)
			{
				free_helper(av1, prev_cwd, av);
				exit(i);
			}
			else
			{
				free_helper(av1, prev_cwd, av);
				exit(0);
			}
		}
	}
	if (_strcmp(av1, "env") == 0)
	{
		while (environ[j])
		{
			_putstring(environ[j++]);
			_putstring("\n");
		}
		free(av);
		return (1);
	}
	return (0);
}

/**
 * _getenv - Entry point
 * Description: Get the value of environment.
 * @name: Name of environment.
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
				environ[i][len + j + 1] = value[j];
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
 * Return: Returns a pointer to the updated directory.
 */

void change_dir(char *av2)
{
	char str[100];
	char *temp = getcwd(NULL, 150);

	_strcpy(str, _getenv("HOME"));

	if ((av2 == NULL) || (_strcmp(av2, "$HOME") == 0))
	{
		chdir(str);
		free(prev_cwd);
		prev_cwd = temp;
		_setenv("PWD", str, 1);
	}
	else if (_strcmp(av2, "-") == 0)
	{
		chdir(prev_cwd);
		_setenv("PWD", prev_cwd, 1);
		free(prev_cwd);
		prev_cwd = temp;
	}
	else if (chdir(av2) == 0)
	{
		_strcat(str, "/");
                _strcat(str, av2);
		_setenv("PWD", str, 1);
		free(prev_cwd);
		prev_cwd = temp;
	}
	else
	{
		free(temp);
		_putstring("path not found\n");
	}
}
/**
 * free_helper - Entry point
 * Description: A simple funciton to free 3 times, used in
 * our builtin function.
 * @av1: First buffer to free.
 * @cwd: Second buffer to free.
 * @av: Third buffer to free.
 * Return: None.
 */

void free_helper(char *av1, char *cwd, char **av)
{
	free(av1);
	free(cwd);
	free(av);
}
