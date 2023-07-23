#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints out the format and additional arguments
 * @format: string to be printed out
 * Return: length of string
 */
int _printf(const char *format, ...)
{
	va_list args, args2;
	int length;

	va_start(args, format);
	length = _count(format, args);
	va_end(args);
	if (length == -1)
		return (0);
	va_start(args2, format);
	_prstr(args2, format);
	va_end(args2);
	return (length);
}
