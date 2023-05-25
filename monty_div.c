
#include "monty.h"

/**
 * divide - Divide the second element of a stack by
 * the topmost element
 * @stack: pointer to address of stack
 * @line_no: unsigned int line being processed
 *
 * Return: always void
 */
void divide(stack_t **stack, unsigned int line_no)
{
	stack_t *first = *stack, *temp;

	if (first == NULL || first->next == NULL)
	{
		free(info.line);
		fclose(info.stream);

		if (first != NULL)
			free(first);
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (first->n == 0)
	{
		free_stack(stack);
		free(info.line);
		fclose(info.stream);
		fprintf(stderr, "L%u: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
	temp = first->next;
	temp->n /= first->n;
	temp->prev = NULL;
	free(first);

	*stack = temp;
}
