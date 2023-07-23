#include "main.h"
/**
 * _width - calculates the width for printing
 * @format: formatted string in which to print args
 * @i: list of args to be printed
 * @args: list of args
 *
 * Return: width
 */
int _width(const char *format, int *i, va_list args)
{
	int current_index;
	int width = 0;

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = current_index - 1;

	return (width);
}
