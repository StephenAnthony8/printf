#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


int _printf(const char *format, ...);
void _write(char *str, int length);
int _strlen(const char *str);
int _precision(const char *format, int *i, va_list args)
int _width(const char *format, int *i, va_list args)
int _flags(const char *format, int *i)

#endif /* MAIN_H */
