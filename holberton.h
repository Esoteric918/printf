#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef struct conversion_specifier
{
	int h;
	int l;
} flag_list;

/**
 * struct format_specifiers - make structs that return func pointers
 * @op: types
 * @f: The function associated
 */
typedef struct format_specifiers
{
	char *op;
	void (*f)(va_list *, unsigned long long *, flag_list *);
} spec_list;

/* prototypes */
int _putchar(char c);
unsigned long long print_all(const char * const format, ...);
void (*get_funky(char *s))(va_list *, unsigned long long *, flag_list *);
void reset_flags(flag_list *flags);
/* print functions */
void p_b(va_list *, unsigned long long *, flag_list *);
void p_c(va_list *, unsigned long long *, flag_list *);
void p_di(va_list *, unsigned long long *, flag_list *);
void p_f(va_list *, unsigned long long *, flag_list *);
void p_o(va_list *, unsigned long long *, flag_list *);
void p_p(va_list *, unsigned long long *, flag_list *);
void p_s(va_list *, unsigned long long *, flag_list *);
void p_u(va_list *, unsigned long long *, flag_list *);
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
