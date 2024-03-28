#include "monty.h"

/**
 * mulnods - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void mulnods(stack_t **stack, unsigned int linenbr)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, linenbr, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modnods - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void modnods(stack_t **stack, unsigned int linenbr)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, linenbr, "mod");


	if ((*stack)->n == 0)
		more_errors(9, linenbr);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
