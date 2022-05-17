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

	printf("line : %d\n", *line);
	if (*line == '\0')
		return (NULL);
	args = malloc(size * sizeof(char *));
	if (args == NULL)
	{
		printf("unable allocate memory");
		return (NULL);
	}
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

/**
 * check_cwd - checks if command is in current working dir
 * @check_run: checks if a command has been executed
 * @args: arguements passed
 * Return: 1 if command in current working dir otherwise 0
 */

int check_cwd(int check_run, char **args)
{
	char cwd[256], *path;
	struct stat st;

	if (check_run == 0)
	{
		getcwd(cwd, sizeof(cwd));
		path = _strcat(cwd, args[0]);
		printf("getcwd %s\n", path);
		if (stat(path, &st) == 0)
		{
			args[0] = path;
			if (access(args[0], X_OK) == 0)
				execute(args);
			else
				dprintf(STDERR_FILENO, "%s: Permission denied\n", path);
			check_run++;
		}
		free(path);
	}
	return (check_run);
}
