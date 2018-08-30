#include "shell.h"

/**
 * _memset - Entry point
 * Description: fills the first n bytes of the memory area.
 * @s: string that need to be filled.
 * @b: constant byte b that will fill to memory area.
 * @n: n of bytes to be filled.
 *
 * Return: pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}

/**
 * sigintHandler - Entry point
 * Description: Handle ignore when user hit Ctrl C.
 * @sig_num: Number 2 when hitting Ctrl C.
 * Return: Nothing.
 */

void sigintHandler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}

/**
 * free_helper - Entry point
 * Description: A simple funciton to free twice, used in
 * our builtin function.
 * @av: The buffer to free.
 * Return: None.
 */

void free_helper(char **av)
{
	free(av[0]);
	free(av);
}

/**
 * _memcpy - Entry point
 * Description: fills the first n bytes of the memory area.
 * @dest: string that need to filled by source.
 * @src:  bytes form source will be pasted to dest.
 * @n: n of bytes to be filled.
 *
 * Return: pointer to the memory area s.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = *(src + i);
	return (dest);
}
