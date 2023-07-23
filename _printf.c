#include "main.h"
#include <stdarg.h>

/**
 * _printf - print function
 * @format: format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	int i, bc = 0, bi = 0, len;

	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bi++] = format[i];
			if (bi == BUFF_SIZE)
				print_buffer(buffer, bi);
			len++;
		}
		else
		{
			print_buffer(buffer, bi);
			flags = func_flags(format, &i);
			width = func_width(format, &i, args);
			precision = func_precision(format, &i, args);
			size = func_size(format, &i);
			i++;

		}
	}
	print_buffer(buffer, &bi);
	va_end(args);

	return (len);
}

/**
 * print_buffer - prints contents of the buffer
 * @buffer: arrays of chars
 * @bi: length of the buffer
 */
void print_buffer(char *buffer, int bi)
{
	if (bi > 0)
		write(1, &buffer[0], *bi);
	*bi = 0;
}
