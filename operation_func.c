#include "monty.h"

/**
 * op_add - adds only the top two elements of the stack
 * @head: Reference to the head of doubly linked list
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_add(stack_t **head, unsigned int num_line)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;
	while (tmp)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n += (*head)->n;
	op_pop(head, num_line);
}

/**
 * op_nop - Doesn't do anything
 * @head: Reference to the head of doubly linked list
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_nop(stack_t **head, unsigned int num_line)
{
	(void)head;
	(void)num_line;
}

/**
 * stack_queue - sets the format of the data to a FIFO stack
 * @head: Reference to the head of doubly linked list
 * @num_line: Reference to the line we are checking in case of an error
 */
void stack_queue(stack_t **head, unsigned int num_line)
{
	(void)head;
	(void)num_line;

	vars.order = 0;
}

/**
 * order_stack - sets the format fo the data to a LIFO stack
 * @head: Reference to the head of doubly linked list
 * @num_line: Reference to the line we are checking in case of an error
 */
void order_stack(stack_t **head, unsigned int num_line)
{

	(void)head;
	(void)num_line;

	vars.order = 1;
}
