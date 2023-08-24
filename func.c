#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Description: If the stack contains less than two elements, prints an error
 * message and exits with EXIT_FAILURE. The result is stored in the second top
 * element of the stack, and the top element is removed. The stack is one
 * element shorter at the end.
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *top;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top = *stack;
*stack = (*stack)->next;
(*stack)->n += top->n;
free(top);
}
