#include "monty.h"

/**
 * rotl - function that rotates the stack to the top
 *
 * @head: Pointer to the stack head
 * @counter: Counts the Line Number.
 *
 * Return: No return value
 */


void rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	new_head = (*head)->next;
	new_head->prev = NULL;

	do {
		current = current->next;
	} while (current->next != NULL);

	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	(*head) = new_head;
}
