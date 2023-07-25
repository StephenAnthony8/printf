#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_reverse - Prints reverse string.
 * @args: Lista of arguments
 * @str: string
 * @buffer: output buffer to store the reversed string
  * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char *str, char buffer[])
{
	int len, count = 0, bi = 0;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	for (len = 0; str[len]; len++)
		;

	for (len = len - 1; len >= 0; len--)
	{
		buffer[bi++] = str[len];
		count++;
	}
	return (len);
}
