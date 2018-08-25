#include "shell.h"

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

	string_mod(buffer);
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
 * Return: None.
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

/**
 * print_num - Prints a number as int type.
 * Return: None.
 */
void print_num(void)
{
	int max_digit_int = 1000000000;
	int temp_num = 0;
	int num = count;

	while (num / max_digit_int == 0)
		max_digit_int /= 10;
	while (max_digit_int > 0)
	{
		temp_num = num / max_digit_int;
		num = num % max_digit_int;
		_putchar(temp_num + '0');
		max_digit_int /= 10;
	}
}

/**
 * _strlen - Entry point
 * Description: Return length of a string.
 * @s: String is to be checked.
 * Return: String length value.
 */
int _strlen(char *s)
{
	int ct = 0;

	while (*(s + ct) != '\0')
		ct++;
	return (ct);
}
