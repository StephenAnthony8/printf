#include "main.h"
#include <stdarg.h>

/**
 * _strlen - checks the length of a string
 * @str: string
 * Return: returns the string length
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 * _strcpy - copies string to the output buffer
 * @src: string to copy
 * @dest: string destination
 */
void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest = '\0';
}
/**
 * x_hex - attaches the x on a pointer
 * @num: int to be converted
 * @str: output string
 * Return: 0x pointer
 */
char *x_hex(int num, char *str)
{
	char *x_arr;

	x_arr = malloc(sizeof(char) * (num + 3));
	if (!x_arr)
	{
		free(x_arr);
		return (NULL);
	}

	x_arr[0] = '0';
	x_arr[1] = 'x';
	_strcpy(&x_arr[2], str);
	free(str);
	return (x_arr);


}
/**
 * prints_xint - prints an integer
 * @args: number value being converted
 * @specifier: conversion flag to be used
 * @buffer: initial string
 * Return: integers printed
 */
int prints_xint(va_list args, const char *specifier, char *buffer)
{
	long int num, len, i = 0;
	unsigned long int unum;
	char *chint;

	if (specifier[i] == 'l')
		switch (specifier[i + 1])
		{
			case 'd': case 'i':
				num = va_arg(args, long int);
				chint = int_conv(num);
				break;
			case 'o': case 'u': case 'x': case 'X':
				unum = va_arg(args, unsigned long int);
				chint = unint_conv(unum, specifier[i + 1]);
				break;
		}
	else
		switch (specifier[i + 1])
		{
			case 'd': case 'i':
				num = va_arg(args, int);
				chint = int_conv(num);
				break;
			case 'o': case 'u': case 'x': case 'X':
				num = va_arg(args, unsigned int);
				chint = unint_conv(num, specifier[i + 1]);
				break;
		}
	_strcpy(buffer, chint);
	len = _strlen(chint);
	free(chint);

	return (len);
}
