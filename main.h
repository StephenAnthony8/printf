#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE */
#define S_LONG 2
#define S_SHORT 1


int _printf(const char *format, ...);
void _write(char *str, int length);
void _itoa(int num, char *str);
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
int _precision(const char *format, int *i, va_list args);
int _width(const char *format, int *i, va_list args);
int _flags(const char *format, int *i);
int prints_character(const char *format, ...);
int prints_int(const char *format, ...);
int prints_string(va_list args, int width, int precision, int flags, char *buffer);
void print_buffer(char buffer[], int *bi);
int _size(const char *format, int *i);
int print_reverse(va_list args, char *str, char buffer[]);
int print_rot13string(char *str, char buffer[]);


#endif /* MAIN_H */
