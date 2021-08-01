#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
void (*get_funky(char *s))(va_list *, unsigned long long *);
void p_c(va_list *, unsigned long long *);
void p_di(va_list *, unsigned long long *);
void p_f(va_list *, unsigned long long *);
void p_p(va_list *, unsigned long long *);
void p_s(va_list *, unsigned long long *);

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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	/* check rtrn val of func to confirm success */
	return (write(1, &c, 1));
}
#endif
