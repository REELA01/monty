#include "monty.h"
/**
 * rotate_norm - the top becomes last
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void rotate_norm(stack_t **stk, __attribute__((unused))unsigned int lnum)
{
	stack_t *curr;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	curr = *stk;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *stk;
	(*stk)->prev = curr;
	*stk = (*stk)->next;
	(*stk)->prev->next = NULL;
	(*stk)->prev = NULL;
}
/**
 * rotate_rev - reverse rotation
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void rotate_rev(stack_t **stk, __attribute__((unused))unsigned int lnum)
{
	stack_t *curr;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	curr = *stk;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *stk;
	curr->prev->next = NULL;
	curr->prev = NULL;
	(*stk)->prev = curr;
	(*stk) = curr;
}
