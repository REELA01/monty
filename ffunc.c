#include "monty.h"
/**
 * cal_func - call functions
 * @func: desired function pointer
 * @op: opration code
 * @va: int value of func
 * @lnum: linenum
 * @fsp: format spesifier
*/
void cal_func(op_function func, char *op, char *va, int lnum, int fsp)
{
	stack_t *node;
	int fl, i;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (va != NULL && va[0] == '-')
		{
			va = va + 1;
			fl = -1;
		}
		if (va == NULL)
			err_or1(5, lnum);
		for (i = 0; va[i] != '\0'; i++)
		{
			if (isdigit(va[i]) == 0)
				err_or1(5, lnum);
		}
		node = make_nod(atoi(va) * fl);
		if (fsp == 0)
			func(&node, lnum);
		if (fsp == 1)
			addto_que(&node, lnum);
	}
	else
		func(&head, lnum);
}
/**
 * find_function - find fun to opcode
 * @opc: opcode desired
 * @va: opcode value
 * @form:  format spesifier
 * @lnum: linenum
 * Return: void value
*/
void find_function(char *opc, char *va, int lnum, int form)
{
	int i, flag;

	instruction_t function_list[] = {
		{"push", add_to_stk},
		{"pall", print_stk},
		{"pint", print_topstk},
		{"pop", pop_topstk},
		{"nop", nop},
		{"swap", swap_nod},
		{"add", add_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rotate_rev},
		{"rotr", rotate_norm},
		{NULL, NULL}
	};

	if (opc[0] == '#')
		return;
	for (flag = 1, i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opc, function_list[i].opcode) == 0)
		{
			cal_func(function_list[i].f, opc, va, lnum, form);
			flag = 0;
		}
	}
	if (flag == 1)
		err_or1(3, lnum, opc);
}
/**
 * parse_line - seprate str
 * @buff: buffer
 * @line_n: linenum
 * @form: storage format
 * Return: int value 0 or 1
*/
int parse_line(char *buff, int line_n, int form)
{
	char *opc, *va;
	const char *delim = "\n ";

	if (buff == NULL)
		err_or1(4);

	opc = strtok(buff, delim);
	if (opc == NULL)
		return (form);
	va = strtok(NULL, delim);
	if (strcmp(opc, "stack") == 0)
		return (0);
	if (strcmp(opc, "queue") == 0)
		return (1);
	find_function(opc, va, line_n, form);
	return (form);
}
/**
 * read_f - readfile
 * @file_d: file descriptor
 * Return: void value
*/
void read_f(FILE *file_d)
{
	size_t len = 0;
	int line_n, form = 0;
	char *buff = NULL;

	for (line_n = 1; getline(&buff, &len, file_d) != -1; line_n++)
	{
		form = parse_line(buff, line_n, form);
	}
	free(buff);
}
/**
 * open_f - open file
 * @fname: filename
 * Return: void value
*/
void open_f(char *fname)
{
	FILE *file_d = fopen(fname, "r");

	if (fname == NULL || file_d == NULL)
		err_or1(2, fname);
	read_f(file_d);
	fclose(file_d);
}
