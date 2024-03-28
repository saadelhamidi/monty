#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @_errs: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int _errs, ...)
{
	va_list arg;
	char *lnt;
	int nums;

	va_start(arg, _errs);
	switch (_errs)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			nums = va_arg(arg, int);
			lnt = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", nums, lnt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	fr_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - handles errors.
 * @_errs: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_errors(int _errs, ...)
{
	va_list arg;
	char *lnt;
	int nums;

	va_start(arg, _errs);
	switch (_errs)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			nums = va_arg(arg, unsigned int);
			lnt = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", nums, lnt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	fr_nodes();
	exit(EXIT_FAILURE);
}

/**
 * str_errors - handles errors.
 * @_errs: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void str_errors(int _errs, ...)
{
	va_list arg;
	int nums;

	va_start(arg, _errs);
	nums = va_arg(arg, int);
	switch (_errs)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", nums);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", nums);
			break;
		default:
			break;
	}
	fr_nodes();
	exit(EXIT_FAILURE);
}
