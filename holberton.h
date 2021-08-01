#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/*#include <unistd.h>*/

/**
 * struct format_specifiers - make structs that return func pointers
 * @op: types
 * @f: The function associated
 */
typedef struct format_specifiers
{
	char *op;
	void (*f)(va_list *);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
void (*get_funky(char *s))(va_list *);
void p_c(va_list *);
void p_s(va_list *);
void p_d(va_list *);
void p_f(va_list *);
void p_p(va_list *);
#endif
