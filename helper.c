#include "shell.h"

extern char **environ;

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
 * @f_av1: string of path: /bin/
 * @f_av2: string of path: /usr/bin/
 * Return: pointer of str that contain valid path. Or, return str of command.
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
 * built_in - Entry Point
 * Description: check the valid built_in function and run it.
 * @name: name of function
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
 * _getenv - Entry Point
 * Description: get the value of environment.
 * @name: name of environment
 * Return: string of value of environment.
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
 * _getenv - Entry Point
 * Description: get the value of environment.
 * @name: name of environment
 * Return: string of value of environment.
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

char *change_dir(char *av2, char *prev_cwd)
{
	char str[100];
	char *temp;

	temp = getcwd(NULL, 150);

	if (prev_cwd == NULL)
		prev_cwd = temp;

	_strcpy(str, _getenv("HOME"));
	if ((av2 == NULL) || (_strcmp(av2, "$HOME") \
			      == 0))
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
