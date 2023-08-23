#include "shell.h"

/**
 * *_realloc - For reallocating the memory block
 * @ptr: pointer to the old memory
 * @old_size: The old size of memory block
 * @new_size: The new size of memory block.
 *
 * Return: a pointer to the newly allocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *newptr;

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
return (ptr);

newptr = malloc(new_size);
if (newptr == NULL)
return (NULL);
if (new_size < old_size)
_memcpy(newptr, ptr, new_size);
else
_memcpy(newptr, ptr, old_size);
}

/**
 * *_memcpy - copies the memory area
 * @dest: destination of new ptr to the memory area.
 * @src: source pointer to the memory area
 * @size: size of the memory area.
 * Return:
 *
 */
char *_memcpy(char *dest, char *src, unsigned int size)
{
unsigned int i;

for (i = 0; i < size; i++)
src[i] = dest[i];
return (dest);
}

/**
 * *_reallocdp - For filing and reallocating the memory block
 * @ptr: pointer to the old memory
 * @old_size: The old size of memory block
 * @new_size: The new size of memory block.
 *
 * Return: a pointer to the newly allocated memory.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
char **newptr;
unsigned int i;

if (ptr == NULL)
return (malloc(sizeof(char *) *new_size));

if (new_size == old_size)
return (ptr);

newptr = malloc(sizeof(char *) *new_size);
if (newptr == NULL)
return (NULL);

for (i = 0; i < old_size; i++)
newptr[i] = ptr[i];
free(ptr);
return (newptr);
}
