#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_reverse - Prints reverse string.
 * @str: string
 * @buffer: output buffer to store the reversed string
  * Return: Numbers of chars printed
 */
int print_reverse(char *str, char *buffer)
{
	int len, bi = 0;

	len = _strlen(str);
	for (len = len - 1; len >= 0; len--)
		buffer[bi++] = str[len];
	return (bi);
}
