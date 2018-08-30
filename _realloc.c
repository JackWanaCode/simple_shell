#include "shell.h"

/**
 * _realloc - Entry point
 * Description: re allocate memory
 * @ptr: pointer point to old memory space.
 * @old_size: old size
 * @new_size: new size
 *
 * Return: new pointer to new size of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *re_ptr = NULL;

	if (old_size == new_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		re_ptr = malloc(new_size);
		if (re_ptr == NULL)
			return (NULL);
		return (re_ptr);
	}
	else
	{
		re_ptr = malloc(new_size);
		if (re_ptr == NULL)
			return (NULL);
		if (new_size > old_size)
		{
			_memcpy(re_ptr, ptr, old_size);
		}
		else
		{
			_memcpy(re_ptr, ptr, new_size);
		}
	}
	free(ptr);
	return (re_ptr);
}
