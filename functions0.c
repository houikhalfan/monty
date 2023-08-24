#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: The line number being executed from the file.
 *
 * Description: The opcode push pushes an element onto the stack.
 * If the argument is not an integer or if there is no argument given,
 * an error message is printed and the program exits with EXIT_FAILURE.
 */

void push(stack_t **stack, unsigned int line_number)
{
char *arg = strtok(NULL, " \t\n");
int value;
stack_t *new_node;
if (arg == NULL || !is_number(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to a pointer to the top of the stack.
 *
 * Description: The opcode pall prints all the values on the stack,
 * starting from the top of
 */
void pall(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * is_number - Checks if a string is a valid integer.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 *
 * Description: This function checks if a given string is a valid integer
 * by checking each character in the string.
 */
int is_number(const char *str)
{
const char *ptr;
if (str == NULL || *str == '\0')
return (0);

for (ptr = str; *ptr != '\0'; ++ptr)
{
if (*ptr < '0' || *ptr > '9')
return (0);
}

return (1);
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being executed from the Monty byte code file.
 *
 * Description: If the stack is empty, prints an error message and exits.
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
instruction_t instructions[] = 
{
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{NULL, NULL}
};
