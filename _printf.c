#include "main.h"
#include "string.c"
#include "sci.c"
#include <stdarg.h>

void print_buffer(char buffer[], int *bi);

/**
 * _printf - print function
 * @format: format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	int i = 0, bc = 0, bi = 0, len = 0;
	int flags = width = 0, precision = -1, size;

	va_list args;
	char buffer[BUFF_SIZE];

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bi++] = format[i];
			if (bi == BUFF_SIZE)
			{
				print_buffer(buffer, &bi);
				len += bi;
			}
		}
		else
		{
			print_buffer(buffer, &bi);
			i++;
			width = _width(format + i, args);
			precision = _precision(format + i, args);
			flags = _flags(format + i);
			switch (format[i])
			{
				case 'c':
				{
					char c = va_arg(args, int)

					buffer[bi++] = c;
					break;
				}
				case 's':
					len += prints_string(args, buffer + len, width, precision, flags);
					break;
				case 'd':
				case 'i':
					len += prints_int(format + i, args, buffer + len, width, precision, flags);
					break;
				default:
					buffer[bi++] = '%';
					buffer[bi++] = format[i];
					break;
			}
		}
	}
	print_buffer(buffer, &bi);
	len += bi;
	va_end(args);

	return (len);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @bi: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bi)
{
	if (*bi > 0)
		write(1, &buffer[0], *bi);

	*bi = 0;
}
