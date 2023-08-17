#include "shell.h"

/**
 * prompt - prints a prompt
 *
 * @av: argument vector
 * @env: environment variable
 */
void prompt(char **av, char **env)
{
char *buf_line = NULL;
int i, j;
int status;
size_t len = 0;
ssize_t num_letter;
char *av[MAX_NUM];
pid_t child_pid;

while (1)
{
if (isatty(STDIN_FILENO))
printf("#cisfun$ ");
num_letter = getline(&buf_line, &len, stdin);
if (num_letter == -1)
{
free(buf_line);
exit(EXIT_FAILURE);
}
for (i = 0; buf_line[i]; i++)
if (buf_line[i] == '\n')
/*keeps looping until it reaches a new line character*/
{
buf_line[i] = 0;/*The value of index is set to NULL*/
}
j = 0;
av[j] = strtok(buf_line, " ");
while (av[j])
av[++j] = strtok(NULL, " ");
/*for creating child process that will handle the path*/
/*The child process takes over from parent process*/
child_pid = fork();
if (child_pid == -1)
free(buf_line);
exit(EXIT_FAILURE);
if (child_pid == 0)
{
if (execve(av[0], av, env) == -1)
/*to execute the command in the stdin*/
printf("%s: No such file or directory\n", av[0]);
}
else
wait(&status);
/*status keeps track on events of the child process*/
}
}
