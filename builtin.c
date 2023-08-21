#include "shell.h"

/**
 * _builtInCmd - a function that exits the shell in stdout
 * @arg: The pointer to the address
 *
 * Return: On success 0.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _builtInCmd(char **arg)
{
	if (strcmp(arg[0], "exit") == 0)
	{
		_printstring("Exiting shell.... \n");
		exit(0);
	}
	else if (strcmp(arg[0], "cd") == 0)
	{
		if (arg[1] == NULL)
		chdir(getenv("HOME"));
		else
		chdir(arg[1]);
	}

	return (0);
}
