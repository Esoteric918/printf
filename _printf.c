#include "holberton.h"
#include <limits.h>
#include <stdio.h>
/**
 * _printf - print the numbers passed to func with separator
 * @format: a string to print with various identifiers to inject variables
 * Return: void
 */
int _printf(const char * const format, ...)
{
	int i = 0, D = 0, bcnt = 0;
	void (*funk)(va_list *, int *, flag_list *);
	char *buffr = malloc(2000);
	va_list args;
	flag_list flags;

	/* check if format exists */
	if (format == NULL)
		return (-1);
/*
	for (i = 0; format[i]; i++)
	;
	if (i == 0)
		return (0);
	i = 0;*/
	/* set initial flags */
	flags_reset(&flags);
	va_start(args, format);
	while (format && format[i])
	{
		/* identify and set flags, or exit returning chars printed */
		if (flag_set(&format[i], &flags, &i, &D, buffr, &bcnt))
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
	free(buffr);
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
int flag_set(const char *c, flag_list *flagz, int *i, int *D, char *buffr, int *bcnt)
{
	char *mods = "hlX" /* *ops = "bcdio%suxX" */;
	int j;

	if (!(*flagz).op && *c == '%')
	{
		(*flagz).op = 1;
		++c;
		++*i;
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
	if ((*flagz).op && get_funky(*c))
		return (0);

	if ((*flagz).op && (*c + 1) == '\0')
	{
		*(buffr + *bcnt) = '\0';
		/* print the buffer */
		p_buffer(buffr, D);
		flags_reset(flagz);
		return (1);
	}
	else if ((*flagz).op)
	{
		*(buffr + (*bcnt)) = *c;
		++*i;
		++*bcnt;
		flag_set((c + 1), flagz, i, D, buffr, bcnt);
	}
	return (0);
}
