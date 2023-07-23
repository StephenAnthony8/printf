#include <stdarg.h>
#include "main.h"
/**
 * _prstr - prints out the format and additional arguments
 * @format: string to be printed out
 * @args: arguments from main.c
 * Return: length of string
 */
void _prstr(va_list args, const char *format)
{
	char c;
	int len, num;
	char *s;

	len = 0;
	while (*format)
	{
		if (*format == '%')
			switch (*(format + 1))
			{
				case 'd':case 'i':
					num = va_arg(args, int);
					num_prt(num);
					format++;
					break;
				case 'c':
					c = va_arg(args, int);
					_outp(&c, 1);
					format++; /* increments string to '%' */
					break;
				case '%':
					c = '%';
					_outp(&c, 1);
					format++;
					break;
				case 's':
					s = va_arg(args, char *);
					len = _strlen(s);
					_outp(s, len);
					format++;
					break;
			}
		else
		{
			c = *format;
			_outp(&c, 1);
		}
		format++; /* increment 2 ndo ipite the second character */
	}
}
