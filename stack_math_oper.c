#include "monty.h"

/**
 * op_div - divides the second top element of stack from the top element
 * @head: head to the stack
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_div(stack_t **head, unsigned int num_line)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) / (*head)->n;
	op_pop(head, num_line);
}

/**
 * op_mul - multiplies the top two elements of the stack
 * @head: head to the stack
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_mul(stack_t **head, unsigned int num_line)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	nel = tmp->next->n * tmp->n;
	*head = (*head)->next;
	(*head)->n = nel;
	free(tmp);
}

/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: head to the stack
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_mod(stack_t **head, unsigned int num_line)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) % (*head)->n;
	op_pop(head, num_line);
}

/**
 * op_pchar - print the top ASCII character of linked list
 * @head: head to the stack
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_pchar(stack_t **head, unsigned int num_line)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * op_pstr - prints all values of linked list in ASCII until find a zero
 * or another character that doesn't have an ASCII representation
 * @head: head to the stack
 * @num_line: Reference to the line we are checking in case of an error
 */
void op_pstr(stack_t **head, unsigned int num_line)
{
	stack_t *tmp;
	(void)num_line;

	tmp = *head;
	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}
