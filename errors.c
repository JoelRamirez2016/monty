#include "monty.h"

/**
 * error_checker - check posible errors in a opcode function
 * @stack: stack o modify with the opcode
 * @opcode: opcode to check
 * @line_n: line number of the opcode in file
 * Return: EXIT_FAILURE if the function called could fail to be invoked
 * otherwise EXIT_SUCCESS
 */
int error_checker(stack_t **stack, char *opcode, int line_n)
{
	int status = EXIT_SUCCESS;

	if (opcode && _strcmp(opcode, "push") == 0)
	{
		if (!file_tokens[1] || !is_number(file_tokens[1]))
		{
			fprintf(stderr, "L<%u>: usage: push integer\n", line_n);
			status = EXIT_FAILURE;
		}
	}
	else if (opcode && _strcmp(opcode, "pall") == 0)
	{
	}
	else if (opcode &&_strcmp(opcode, "pint") == 0)
	{
		if (!*stack)
		{
			fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_n);
			status = EXIT_FAILURE;
		}
	}
	else
	{
		fprintf(stderr, "L<%i>: unknown instruction <%s>\n", line_n, opcode);
		status = EXIT_FAILURE;
	}

	return (status);
}
