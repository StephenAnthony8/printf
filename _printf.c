#include "main.h"
#include <stdarg.h>

void print_buffer(char buffer[], int *bi);

/**
 * _printf - print function
 * @format: format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	int i = 0, bi = 0, len = 0;
	int flags = 0, width = 0, precision = -1;
	va_list args;
	char buffer[BUFF_SIZE], c;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bi++] = format[i];
			if (bi == BUFF_SIZE)
				print_buffer(buffer, &bi);
		}
		else
		{
			/* _write(buffer, bi); */
			width = _width(format, &i, args);
			precision = _precision(format, &i, args);
			flags = _flags(format + i, &i);
			i++;
			switch (format[i])
			{
				case '%':
					buffer[bi++] = '%';
					bi++;
					break;
				case 'c':
					c = va_arg(args, int);
					buffer[bi++] = c;
					bi++;
					break;
				case 's': case 'r': case 'R':
					bi += prints_string(args, width, precision, flags, &buffer[bi]);
					break;
				case 'l':case 'h':
					bi += prints_xint(args, &format[i], &buffer[bi]);
					i++;
					break;
				case 'd': case 'i':case 'x':case 'o': case 'p': case 'X':
					bi += prints_int(args, format[i], &buffer[bi]);
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
