#include "shell.h"

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
