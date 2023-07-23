#include "main.h"
/**
 * _strlen - checks the length of a string
 * @s: string
 * Return: returns the string length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
