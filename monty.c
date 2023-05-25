#include "monty.h"

info_t info = {NULL, NULL, NULL};

/**
 * main - Entry point to monty program
 * @argc: integer number of commandline arguments
 * @argv: array of commandline values
 *
 * Return: integer 0
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	ssize_t char_read;
	size_t char_len = 0, line_no = 0, t_cnt, done;
	char *opcode = NULL, *temp = NULL;

	handle_monty_argc(argc);	/* exit with error if argc is not 2 */
	handle_monty_file_stream(&(info.stream), argv[1]); /* exit if error */
	while ((char_read = getline(&(info.line), &char_len, info.stream)) != -1)
	{
		line_no++;
		temp = strtok(info.line, " \n");
		for (t_cnt = 0, done = 0;; temp = strtok(NULL, " \n"))
		{
			if (temp == NULL || done || t_cnt > 1)
			{
				if (t_cnt == 0)
					break;
				op_func(&stack, opcode, line_no)(&stack, line_no);
				opcode = NULL;
				info.value = NULL;
				break;
			}
			else if (!_is_empty(temp))
			{
				if (++t_cnt == 1)
					opcode = temp;
				else if (t_cnt == 2)
					info.value = temp;
				else
					done = 1;
			}
		}
	}
	fclose(info.stream);
	free(info.line);
	free_stack(&stack);
	return (0);
}

/**
 * op_func - Get the function corresponding to given opcode
 * @code: pointer to string
 * @ln: unsigned integer line number that is being processed
 * @stk: pointer to address of stack head
 *
 * Return: pointer to function corresponding to opcode or NULL if error
 */
void (*op_func(stack_t **stk, char *code, size_t ln))(stack_t **, unsigned int)
{
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	int itr = 0;

	while (instr[itr].opcode != NULL)
	{
		if ((strcmp(code, instr[itr].opcode) == 0))
		{
			return (instr[itr].f);
		}
		itr++;
	}
	/* check if null */
	if (instr[itr].opcode == NULL)
	{
		free_stack(stk);
		fprintf(stderr, "L%lu: unknown instruction %s\n", ln, code);
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
