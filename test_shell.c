#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFSIZE 1024
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
int main(void)
{
        int status = 1;
        int read;
        size_t size = BUFSIZE;
        char *buffer;
	char **av = NULL;


        while(status)
        {
                printf("$ ");
                read = getline(&buffer, &size, stdin);
                if (read == -1)
                {
                        puts ("ERROR!");
                        status = 0;
                }
                else if (read == 0)
                        status = 0;
                else
                {
			*av = malloc(sizeof(char) * read);
                        if (av == NULL)
                                return (1);
                        string_split(buffer, av, read);
                        free(*av);
                }
        }
        return (0);
}
