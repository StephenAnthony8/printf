#include "main.h"
#include <stdarg.h>
#include <unistd.h>

void print_buffer(char buffer[], int *bi);

/**
 * _printf - print function
 * @format: format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	int i = 0, bi = 0, len = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (; format && format[i] != '\0'; i++)
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
			switch (format[i++])
			{
				case 's':
					bi += print_reverse(args, va_arg(args, char *), &buffer[bi]);
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
