#include "main.h"
#include <stdarg.h>

/**
 * prints_string  - prints a string
 * @args: list of args
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * Return: Number of chars printed
 */
int prints_string(va_list args, int width,
		int precision, int flags)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS) /*left justified*/
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else /*right justified*/
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));

}
