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

#define END_OF_FILE -2
#define EXIT -3

/*************************FUNCTION PROTOTYPES************************/
int _putchar(char c);
int _printstring(char *str);
char *location(char *path, char *arg);
char *get_loc(char *arg);
int _builtInCmd(char **arg);


/******GLOBAL VARIABLES*******/
extern char **environ;

/***STRING_FUNCTIONS***/
int _strlen(char *s);
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

/***PROMPT***/
void prompt(char **argv, char **envp);
void display_prompt(void);

/**GETENV**/
char *_getenv(const char *env);


/* Main Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
int execute(char **args, char **front);
char *_itoa(int num);

#endif /*_SHELL_H_ */
