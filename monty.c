#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	printf("push function called\n");
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
