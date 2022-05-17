#include "main.h"

/**
 * check_dir - check if the command is an absolute path
 * @args: command
 * Return: 1 if it's a directory else 0
 */

int check_dir(char **args)
{
	if ((*(*args)) == '/')
		return (1);
	return (0);
}

/**
 * execute - executes a command in a child process
 * @args: command
 */

void execute(char **args)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			dprintf(STDERR_FILENO, "%s: Is a directory\n", args[0]);
			exit(0);
		}
	}
	else if (child < 0)
	{
		dprintf(STDERR_FILENO, "Failed to execute command");
	}
	else
		wait(&status);
}

/**
 * check_execute - checks if the command exits in the path
 * @args: command
 * Return: 1 on success
 */

int check_execute(char **args)
{
	struct stat st;

	if (stat(args[0], &st) == 0)
	{
		if (access(args[0], X_OK) == 0)
			execute(args);
		else
			dprintf(STDERR_FILENO, "%s: Permission denied\n", args[0]);
	}
	else
		dprintf(STDERR_FILENO, "%s: No such file or directory\n", args[0]);
	return (1);
}

/**
 * execute_cmd - calls functions necessary to succesfully execute a command
 * @args: command
 * Return: 1 if command is sucessfully executed otherwise 0
 */

int execute_cmd(char **args)
{
	int dir_check, check;

	dir_check = check_dir(args);
	if (dir_check > 0)
		check = check_execute(args);
	else
		check = exec_cmd(args);
	return (check);
}

/**
 * exec_cmd - Execute a args that are not directories
 * @args: arguement
 * Return: returns 1 if successfully executed
 */

int exec_cmd(char **args)
{
	char *pathenv, *token,  *path;
	int  check_run = 0;
	struct stat st;

	pathenv = _getenv("PATH");
	pathenv = _strdup(pathenv);
	token = _strtok(pathenv, ":");
	while (token != NULL)
	{
		path = _strcat(token, args[0]);
		if (stat(path, &st) == 0)
		{
			args[0] = path;
			if (access(args[0], X_OK) == 0)
			{
				execute(args);
				free(path);
			}
			else
			{
				dprintf(STDERR_FILENO, "%s: Permission denied\n", path);
				free(path);
			}
			check_run++;
			break;
		}
		free(path);
		token = _strtok(NULL, ":");
	}
	check_run = check_cwd(check_run, args);
	if (check_run < 1)
		dprintf(STDERR_FILENO, "%s: No such file or directory\n", args[0]);
	free(pathenv);
	return (1);
}
