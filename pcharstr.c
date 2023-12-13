#include "monty.h"

/**
 * p_char - print assci for val
 * @stk: top node pointer
 * @lnum: opcode linenum
*/
void p_char(stack_t **stk, unsigned int lnum)
{
	int val;

	if (stk == NULL || *stk == NULL)
		err_or3(11, lnum);
	val = (*stk)->n;
	if (val < 0 || val > 127)
		err_or3(10, lnum);
	printf("%c\n", val);
}
/**
 * p_str - print string from int
 * @stk: top node poniter
 * @lnum: opcode linenum
*/
void p_str(stack_t **stk, __attribute__((unused))unsigned int lnum)
{
	stack_t *curr;
	int val;

	if (stk == NULL || *stk == NULL)
	{
		printf("\n");
		return;
	}
	curr = *stk;
	while (curr != NULL)
	{
		val = curr->n;
		if (val <= 0 || val > 127)
			break;
		printf("%c", val);
		curr = curr->next;
	}
	printf("\n");
}
