#include "shell.h"

/**
 * *_getenv -  gets an environment variable
 * @env: environment variable
 * Return: pointer to the value
*/
char *_getenv(const char *env)
{
/*extern char **environ;*/
int index = 0;
char *p;

while (environ[index])
{
p = strtok(environ[index], "=");
if (strcmp(env, p) == 0)
return (strtok(NULL, "="));
index++;
}
return (NULL);
}

/**
 * main - program
 *
 * Return: 0
 */
int main(void)
{
printf("%s\n", _getenv("LS"));
return (0);
}
