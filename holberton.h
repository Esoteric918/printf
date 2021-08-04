#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

typedef struct conversion_specifier
{
	int op;
	int h;
	int l;
	int X;
} flag_list;

/**
 * struct format_specifiers - make structs that return func pointers
 * @op: types
 * @f: The function associated
 */
typedef struct format_specifiers
{
	char *op;
	void (*f)(va_list *, unsigned long *, flag_list *);
} spec_list;

/* define unused parameters */
#define UNUSED(argz) (void)(argz)
#define UNUZED(flagz) (void)(flagz)

/* prototypes */
int _putchar(char c);
int _strcmp(char *s1, char *s2);
void flag_set(const char *, flag_list *, int *);
void flags_reset(flag_list *);
void prnt_hlpr(int, int, unsigned long *);
unsigned long print_all(const char * const format, ...);
void (*get_funky(char s))(va_list *, unsigned long *, flag_list *);
/* print functions */
void p_b(va_list *, unsigned long *, flag_list *);
void p_c(va_list *, unsigned long *, flag_list *);
void p_di(va_list *, unsigned long *, flag_list *);
void p_o(va_list *, unsigned long *, flag_list *);
void p_p(va_list *, unsigned long *, flag_list *);
void p_s(va_list *, unsigned long *, flag_list *);
void p_u(va_list *, unsigned long *, flag_list *);
void p_Xx(va_list *, unsigned long *, flag_list *);

#endif
