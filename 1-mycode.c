#include "monty.h"


/**
 * add_stk - Adds a node to the stack.
 * @newnd: Pointer to the new node.
 * @ln: Interger representing the line number of of the code.
 */
void add_stk(stack_t **newnd, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newnd == NULL || *newnd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnd;
		return;
	}
	tmp = head;
	head = *newnd;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * printfun_stk - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: line number of  the code.
 */
void printfun_stk(stack_t **stack, unsigned int linenbr)
{
	stack_t *tmp;

	(void) linenbr;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void _pop(stack_t **stack, unsigned int linenbr)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_errs(7, linenbr);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printed_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenbr: Interger representing the line number of of the code.
 */
void printed_top(stack_t **stack, unsigned int linenbr)
{
	if (stack == NULL || *stack == NULL)
		more_errs(6, linenbr);
	printf("%d\n", (*stack)->n);
}
