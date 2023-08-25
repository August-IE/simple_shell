#ifndef _SHELL_H_
#define _SHELL_H_


#define MAX_NUM 20

/*
 * File: Shell.h
 * Desc: My header file for 0x16. C - Simple Shell
 *      containing all function prototypes.
 */

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
#include <limits.h>
#include <stdarg.h>

#define MAX_INPUT_SIZE 1024
#define END_OF_FILE -2
#define EXIT -3


/*************************FUNCTION PROTOTYPES*********************
int _putchar(char c);
int _printstring(char *str);
char *location(char *path, char *arg);
char *get_loc(char *arg);
int _builtInCmd(char **arg);
int main(int argc, char **argv);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...)**/
/**
 * struct ACdata
 * @argv:
 * @input:
 * @args:
 * @status:
 * @**_environ:
 * @pid:
typedef struct ACdata
{
char **argv;
char **args;
char *input;
char **_environ;
char pid;
int status;
int count;
} ACdata_t;**/

/**
 * struct builtin_s
 * @name:
 * @f:
typedef struct builtin_s
{
char *name;
int (*f)(ACdata_t *acdata);
} builtin_t;**/

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
        char *str;
        unsigned int len;
        struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

/*************************FUNCTION PROTOTYPES************************/

/*********GETLINE*********
void bring_line(char **lineptr, size_t *n, char *buffer, size_t i);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *read_line(int *i_eof);

*ENVIRONMENT VARIABLRES**
char *_getenv(const char *name, char **_environ);
int _env(ACdata_t *acdata);

*****CD SHELL******
void cd_dot(ACdata_t *acdata);
void cd_to(ACdata_t *acdata);
void cd_previous(ACdata_t *acdata);
void cd_home(ACdata_t *acdata);
int cd_shell(ACdata_t *acdata);
******EXIT SHELL*******
int exit_shell(ACdata_t *acdata);**/

/***********BUILTIN_CMD**********
int (*get_builtin(char *cmd))(ACdata_t *acdata);
char *copy_data(char *name, char *n);
void set_env(char *name, char *n, ACdata_t *acdata);
int _setenv(ACdata_t *acdata);
int _unsetenv(ACdata_t *acdata);**/

/*********STRING_FUNCTIONS3********
char *_strdup(const char *s);
int _isdigit(const char *s);
void rev_string(char *s);
int _strlen(char *s);**/

/***STRING_FUNCTIONS***/
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
void set_string(char **s, char *to);
int _strncmp(const char *s1, const char *s2, size_t n);

/******FOR MEMORY******/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* Main Helpers */
char **_strtok(char *line, char *delim);
char *get_location(char *command);
int execute(char **args, char **front);
char *_itoa(int num);

int _putchar(char c);
int _printstring(char *str);
char *location(char *path, char *arg);
char *get_loc(char *arg);
int _builtInCmd(char **arg);
/*int main(int argc, char **argv, char **env);*/

/***** VARIADIC FUNCTIONS *****/

/**
 * struct printer - A struct type defining a printer.
 * @symbol: A symbol representing a data type.
 * @print: The function pointer to a function that prints
 *         a data type corresponding to symbol.
 */
typedef struct printer
{
	char *symbol;
	void (*print)(va_list arg);

} printer_t;

/**Error printing functions */
void zerror(char *prog, int count, char *cmd);
void _puts(char *str);
int _putchar(char c);
void free_array(int argc, char *argv[]);

/*Global Variable*/
extern char **environ;
int exit_num;
int execn(char **args, char **argv);
int extra_execn(char **args, char **argv, char *fullcmd);
char *get_full_path(char *paths, char *cmd);
char *_getpath(void);
void fix_comments(char *buffer);
int handle_builtins(char **args, char *progname, char *buffer);

char **tokenizah(char *string);

#endif
