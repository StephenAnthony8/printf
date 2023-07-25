#include "main.h"

/**
 * _flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: loop iterator
 * Return: Flags:
 */
int _flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */ /*bit manipulation to rep and store values */
	int j, current_index;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[current_index] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = current_index - 1;

	return (flags);
}
