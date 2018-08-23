#include "shell.h"

/**
 * _strcat - Entry point
 * Description: concatenate a string from source to destination.
 * @dest: destination string.
 * @src: source string.
 * Return: A pointer to dest.
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
 * @src: source of string.
 * Return: Pointer to dest.
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

/**
 * _strcmp - Entry point
 * Description: compare 2 string, character by character
 * @s1: first string to be compared.
 * @s2: second string for comparing.
 *
 * Return: equal ? 0 : ascii dif value for the 1st dif numbers.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *(s1 + i) != '\0'; i++)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
	}
	if (*(s2 + i) != '\0')
		return (*(s2 + i) * -1);
	return (0);
}

/**
 * _stoi - Entry point
 * Description:
 * @s: The string to be convereted to integer.
 * Return: number as an integer type
 */
int _stoi(char *s)
{
	int n = 0, i = 0;

	for (; s[i] != '\0'; i++)
	{
		n = n * 10 + (s[i] - '0');
	}
	return (n);
}
