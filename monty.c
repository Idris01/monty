#include "monty.h"

char *node_value = NULL;

/**
 * main - Entry point to monty program
 * @argc: integer number of commandline arguments
 * @argv: array of commandline values
 *
 * Return: integer 0
 */

int main(int argc, char **argv)
{
	FILE *stream = NULL;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_no);
	ssize_t char_read;
	size_t char_len = 0, line_no = 0, token_cnt, done;
	char *opcode = NULL, *line_read = NULL, *temp = NULL;

	handle_monty_argc(argc);	/* exit with error if argc is not 2 */
	handle_monty_file_stream(&stream, argv[1]); /* exit if error */
	while ((char_read = getline(&line_read, &char_len, stream)) != -1)
	{
		line_no++;
		temp = strtok(line_read, " \n");
		for (token_cnt = 0, done = 0;; temp = strtok(NULL, " \n"))
		{
			if (temp == NULL || done || token_cnt > 1)
			{
				if (token_cnt == 0)
					break;
				f = get_op_func(opcode, line_no);
				f(&stack, line_no);
				opcode = NULL;
				node_value = NULL;
				break;
			}
			else if (!_is_empty(temp))
			{
				token_cnt++;
				if (token_cnt == 1)
					opcode = temp;
				else if (token_cnt == 2)
					node_value = temp;
				else
					done = 1;
			}
		}
	}
	fclose(stream);
	free_stack(&stack);
	return (0);
}

/**
 * get_op_func - Get the function corresponding to given opcode
 * @opcode: pointer to string
 * @line_no: unsigned integer line number that is being processed
 *
 * Return: pointer to function corresponding to opcode or NULL if error
 */
void (*get_op_func(char *opcode, size_t line_no))(stack_t **, unsigned int)
{
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int itr = 0;

	while (instr[itr].opcode != NULL)
	{
		if ((strcmp(opcode, instr[itr].opcode) == 0))
		{
			return (instr[itr].f);
		}
		itr++;
	}
	/* check if null */
	if (instr[itr].opcode == NULL)
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n", line_no, opcode);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}

/**
 * handle_monty_argc - Check that the required number of argument
 * is suppplied to the monty program
 * @argc: integer number of arguments
 *
 * Return: always void
 */
void handle_monty_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_monty_file_stream - Opens a file stream using a given file_name
 * @stream: pointer to FILE
 * @file_name: pointer to string
 *
 * Return: always void
 */
void handle_monty_file_stream(FILE **stream, char *file_name)
{
	*stream = fopen(file_name, "r");
	if (*stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

}

/**
 * free_stack - Frees memory of a given doubly linked list
 * @stack: pointer to address of head of stack
 *
 * Return: always void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack != NULL)
	{
		for (; *stack != NULL;)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
	}
}
