#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int counter)
{
	int value, index = 0, invalid_input = 0;

	if (files.arg)
	{
		if (files.arg[0] == '-')
			index++;
		while (files.arg[index] != '\0')
		{
			if (files.arg[index] < '0' || files.arg[index] > '9')
			{
				invalid_input = 1;
				break;
			}
			index++;
		}
		if (invalid_input)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(files.file);
			free(files.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(files.file);
			free(files.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		value = atoi(files.arg);
	if (files.lifi == 0)
	{
		addnode(head, value);
	}
	else
		add_to_queue(head, value);
}
