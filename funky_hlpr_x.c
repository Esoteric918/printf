#include "holberton.h"
/**
 * p_fd - print floats, doubles, and long doubles up to 19 points
 * @argz: currently a fractional value in va_list
 * @D: count of chars printed
 * @flagz: UNUSED - list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_fd(va_list *argz, unsigned long *D, flag_list *flagz)
{
	long double val = va_arg(*argz, long double);
	long double digit;
	int i;

	UNUZED(flagz);
	/* check for negative val */
	if (val < 0)
	{
		_putchar('-');
		val *= -1;
		++*D;
	}
	if (val == 0)
	{
		putchar('0');
		++*D;
	}
	if (val >= 1)
	{
		/* if val >= 1 find size of val */
		for (digit = 1; (val / digit) >= 10; digit *= 10)
		;
	}
	else
	{
		_putchar('.');
		++*D;
		/* if 0 < val < 1 */
		for (digit = 0.000000000000000001; (val / digit) >= 10; digit *= 10)
		;
	}
	/* walk it back one, and print all the values */
	for (i = 0; val > 0 && i < 19; val = fmod(val, digit), digit /= 10)
	{
		_putchar((val / digit) + '0');
		if (val < 1 && val > 0)
			++i;
		++*D;
	}
	flags_reset(flagz);
}
