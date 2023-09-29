#include "monty.h"

/**
 * pstr - This function prints the string starting at the top of the stack,
 *
 * @head: stack head
 * @counter: line_number
 *
 * Return: returns noting
 */

void pstr(stack_t **head, unsigned int counter)
{
        stack_t *current_node;
        (void)counter;

        current_node = *head;
        while (current_node)
        {
                if (current_node->n > 127 || current_node->n <= 0)
                {
                        break;
                }
                printf("%c", current_node->n);
                current_node = current_node->next;
        }
	printf("\n");
}
