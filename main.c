#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
	_printstring("Hello, World!");
	(void)argc;
	(void)argv;

	char *prompt = "(Shell)$ ";
	char *buffer = NULL;
	size_t buffSize = 0;
	ssize_t n_chars;
	char *arg[11], *delim = " \n";
	pid_t Child_ID;
	int status, i, exe;

	while (1)
	{
	if (isatty(0))
	_printstring(prompt);

	n_chars = getline(&buffer, &buffSize, stdin);

	if (n_chars == -1)
	{
	free(buffer);
	exit(0);
	}

	/* Remove newline character from input */
	buffer[strcspn(buffer, "\n")] = '\0';

	i = 0;
	arg[i] = strtok(buffer, delim);
	while (arg[i] && i < 10) /* Limit arguments to 10 */
	{
		arg[++i] = strtok(NULL, delim);
	}
	arg[i] = NULL;

	char *path;

	path = get_loc(arg[0]);

	if (path == NULL)
	{
	if (_builtInCmd(arg) != 0)
		{
		continue;
		}
		else
		{
		_printstring("Command not found\n");
		continue;
		}
	}

	Child_ID = fork();
	if (Child_ID < 0)
	{
		_printstring("Forking failed");
		free(buffer);
		exit(1); /* Exit with an error code */
	}
	else if (Child_ID == 0)
	{
		exe = execve(path, arg, env);
	if (exe == -1)
	{
		_printstring("Command does not exist\n");
		free(buffer);
		exit(1); /* Exit with an error code */
	}
	}
	else
	{
		wait(&status);
	}

	free(path);
	}

	free(buffer);

	return (0);
}
