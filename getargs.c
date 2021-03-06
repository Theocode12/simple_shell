#include "main.h"

/**
 * get_args - creates an array of pointers to tokens
 * @line: buffer to split into tokens
 * Return: pointer to a pointer of tokens aka double pointer
 */

char **get_args(char *line)
{
	char **args, *msg;
	int i = 0, size = BUFFSIZE;

	if (*line == '\0')
		return (NULL);
	args = malloc(size * sizeof(char *));
	if (args == NULL)
	{
		msg = "unable allocate memory";
		i = _strlen(msg);
		write(STDERR_FILENO, msg, i);
		return (NULL);
	}
	args[i] = _strtok(line, " \n\t\r");
	if (args[i] == NULL)
	{
		free(args);
		return (NULL);
	}
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
		args[i] = _strtok(NULL, " \n\t\r");
	};
	return (args);
}

/**
 * check_cwd - checks if command is in current working dir
 * @check_run: checks if a command has been executed
 * @args: arguements passed
 * @argv: arguement passed into the function
 * Return: 1 if command in current working dir otherwise 0
 */

int check_cwd(int check_run, char **args, char **argv)
{
	char cwd[256], *path;
	struct stat st;

	if (check_run == 0)
	{
		getcwd(cwd, sizeof(cwd));
		path = _strcat(cwd, args[0]);
		if (stat(path, &st) == 0)
		{
			args[0] = path;
			if (access(args[0], X_OK) == 0)
				execute(args, argv);
			else
				dprintf(STDERR_FILENO, "%s: Permission denied\n", path);
			check_run++;
		}
		free(path);
	}
	return (check_run);
}

/**
 * check_cmd_tty - checks if command is from terminal and print error message
 * @args: arguments
 * @argv: arguement vectori
 */

void check_cmd_tty(char **args, char **argv)
{
	int count = 0;

	count = _strlen(argv[0]);
	if (isatty(STDIN_FILENO))
	{
		write(STDERR_FILENO, argv[0], count);
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	else
	{
		write(STDERR_FILENO, argv[0], count);
		write(STDERR_FILENO, ": 1: ", 5);
		count = _strlen(args[0]);
		write(STDERR_FILENO, args[0], count);
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
