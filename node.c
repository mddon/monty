#include "monty.h"

/**
<<<<<<< HEAD
 * addnode - Adds a new node with the specified value to the beginning of a stack.
 * @head: This is a ointer to the head of the stack.
 * @new_value: The value to be stored in the new node.
 * Return: No (void) return value.
=======
 * addnode - Adds new node with the value to the beginning of a stack.
 * @head: Pointer to the head of the stack.
 * @new_value: The value to be stored in the new node.
 * Return: return void
>>>>>>> 390b19467a31015412848b3abf6ed628723f409a
 */
void addnode(stack_t **head, int new_value)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
	{
		temp->prev = new_node;
	}
	new_node->n = new_value;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
