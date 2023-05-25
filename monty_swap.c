#include "monty.h"

/**
 * swap - Swaps the first two elements in a stack
 * @stack: pointer to address of stack
 * @line_no: unsigned integer present line number
 *
 * Return: always void
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *first = *stack, *second, *temp;

	if (first == NULL || first->next == NULL)
	{
		free(info.line);
		fclose(info.stream);

		if (first != NULL)
			free(first);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	temp = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = temp;

	*stack = second;
}


