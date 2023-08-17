#include "shell.h"

/**
 * getenv -  gets an environment variable
 * @env: environment variable
 * Return: pointer to the value
*/
char *_getenv(const char *env)
{
extern char **environ;
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
int main()
{
printf("%s\n", _getenv("LS"));
return (0);
}
