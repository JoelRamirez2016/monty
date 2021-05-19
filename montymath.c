#include "monty.h"

/**
 * add - adds the two top elements of stack
 * @stack: stack
 * @line_number: second argument of input
 */
void add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	delete_node_stack(stack);
}
/**
 * sub - substracts top element of stack from the 2nd top element
 * @stack: stack
 * @line_number: second argument of input
 */
void sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
		delete_node_stack(stack);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * _div - divides the 2nd top element of stack by the top element
 * @stack: stack
 * @line_number: second argument of input
 */
void _div(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			printf("L<line_number>: division by zero\n");
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n = (*stack)->next->n / (*stack)->n;
		delete_node_stack(stack);
	}
	else
	{
		printf("L<line_number>: can't div, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * mul - multiply 2nd top element of stack with the top element
 * @stack: stack
 * @line_number: second argument of input
 */
void mul(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n = (*stack)->next->n * (*stack)->n;
		delete_node_stack(stack);
	}
	else
	{
		printf("L<line_number>: can't mul, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - computes remainder of a division between 2nd and top element of stack
 * @stack: stack
 * @line_number: second argument of input
 */
void mod(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			printf("L<line_number>: division by zero\n");
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n = (*stack)->next->n % (*stack)->n;
		delete_node_stack(stack);
	}
	else
	{
		printf("L<line_number>: can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
