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

	if (opcode && strcmp(opcode, "pop") == 0)
        {
		if (!*stack)
		{
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
			status = EXIT_FAILURE;
		}
	}
	else if (opcode && strcmp(opcode, "push") == 0)
	{
	}
	else if (opcode && strcmp(opcode, "pall") == 0)
	{
	}
	else if (opcode && strcmp(opcode, "pint") == 0)
	{
		if (!*stack)
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
			status = EXIT_FAILURE;
		}
	}

	return (status);
}
