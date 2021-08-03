#include "holberton.h"
#include "funky_hlpr_0-3.c"
#include "funky_hlpr_4.c"
#include "funky_hlpr_x.c"
/**
 * print_numbers - print the numbers passed to func with separator
 * @n: the numbers to print
 * @separator: the string to put between numbers
 * Return: void
 */
unsigned long print_all(const char * const format, ...)
{
	int i = 0;
	void (*funk)(va_list *, unsigned long *, flag_list *);
	char ch2str[2];
	unsigned long D = 0;
	va_list args;
	/* establish flags variable and set initial values */
	flag_list flags;

	reset_flags(&flags);
	va_start(args, format);

	while (format && format[i])
	{
		/* identify and set flags */
		switch(format[i])
		{
			case 'h':
				flags.h = 1;
				break;
			case 'l':
				flags.l = 1;
				break;
			case 'X':
				flags.X = 1;
				break;
		}

		ch2str[0] = format[i];
		ch2str[1] = '\0';

		funk = get_funky(ch2str);

		/* check if func != NULL */
		if (funk != NULL)
		{
			/* feed in the va_list for current function */
			funk(&args, &D, &flags);
			/* print seperator between values, should remove */
			if (format[i + 1] != '\0' )
				_putchar(',');
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
void (*get_funky(char *s))(va_list *, unsigned long *, flag_list *)
{
	spec_list spec[] = {
		{"b", p_b},
		{"c", p_c},
		{"d", p_di},
		{"f", p_fd},
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

	/* find the correct func based on s */
	while (spec[i].op != NULL && _strcmp(spec[i].op, s))
		++i;

	return (spec[i].f);
}
/**
 * reset_flags - set the print modifiers to zero
 * @flags: a flag_list with values to reset
 * Return: void
 */
void reset_flags(flag_list *flags)
{
	(*flags).h = 0;
	(*flags).l = 0;
	(*flags).X = 0;
}
/* for testing */
int main(void)
{
	int d = 327670;
	print_all("c%isduhdboX", 'p', 0, "stuff", -2147483647, UINT_MAX, d, 9, -2147483647, 175);

	return (0);
}
/**
 * _strcmp - compares two strings
 *@s1: dest of string
 *@s2: src of string
 *
 * Return: n
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] ; i++)
		if (s1[i] == '\0')
			return (0);
	return (s1[i] - s2[i]);

}