#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (!add_node_stack(stack, atoi(file_tokens[1])))
	{
		file_tokens[2][0] = '1';
	}
}
/**
 * pall - prints all values on the stack starting from the top
 * @stack: stack
 * @line_number: second argument of input
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%i\n", curr->n);
		curr = curr->next;
	}
}
/**
 * pint - prints value at the top of the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	printf("%i\n", (*stack)->n);
}
/**
 * pop - removes top element of stack
 * @stack: stack
 * @line_number: second argument of input
 */
void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	delete_node_stack(stack);
}
/**
 * nop - nothing
 * @stack: stack
 * @line_number: second argument of input
 */
void nop(__attribute__((unused)) stack_t **stack,
	 __attribute__((unused)) unsigned int line_number)
{
}
