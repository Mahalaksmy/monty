#include "monty.h"
/**
 * swap - function that swaps the top two elements of the stack.
 * @head: Variable Pointer
 * @num: Number of line
 * Return - Nothing, Function void
 */
void swap(stack_t **head, unsigned int num)
{
	stack_t *list = *head;
	int tmp;

	if (var.funlen < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", num);
		funfree();
		exit(EXIT_FAILURE);
	}

	tmp = list->n;
	list->n = list->next->n;
	list->next->n = tmp;

}
