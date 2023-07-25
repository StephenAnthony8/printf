#include "main.h"
#include <unistd.h>
/**
 * _write - Puts out converted strings to the standard output
 * @str: converted string
 * @length: number of bytes to print out
 */
void _write(char *str, int length) /* length = sizeof(char) * str length */
{
	write(1, str, length);
}
