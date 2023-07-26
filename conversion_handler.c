#include "main.h"
/**
 * size - size of the array to contain the values
 * @n: number system value
 * @base: base value
 * Return: array size
 */
int size(unsigned int long n, unsigned int long base)
{
	int count = 0;

	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
/**
 * arr_num - creates an array of the numbers to be converted
 * @n: number to be divided
 * @base: base number dividing
 * Return: array mimicking place value
 */
int *arr_num(unsigned int long n, unsigned int long base)
{
	int *arr, count;

	count = size(n, base);
	if (n == 0)
		count = 1;
	arr = malloc(sizeof(int) * count);
	if (!arr)
	{
		free(arr);
		return (NULL);
	}
	for (count--; count >= 0; count--)
	{
		arr[count] = n % base;
		n /= base;
	}
	return (arr);
}
/**
 * int_conv - converts a signed integer into a string
 * @value: signed integer to convert
 * Return: number string
 */
char *int_conv(int long value)
{
	int len, i, j, *iarr;
	char *charr;
	long int neg;

	j = i = 0;
	len = 1;
	neg = value;
	if (value < 0)
		value = -value;
	len = size(value, 10);
	if (neg < 0)
		len++;
	charr = malloc(sizeof(char) * (len + 1));
	if (!charr)
	{
		free(charr);
		return (NULL);
	}
	if (neg < 0)
	{
		charr[i] = '-';
		i++;
	}
	iarr = arr_num(value, 10);
	for (; i < len; i++, j++)
		charr[i] = '0' + iarr[j];
	charr[i] = '\0';
	free(iarr);
	return (charr);
}
/**
 * unint_conv - converts any unsigned int type into a string
 * @value: signed integer to convert
 * @specifier: conversion specifier
 * Return: number string
 */
char *unint_conv(unsigned int long value, char specifier)
{
	int len = 1, i = 0, j = 0, *iarr, hex, base;
	char *charr;

	base = b_select(specifier);

	len += size(value, base);
	charr = malloc(sizeof(char) * (len));
	if (!charr)
	{
		free(charr);
		return (NULL);
	}
	iarr = arr_num(value, base);
	for (; i < len - 1; i++, j++)
	{
		if (iarr[j] > 9)
		{
			hex = iarr[j] - 10;
			if (specifier == 'X')
				charr[i] = 'A' + hex;
			else if (specifier == 'x' || specifier == 'p')
				charr[i] = 'a' + hex;
		}
		else
			charr[i] = iarr[j] + '0';
	}
	charr[i] = '\0';
	free(iarr);
	return (charr);
}
/**
 * prints_int - iterates through the int choices
 * @args: int container
 * @specifier: conversion flag
 * @buffer: original string
 * Return: string length
 */
int prints_int(va_list args, char specifier, char *buffer)
{
	int num, len;
	unsigned int unum;
	unsigned long int ptr;
	char *chint;

	switch (specifier)
	{
		case 'd': case 'i':
			num = va_arg(args, int);
			chint = int_conv(num);
			break;
		case 'b': case 'o': case 'u': case 'x': case 'X':
			unum = va_arg(args, unsigned int);
			chint = unint_conv(unum, specifier);
			break;

		case 'p':
			ptr = (unsigned long int)va_arg(args, void *);
			chint = unint_conv(ptr, specifier);
			break;
	}
	len = _strlen(chint);
	if (specifier == 'p')
		chint = x_hex(len, chint);
	_strcpy(buffer, chint);
	free(chint);

	return (len);
}
