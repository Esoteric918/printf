#include "holberton.h"
#include "funky_hlpr_0-1.c"
#include "funky_hlpr_2.c"
/**
 * print_numbers - print the numbers passed to func with separator
 * @n: the numbers to print
 * @separator: the string to put between numbers
 * Return: void
 */
unsigned long long print_all(const char * const format, ...)
{
	int i = 0;
	void (*funk)(va_list *, unsigned long long *, flag_list *);
	flag_list flags;
	char ch2str[2];
	unsigned long long D = 0;

	va_list args;
	va_start(args, format);

	while (format && format[i])
	{
		/* identify and set flags */
		switch(format[i])
		{
			case 'h':
				flags.h = 1;
			case 'l':
				flags.l = 1;
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
				printf(", ");
		}
		++i;
	}
	va_end(args);

	printf("\n");

	return (D);
}
/**
 * get_funky - returns a pointer to the correct function to use
 * @s: string of operation fed from argv[2]
 * Return: pointer to the correct function
 */
void (*get_funky(char *s))(va_list *, unsigned long long *, flag_list *)
{
	spec_list spec[] = {
		{"b", p_b},
		{"c", p_c},
		{"d", p_di},
		{"f", p_fd},
		{"i", p_di},
		{"%", p_p},
		{"s", p_s},
		{"u", p_u},
		{"o", p_o},
		{NULL, NULL}
	};
	int i = 0;

	/* find the correct func based on s */
	while (spec[i].op != NULL && strcmp(spec[i].op, s))
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
}
/* for testing */
int main(void)
{
	int d = 327670;
	printf("%o\n", INT_MIN);
	printf("%llu", print_all("c%isduhdbo", 'p', 0, "stuff", INT_MIN, UINT_MAX, d, 9, INT_MIN));

	return (0);
}
