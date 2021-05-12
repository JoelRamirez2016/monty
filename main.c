#include "monty.h"

void exeMonty(char *l);
stack_t *stack;

int main(int argc, char *argv[])
{
	FILE *fp;
	char buff[1024], line[255];

	fp = fopen("bytecodes.m", "r");

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
		{0, 0}
	};
	int i;
	char *opcode;
	char *arg;

	opcode = strtok(l, " \n");
	arg = strtok(0, " \n");
	for (i = 0; instructions[i].opcode; i++)
		if(strcmp(instructions[i].opcode, opcode) == 0)
			instructions[i].f(&stack, arg ? atoi(arg) : 0);
}
