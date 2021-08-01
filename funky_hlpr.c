#include "holberton.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * p_c - print char
 * @argz: currently char in va_list
 * Return: 1 since char is only ever 1 character
 */
void p_c(va_list *argz, unsigned long long *D)
{
	char ch = va_arg(*argz, int);
	_putchar(ch);
	++*D;
}
/**
 * p_s - print string
 * @argz: currently string in va_list
 * Return: count of chars from string printed
 */
void p_s(va_list *argz, unsigned long long *D)
{
	unsigned int i;
	char *str = va_arg(*argz, char *);

	if (str)
	{
		for (i = 0; str[i]; ++i, ++*D)
			_putchar(str[i]);
	}
}
/**
 * p_p - % specifier and print
 * @argz: argument pointer
 *
 * Return: count
 */
void p_p(va_list *argz, unsigned long long *D)
{
	_putchar('%')
		++*D;
}

/**
 * p_d - print integer
 * @argz: currently integer in va_list
 * Return: count of chars from int printed
 */
void p_d(va_list *argz, unsigned long long *D)
{
	printf("%d", va_arg(*argz, int));
}
/**
 * p_fd - print float or double
 * @argz: currently float/double in va_list
 * Return: count of chars from float/double printed
 */
void p_f(va_list *argz, unsigned long long *D)
{
/*	printf("%f", db); */
}
