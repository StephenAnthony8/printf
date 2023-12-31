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
	int i = 0, bi = 0;
	va_list args;
	char *buffer;

	buffer = malloc(BUFF_SIZE);
	if (!buffer)
		return (-1);
	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			buffer[bi++] = format[i];
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					buffer[bi++] = '%';
					break;
				case 'c':
					buffer[bi++] = va_arg(args, int);
					break;
				case 's': case 'r': case 'R': case 'S':
					bi += prints_string(args, format[i], &buffer[bi]);
					break;
				case 'l':case 'h':
					bi += prints_xint(args, &format[i], &buffer[bi]);
					i++;
					break;
				case 'd': case 'i':case 'o':case 'u':
				case 'p': case 'x': case 'X':case 'b':
					bi += prints_int(args, format[i], &buffer[bi]);
					break;
				default:
					buffer[bi] = '%';
					buffer[++bi] = format[i];
					bi++;
					break;

			}
		}
		if (bi == BUFF_SIZE)
			_write(buffer, bi);
	}
	_write(buffer, bi);
	va_end(args);
	return (reset_buffer(buffer, bi));
}
/**
 * reset_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @bi: Index at which to add next char, represents the length.
 * Return: string length
 */
int reset_buffer(char *buffer, int bi)
{
	free(buffer);
	return (bi);
}
