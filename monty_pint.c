#include "monty.h"

/**
 * pint - Print the item at the top of the stack
 * @stack: pointer to address of head
 * @line_no: unsigned integer line number currently being processed
 *
 * Return: always void
 */
void pint(stack_t **stack, unsigned int line_no)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*stack)->n);
}
