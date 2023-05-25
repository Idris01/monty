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
		free(info.line);
		fclose(info.stream);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next == NULL)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	free(temp);
}
