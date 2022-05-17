#include "main.h"

/**
 * _unsetenv - removes an environment variable
 * @name: name of the environment variable
 * Return: 0 on sucess otheewise -1
 */

int _unsetenv(char *name)
{
	char **new_env;
	unsigned int i = 0, count = 0;
	int cmp_val;

	while (environ[i])
	{
		cmp_val = _strcmp(name, environ[i]);
		if (cmp_val == 0)
			count++;
		i++;
	}
	i--;
	if (count == 0)
		return (0);
	new_env = malloc(i * sizeof(char *));
	if (new_env == NULL)
	{
		perror("Unable to remove env variable");
		return (-1);
	}
	count = 0;
	for (i = 0; environ[i]; i++)
	{
		cmp_val =  _strcmp(name, environ[i]);
		if (cmp_val == 0)
			;
		else
			new_env[count++] = environ[i];
	}
	new_env[count++] = NULL;
	environ = new_env;
	return (0);
}
