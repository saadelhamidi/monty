#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void nop(stack_t **stack, unsigned int linenbr)
{
	(void)stack;
	(void)linenbr;
}


/**
 * swapnods - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void swapnods(stack_t **stack, unsigned int linenbr)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errs(8, linenbr, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * addnods - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void addnods(stack_t **stack, unsigned int linenbr)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errs(8, linenbr, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subnods - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void subnods(stack_t **stack, unsigned int linenbr)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errs(8, linenbr, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divnods - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void divnods(stack_t **stack, unsigned int linenbr)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errs(8, linenbr, "div");

	if ((*stack)->n == 0)
		more_errs(9, linenbr);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
