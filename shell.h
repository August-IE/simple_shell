#ifndef SHELL_H
#define SHELL_H

/*
 * File: Shell.h
 * Desc: My header file for 0x16. C - Simple Shell
 *      containing all function prototypes.
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*************************FUNCTION PROTOTYPES************************/

int _putchar(char c);
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

#endif /* SHELL_H */
