#include "monty.h"

/**
 * pop - removes the top element from the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the command
 * Return: return void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}
