#include "shell.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - Entry point of the shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @env: Environment variables.
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
char input[MAX_INPUT_SIZE];
char *args[MAX_INPUT_SIZE]; /* The arguments to be passed to execve */
pid_t pid;
(void)argc;
(void)argv;
(void)env;

while (1)
{
if (isatty(0) == 1)
{ printf("ACShell($) ");
fflush(stdout); }
if (fgets(input, sizeof(input), stdin) == NULL)
{
if (feof(stdin))
{ printf("\nExiting shell...\n");
break; /* End of file (Ctrl+D) */ }
else
{ perror("Input error");
continue; }}
input[strcspn(input, "\n")] = '\0';
if (strcmp(input, "exit") == 0)
{ printf("Exiting shell...\n");
break; }
pid = fork();
if (pid == 0)
{/* Child process */ char *env[] = { NULL }; /* Empty environment for execve */
args[0] = input;
args[1] = NULL;
if (execve(input, args, env) == -1)
{ perror("Command execution error");
exit(1); }}
else if (pid < 0)
{ perror("Fork failed"); }
else
{int status;  /* Parent process */
waitpid(pid, &status, 0); }}
return (0);
}
