#include "shell.h"

int _getline(char **buffer, size_t *n)
{
	char buf[1024];
	char *newbuf = NULL, *temp = NULL;
	int num_char = 0, ct = 1;
	int status = 1, i = 0;

	newbuf = malloc(sizeof(char) * 1024);
	_memset(newbuf, 0, 1024);
	while (status)
	{
		ct++;
		_memset(buf, 0, 1024);
		i = read(0, buf, 1023);
		num_char += i;
		if (i == 0)
		{
			free(newbuf);
                        return (-1);
		}
		else if (buf[i - 1] == '\n')
			status = 0;
		_strcat(newbuf, buf);
		if (status == 1)
		{
			temp = newbuf;
			newbuf = _realloc(newbuf, sizeof(char) * 3 * (ct - 1), sizeof(char) * 3 * ct);
			free(temp);
		}
		i++;
	}
	if (*buffer)
		free(*buffer);
	*buffer = newbuf;
	return (*n = num_char);
}
