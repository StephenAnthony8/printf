#include "main.h"
/**
 * is_digit - checks if a char is a digit
 * @: input value
 * Return 1 if true, 0 if otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

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
/**
 * _precision - calcultes precision for printing
 * @format: formatted string
 * @i: list of args to be printed
 * @args: list of arguments
 *
 * Return: precision
 */
int _precision(const char *format, int *i, va_list args)
{
	int current_index = *i + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return (precision);
	precision = 0;
	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*i = current_index - 1;

	return (precision);
}
