#include "holberton.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        /* check rtrn val of func to confirm success */
        return (write(1, &c, 1));
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
