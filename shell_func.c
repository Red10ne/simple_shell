#include "simple_shell.h"

/**
 * _strcmp - Compare two strings.
 *
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: An integer less than, equal to,
 * or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strcpy - Copies a string.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination string (`dest`).
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 *
 * @s: The string to get the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
	const char *ptr = s;

	while (*ptr)
		ptr++;

	return ((size_t)(ptr - s));
}

/**
 * _memcpy - Copies a block of memory.
 * @dest: Pointer to the destination memory.
 * @src: Pointer to the source memory.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory (@dest).
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = (char *)dest;
	const char *csrc = (const char *)src;
	size_t i;

	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: Pointer to the string to be duplicated.
 *
 * Return: Pointer to the newly allocated string (a duplicate of @str), or
 * NULL if the allocation fails.
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *duplicate = malloc(len);

	if (duplicate != NULL)
		_memcpy(duplicate, str, len);

	return (duplicate);
}
