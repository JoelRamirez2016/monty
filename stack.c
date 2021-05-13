#include "stack.h"
/**
 * add_node_stack - adds a new node to the stack
 * @stack: stack
 * @line_number: second argument of input
 */
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

/**
 * delete_node_stack - deletes a node in the stack
 * @stack: stack
 */
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

/**
 * free_stack - frees stack
 * @stack: stack
 */
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
