#include "monty.h"
/**
 * is_number - check if a string is a number
 * @s: string
 * Return: 1 if true, 0 if false
 */
int is_number(char *s)
{
	int i;

	for (i = 0; s && s[i]; i++)
		if (!(s[i] == '-' && i == 0) && (s[i] < '0' || s[i] > '9'))
			return (0);
	return (1);
}
