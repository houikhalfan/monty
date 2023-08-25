#include "monty.h"
/**
 * mod - mod function
 * @stack : pointer to the stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
stack_t *top
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

t = *stack;
*stack = (*stack)->next;
(*stack)->n %= t->n;

free(t);
}
