#include "monty.h"

/**
 * op_push - this function add a new node into doubly linked list
 * @head: Reference to the head of doubly linked list
 * @num_line: Reference to the line with an error
 */

void op_push(stack_t **head, unsigned int num_line)
{
	int number = 0;
	int x = 0;

	if (!vars.stack)
	{
		fprintf(stderr, "L%u usage: push integer\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}

	while (vars.stack[x] != '\0')
	{
		if ((!(isdigit(vars.stack[x]))) && vars.stack[x] != '-')
		{
			fprintf(stderr, "L%u usage: push integer\n", num_line);
			free_vars();
			exit(EXIT_FAILURE);
		}
		x++;
	}
	number = atoi(vars.stack);
	if (vars.order == 1)
		add_dnodeint(head, number);
	else
		add_dnodeint_end(head, number);
}


/**
 * op_pall - this function print all values on the doubly linked list
 * @head: reference to the head of doubly linked list
 * @num_line: reference to line we are reading
 */
void op_pall(stack_t **head, unsigned int num_line)
{
	stack_t *tmp;
	(void)num_line;


	tmp = *head;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * op_pint - prints only the value at the top of the doubly linked list
 * @head: reference to the head of doubly linked list
 * @num_line: reference to line number if there is an error
 * Return: no return
 */
void op_pint(stack_t **head, unsigned int num_line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_line);
		fclose(vars.fd);
		free(vars.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * op_pop - removes only the top element of the doubly linked list
 * @head: reference to the head of doubly linked list
 * @num_line: reference to line number if there is an error
 * Return: no return
 */
void op_pop(stack_t **head, unsigned int num_line)
{
	stack_t *tmp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

/**
 * op_swap - swaps only the two top elements of doubly linked list
 * @head: reference to the head of doubly linked list
 * @num_line: reference to line number if there is an error
 * Return: no return
 */
void op_swap(stack_t **head, unsigned int num_line)
{
	int lvl = 0;
	stack_t *tmp = NULL;

	tmp = *head;

	while (tmp != NULL)
	{
		lvl++;
		tmp = tmp->next;
	}
	if (lvl < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num_line);
		free_vars();
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}
