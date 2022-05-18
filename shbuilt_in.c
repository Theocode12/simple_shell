#include "main.h"

/**
 * builtin_args - evaluates built in commands
 * @args: command line arguements
 * Return: -1 if no built in function is found else 1
 */

int builtin_args(char **args)
{
	int i, status = -1;
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
			ptr[i].f(args);
		}
	}
	return (status);
}

/**
 * bui_unsetenv - unset an env variable
 * @args: arguements
 */

void bui_unsetenv(char **args)
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
 */

void bui_exit(char **args)
{
	int status =  0;

	if (args[2] != NULL)
	{
		write(STDERR_FILENO, args[0], 4);
		write(STDERR_FILENO, ": too many arguenment\n", 22);
		return;
	}
	else if (args[1] != NULL)
	{
		status =  atoi(args[1]);
	}
	free(*args);
	free(args);
	exit(status);
}

/**
 * bui_env - get environment variables
 * @args: arguement list
 */

void bui_env(__attribute__((unused))char **args)
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

void bui_setenv(char **args)
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
