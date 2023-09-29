#include "monty.h"
/**
 * pall - This function prints the stack
 * @head: stack head
 * @counter: was not defined/used in this function
 * Return: return void
*/
void pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
