#include "main.h"

/**
 * sh_loop - shell loop
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
		args = get_args(line);
		status = built_in(args);
		if (status < 0)
			status = execute_cmd(args);
	} while (status);
}
