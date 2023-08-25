#include "shell.h"

/**
 * handle_builtins - function to handle builtins
 * @args: a pointer to an array of strings
 * @progname: name of the string
 * @buffer: allows user inputs
 *
 * Return: sucess
 */

int handle_builtins(char **args, char *progname, char *buffer)
{
	int executed = 0, idx = 0;

	(void)progname;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buffer);
		exit(errno);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[idx] != NULL)
		{
			write(1, environ[idx], strlen(environ[idx]));
			write(1, "\n", 1);

			idx++;
		}
		free(args); /*Only args is freed no need to free buffer*/
		executed = 1;
	}

	return (executed);
}
