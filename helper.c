#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * string_split - Entry Point
 * Description: split a string of string into array of pointer
 * @buffer: source string
 * @array: array of string. Each substring will be stored here
 * @read: number of
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
	}
	return (k);
}
/**
 * argv_check - Entry Point
 * Description: check status of argument in /bin/ and /usr/bin
 * @av: string of command from user.
 * @path1: string of path: /bin/
 * @path2: string of path: /usr/bin/
 * return: pointer of str that contain valid path. Or, return str of command.
 */
char *argv_check(char *av, char *f_av1, char *f_av2)
{
	struct stat st;

	if (stat(av, &st) == 0)
		return (av);
	_strcat(f_av1, av);
	if (stat(f_av1, &st) == 0)
		return (f_av1);
	_strcat(f_av2, av);
	if(stat(f_av2, &st) == 0)
		return (f_av2);
	return (av);
}

/**
 * _strcat - Entry point
 * Description: concatenate a string from source to destination.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	int bool = 1;

	for (i = 0; bool == 1; i++)
	{
		if (*(dest + i) == '\0')
		{
			for (j = 0; *(src + j) != '\0'; j++, i++)
				*(dest + i) = *(src + j);
			*(dest + i) = '\0';
			bool = 0;
		}
	}
	return (dest);
}
/**
 * _strcpy - Entry point
 * Description: copy a string to another string.
 * @dest:  str is to be printed after copying.
 * @src: source of string
 *
 * Return: no return.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}
