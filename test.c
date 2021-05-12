#include "monty.h"

int main()
{
	char *string = "hola banana";
	char **args = _strtok(string, ' ');

	printf("string: %s\n", args[0]);
	printf("string(1): %s\n", args[1]);
	return (0);
}
