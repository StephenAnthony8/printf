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
	int i, bc = 0, bi = 0, len;
	int flags, width, precision, size;

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
				print_buffer(buffer, &bi);
			len++;
		}
		else
		{
			print_buffer(buffer, &bi);
			i++;

		}
	}
	print_buffer(buffer, &bi);
	va_end(args);

	return (len);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bi)
{
	if (*bi > 0)
		write(1, &buffer[0], *bi);

	*bi = 0;
}
