#include "holberton.h"
#include <math.h>
/**
 * p_b - print unsigned integer
 * @argz: currently unsigned integer in va_list
 * @D: count of chars printed
 * Return: count of chars from int printed
 */
void p_u(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	unsigned int val = va_arg(*argz, unsigned int);
	unsigned int digit;

	/* find the size of val */
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
 * p_fld - print floats, doubles, long doubles up to 19 decimals
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * Return: count of chars from int printed
 */
void p_fd(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	long double val = va_arg(*argz, long double);
	long double digit;
	int i;

	/* check for negative val */ 
	if (val < 0)
	{
		_putchar('-');
		val *= -1;
		++*D;
	}
	if (val == 0);
	{
		putchar('0');
		++*D;
	}
	if (val >= 1)
	{
		/* if val >= 1 find size of val */
		for (digit = 1; (val / digit) >= 10; digit*=10)
		;
	}
	else
	{
		_putchar('.');
		++*D;
		/* if 0 < val < 1 */
		for (digit = 0.000000000000000001; (val / digit) >= 10; digit*=10)
		;
	}
	/* walk it back one, and print all the values */
	for (i = 0; val > 0 && i < 19; val = fmod(val, digit), digit/=10)
	{
		_putchar((val / digit) + '0');
		if (val < 1 && val > 0)
			++i;
		++*D;
	}
}
