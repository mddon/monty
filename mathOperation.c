#include "monty.h"

/**
 * addition - This function adds the top two elements of the stack.
 *
 * @head: Pointer to the stack's head.
 * @line_count: counter the lines
 *
 * Return: No return value.
 */

void addition(stack_t **head, unsigned int line_count)
{
	stack_t *h = *head;
	int length = 0, temp;

	do {
		h = h->next;
		length++;
	} while (h);

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}


/**
 * subtract - This function subtracts the top two elements of the stack.
 *
 * @head: head of the stack
 * @line_number: line_number
 *
 * Return: returns nothing
 */

void subtract(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int nodes = 0;

	while (temp)
	{
		temp = temp->next;
		nodes++;
	}

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	temp->next->n -= temp->n;
	*head = temp->next;
	free(temp);
}

/**
 * divide - this function divides the top two elements of the stack.
 * @head: stack head
 * @line_count: counter the lines
 * Return: void return
 */
void divide(stack_t **head, unsigned int line_count)
{
	stack_t *h = *head;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h->next->n = h->next->n / h->n;
	*head = h->next;
free(h);
}


/**
 * _mul - This function multiplies the top two elements of the stack.
 *
 * @head: stack head
 * @counter: line counter
 *
 * Return: void, return nothing
 */

void _mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_size = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(files.file);
		free(files.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
