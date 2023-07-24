#include "main.h"
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
