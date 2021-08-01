#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct format_specifiers - make structs that return func pointers
 * @op: types
 * @f: The function associated
 */
typedef struct format_specifiers
{
	char *op;
	void (*f)(va_list *, unsigned long long *);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
void (*get_funky(char *s))(va_list *, unsigned long long *);
void p_c(va_list *, unsigned long long *);
void p_s(va_list *, unsigned long long *);
void p_d(va_list *, unsigned long long *);
void p_f(va_list *, unsigned long long *);
void p_p(va_list *, unsigned long long *);
#endif
