#include "main.h"

/**
 * builtin_args - evaluates built in commands
 * @args: command line arguments
 * @argv: argument vector
 * Return: -1 if no built in function is found else 1
 */

int builtin_args(char **args, char **argv)
{
	int i = 0, status = -1;
	built_in  ptr[] = {
		{"exit", bui_exit},
		{"env", bui_env},
		{"unsetenv", bui_unsetenv},
		{"setenv", bui_setenv},
		{NULL, NULL}
	};
	if (args == NULL)
		return (1);
	for (i = 0; ptr[i].name; i++)
	{
		if (_strcmp(args[0], ptr[i].name) == 0)
		{
			status = 1;
			ptr[i].f(args, argv);
		}
	}
	return (status);
}

/**
 * bui_unsetenv - unset an env variable
 * @args: arguments
 * @argv: argument vector from main.c
 */

void bui_unsetenv(char **args,  __attribute__((unused))char **argv)
{
	if (args[2] != NULL)
	{
		perror("To many arguements");
		return;
	}
	if (args[1] == NULL)
	{
		perror("insufficient arguements");
		return;
	}
	_unsetenv(args[1]);
}

/**
 * bui_exit - built_in exit
 * @args: arguement
 * @argv: argument vector from main.c
 */

void bui_exit(char **args, char **argv)
{
	int status =  0, count = 0, i;
	char *msg = ": too many arguments\n";

	for (i = 0; args[i]; i++)
		;
	if (i > 2)
	{
		status = _strlen(msg);
		count = _strlen(argv[0]);
		write(STDERR_FILENO, argv[0], count);
		write(STDERR_FILENO, ": ", 2);
		count = _strlen(args[0]);
		write(STDERR_FILENO, args[0], count);
		write(STDERR_FILENO, msg, status);
		return;
	}
	if (args[1] != NULL)
		status =  _atoi(args[1]);
	free(*args);
	free(args);
	exit(status);
}

/**
 * bui_env - get environment variables
 * @args: argument list
 * @argv: argument vector from main.c
 */

void bui_env(__attribute__((unused))char **args, __attribute__((unused))char **argv)
{
	unsigned int i, count = 0;

	i = 0;
	if (args[1] == NULL)
		while (environ[i] != NULL)
		{
			count = _strlen(environ[i]);
			write(STDOUT_FILENO, environ[i], count);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	else
	{
		count = _strlen(args[1]);
		write(STDERR_FILENO, args[0], 3);
		write(STDERR_FILENO, ": ", 3);
		write(STDERR_FILENO, args[1], count);
		write(STDERR_FILENO, ": No such file or directory\n", 31);
	}
}

/**
 * bui_setenv - set an environmental variable
 * @args: arguements
 */

void bui_setenv(char **args,  __attribute__((unused))char **argv)
{
	if (args[3] != NULL)
	{
		perror("Too many arguements for setenv");
		return;
	}
	if (args[1] == NULL)
	{
		perror("insufficient arguements");
		return;
	}
	_setenv(args[1], args[2]);
}
