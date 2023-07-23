#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void _outp(char *str, int length);
int _strlen(char *s);
int _count(const char *format, va_list args);
void _prstr(va_list args, const char *format);
int num_val(int n);
int int_count(int m);
void num_prt(int n);
void prt_int(int m);

#endif /* MAIN_H */
