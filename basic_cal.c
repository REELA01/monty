#include "monty.h"
/**
 * add_func - do addtion
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void add_func(stack_t **stk, unsigned int lnum)
{
	int s;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err_or2(8, lnum, "add");

	(*stk) = (*stk)->next;
	s = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = s;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * sub_func - do sub
 * @stk: top node pointer
 * @lnum: opcode ;inenum
*/
void sub_func(stack_t **stk, unsigned int lnum)
{
	int m;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err_or2(8, lnum, "sub");

	(*stk) = (*stk)->next;
	m = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = m;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * mul_func - de multiplay
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void mul_func(stack_t **stk, unsigned int lnum)
{
	int mull;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err_or2(8, lnum, "mul");
	(*stk) = (*stk)->next;
	mull = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = mull;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * div_func - do devision
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void div_func(stack_t **stk, unsigned int lnum)
{
	int d;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err_or2(8, lnum, "div");

	if ((*stk)->n == 0)
		err_or2(9, lnum);

	(*stk) = (*stk)->next;
	d = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = d;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * mod_func -  do modlus
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void mod_func(stack_t **stk, unsigned int lnum)
{
	int m;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err_or2(8, lnum, "mod");

	if ((*stk)->n == 0)
		err_or2(9, lnum);

	(*stk) = (*stk)->next;
	m = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = m;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
