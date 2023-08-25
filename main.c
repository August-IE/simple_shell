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
{ count++;
if (mode == 1) /*Prints prompt in interactive mode*/
write(1, "$ ", 2);
num = getline(&buffer, &buff_Size, stdin);
if (num == -1)
{ /*if (mode == 1)free(args); To avoid memory leaks*/
free(buffer);
exit(errno); }
fix_comments(buffer);
args = tokenizah(buffer); /*dynamically allocated*/
if (args[0] == NULL)
{ free(args);
continue; /*ONLY SPACES\NEW LINES ARE ENTERED We return and print prompt*/
} /*Tests for wrong command- NOT A FULL PATH,returns -1 when path isn't found*/
if (access(args[0], X_OK) == -1)
{ /*To confirm builtin:for 0 cmd not builtin or returns 1 to builtin_status*/
builtin_status = handle_builtins(args, argv[0], buffer);
if (builtin_status == 1)
continue; /*Get and assign fullpath to variable and implement builtin*/
fullcmd = get_full_path(_getpath(), args[0]);
if (fullcmd == NULL)
{ cmdc = (count + '0'); /*Converting an int to char*/
zerror(argv[0], cmdc, args[0]);
free(args);
errno = 127; /*Sets errno to 127 for cmd not found,when no system call*/
continue; } /*Called when the concatenated full path is valid*/
extra_execn(args, argv, fullcmd);
continue;
} /*Continue loop and handles full path entered by user*/
execn(args, argv); }
return (errno); }
