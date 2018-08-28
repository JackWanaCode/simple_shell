#include "shell.h"
#include "holberton.h"

/**
 * string_split - Entry point
 * Description: Split a string of string into array of pointer.
 * @buffer: Source string.
 * @array: Array of string. Each substring will be stored here.
 * @read: Length of the string buffer.
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
 * string_mod - Entry point
 * Description: Find and remove continous whitespaces, create a string
 * without extra spaces.
 * @str: Source string.
 * Return: None.
 */

int string_mod(char *str)
{
	int i = 0, j = 0, str_ct = 0, check = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t')
		{
			check = 1;
			str[j++] = str[i++];
		}
		if (check == 1)
		{
			str_ct += 1;
			check = 0;
		}
		if (str[i] != '\0')
			str[j++] = ' ';
	}
	while (str[j] != '\0')
		str[j++] = '\0';
	return (str_ct);
}
