#include "holberton.h"

/**
 * p_b - print unsigned base10 as base2
 * @agrz: currently unsigned decimal in va_list
 * Return: count of chars from int printed
 */
void p_b(va_list *argz, unsigned long long *D, flag_list *flagz)
{
	unsigned int val = va_arg(*argz, unsigned int);
	unsigned int digit = 1;
	
	if (val < 0)
		return;
	/* find the size of val */
	for (digit = 1; (val / digit) >= 2; digit*=2)
	;
	for (; digit >= 1; val%=digit, digit/=2)
	{
		_putchar((val / digit) + '0');
		++*D;
	}
}
/**
 * p_u - print unsigned integer
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
 * p_o - print integer
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * Return: count of chars from int printed
 */
void p_o(va_list *argz, unsigned long long *D, flag_list *flagz)
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
	for (digit = 1; (val / digit) >= 8; digit*=8)
	;
	/* walk it back one, and print all the values */
	for (; digit > 0; val%=digit, digit/=8)
	{
		_putchar((val / digit) + '0');
		++*D;
	}
}