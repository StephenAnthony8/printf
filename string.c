#include "main.h"
#include <stdarg.h>

/**
 * prints_string  - prints a string
 * @args: list of args
 * @flag: calculates active flags
 * @buffer: original string
 * Return: Number of chars printed
 */
int prints_string(va_list args, char flag, char *buffer)
{
	int len;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		_strcpy(buffer, str);
		return (len);
	}
	len = _strlen(str);
	if (flag == 'R')
		len = print_rot13string(str, buffer);
	else if (flag == 'r')
		len = print_reverse(str, buffer);
	else if (flag == 'S')
		len = x_string(str, buffer);

	else
		_strcpy(buffer, str);

	return (len);
}
/**
 * x_string - converts a non printing string into a hex int
 * @str: string iterated through
 * @buffer: string to copy to
 * Return: string length
 */
int x_string(char *str, char *buffer)
{
	int i, j, len = 0, h_count, tick;
	char *chex;
	char *iex;

	for (tick = h_count = i = 0; str[i]; i++)
		if (str[i] <= 31 || str[i] >= 127)
		{
			h_count += (3 + size(str[i], 16));
			tick++;
		}
	len = (tick == _strlen(str)) ? h_count : (h_count + (i - 1));
	len = (tick == 0) ? _strlen(str) : len;
	chex = malloc(sizeof(char) * len + 1);
	if (!chex)
		return (0);
	for (i = j = 0; i < len && str[j] != '\0'; i++, j++)
	{
		if (str[j] <= 31 || str[j] >= 127)
		{
			chex[i] = '\\';
			chex[i + 1] = 'x';
			if (str[j] < 16)
				chex[i + 2] = '0';
			i += (str[j] < 15) ? 3 : 2;
			iex = unint_conv(str[j], 'X');
			_strcpy(&chex[i], iex);
			i += (str[j] < 15) ? 0 : 1;
			free(iex);
			continue;
		}
		chex[i] = str[j];
	}
	_strcpy(buffer, chex);
	len = _strlen(chex);
	free(chex);
	return (len);

}
/**
 * b_select - base selector
 * @specifier: flag options
 * Return: base
 */
int b_select(char specifier)
{
	switch (specifier)
	{
		case 'x': case 'X': case 'p':
			return (16);
		case 'u':
			return (10);
		case 'o':
			return (8);
		case 'b':
			return (2);
	}
	return (0);
}
