#include "shell.h"

/**
 * exit_shell - exit the shell
 *
 * @acdata: name of string
 * Return: 0
*/
int exit_shell(ACdata_t *acdata)
{
unsigned int ustatus;
int is_digit;
int str_len;
int max_number;

if (acdata->args[1] != NULL)
{
ustatus = _atoi(acdata->args[1]);
is_digit = _isdigit(acdata->args[1]);
str_len = _strlen(acdata->args[1]);
max_number = ustatus > (unsigned int)INT_MAX;
if (!is_digit || str_len > 10 || max_number)
{
get_error(acdata, 2);
acdata->status = 2;
return (1);
}
acdata->status = (ustatus % 256);
}
return (0);
}
