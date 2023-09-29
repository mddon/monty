#include "monty.h"

/**
* execute - this function executes the opcode
* @content: this is the line content
* @stack: head linked list - stack
* @counter: this variables counts lines
* @file: pointer to monty file
* Return: void return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", f_pint},
		{"pop", pop},
		{"swap", swap},
		{"add", addition},
		{"nop", nop},
		{"sub", subtract},
		{"div", divide},
		{"mul", _mul},
		{"mod", f_mod},
		{"pchar", custom_pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", f_stack},
		{NULL, NULL}
	};

	unsigned int index = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	files.arg = strtok(NULL, " \n\t");
	for (index = 0; opst[index].opcode && opcode; index++)
	{
		if (strcmp(opcode, opst[index].opcode) == 0)
		{
			opst[index].f(stack, counter);
			return (0);
		}
	}
	if (opcode && opst[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

