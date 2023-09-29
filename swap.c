#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: stack head
 * @line_number: line number
<<<<<<< HEAD
 * Return: return nothing.
=======
 * Return: return void
>>>>>>> 390b19467a31015412848b3abf6ed628723f409a
 */

void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int count = 0, temp_value;

	while (temp)
	{
		temp = temp->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	temp_value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_value;
}
