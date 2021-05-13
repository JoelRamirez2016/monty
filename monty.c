#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void push(stack_t **stack, unsigned int line_number)
{
	add_node_stack(stack, line_number);
}
/**
 * pall - prints all values on the stack starting from the top
 * @stack: stack
 * @line_number: second argument of input
 */
void pall(stack_t **stack, unsigned int line_number)
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
void pint(stack_t **stack, unsigned int line_number)
{
	printf("%i\n", (*stack)->n);
}
/**
 * pop - removes top element of stack
 * @stack: stack
 * @line_number: second argument of input
 */
void pop(stack_t **stack, unsigned int line_number)
{
	delete_node_stack(stack);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: second argument of input
 */
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
/**
 * add - adds the two top elements of stack
 * @stack: stack
 * @line_number: second argument of input
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n = (*stack)->n + (*stack)->next->n;
		delete_node_stack(stack);
	}
	else
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * nop - does absolutely nothing
 * @stack: stack
 * @line_number: second argument of input
 */
void nop(stack_t **stack, unsigned int line_number)
{
}
/**
 * sub - substracts top element of stack from the 2nd top element
 * @stack: stack
 * @line_number: second argument of input
 */
void sub(stack_t **stack, unsigned int line_number)
{
        if (*stack && (*stack)->next)
        {
                (*stack)->next->n = (*stack)->next->n - (*stack)->n;
                delete_node_stack(stack);
        }
        else
        {
                printf("L<line_number>: can't sub, stack too short\n");
                exit(EXIT_FAILURE);
        }
}
/**
 * _div - divides the 2nd top element of stack by the top element
 * @stack: stack
 * @line_number: second argument of input
 */
void _div(stack_t **stack, unsigned int line_number)
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
void mul(stack_t **stack, unsigned int line_number)
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
 * mod - computes the remainder of a division between 2nd and top element of stack
 * @stack: stack
 * @line_number: second argument of input
 */
void mod(stack_t **stack, unsigned int line_number)
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
/**
 * pchar - print char at the top of the stack
 * @stack: stack
 * @line_number: second argument of input
 */
void pchar(stack_t **stack, unsigned int line_number)
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
