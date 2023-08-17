#include "shell.h"

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 * Return: success 0.
 */

int main(int ac, char **av, char **env)
{
    if (ac != 0)
    prompt(av, env);
    return (0);
}
