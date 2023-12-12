#include "mon.h"
/**
 * err_or1 - handle error of monty
 * @err_c: switch handling erorr in order
*/
void err_or1(int err_c, ...)
{
	char *opc;
	int line_n;
	va_list argg;

	va_start(argg, err_c);
	switch (err_c)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argg, char *));
			break;
		case 3:
			line_n = va_arg(argg, int);
			opc = va_arg(argg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opc);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argg, int));
			break;
		default:
			break;
	}
	free_nod();
	exit(EXIT_FAILURE);
}
/**
 * err_or2 - rest of monty error
 * @err_c: switch handling error
*/
void err_or2(int err_c, ...)
{
	char *opc;
	int line_n;
	va_list argg;

	va_start(argg, err_c);
	switch (err_c)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argg, int));
			break;
		case 8:
			line_n = va_arg(argg, unsigned int);
			opc = va_arg(argg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, opc);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argg, unsigned int));
			break;
		default:
			break;
	}
	free_nod();
	exit(EXIT_FAILURE);
}

/**
 * err_or3 - handles other err
 * @err_c: switch handle error casses in order
*/
void err_or3(int err_c, ...)
{
	int line_n;
	va_list argg;

	va_start(argg, err_c);
	line_n = va_arg(argg, int);
	switch (err_c)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
			break;
		default:
			break;
	}
	free_nod();
	exit(EXIT_FAILURE);
}
