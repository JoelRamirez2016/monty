#include "monty.h"

/**
 * _strlen - return length of string
 * @string: string
 * Return: length of string
 */
size_t _strlen(const char *string)
{
	size_t length;

	for (length = 0; string[length]; length++)
		;
	return (length);
}
/**
 * _strcmp - compare two strings
 * @string: first string
 * @string2: second string
 * Return: 0 if equal, 1 if different
 */
int _strcmp(char *string, char *string2)
{
	while ((*string != '\0' && *string2 != '\0') && (*string == *string2))
	{
		string++;
		string2++;
	}
	if (*string == *string2)
		return (0);
	return (1);
}

/**
 * _split - create a array of strings
 * @s: string to split
 * @ds: delimiters of the strings
 * Return: array of strings
 */
char **_split(char *s, char *ds)
{
	int lenA = 0, i = 0, j = 0, k = 0, w = 0;
	char **array;

	for (i = 0; s && s[i]; i++)
		if ((!strchr(ds, s[i]) && strchr(ds, s[i + 1])) ||
		(!strchr(ds, s[i]) && !s[i + 1]))
			lenA += 1;
	array = malloc(sizeof(*array) * lenA + 1);
	array[lenA] = 0;

	for (i = 0; s && s[i]; i++)
	{
		if ((strchr(ds, s[i]) && !strchr(ds, s[i + 1])) ||
		(!strchr(ds, s[i]) && i == 0))
		{
			j = i + 1;

			while (!strchr(ds, s[j]))
				j++;
			j += i == 0 ? 1 : 0;

			array[k] = malloc(sizeof(char) * (j - i));
			array[k][j - i - 1] = 0;
			j = i == 0 ? 0 : i + 1;

			while (!strchr(ds, s[j]))
			{
				w = i == 0 ? j - i : j - i - 1;
				array[k][w] = s[j++];
			}
			k++;
		}
	}
	return (array);
}
