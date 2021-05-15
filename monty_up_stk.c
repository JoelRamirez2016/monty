#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *old_next;

	old_next = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	if ((*stack)->next)
		(*stack)->next->prev = *stack;
	(*stack)->prev = old_next;
	old_next->next = *stack;
	old_next->prev = 0;
	*stack = old_next;

}

