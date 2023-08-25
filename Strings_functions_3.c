#include "shell.h"

/**
 * _strdup - duplicates the string
 * @s: pointer to the string
 * Return: success 0
*/
char *_strdup(const char *s)
{
char *new;
size_t len;

len = _strlen(s);
new = malloc(sizeof(char) * (len + 1));
if (new == NULL)
return (NULL);
_memcpy(new, s, len + 1);
return (new);
}

/**
 * _isdigit - a function that checks for a digit
 * @s: pointer to the string
 * Return: 1 on success
*/
int _isdigit(const char *s)
{
unsigned int num;
for (num = 0; s[num]; num++)
{
if (s[num] < 48 || s[num] > 57)
return (0);
}
return (1);
}

/**
 * rev_string - a function that prints the string in reverse
 * @s: pointer to the string
 * Return: void
*/
void rev_string(char *s)
{
int num = 0, i, j;
char temp;
char *str;

while (num >= 0)
{
if (s[num] == '\0')
break;
num++;
}
str = s;
for (i = 0; i < (num - 1); i++)
{
for (j = i + 1; j > 0; j--)
{
temp = *(str + j);
*(str + j) = *(str + (j - 1));
*(str + (j - 1)) = temp;
}
}
}
