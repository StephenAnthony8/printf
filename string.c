#include "main.h"
#include <stdarg.h>

/**
 * prints_string  - prints a string
 * @args: list of args
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * Return: Number of chars printed
 */
int prints_string(va_list args, int width,
		int precision, int flags, char *buffer)
{
	int length = 0, i, j;
	char *str = va_arg(args, char *);


	if (str == NULL)
		str = "(null)";

	length = _strlen(str);

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS) /*left justified*/
		{
			for (i = 0; i < width; i++)
			{
				if (length > i)
					buffer[i] = str[i];
				else
					buffer[i] = ' ';
			}
			return (width);
		}
		else /*right justified*/
		{
			for (i = j = 0; i < width; i++)
			{
				if (i < width - length)
					buffer[i] = ' ';
				else
					buffer[i] = str[j];
			}
			return (width);
		}
	}
	else
		_strcpy(buffer, str);
	return (length);

}
