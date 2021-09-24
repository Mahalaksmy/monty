#include "monty.h"
#include <stdio.h>

/**
 * pint - Prints the int at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The number of the current line being processed
 * Return - Nothing, Function void
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", lineNum);
		funfree();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
