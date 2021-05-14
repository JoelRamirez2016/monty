#include "stack.h"

/**
 * add_node_stack - add node in the stack
 * @stack: stack of vars to add
 * @line_number: number to add in the new node
 */
void add_node_stack(stack_t **stack, int number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->prev = 0;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;
		*stack = new;
}

/**
 * delete_node_stack - delete the fisrt node in the stack
 * @stack: stack of vars to delete
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
 * free_stack - free all memory of the stack
 * @stack: stack to empty
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
