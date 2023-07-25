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
 * _itoa - converts an integer to a string
 * @num: int to be converted
 * @str: output string
 */
void _itoa(int num, char *str)
{
	int i = 0, rem, start, end, is_negative = 0;
	char temp;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num != 0)
	{
		rem = num % 10;
		str[i++] = rem + '0';
		num = num / 10;
	}
		if (is_negative)
		str[i++] = '-';

	str[i] = '\0';
	start = 0;
	end = i - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
/**
 * prints_character - prints a char
 * @format: string to format
 * Return: Number of chars printed
 */
int prints_character(const char *format, ...)
{
	va_list args;
	char buffer[BUFF_SIZE], c;
	const char *str;
	int bi = 0, i = 0, len;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			buffer[bi++] = format[i];
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					buffer[bi++] = c;
					break;
				case 's':
					str = va_arg(args, const char *);
					len = _strlen(str);
					_strcpy(&buffer[bi], str);
					bi += len;
					break;
				case '%':
					buffer[bi++] = '%';
					break;
				default:
					i++;
					break;
			}
		}
	}
	va_end(args);
	buffer[bi] = '\0';
	return (bi);
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
