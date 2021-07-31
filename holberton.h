#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdarg.h>

/**
 * struct format_specifiers - make structs that selects func's
 * @spec: types
 * @f: The function associated
 */
typedef struct format_spesifiers
{
	char spec;
	int (*f)(va_list);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
void (*get_funky(char *s))(va_list);
int p_c(va_list);
int p_s(va_list);
int p_p(va_list);
int p_d(va_list);

#endif
