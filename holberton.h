#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct conversion_specifier - for identifying conversion flags
 * @op: to identify the operations variable %
 * @h: for short ints
 * @l: for long ints
 * @X: for capital hex
 */
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
	void (*f)(va_list *, int *, flag_list *);
} spec_list;

/* prototypes */
int _putchar(char c);
int _strcmp(char *, char *);
int flag_check(const char *, flag_list *, int *, int *, char *, int *);
int flag_set(const char *c, flag_list *flagz);
void flags_reset(flag_list *);
void prnt_hlpr(int, int, int *);
int _printf(const char * const format, ...);
void (*get_funky(char s))(va_list *, int *, flag_list *);
/* print functions */
void p_b(va_list *, int *, flag_list *);
void p_c(va_list *, int *, flag_list *);
void p_di(va_list *, int *, flag_list *);
void p_o(va_list *, int *, flag_list *);
void p_p(va_list *, int *, flag_list *);
void p_s(va_list *, int *, flag_list *);
void p_u(va_list *, int *, flag_list *);
void p_Xx(va_list *, int *, flag_list *);
void p_buffer(char *buff, int  *D);

#endif
