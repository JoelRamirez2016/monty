#include "monty.h"

char **file_tokens;
int exeMonty(char *l, stack_t **stack, int line_n);

/**
 * main - interpreter of monty bytecodes
 * @argc: number of arguments of the program
 * @argv: arguments of the program
 * Return: 0 if success, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t size_l, lN = 0;
	stack_t *stack = 0;
	int status = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size_l, fp) != EOF)
	{
		status = exeMonty(line, &stack, ++lN);

		if (status == EXIT_FAILURE)
			break;
	}
	free(line);
	free_stack(&stack);
	fclose(fp);
	return (status);
}

/**
 * exeMonty - execute a monty instruction in a line
 * @l: line with the monty instruction
 * @stack: stack of vars
 * @line_n: number of line with monty instruction
 * Return: status of the monty instruction
 */
int exeMonty(char *l, stack_t **stack, int line_n)
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
	int i, status = 0;
	char *opcode;


	file_tokens = _split(l, " \n");
	opcode = file_tokens[0];

	for (i = 0; instructions[i].opcode; i++)
	{
		if (opcode)
			if (_strcmp(instructions[i].opcode, opcode) == 0)
			{
				status = error_checker(stack, opcode, line_n);

				if (status != EXIT_FAILURE)
					instructions[i].f(stack, line_n);
				break;
			}
	}
	if (opcode && !instructions[i].opcode)
		status = error_checker(stack, opcode, line_n);

	free_split(file_tokens, 2);
	return (status);
}
