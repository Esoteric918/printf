#include "holberton.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
}
/**
 * op_add - add two numbers and return result
 * @a: number to be added
 * @b: number to be added
 * Return: result of a + b
 */
void p_c(void *c)
{

	_putchar(get_op_func(void *);   /** working out set up for fucntion**/
}
}
/**
 * p_s  - print string
 * @str:  agr string
 * 
 * Return: ????
 */
void p_s(void *str)
{
	int i = 0;
        if (!str)
             str = "(null)";
        while (str[i] != '\0')   /** working out set up for fucntion*/
	{
		_putchar(str[i]);
		i++;

	}
}
/**
 * op_sub - subtract two numbers and return result
 * @a: number to be subtracted from
 * @b: number to subtract
 * Return: result of a - b
 */
void p_d(void *num)
{
	printf("%d", num);
}
/**
 * op_mul - multiply two numbers and return result
 * @a: number to be multiplied
 * @b: number to be multiplied
 * Return: result of a * b
 */
void p_f(void *db)
{
	printf("%f", db);
}
