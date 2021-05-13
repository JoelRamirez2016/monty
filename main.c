#include "monty.h"

void exeMonty(char *l);
stack_t *stack;

int main(int argc, char *argv[])
{
	FILE *fp;
	char buff[1024], line[255];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if(!fp)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 255, (FILE*)fp))
	{
		exeMonty(line);
	}

	free_stack(&stack);
	fclose(fp);
	return (0);
}

void exeMonty(char *l)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{0, 0}
	};
	int i;
	char *opcode;
	char *arg;
	char **args = _split(l, " \n");

	opcode = args[0];
	arg = args[1];

	for (i = 0; instructions[i].opcode; i++)
		if(strcmp(instructions[i].opcode, opcode) == 0)
			instructions[i].f(&stack, arg ? atoi(arg) : 0);
	for (i = 0; i < 2; i++) 
		free(args[i]);
	free(args);

	if (!instructions[i].opcode)
	{}

}
