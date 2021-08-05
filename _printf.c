#include "holberton.h"
#include <limits.h>
#include <stdio.h>
#include "funky_hlpr_0-3.c"
#include "funky_hlpr_4.c"
#include "str_funks.c"

/**
 * _printf - print the numbers passed to func with separator
 * @format: a string to print with various identifiers to inject variables
 * Return: void
 */
int _printf(const char * const format, ...)
{
	int i = 0, D = 0;
	void (*funk)(va_list *, int *, flag_list *);
	va_list args;
	flag_list flags;

	/* check if format exists */
	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	;
	if (format[i - 1] == '%' || i == 0)
		return (0);
	i = 0;
	/* set initial flags */
	flags_reset(&flags);
	va_start(args, format);
	while (format && format[i])
	{
		/* identify and set flags, or exit returning chars printed */
		if (flag_set(&format[i], &flags, &i, &D))
			return (-1);
		/* if not for flags.op */
		if (!flags.op)
		{
			D += _putchar(format[i]);
			flags_reset(&flags);
		}
		else
		{
			funk = get_funky(format[i]);
			/* check if func != NULL */
			if (funk != NULL)
				funk(&args, &D, &flags);
		}
		++i;
	}
	va_end(args);
	flags_reset(&flags);
	return (D);
}
/**
 * get_funky - returns a pointer to the correct function to use
 * @s: string of operation fed from argv[2]
 * Return: pointer to the correct function
 */
void (*get_funky(char s))(va_list *, int *, flag_list *)
{
	char ch2str[2];
	spec_list spec[] = {
		{"b", p_b},
		{"c", p_c},
		{"d", p_di},
		{"i", p_di},
		{"o", p_o},
		{"%", p_p},
		{"s", p_s},
		{"u", p_u},
		{"x", p_Xx},
		{"X", p_Xx},
		{NULL, NULL}
	};
	int i = 0;

	ch2str[0] = s;
	ch2str[1] = '\0';

	/* find the correct func based on s */
	while (spec[i].op != NULL && _strcmp(spec[i].op, ch2str))
		++i;

	return (spec[i].f);
}
/**
 * flags_reset - set the print modifiers to zero
 * @flagz: a flag_list with values to reset
 * Return: void
 */
void flags_reset(flag_list *flagz)
{
	(*flagz).op = 0;
	(*flagz).h = 0;
	(*flagz).l = 0;
	(*flagz).X = 0;
}
/**
 * flag_set - sets the flags for the current char
 * @c: current char in format
 * @flagz: our flag_list variable
 * @i: iterator where the op is found
 * @D: count of printed chars
 * Return: 1 if % is last char in c string, else 0
 */
int flag_set(const char *c, flag_list *flagz, int *i, int *D)
{
	char *mods = "hlX", *ops = "bcdio%suxX";
	int j, ordr = *i + 1;

	if (!*flagz.op && *c == '%')
	{
		(*flagz).op = order;
		++c;
		++*i;
	}
	}
	for (j = 0; (*flagz).op && mods[j]; ++j)
	{
		if (mods[j] == *c)
		{
			if (j == 0)
				(*flagz).h = ++ordr;
				return (0);
			else if (j == 1)
				(*flagz).l = ++ordr;
				return (0);
			else if (j == 2)
				(*flagz).X = ++ordr;
				return (0);
		}
	}
	for (j = 0; (*flagz).op && ops[j]; ++j)
		is (*ops[j] == *c)
			return (0);
	
	/* create a global flag buffer and add to it until it's end of buffer */

	if ((*flagz).op && *c == ' ')
		return (0);
	else if ((*flagz).op)
		*D += _putchar('%');






	if (!(*flagz).op && *c == '%')
	{
		(*flagz).op = 1;
		++*i;
		if (*(c + 1) == '\0')
			return (1);
		flag_set(c + 1, flagz, i, D);
	}
	for (j = 0; (*flagz).op && mods[j]; ++j)
	{
		if (mods[j] == *c)
		{
			if (j == 0)
				(*flagz).h = 1;
			else if (j == 1)
				(*flagz).l = 1;
			else if (j == 2)
				(*flagz).X = 1;
		}
	}
	if ((*flagz).op && *(c + 1) == '\0')
		return (1);
	for (j = 0; ops[j]; ++j)
		if (*c == ops[j])
			return (0);
	if ((*flagz).op && *c != ' ' && ((*flagz).h || (*flagz).l || (*flagz).X))
	{
		*D += _putchar('%');
		flags_reset(flagz);
	}
	return (0);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}