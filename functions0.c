#include "monty.h"

/**
 * _push - push
 * @stack: linked lists
 */
void _push(stack_t **stack)
{
stack_t *top;
top = malloc(sizeof(stack_s));
if (top == NULL)
{
fprintf(stderr, "Error: malloc failed");
exit(EXIT_FAILURE);
}
top->n = var.arg;
top->next = *stack;
top->prev = NULL;
if (*stack != NULL)
(*stack)->prev = top;
*stack = top;
}
