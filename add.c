#include "monty.h"
/**
 * add - function that adds the  elements.
 * @head: Variable Pointer
 * @num: Number of line
 * Return - Nothing, Function void
 */
void add(stack_t **head, unsigned int num)
{
	int sum;

	if (!*head || !(*head)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", num);
		funfree();
		exit(EXIT_FAILURE);
	}

	sum = (*head)->n + (*head)->next->n;
	pop(head, num);
	(*head)->n = sum;
}
