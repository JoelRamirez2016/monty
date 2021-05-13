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
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return *s1 - *s2;
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
                if ((!_strchr(ds, s[i]) && _strchr(ds, s[i + 1])) ||
                (!_strchr(ds, s[i]) && !s[i + 1]))
                        lenA += 1;

        array = malloc(sizeof(*array) * lenA + 1);

        if (!array)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        for (k = 0; k < lenA; k++)
        {
                i = j == 0 ? 0 : j + 1;
                j = i;
                while (s[j])
                    if ((!_strchr(ds, s[j]) && _strchr(ds, s[j + 1])) ||
                    (!_strchr(ds, s[j]) && !s[j + 1]))
                        break;
                    else
                        j++;
                j++; 
                array[k] = malloc(sizeof(char) * (j - i + 1));
                
                while (i <= j)
                {
                    if (!_strchr(ds, s[i]))
                    {
                        array[k][w] = s[i];
                        w++;
                    }
                    i++;
                }
                array[k][w] = 0;
                w = 0;
        }
        array[k] = 0;
        return (array);
}
/**
 * _strchr - locates a character in a string
 * @s: pointer to check value
 * @c: char search in s
 * Return: pointer with value updated.
*/

char *_strchr(char *s, char c)
{
	int i;
	for (i = 0; s && s[i]; i++)
		if (s[i] == c)
			return (s + i);
	return (0);
}

void free_split(char **s, int len)
{
	int i;

	for (i = 0; i < len; i++)
		free(s[i]);
	free(s);
}

int is_number(char *s)
{
	int i;

	for (i = 0; s && s[i]; i++)
		if (!(s[i] == '-' && i == 0) && (s[i] < '0' || s[i] > '9'))
			return (0);
	return (1);
}
