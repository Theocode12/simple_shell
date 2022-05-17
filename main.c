#include "main.h"

/**
 * main - Entry point
 *
 * Description: Standard output display of shell.
 * Return: 0 on success.
 */

int main(void)
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
			free(line);
			status = 0;
			break;
		}
		args = get_args(line);
		if (args == NULL)
			printf("Null seen");
		status = builtin_args(args);
		printf("status: %d\n", status);
		if (status < 0)
			status = execute_cmd(args);
		/*i = 0;
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}*/
		
		/*if (*line != '\0')
		{
			free(line);
			
		}
		free(NULL);*/
	} while (status);

	return (0);
}
