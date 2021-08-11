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
 * @sp: if a space is before the op
 * @X: for capital hex
 */
typedef struct conversion_specifier
{
	int op;
	int h;
	int l;
	int S;
	int sp;
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
int _printf(const char * const format, ...);
int _putchar(char c);
int _strcmp(char *, char *);
/* flag functions */
int flag_check(const char *, flag_list *, int *, int *, char *, int *);
int flag_set(const char *, flag_list *);
void flags_reset(flag_list *, char *);
void (*get_funky(char s))(va_list *, int *, flag_list *);
/* print functions */
void p_b(va_list *, int *, flag_list *);
void p_c(va_list *, int *, flag_list *);
void p_di(va_list *, int *, flag_list *);
int p_l_sgn(va_list *, long int, flag_list *);
int p_l_uns(va_list *, unsigned long int, flag_list *);
void p_o(va_list *, int *, flag_list *);
void p_p(va_list *, int *, flag_list *);
void p_Ss(va_list *, int *, flag_list *);
void p_u(va_list *, int *, flag_list *);
void p_Xx(va_list *, int *, flag_list *);
int p_hex_hlpr(int, int);
void p_buffer(char *, int  *);


#endif
