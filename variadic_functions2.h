#ifndef _variablah
#define _variablah

#include <stdio.h>
#include <stdarg.h>

/**
 * struct op - Struct op
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	void (*f)(void *);
} op_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

void (*get_op_func(char *s))(void *);
void p_c(void *);
void p_d(void *);
void p_f(void *);
void p_s(void *);

#endif
