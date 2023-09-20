#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue).
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*j)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variables - all global variables to initialize
 * @order: Stablish the order of the stack, when is a queue or stack
 * @fd: File wil be open
 * @cline: Counter of lines into file
 * @buffer: this pointer allocate the data of each line of the file
 * @stack: Reference to the stack will be added
 * @head: Reference the head of doubly linked list
 * Description: keeps all variables expecting for a value
 */
typedef struct global_variables
{
	FILE *fd;
	int order;
	unsigned int count_line;
	char *buffer;
	char *stack;
	stack_t *head;
} global_t;

extern global_t vars;
void (*get_operation(char *s))(stack_t **head, unsigned int num_line);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_vars(void);
void free_stack(stack_t *head);
void op_push(stack_t **head, unsigned int num_line);
void op_pall(stack_t **head, unsigned int num_line);
void op_pint(stack_t **head, unsigned int num_line);
void op_pop(stack_t **head, unsigned int num_line);
void op_add(stack_t **head, unsigned int num_line);
void op_swap(stack_t **head, unsigned int num_line);
void op_nop(stack_t **head, unsigned int num_line);
FILE *open_valid(int argc, char **argv);
void init(FILE *fd);
void stack_queue(stack_t **head, unsigned int num_line);
void order_stack(stack_t **head, unsigned int num_line);
void op_div(stack_t **head, unsigned int num_line);
void op_mul(stack_t **head, unsigned int num_line);
void op_mod(stack_t **head, unsigned int num_line);
void op_pchar(stack_t **head, unsigned int num_line);
void op_pstr(stack_t **head, unsigned int num_line);

#endif /* #ifndef MONTY_H */
