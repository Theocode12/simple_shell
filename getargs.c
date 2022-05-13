#include "main.h"

/**
 * get_args - creates an array of pointers to tokens
 * @line: buffer to split into tokens
 * Return: pointer to a pointer of tokens aka double pointer
 */

char **get_args(char *line)
{
	char **args;
	int i = 0, size = BUFFSIZE;

	if (*line == '\0')
		return (NULL);
	args = malloc(size * sizeof(char *));
	args[i] = _strtok(line, " ");
	while (args[i] != NULL)
	{
		if (i >= size)
		{
			size *= 2;
			args = realloc(args, size);
			if (args == NULL)
				return (NULL);
		}
		i++;
		args[i] = _strtok(NULL, " ");
	}
	return (args);
}
