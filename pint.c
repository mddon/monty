#include "monty.h"

/**
 * f_pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the command
 * Return: no return
 */

void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
