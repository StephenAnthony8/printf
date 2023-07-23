#include <stdarg.h>
#include "main.h"
/**
 * _count - prints out the format and additional arguments
 * @format: string to be printed out
 * @args: arguments from main.c
 * Return: length of string
 */
int _count(const char *format, va_list args)
{
	int prints, len, check;
	char *s, *newline = "'\n";

	prints = check = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*(format))
			{
				case ('d'):case ('i'):
					prints += num_val(va_arg(args, int));
					break;
				case 'c':case '%':
					prints++;
					break;
				case 's':
					prints += _strlen(va_arg(args, char *));
					break;
				default:
					s = "unknown conversion type character '";
					len = _strlen(s);
					_outp(s, len);
					_outp((char *) format, 1);
					_outp(newline, 2);
					check = -1;
			}
		}
		else
			prints++;
		format++; /* increment 2 ndo ipite the second character */
	}
	if (check != 0)
		return (check);
	return (prints);
}
