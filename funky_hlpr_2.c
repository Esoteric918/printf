#include "holberton.h"
/**
 * p_b - print unsigned integer
 * @argz: currently unsigned integer in va_list
 * Return: count of chars from int printed
 */
void p_b(va_list *argz, unsigned long long *D)
{
	unsigned int val = va_arg(*argz, unsigned int);
	unsigned int digit;

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
