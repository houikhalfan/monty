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
/**
 * nop - Doesn't perform any operation.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
/**
 * sub - sub function
 * @stack : pointer to the stack
 * @line_number: line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
tmp = *stack;
*stack = (*stack)->next;
(*stack)->n = tmp->n;
free(tmp);
}
/**
 * div - div function
 * @stack : pointer to the stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
int length = 0;
stack_t *t = *stack;
while (t != NULL)
{
length++;
t = t->next;
}
if (length < 2 ||*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
tmp = *stack;
*stack = (*stack)->next;
(*stack)->n /= tmp->n;
free(tmp);
}
/**
 * mul - mul function
 * @stack : pointer to the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
tmp = *stack;
*stack = (*stack)->next;
(*stack)->n *= tmp->n;
free(tmp);
}
