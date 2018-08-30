#include "shell.h"

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
	}
	if (k == 0)
		array[k++] = &buffer[j];
	array[k] = NULL;
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

/**
 * print_num - Entry point
 * Description: Prints a number as int type.
 * @count: The count of loops.
 * Return: None.
 */

void print_num(int count)
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
 * _strlen - find the length of a string                                                             
 * @s: string to be parsed                                                                           
 *                                                                                                   
 * Return: num of characters in string                                                               
 */
int _strlen(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)
                ;
        return (i);
}

/**                                                                                                  
 * _putchar - writes the character c to stdout                                                       
 * @c: The character to print                                                                        
 *                                                                                                   
 * Return: On success 1.                                                                             
 * On error, -1 is returned, and errno is set appropriately.                                         
 */
int _putchar(char c)
{
        return (write(STDERR_FILENO, &c, 1));
}
