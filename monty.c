#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new && stack)
	{
		new->n = line_number;
		new->prev = 0;
		new->next = *stack;

		if (*stack)
			(*stack)->prev = new;

		*stack = new;
	}
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
