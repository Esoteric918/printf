#include "holberton.h"
/**
 * p_b - print unsigned base10 as base2
 * @argz: currently unsigned decimal in va_list
 * @D: count of chars printed
 * @flagz: UNUZED - list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_b(va_list *argz, unsigned long *D, flag_list *flagz)
{
	unsigned int val = va_arg(*argz, unsigned int);
	unsigned int digit = 1;

	UNUZED(flagz);
	/* find the size of val */
	for (digit = 1; (val / digit) >= 2; digit *= 2)
	;
	for (; digit >= 1; val %= digit, digit /= 2)
	{
		_putchar((val / digit) + '0');
		++*D;
	}
	flags_reset(flagz);
}
/**
 * p_c - print char
 * @argz: currently char in va_list
 * @D: count of chars printed
 * @flagz: UNUSED - list of possible print modifiers
 * Return: 1 since char is only ever 1 character
 */
void p_c(va_list *argz, unsigned long *D, flag_list *flagz)
{
	char ch = va_arg(*argz, int);

	UNUZED(flagz);
	_putchar(ch);
	++*D;
	flags_reset(flagz);
}
/**
 * p_di - print integer
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * @flagz: list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_di(va_list *argz, unsigned long *D, flag_list *flagz)
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
			*D += 2;
			/* set all values for flag 0 */
			flags_reset(flagz);
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
	for (digit = 1; (val / digit) >= 10; digit *= 10)
	;
	/* walk it back one, and print all the values */
	for (; digit >= 1; val %= digit, digit /= 10)
	{
		_putchar((val / digit) + '0');
		++*D;
	}
	flags_reset(flagz);
}
/**
 * p_p - print %
 * @argz: UNUSED - argument pointer
 * @D: count of chars printed
 * @flagz: UNUSED - list of possible print modifiers
 * Return: count
 */
void p_p(va_list *argz, unsigned long *D, flag_list *flagz)
{
	UNUSED(argz);
	UNUZED(flagz);

	_putchar('%');
	++*D;
	flags_reset(flagz);
}
/**
 * p_s - print string
 * @argz: currently string in va_list
 * @D: count of chars printed
 * @flagz: UNUSED - list of possible print modifiers
 * Return: count of chars from string printed
 */
void p_s(va_list *argz, unsigned long *D, flag_list *flagz)
{
	unsigned int i;
	char *str = va_arg(*argz, char *);

	UNUZED(flagz);
	if (str)
	{
		for (i = 0; str[i]; ++i, ++*D)
			_putchar(str[i]);
	}
	flags_reset(flagz);
}
