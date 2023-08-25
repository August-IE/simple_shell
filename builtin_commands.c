#include "shell.h"

/**
* get_builtin - builtin commands to implement
* @cmd: command
* Return: success 0
*/
int (*get_builtin(char *cmd))(ACdata_t *)
{
builtin_t builtin[] = {
	{"env", _env},
	{"exit", exit_shell},
	{"setenv", _setenv},
	{"unsetenv", _unsetenv},
	{"cd", cd_shell},
	{"alias", _alias},
	{"help", get_help},
	{NULL, NULL}
};
int i;
for (i = 0; builtin[i].name; i++)
{
if (_strcmp(builtin[i].name, cmd) == 0)
break;
}
return (builtin[i].f);
}
