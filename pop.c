#include "monty.h"
/**
 * pop - function that removes the top element of the stack.
 * @elm: pointer to the variable
 * @times: Number of line.
 * Return: Return - Nothing, Function void
 */
void pop(stack_t **elm, unsigned int num)
{
	stack_t *list = *elm;

	if (*elm == NULL || elm == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
	(*elm) = list->next;
	if (list->next)
		list->next->prev = NULL;

	free(list);
}
