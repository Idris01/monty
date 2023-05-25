#include "monty.h"

/**
 * add - Adds the topmost node of a stack to the
 * next to it
 * @stack: pointer to address of stack
 * @line_no: unsigned int line being processed
 *
 * Return: always void
 */
void add(stack_t **stack, unsigned int line_no)
{
	stack_t *first = *stack, *temp;

	if (first == NULL || first->next == NULL)
	{
		free(info.line);
		fclose(info.stream);

		if (first != NULL)
			free(first);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	temp = first->next;
	temp->n += first->n;
	temp->prev = NULL;
	free(first);

	*stack = temp;
}
