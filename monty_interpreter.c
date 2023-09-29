#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

bus_t files = {NULL, NULL, NULL, 0};
/**
 * main - Monty Language Interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 * Return: 0 is returned on success of this program.
 */

int main(int argc, char *argv[])
{
	FILE *monty_file = NULL;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 0;
	ssize_t read_result;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: mnonty file\n");
		{
			return (EXIT_FAILURE);
		}
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		{
			return (EXIT_FAILURE);
		}
	}
	files.file = monty_file;

	do {
		read_result = getline(&line, &line_size, monty_file);
		files.content = line;
		line_number++;

		if (read_result > 0)
		{
			execute(line, &stack, line_number, monty_file);
		}
	} while (read_result != -1);
	free(line);
	free_stack(stack);
	fclose(monty_file);

	return (EXIT_SUCCESS);
}
