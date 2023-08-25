#include "shell.h"

/**
 * _printstring - prints a string to the stdout
 * @str: The pointer to the string
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printstring(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}

	return (count);
}
