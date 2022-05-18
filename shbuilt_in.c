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

	if (args[1] != NULL)
	{
		status =  _atoi(args[1]);
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
	unsigned int i;

	i = 0;
	if (args[1] == NULL)
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
}
