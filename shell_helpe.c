#include "simple_shell.h"


/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the resulting string `dest`.
 */
char *_strcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (temp);
}


/**
 * _strpbrk - Searches a string for the first occurrence of any character
 * from a specified set.
 *
 * @str: The string to search in.
 * @charset: The set of characters to search for.
 *
 * Return: A pointer to the first occurrence of a matching character
 * in the string, or NULL if no ma ching characters are found.
 */
char *_strpbrk(const char *str, const char *charset)
{
	const char *c;

	for (; *str != '\0'; ++str)
	{
		for (c = charset; *c != '\0'; ++c)
		{
			if (*str == *c)
			{
				return ((char *)str);
			}
		}
	}
	return (NULL);
}

/**
 * _strtok - Tokenizes a string into individual tokens.
 *
 * @str: The string to be tokenized.
 * @delim: The delimiter characters used to tokenize the string.
 *
 * Return: A pointer to the next token in the string
 * or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *current_token;
	char *delimiter;

	if (str != NULL)
	{
		token = str;
	}
	else if (token == NULL)
	{
		return (NULL);
	}

	current_token = token;
	delimiter = _strpbrk(current_token, delim);

	if (delimiter != NULL)
	{
		*delimiter = '\0';
		token = delimiter + 1;
	}
	else
	{
		token = NULL;
	}

	return (current_token);
}
