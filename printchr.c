#include "monty.h"

/**
 * custom_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_pchar(stack_t **stack, unsigned int line_number)
{
        stack_t *current_node;

        current_node = *stack;
        if (!current_node)
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
                fclose(files.file);
                free(files.content);
                free_stack(*stack);
                exit(EXIT_FAILURE);
        }
        if (current_node->n > 127 || current_node->n < 0)
        {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
                fclose(files.file);
                free(files.content);
                free_stack(*stack);
                exit(EXIT_FAILURE);
        }
        printf("%c\n", current_node->n);
}
