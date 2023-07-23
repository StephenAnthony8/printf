#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* printf function */
int _printf(const char *format, ...); /* main printf function */

/* write function */
void _outp(char * str, int length); /* the write function */

/* string length function */
int _strlen(char *s); /* calculates the length of the argument strings */

/* total string count */
int _count(const char *format, va_list args); 
/* calculates the total string length */

/* string print */
void _prstr(va_list args, const char *format); 
/* prints out the string if count is successful */

/** int handling 
 * Current values are base 10 but we will fix them in advanced
 */
/* number count */
int num_val(int n); /* checks number position on numberline */
int int_count(int m); /* calculates int values & passes to num_val */

/* number printing */
void num_prt(int n); /* checks number position on numberline */
void prt_int(int m);/* prints int values */

#endif /* MAIN_H */
