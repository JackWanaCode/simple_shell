#include "shell.h"

/**
 * argv_check - Entry point
 * Description: Check status of argument in /bin/ and /usr/bin
 * @av0: First argument from user.
 * @f_av: pointer to a full path of command.
 * Return: nothing
 */

void argv_check(char *av0, char *f_av, char **env)
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
	str = _getenv(env, "PATH");
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

int built_in(char **av, char *prev_cwd, char **env, char *name, int count)
{
	long i = 0;
	int j = 0;

	if (_strcmp(av[0], "cd") == 0)
        {
                change_dir(av[1], prev_cwd, env);
                free(av);
                return (1);
        }
	if (_strcmp(av[0], "exit") == 0)
	{
		if (av[1] == NULL)
		{
			free_helper(av);
			exit(0);
		}
		else
		{
			i = _stoi(av[1]);
			if (i > INT_MAX || i < 0)
			{
				write(1, name, _strlen(name));
				write(1, ": ", 2);
				print_num(count);
				write(1, ": ", 2);
				_putstring(av[0]);
				write(1, ": ", 2);
				_putstring("Illegal number: ");
				_putstring(av[1]);
				_putstring("\n");
				free(av);
				return (1);
			}
			else if (i >= 0)
			{
				free_helper(av);
				exit(i);
			}
			else
			{
				free_helper(av);
				exit(0);
			}
		}
	}
	if (_strcmp(av[0], "env") == 0)
	{
		while (env[j])
		{
			_putstring(env[j++]);
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

char *_getenv(char **env, const char *name)
{
	int i = 0, j = 0, len = 0;

	for (len = 0; name[len] != '\0'; len++)
		;
	while (env[i])
	{
		for (j = 0; env[i][j] == name[j]; j++)
			;
		if (j == len)
			return (&env[i][len + 1]);
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

int _setenv(char **env, const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0, len = 0;

	for (len = 0; name[len] != '\0'; len++)
		;
	while (env[i] && overwrite > 0)
	{
		for (j = 0; env[i][j] == name[j]; j++)
			;
		if (j == len)
		{
			env[i][len] = '=';
			for (j = 0; value[j] != '\0'; j++)
				env[i][len + j + 1] = value[j];
			env[i][len + j + 1] = '\0';
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

void change_dir(char *av2, char *prev_cwd, char **env)
{
	char str[200];

	_strcpy(str, _getenv(env, "HOME"));
	if ((av2 == NULL) || (_strcmp(av2, "$HOME") == 0))
	{
		chdir(str);
		_memset(prev_cwd, 0, 200);
		_strcpy(prev_cwd, _getenv(env, "PWD"));
 		_setenv(env, "PWD", str, 1);
	}
	else if (_strcmp(av2, "-") == 0)
	{
		chdir(prev_cwd);
		_memset(prev_cwd, 0, 200);
                _strcpy(prev_cwd, _getenv(env, "PWD"));
		_setenv(env, "PWD", prev_cwd, 1);
	}
	else if (chdir(av2) == 0)
	{
		_memset(prev_cwd, 0, 200);
                _strcpy(prev_cwd, _getenv(env, "PWD"));
		_strcat(str, "/");
                _strcat(str, av2);
		_setenv(env, "PWD", str, 1);
	}
	else
	{
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

void free_helper(char **av)
{
	free(av[0]);
	free(av);
}
