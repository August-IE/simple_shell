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
FILE *scriptFile = NULL;
(void)env;

if (argc > 1)
{ scriptFile = fopen(argv[1], "r");
if (scriptFile == NULL) 
{ perror("Error opening script file");
return 1; }}

while (1)
{
if (scriptFile == NULL && isatty(0))
{ printf("#ACShell$ ");
fflush(stdout); }

if (scriptFile != NULL && fgets(input, sizeof(input), scriptFile) == NULL)
{ break; /* End of file in non-interactive mode */ }
else if (scriptFile == NULL && fgets(input, sizeof(input), stdin) == NULL)
{ if (feof(stdin))
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
{ perror("Command error");
exit(1); }}
else if (pid < 0)
{ perror("Fork failed"); }
else
{int status;  /* Parent process */
waitpid(pid, &status, 0); }}

if (scriptFile != NULL)
{ fclose(scriptFile); }
return (0);
}
