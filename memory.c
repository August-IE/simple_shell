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

}

/**
 * *_memcpy - copies the memory area
 * @dest: destination of new ptr to the memory area.
 * @src: source pointer to the memory area
 * @size: size of the memory area.
 * Return:
 *
 */
void *memcpy(char *dest, char *ptr, unsigned int size)
{
unsigned int i;

for (i = 0; i < size; i++)
src[i] = dest[i];
return (dest);
}
