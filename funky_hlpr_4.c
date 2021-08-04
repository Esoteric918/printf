#include "holberton.h"
/**
 * p_o - print number in Base8, Octal
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * @flagz: list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_o(va_list *argz, unsigned long *D, flag_list *flagz)
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
	for (digit = 1; (val / digit) >= 8; digit *= 8)
	;
	/* walk it back one, and print all the values */
	for (; digit >= 1; val %= digit, digit /= 8)
	{
		_putchar((val / digit) + '0');
		++*D;
	}
	flags_reset(flagz);
}
/**
 * p_u - print unsigned integer in Base10
 * @argz: currently unsigned integer in va_list
 * @D: count of chars printed
 * @flagz: UNUSED - list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_u(va_list *argz, unsigned long *D, flag_list *flagz)
{
	unsigned int val = va_arg(*argz, unsigned int);
	unsigned int digit;

	UNUZED(flagz);
	/* find the size of val */
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
 * p_Xx - print value in Base16, hexidecimal
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * @flagz: list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_Xx(va_list *argz, unsigned long *D, flag_list *flagz)
{
	int val = va_arg(*argz, int);
	int digit, result;
	char hex_val;

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
	for (digit = 1; (val / digit) >= 16; digit *= 16)
	;
	/* walk it back one, and print all the values */
	for (; digit >= 1; val %= digit, digit /= 16)
	{
		prnt_hlpr(val / digit, (*flagz).X, D);
	}
	flags_reset(flagz);
}
/**
 * prnt_hlpr - hex printer
 * @result: value to print
 * @caps: flags.X int indication to print Caps
 * @D: count of chars printed
 * Return: void
 */
void prnt_hlpr(int result, int caps, unsigned long *D)
{
	if (result == 10 && caps)
		_putchar('A');
	else if (result == 10)
		_putchar('a');
	else if (result == 11 && caps)
		_putchar('B');
	else if (result == 11)
		_putchar('b');
	else if (result == 12 && caps)
		_putchar('C');
	else if (result == 12)
		_putchar('c');
	else if (result == 13 && caps)
		_putchar('D');
	else if (result == 13)
		_putchar('d');
	else if (result == 14 && caps)
		_putchar('E');
	else if (result == 14)
		_putchar('e');
	else if (result == 15 && caps)
		_putchar('F');
	else if (result == 15)
		_putchar('f');
	else
		_putchar(result + '0');
	++*D;
}
