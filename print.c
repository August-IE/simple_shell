#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
