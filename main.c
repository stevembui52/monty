#include "monty.h"

global_t vars;
/**
 * main - this function evaluates the input to execute the
 * functions.
 * @argc: Counter of arguments
 * @argv: Pointer to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t size = 100;
	ssize_t num_line = 0;
	char *args[2] = {NULL, NULL};
	void (*j)(stack_t **head, unsigned int num_line);

	fd = open_valid(argc, argv);
	init(fd);
	num_line = getline(&vars.buffer, &size, fd);
	while (num_line != -1)
	{
		args[0] = strtok(vars.buffer, " \n\t");
		if (args[0][0] != '#' && args[0] != NULL)
		{
			j = get_operation(args[0]);
			if (!j)
			{
				fprintf(stderr, "L%u: ", vars.count_line);
				fprintf(stderr, "unknown instruction %s\n", args[0]);
				free_vars();
				exit(EXIT_FAILURE);
			}
			vars.stack = strtok(NULL, " \n\t");
			j(&vars.head, vars.count_line);
		}
		num_line = getline(&vars.buffer, &size, fd);
		vars.count_line++;
	}

	free_vars();
	return (0);
	exit(EXIT_SUCCESS);
}
