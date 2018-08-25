#include "shell.h"

/**
 * _putchar - Prints a char.
 * @c: The character to print.
 * Return: Returns the written char.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstring - Prints a string.
 * @str: The string to be printed.
 * Return: Number of chars. printed.
 */

int _putstring(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\0');
	return (i);
}

/**
 * string_split - Entry Point
 * Description: Split a string of string into array of pointer
 * @buffer: Source string.
 * @array: Array of string. Each substring will be stored here.
 * @read: Number .
 * Return: Returns the number of characters counted, - NULL.
 */

int string_split(char *buffer, char **array, int read)
{
	int i, j, k;

	printf("bf buffer is %s\n", buffer);
	string_mod(buffer);
	printf("af buffer is %s\n", buffer);
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
 * string_mod - Entry Point
 * Description: Uniq the two or more continous whitespaces.
 * @str: Source string.
 * Return: nothing
 */
void string_mod(char *str)
{
	int i = 0, j = 0;

	for (i = 0; str[i] != '\0';)
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != ' ' && str[i] != '\0')
		{
			str[j] = str[i];
			j++;
			i++;
		}
		if (str[i] != '\0')
			str[j++] = ' ';
	}
	while (str[j] != '\0')
		str[j++] = '\0';
}
