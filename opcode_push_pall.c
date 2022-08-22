#include "monty.h"
#include <stdio.h>
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int sq_flag = 0;
	stack_t *new = NULL;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stk(stack, line_number);
		error_exit(stack);
	}
	free(new);

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_dnodeint(stack, push_arg);
	}

}
/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * free_stk - frees the stack
 * @stack: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void free_stk(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		_pop(stack, line_number);
}
