#include "monty.h"

/**
 * init - initialize all variables into the struct global_t
 * and keep values while the program finish
 * @fd: - file descriptor of file opened
 * Return: No return.
 */
void init(FILE *fd)
{
	vars.order = 1;
	vars.fd = fd;
	vars.count_line = 1;
	vars.buffer = NULL;
	vars.stack = NULL;
	vars.head = NULL;
}

/**
 * open_valid - validate if the argument represent a file or not
 * @argc: Counter of arguments
 * @argv: Pointer with the reference to arguments
 * Return: File descriptor of file opened or -1 is not exists
 */
FILE *open_valid(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
	exit(EXIT_SUCCESS);
}
