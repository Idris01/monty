#include "monty.h"

/**
 * push - Pushes new node to stack
 * @stack: pointer to address of stack
 * @line_number: unsigned integer line number that is being processed
 *
 * Return: always void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if (!is_num(node_value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new = malloc_stack();
	new->n = atoi(node_value);
	new->prev = NULL;
	new->next = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pall - Print all items in a stack starting from the head
 * @stack: pointer to adress of stack head
 * @line_number: unsigned integer line number that is presenty being processed
 *
 * Return: always void
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp = *stack;

	for (; temp != NULL; temp = temp->next)
	{
		fprintf(stdout, "%d\n", temp->n);
	}
}

/**
 * malloc_stack - Create a new memory address of type stack_t
 *
 * Return: pointer to stack_t
 */
stack_t *malloc_stack(void)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	return (new);
}

/**
 * is_num - Checks if a given string contains only numbers
 * @value: pointer to string to check
 *
 * Return: 1 if true otherwise 0
 */
int is_num(char *value)
{
	size_t itr = 0;
	char c;

	if (value == NULL)
		return (0);
	if (*value == '-' || *value == '+')
		itr++;

	for (c = value[itr]; c != '\0'; itr++, c = value[itr])
	{
		if (!isdigit(c))
			return (0);
	}
	return (1);
}

/**
 * _is_empty - Checks whether a given string contain only white spaces
 * @str: pointer to string to check
 *
 * Return: integer 1 if true else 0
 */
int _is_empty(char *str)
{
	size_t len, cnt = 0;

	if (str == NULL)
		return (1);
	for (len = strlen(str); cnt < len; cnt++)
	{
		if (!isspace(str[cnt]))
			return (0);
	}
	return (1);
}
