#include <unistd.h>
#include "main.h"
/**
 * _outp - Puts out converted strings to the standard output
 * @str: converted string
 * @length: number of bytes to print out
 */
void _outp(char *str, int length) /* length = sizeof(char) * str length */
{
	write(1, str, length);
}
