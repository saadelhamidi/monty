#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list represent the stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - code and its function
 * @code: the code
 * @f: function to handle the code
 *
 * Description: code and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int linenbr);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void error(int _errs, ...);
void more_errors(int error_code, ...);
void str_errors(int _errs, ...);

void open_fun(char *f_name);
void read_fun(FILE *fd);
int parsefun(char *buffer, int linenbr, int i);
void callfun(op_func func, char *ops, char *val, int ln, int f);
void find_fun(char *ops, char *val, int ln, int i);

stack_t *nods(int n);
void fr_nodes(void);
void addqueue(stack_t **, unsigned int);

void add_stk(stack_t **, unsigned int);
void printfun_stk(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void printed_top(stack_t **, unsigned int);

void nop(stack_t **, unsigned int);
void swapnods(stack_t **, unsigned int);
void addnods(stack_t **, unsigned int);
void subnods(stack_t **, unsigned int);
void divnods(stack_t **, unsigned int);

void mulnods(stack_t **, unsigned int);
void modnods(stack_t **, unsigned int);

void printed_char(stack_t **, unsigned int);
void printed_str(stack_t **, unsigned int);
void rfnsb(stack_t **, unsigned int);
void rlnst(stack_t **, unsigned int);


#endif
