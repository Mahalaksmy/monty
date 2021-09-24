#include "monty.h"
/**
 * swap - function that swaps the top two elements of the stack.
 * @head: Variable Pointer
 * @num: Number of line
 * Return - Nothing, Function void
 */
void swap(stack_t **head, unsigned int num)
{
	stack_t *list;

	if (!*head || !(*head)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", num);
		funfree();
		exit(EXIT_FAILURE);
	}

	list = (*head)->next;
	(*head)->next = list->next;
	list->next = (*head);
	(*head)->prev = list;
	list->prev = NULL;
	*head = list;
}
