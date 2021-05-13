#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	add_node_stack(stack, atoi(file_tokens[1]));
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
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *old_next;

	if (*stack && (*stack)->next)
	{
		old_next = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->next->prev = *stack;
		(*stack)->prev = old_next;
		old_next->next = *stack;
		old_next->prev = 0;
		*stack = old_next;
	}
}
/**
 * nop - does absolutely nothing
 * @stack: stack
 * @line_number: second argument of input
 */
void nop(__attribute__((unused)) stack_t **stack,
	 __attribute__((unused)) unsigned int line_number)
{
}
/**
 * pchar - print char at the top of the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void pchar(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack)
	{
		if ((*stack)->n > 177 || (*stack)->n < 0)
		{
			printf("L<line_number>: can't pchar, value out of range\n");
			exit(EXIT_FAILURE);
		}
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		printf("L<line_number>: can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}
}
