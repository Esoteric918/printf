#include "holberton.h"
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
 * p_d - print integer
 * @argz: currently integer in va_list
 * Return: count of chars from int printed
 */
void p_di(va_list *argz, unsigned long long *D)
{
	int val = va_arg(*argz, int);
	int digit;

	/* check for negative val */ 
	if (val < 0)
	{
		_putchar('-');
		val *= -1;
		++*D;
	}
	/* find the size of int */
	for (digit = 1; (val / digit) >= 10; digit*=10)
	;
	/* walk it back one, and print all the values */
	for (; digit > 0; val%=digit, digit/=10)
	{
		_putchar((val / digit) + '0');
		++*D;
	}
}
/**
 * p_f - print float or double
 * @argz: currently float/double in va_list
 * Return: count of chars from float/double printed
 */
void p_f(va_list *argz, unsigned long long *D)
{
	printf("%f", va_arg(*argz, double));
}
/**
 * p_p - % specifier and print
 * @argz: argument pointer
 * Return: count
 */
void p_p(va_list *argz, unsigned long long *D)
{
	_putchar('%');
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