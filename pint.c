#include "monty.h"
#include <stdio.h>

/**
 * pint - Prints the int at the top of the stack
 * @head: Double pointer to the head of the stack
 * @num: The number of the current line being processed
 * Return - Nothing, Function void
 */
void pint(stack_t **head, unsigned int num)
{
	if (*head != NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", num);
		funfree();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
