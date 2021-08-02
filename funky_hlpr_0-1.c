#include "holberton.h"
/**
 * p_c - print char
 * @argz: currently char in va_list
 * @D: count of chars printed
 * Return: 1 since char is only ever 1 character
 */
void p_c(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	char ch = va_arg(*argz, int);
	_putchar(ch);
	++*D;
}
/**
 * p_d - print integer
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * Return: count of chars from int printed
 */
void p_di(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	int val = va_arg(*argz, int);
	int digit;

	if ((*flagz).h)
	{
		/* check if value is within short range */
		if (val > 32767 || val < -32768)
		{
			_putchar('-');
			_putchar('1');
			*D+=2;
			/* set all values for flag 0 */
			reset_flags(flagz);
			return;
		}
	}
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
 * @D: count of chars printed
 * Return: count of chars from float/double printed
 */
void p_f(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	printf("%f", va_arg(*argz, double));
}
/**
 * p_p - % specifier and print
 * @argz: argument pointer
 * Return: count
 */
void p_p(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	_putchar('%');
		++*D;
}
/**
 * p_s - print string
 * @argz: currently string in va_list
 * @D: count of chars printed
 * Return: count of chars from string printed
 */
void p_s(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	unsigned int i;
	char *str = va_arg(*argz, char *);

	if (str)
	{
		for (i = 0; str[i]; ++i, ++*D)
			_putchar(str[i]);
	}
}