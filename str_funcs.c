#include "hoberton.h"

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
