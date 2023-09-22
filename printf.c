#include "simple_shell.h"

/**
 * ft_putchar_fd - Writes a character to the specified file descriptor.
 *
 * @c:	   The character to write.
 * @fd:	   The file descriptor to write to.
 * Return: The number of characters written.
 */
static int ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * ft_putstr_fd - Writes a string to the specified file descriptor.
 *
 * @s:	   The string to write.
 * @fd:	   The file descriptor to write to.
 * Return: The number of characters written.
 */
static int ft_putstr_fd(char *s, int fd)
{
	int len = 0;

	while (*s)
		len += ft_putchar_fd(*s++, fd);
	return (len);
}

/**
 * ft_putnbr_fd - Writes a number to the specified file
 * descriptor using the specified base.
 *
 * @nb:    The number to write.
 * @base:  The base to use for formatting.
 * @fd:	   The file descriptor to write to.
 * Return: The number of characters written.
 */
static int ft_putnbr_fd(long nb, int base, int fd)
{
	int len = 0;

	if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= base)
		len += ft_putnbr_fd(nb / base, base, fd);
	len += ft_putchar_fd(hex[(nb % base)], fd);

	return (len);
}

/**
 * ft_index - Formats and writes a string to the specified file descriptor
 * according to the format specifier.
 *
 * @s:	   The format string.
 * @ap:	   The variable argument list.
 * @fd:	   The file descriptor to write to.
 * Return: The number of characters written.
 */
static int ft_index(char *s, va_list ap, int fd)
{
	int len;
	char ch;

	len = 0;

	while (*s)
	{
		ch = *s++;

		if (ch != '%')
			len += ft_putchar_fd(ch, fd);
		else
		{
			ch = *s++;
			if (ch == 'c')
				len += ft_putchar_fd((char)va_arg(ap, int), fd);
			if (ch == 's')
				len += ft_putstr_fd(va_arg(ap, char *), fd);
			if (ch == 'd')
				len += ft_putnbr_fd((long)va_arg(ap, int), 10, fd);
			if (ch == 'x')
				len += ft_putnbr_fd((long)va_arg(ap, unsigned int), 16, fd);
		}
	}

	return (len);
}

/**
 * ft_printf_fd - Writes formatted output to the specified file descriptor.
 *
 * @fd:		The file descriptor to write to.
 * @format:	The format string.
 * @...:	Additional arguments.
 * Return:	The number of characters written.
 */
int ft_printf_fd(int fd, char *format, ...)
{
	va_list ap;
	int len = 0;

	va_start(ap, format);
	len += ft_index(format, ap, fd);

	va_end(ap);

	return (len);
}
