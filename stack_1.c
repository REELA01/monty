#include "monty.h"
/**
 * print_stk - print satck
 * @stk: top node pointer
 * @line_n: opcode linenum
*/
void print_stk(stack_t **stk, unsigned int line_n)
{
	stack_t *curr;

	(void) line_n;
	if (stk == NULL)
		exit(EXIT_FAILURE);
	curr = *stk;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
/**
 * print_topstk - print top node
 * @stk: poinetr of top node
 * @line_n: linenum of opcode
*/
void print_topstk(stack_t **stk, unsigned int line_n)
{
	if (stk == NULL || *stk == NULL)
		err_or2(6, line_n);

	printf("%d\n", (*stk)->n);
}
/**
 * add_to_stk - Add node
 * @nn: newnode pointer
 * @lnum: linenumber
*/
void add_to_stk(stack_t **nn, __attribute__((unused))unsigned int lnum)
{
	stack_t *curr;

	if (nn == NULL || *nn == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nn;
		return;
	}
	curr = head;
	head = *nn;
	head->next = curr;
	curr->prev = head;
}
/**
 * pop_topstk - pop node from stack
 * @stk: top node pointer
 * @line_n: linenum of opcode
*/
void pop_topstk(stack_t **stk, unsigned int line_n)
{
	stack_t *curr;

	if (stk == NULL || *stk == NULL)
		err_or2(7, line_n);
	curr = *stk;
	*stk = curr->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(curr);
}
