#include "holberton.h"
/**
 * p_o - print number in Base8, Octal
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * @flagz: list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_o(va_list *argz, int *D, flag_list *flagz)
{
	unsigned int val;
	unsigned int digit;

	if ((*flagz).l)
	{
		*D += p_l_uns(argz, 8, flagz);
		return;
	}
	val = va_arg(*argz, unsigned int);
	if ((*flagz).h)
	{
		/* check if value is within short range */
		if (val > USHRT_MAX)
		{
			*D += _putchar('-');
			*D += _putchar('1');
			return;
		}
	}
	if ((*flagz).sp)
		*D += _putchar(' ');
	/* find the size of int */
	for (digit = 1; (val / digit) >= 8; digit *= 8)
	;
	/* walk it back one, and print all the values */
	for (; digit >= 1; val %= digit, digit /= 8)
		*D += _putchar((val / digit) + '0');
}
/**
 * p_u - print unsigned integer in Base10
 * @argz: currently unsigned integer in va_list
 * @D: count of chars printed
 * @flagz: UNUSED - list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_u(va_list *argz, int *D, flag_list *flagz)
{
	unsigned int val;
	unsigned int digit;

	if ((*flagz).l)
	{
		*D += p_l_uns(argz, 10, flagz);
		return;
	}
	val = va_arg(*argz, unsigned int);
	if ((*flagz).sp)
		*D += _putchar(' ');
	/* find the size of val */
	for (digit = 1; (val / digit) >= 10; digit *= 10)
	;
	/* walk it back one, and print all the values */
	for (; digit >= 1; val %= digit, digit /= 10)
		*D += _putchar((val / digit) + '0');
}
/**
 * p_Xx - print value in Base16, hexidecimal
 * @argz: currently integer in va_list
 * @D: count of chars printed
 * @flagz: list of possible print modifiers
 * Return: count of chars from int printed
 */
void p_Xx(va_list *argz, int *D, flag_list *flagz)
{
	unsigned int val;
	unsigned int digit;

	if ((*flagz).l)
	{
		*D += p_l_uns(argz, 16, flagz);
		return;
	}
	val = va_arg(*argz, unsigned int);
	if ((*flagz).h)
	{
		/* check if value is within short range */
		if (val > USHRT_MAX)
		{
			*D += _putchar('-');
			*D += _putchar('1');

			return;
		}
	}
	if ((*flagz).sp)
		*D += _putchar(' ');
	/* find the size of int */
	for (digit = 1; (val / digit) >= 16; digit *= 16)
	;
	/* walk it back one, and print all the values */
	for (; digit >= 1; val %= digit, digit /= 16)
	{
		*D += p_hex_hlpr(val / digit, (*flagz).X);
	}
}
/**
 * p_hex_hlpr - hex printer
 * @result: value to print
 * @caps: flags.X int indication to print Caps
 * Return: void
 */
int p_hex_hlpr(int result, int caps)
{
	int count = 0;

	char val_U[] = "0123456789ABCDEF";
	char val_L[] = "0123456789abcdef";

	if (caps)
		count += _putchar(val_U[result]);
	else
		count += _putchar(val_L[result]);

	return (count);
}
/**
 * p_buffer - print buffer
 * @buff: buffer to print
 * @D: count of chars printed
 * Return: void
 */
void p_buffer(char *buff, int  *D)
{
	int i;

	for (i = 0; buff[i]; ++i, ++*D)
		_putchar(buff[i]);
}
