#include "holberton.h"
#include "funky_hlpr.c"

/**
 * print_numbers - print the numbers passed to func with separator
 * @n: the numbers to print
 * @separator: the string to put between numbers
 * Return: void
 */
unsigned long long print_all(const char * const format, ...)
{
	int i = 0;
	void (*funk)(va_list *, unsigned long long *);
	char ch2str[2];
	unsigned long long D = 0;

	va_list args;
	va_start(args, format);

	while (format && format[i])
	{
		ch2str[0] = format[i];
		ch2str[1] = '\0';

		funk = get_funky(ch2str);

		/* check if func != NULL */
		if (funk != NULL)
		{
			/* feed in the va_list for current function */
			funk(&args, &D);
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
void (*get_funky(char *s))(va_list *, unsigned long long *)
{
	op_t ops[] = {
		{"c", p_c},
		{"i", p_d},
		{"f", p_f},
		{"s", p_s},
		{"%", p_p},
		{NULL, NULL}
	};
	int i = 0;

	/* find the correct func based on s */
	while (ops[i].op != NULL && strcmp(ops[i].op, s))
		++i;

	return (ops[i].f);
}

int main(void)
{
	printf("%llu", print_all("c%is", 'p', 0, "stuff"));

	return (0);
}
