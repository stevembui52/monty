#include "monty.h"
/**
 * get_operation - get the option of char input to perform the opcode
 * @s: input opcode
 * Return: a pointer to the function given the opcode or NULL if not found
 */
void (*get_operation(char *s))(stack_t **head, unsigned int num_line)
{
	int i = 0;
	instruction_t stack[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"swap", op_swap},
		{"pop", op_pop},
		{"add", op_add},
		{"nop", op_nop},
		{"queue", stack_queue},
		{"stack", order_stack},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}
	};

	while (stack[i].opcode)
	{
		if (strcmp(stack[i].opcode, s) == 0)
			break;
		i += 1;
	}
	return (stack[i].j);
}
