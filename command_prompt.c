#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void display_prompt(void)
{
	printf("(AC_Shell) # ");
	fflush(stdout);
}

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_INPUT_SIZE];/*arguments will be passed to execve*/
	pid_t pid;

	while (1)
	{
	display_prompt();

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		if (feof(stdin))
	{
		printf("\nExiting shell...\n");
		break; /* End of file (Ctrl+D) */
	}
	else
	{
		perror("Input error");
		continue;
	}
	}

	/* Remove the newline character from the input */
	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		printf("Exiting shell...\n");
		break;
	}

	pid = fork();

	if (pid == 0)
	{ /* Child process */
	char *env[] = { NULL }; /* Empty environment for execve */
		args[0] = input;
		args[1] = NULL;


		if (execve(input, args, env) == -1)
	{
		perror("Command execution error");
		exit(1);
	}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{ /* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
	}

	return (0);
}
