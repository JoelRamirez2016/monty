#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	add_node_stack(stack, line_number);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%i\n", curr->n);
		curr = curr->next;
	}
}
void pint(stack_t **stack, unsigned int line_number)
{
	printf("%i\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	delete_node_stack(stack);
}

void swap(stack_t **stack, unsigned int line_number)
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

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)	
	{
		(*stack)->next->n = (*stack)->n + (*stack)->next->n;
		delete_node_stack(stack);
	}
	else
	{
		printf("L<line_number>: can't add, stack too short");
		exit(EXIT_FAILURE);
	}	
}

void nop(stack_t **stack, unsigned int line_number)
{
}
