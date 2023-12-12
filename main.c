#include "mon.h"
stack_t *head = NULL;
/**
 * addto_que - addd node to que
 * @nn: newnode pointer
 * @ln: opcode linenum
*/
void addto_que(stack_t **nn, __attribute__((unused))unsigned int lnum)
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
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *nn;
	(*nn)->prev = curr;
}
/**
 * make_nod - make new node
 * @number: node data
 * Return: node or null
*/
stack_t *make_nod(int number)
{
	stack_t *nod;

	nod = malloc(sizeof(stack_t));
	if (nod == NULL)
		err_or1(4);
	nod->next = NULL;
	nod->prev = NULL;
	nod->n = number;
	return (nod);
}
/**
 * free_nod - free stack node
*/
void free_nod(void)
{
	stack_t *curr;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}
/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg araay
 * Return: int value 0
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nod();
	return (0);
}
