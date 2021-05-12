#include "monty.h"

int main()
{
	char *string = "hola banana";
	char **args = _strtok(string, ' ');
	int indargs = 0;
	printf("string: %s\nstring(1): %s\n", args[0], args[1]);
	/*printf("string(1): %s\nstring(2): %s\nstring(3): %s\nstring(4): %s\n", args[1], args[2], args[3], args[4]);*/
	for (; args[indargs]; indargs++)
	{
		printf("%d\n", indargs);
		free(args[indargs]);
	}
	free(args);
	return (0);
}
