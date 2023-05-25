#include "shell.h"

/**
<<<<<<< HEAD
 * interactive - returns true if shell is interactive mode.
 * @info: struct addr.
=======
 * interactive - return true if shell is in interactive mode
 * @info: struct address
>>>>>>> 448616a8406c3199bb373d368df2ba36ce43dbcf
 *
 * Return: 1 if in interactive mode, 0 if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
<<<<<<< HEAD
 * is_delim - checks if char is a delimeter.
 * @c: the char to check.
 * @delim: the delimeter str.
 * Return: 1 if true, 0 if false.
=======
 * is_delim - checks if character is delimeter
 * @c: Char to check
 * @delim: Delimeter string
 * Return: 1 if true, 0 if false
>>>>>>> 448616a8406c3199bb373d368df2ba36ce43dbcf
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
<<<<<<< HEAD
 * _isalpha - checks for alphabetic char.
 * @c: The char to input.
 * Return: 1 if c is alphabetic, 0 otherwise.
=======
 * _isalpha - check for Alphabetic character
 * @c: Character to input
 * Return: 1 if c is alphabetic, 0 otherwise
>>>>>>> 448616a8406c3199bb373d368df2ba36ce43dbcf
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
<<<<<<< HEAD
 * _atoi - converts a str to an int.
 * @s: the string to be converted.
 * Return: 0 if no num in str, converted num otherwise.
=======
 * _atoi - convert string to integer
 * @s: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
>>>>>>> 448616a8406c3199bb373d368df2ba36ce43dbcf
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
