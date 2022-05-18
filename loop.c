#include "main.h"

/**
 *sh_loop -Standard output display of C - simple_shell
 */
void sh_loop(void)
{
	char *line = NULL, **args;
	int status = 1;
	ssize_t count;
	size_t n = 0;

	do {
		printf("($) ");
		count = _getline(&line, &n, stdin);
		if (count < 0)
		{
			putchar('\n');
			status = 0;
			break;
		}
		if (_strcmp(line,"exit") == 0)
		{
			status = 0;
			break;
		}
		args = get_args(line);
		status = builtin_args(args);
		if (status < 0)
			status = execute_cmd(args);
	} while (status);
}
