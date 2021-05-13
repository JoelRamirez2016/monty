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
	if (_strcmp(opcode, "unknown") == 0)
	{
		fprintf(stderr, "L<%i>: unknown instruction <%s>\n", line_n, opcode);
		return (EXIT_FAILURE);
	}
	if (_strcmp(opcode, "push") == 0)
		if ( !file_tokens[1] || !is_number(file_tokens[1]))
		{
			fprintf(stderr, "L<%u>: usage: push integer\n", line_n);
			return (EXIT_FAILURE);
		}
	if (_strcmp(opcode, "pint") == 0)
		if (!*stack)
		{
			fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_n);
			return (EXIT_FAILURE);
                }

	return (EXIT_SUCCESS);
}