#include "main.h"
#include <stdarg.h>
/**
 * _strlen - checks the length of a string
 * @s: string
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
 */
void _strcpy(char *dest, const char *src) {
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
}

/**
 * _itoa - converts an integer to a string
 * @num: int to be converted
 * @str: output string
 */
void _itoa(int num, char *str) {
	int i = 0;
	int is_negative = 0;

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
		int rem = num % 10;
		str[i++] = rem + '0';
		num = num / 10;
	}

	if (is_negative)
		str[i++] = '-';

	str[i] = '\0';

	int start = 0;
	int end = i - 1;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/** Prints char*/
/**
 * prints_chars - prints a char
 * @specifier: list of args
 * @buffer: bufer array to print
 * Return: Number of chars printed
 */
int prints_character(va_list specifier, char *buffer)
{
	char buffer[BUFFER_SIZE];
	char temp_str[BUFFER_SIZE];
	int bi = 0;
	int i = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%') {
		buffer[bi++] = format[i];
	}
	else
	{
		i++;

		switch (format[i])
		{
			case 'c':
			{
				char c = va_arg(args, int);
				buffer[bi++] = c;
				i++;
				break;
			}
			case 's':
			{
				const char *str = va_arg(args, const char *);
				int len = _strlen(str);   
				_strcpy(&buffer[bi], str);
				bi += len;
				i++;
				break;
			}
			case '%':
			{
				buffer[bi++] = '%';
				i++;
				break;
			}
			case 'd':
			case 'i':
			{
				int num = va_arg(args, int);
				_itoa(num, temp_str);
				int len = _strlen(temp_str);
				_strcpy(&buffer[bi], temp_str);
				bi += len;
				i++;
				break;
                	}
			default:
				i++;
				break;
			}
		}
	}

	va_end(args);

	buffer[bi] = '\0';

	return bi;
}


/**prints string*/
/**
 * prints_string  - prints a string
 * @specifier: list of args
 * @buffer: buffer array to handle print
 * REturn: Number of chars printed
 */
int prints_string(va_list specifier, char *buffer, int flags, int width, int precision, int size)
{
	int length = 0;
	char *str = va_arg(specifier, char *);

	if (str == NULL)
	{
		return(NULL);
	}
	while(str[length] != '\0')
		length++;

	return(write(1, str, length));

}
/** prints % */
/**
 * print_percent - prints a % sign
 * @specifier: list of arguments
 * @buffer: buffer array to handle print
 * Return: number of chars to be printed
 */
int prints_sign(va_list specifier, char *buffer, int flags, int width, int precision, int size)
{
	return(write(1, %%, 1));
}
