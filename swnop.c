#include "mon.h"
/**
 * swap_nod - swap between 2 nodes data
 * @stk: stack pointer
 * @lnum: opcode linenum
*/
void swap_nod(stack_t **stk, unsigned int lnum)
{
	stack_t *curr;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err_or2(8, lnum, "swap");

	curr = (*stk)->next;
	(*stk)->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = *stk;

	curr->next = *stk;
	(*stk)->prev = curr;
	curr->prev = NULL;
	*stk = curr;
}
/**
 * nop - func to do nothing
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void nop(stack_t **stk, unsigned int lnum)
{
	(void)stk;
	(void)lnum;
}
