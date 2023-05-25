#include "monty.h"

/**
 * pop - Removes an item from the head of stack
 * @stack: pointer to address of stack head
 * @line_no: unsigned integer line number being processed
 *
 * Return: always void
 */
void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		fclose(info.stream);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
