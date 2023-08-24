#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

stack_t *stack = NULL;
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void execute_file(const char *filename);
int main(int argc, char *argv[]);

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being executed from the Monty byte code file.
 *
 * Description: If the stack is empty, prints an error message and exits.
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
temp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 *
 * Description: If the stack contains less than two elements,
 *              an error message is printed and the program exits.
*/
void swap(stack_t **stack, unsigned int line_number)
{
int temp;	
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{NULL, NULL}
};
/**
 * execute_file - Read and execute Monty byte code commands from a file.
 * @filename: The name of the file containing Monty byte code commands.
 */
void execute_file(const char *filename)
{
FILE *file = fopen(filename, "r");
char line[256];
unsigned int line_number = 0;
int found;
int i;
char *opcode;
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
while (fgets(line, sizeof(line), file) != NULL)
{
line_number++;
opcode = strtok(line, " \t\n");
if (opcode != NULL)
{
found = 0;
for (i = 0; instructions[i].opcode != NULL; i++)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(&stack, line_number);
found = 1;
break;
}
}
if (!found)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
fclose(file);
exit(EXIT_FAILURE);
}
}
}
fclose(file);
}
/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 *
 * Description: The main function reads and executes Monty byte code
 * files line by line. It parses the opcode and its argument, executes
 * the corresponding function, and handles errors as specified.
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
execute_file(argv[1]);
return (EXIT_SUCCESS);
}
