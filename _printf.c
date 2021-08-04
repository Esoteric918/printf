#include "holberton.h"
/**
 * print_all - print the numbers passed to func with separator
 * @format: a string to print with various identifiers to inject variables
 * Return: void
 */
unsigned long print_all(const char * const format, ...)
{
	int i = 0;
	void (*funk)(va_list *, unsigned long *, flag_list *);
	unsigned long D = 0;
	va_list args;

	/* establish flags variable and set initial values */
	flag_list flags;

	flags_reset(&flags);
	va_start(args, format);
	while (format && format[i])
	{
		/* identify and set flags */
		flag_set(&format[i], &flags, &i);
		/* if not for flags.op */
		if (!flags.op)
		{
			_putchar(format[i]);
			++D;
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
	_putchar('\n');
	return (D);
}
/**
 * get_funky - returns a pointer to the correct function to use
 * @s: string of operation fed from argv[2]
 * Return: pointer to the correct function
 */
void (*get_funky(char s))(va_list *, unsigned long *, flag_list *)
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
 * @i: iderate whe the op is found
 */
void flag_set(const char *c, flag_list *flagz, int *i)
{
	switch (*c)
	{
	case '%':
		if (!(*flagz).op)
		{
			(*flagz).op = 1;
			++*i;
			flag_set(c + 1, flagz, i);
		}
		break;
	case 'h':
		(*flagz).h = 1;
		break;
	case 'l':
		(*flagz).l = 1;
		break;
	case 'X':
		(*flagz).X = 1;
	}
}
/* for testing */
int main(void)
{
	int d = 327670;
	d = print_all("my balls%c,%%,%i,%s,%d,%u,%hd,%b,%o,%X", 'p', 0, "stuff", -214, UINT_MAX, d, 9, -214, 175);
	print_all("%d", d);
	return (0);
}