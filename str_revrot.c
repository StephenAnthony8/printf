#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_reverse - Prints reverse string.
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
  * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char *str)
{
	int i, count = 0;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char reverse_string = str[i];

		write(1, &reverse_string, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @args: List of arguments
 * @str: pointer to string parameters
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args, char *str)
{
	char x;
	int count = 0;
	unsigned int i, j;
	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; data1[j]; j++)
		{
			if (data1[j] == str[i])
			{
				x = datarot[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!data1[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
