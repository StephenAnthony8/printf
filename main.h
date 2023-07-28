#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/* integer conversion */
int b_select(char specifier);
char *int_conv(int long value);
char *x_hex(int num, char *str);
int size(unsigned int long n, unsigned int long base);
int *arr_num(unsigned int long n, unsigned int long base);
char *unint_conv(unsigned int long value, char specifier);
int prints_int(va_list args, char specifier, char *buffer);
int prints_xint(va_list args, const char *specifier, char *buffer);

/* string conversion */
int _strlen(const char *str);
int x_string(char *str, char *buffer);
void _strcpy(char *dest, const char *src);
int print_reverse(char *str, char *buffer);
int print_rot13string(char *str, char *buffer);
int prints_string(va_list args, char flag, char *buffer);

/* printf functions */
int reset_buffer(char *buffer, int bi);
int _printf(const char *format, ...);
void _write(char *str, int length);



#endif /* MAIN_H */
