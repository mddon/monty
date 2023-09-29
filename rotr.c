#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: return void
 */

void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	{
			copy = copy->next;
	} while (copy->next)

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;

	do {
		copy = copy->next;
	} while (copy->next != NULL);

	copy->prev = *head;
	*head = copy;
}
