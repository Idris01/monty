#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *node_value;

void handle_process(size_t line_no);
void handle_monty_argc(int argc);
int is_num(char *value);
int _is_empty(char *str);
void free_stack(stack_t **stack);
void handle_monty_file_stream(FILE **stream, char *file_name);
void push(stack_t **stack, unsigned int line_number);
void (*get_op_func(char *opcode, size_t line_no))(stack_t **, unsigned int);
stack_t *malloc_stack(void);
void pall(stack_t **stack, unsigned int line_number);

#endif
