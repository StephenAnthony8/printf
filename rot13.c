#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_rot13string - Print a string in rot13.
 * @str: pointer to string parameters
 * @buffer: buffer array
 * Return: Numbers of chars printed
 */
int print_rot13string(char *str, char *buffer)
{
	char x;
	int count = 0, bi = 0;
	unsigned int i, j;
	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";


	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; data1[j]; j++)
		{
			if (data1[j] == str[i])
			{
				x = datarot[j];
				buffer[bi++] = x;
				count++;
				break;
			}
		}
		if (!data1[j])
		{
			x = str[i];
			buffer[bi++] = x;
			count++;
		}
	}
	buffer[bi] = '\0';

	return (count);
}
