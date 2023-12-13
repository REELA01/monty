#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#define _GNU_SOURCE
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *head;
int len_chars(FILE *);
typedef void (*op_func)(stack_t **, unsigned int);
/*Stack_1*/
void print_stk(stack_t **stk, unsigned int line_n);
void print_topstk(stack_t **stk, unsigned int line_n);
void add_to_stk(stack_t **nn, __attribute__((unused))unsigned int lnum);
void pop_topstk(stack_t **stk, unsigned int line_n);
/*Main.c*/
void addto_que(stack_t **nn, __attribute__((unused))unsigned int lnum);
stack_t *make_nod(int number);
void free_nod(void);
/*Swnop.c*/
void swap_nod(stack_t **stk, unsigned int lnum);
void nop(stack_t **stk, unsigned int lnum);
/*Basic_cal.c*/
void add_func(stack_t **stk, unsigned int lnum);
void sub_func(stack_t **stk, unsigned int lnum);
void mul_func(stack_t **stk, unsigned int lnum);
void div_func(stack_t **stk, unsigned int lnum);
void mod_func(stack_t **stk, unsigned int lnum);
/*Pstrchar*/
void p_char(stack_t **stk, unsigned int lnum);
void p_str(stack_t **stk, __attribute__((unused))unsigned int lnum);
/*Rotate*/
void rotate_norm(stack_t **stk, __attribute__((unused))unsigned int lnum);
void rotate_rev(stack_t **stk, __attribute__((unused))unsigned int lnum);
