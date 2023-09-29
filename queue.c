#include "monty.h"
/**
 * queue - changes the stack mode to queue mode
 * @head: stack head
 * @counter: line_number
 * Return: return void
*/
void queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	files.lifi = 1;
}

/**
 * add_to_queue - adds a new node to the end of the queue
 * @n: new_value
 * @head: head of the queue
 * Return: return void
*/
void add_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
