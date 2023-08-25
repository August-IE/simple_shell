#include "shell.h"

/**
 * main - Simple shell entry point
 * @argc: Argument counter
 * @argv: Argument Vector
 * Return: Errno
 *
 */

int main(int argc, char **argv)
{

	int mode = isatty(0);
	char *buffer = NULL, cmdc, **args = NULL, *fullcmd = NULL;
	size_t buff_Size = 0;
	ssize_t num = 0;
	int count = 0, builtin_status = 0;

	errno = 0;

	(void)argc;
	while (1)
	{
		count++;
		if (mode == 1) /*Prints prompt in interactive mode*/
			write(1, " $    ", 2);

		num = getline(&buffer, &buff_Size, stdin);
		if (num == -1)
		{
			free(buffer);
			exit(errno);
		}
		fix_comments(buffer);
		args = tokenizah(buffer); /*dynamically allocated*/
		if (args[0] == NULL)
		{
			free(args); /* return and print the prompt*/
			continue;
		}
		/*Tests that the command is wrong - NOT A FULL PATH!*/
		/* Access returns -1 when the path is not found*/
		if (access(args[0], X_OK) == -1)
		{
			builtin_status = handle_builtins(args, argv[0], buffer);

			if (builtin_status == 1)
				continue;

			/*Get full path and assign to fullpath variable*/
			/* Implement builtin within this block*/
			fullcmd = get_full_path(_getpath(), args[0]);

			if (fullcmd == NULL)
			{
				cmdc = (count + '0'); /*Converts int to char*/
				zerror(argv[0], cmdc, args[0]);
				free(args);
				errno = 127; /*Sets errno 127 cmd not found*/
				continue;
			}
			/* The full path is not NULL*/
			extra_execn(args, argv, fullcmd);
			continue;
			/*Continuing to the top of the loop*/
		}
		/* Handles when full path is entered by user correctly*/
		execn(args, argv);
	}

	return (errno);
}
