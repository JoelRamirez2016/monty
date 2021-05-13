#include "stack.h"

void add_node_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->prev = 0;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;
		*stack = new;
}


void delete_node_stack(stack_t **stack)
{
	stack_t *curr = *stack;

	if (!*stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(curr);
}

void free_stack(stack_t **stack)
{
	stack_t *curr = *stack, *next;

	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}
