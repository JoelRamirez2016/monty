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
 * _strtok - splits string into multiple arguments
 * @string: string
 * @delim: word separator
 * Return: array of strings
 */
char **_strtok(char *string, const char delim)
{
	char **token;
	int indletter = 0, indword = 0, indstr = 0;

	if (string == NULL || delim == '\0')
		return (NULL);

	if (string[indstr] == delim)
		while (string[indstr] == delim)
			indstr++;

	for (; string[indstr]; indstr++)
		if (string[indstr] == delim)
		{
			indword++;
			indletter = 0;
			while (string[indstr] == delim)
				indstr++;
		}
		else
		{
			token[indword][indletter] = string[indstr];
			indletter++;
		}
	return (token);
}
