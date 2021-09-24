#include "monty.h"
/**
 * pop - function that removes of the elements.
 * @head: pointer to the variable
 * @num: Number of line.
 * Return: Return - Nothing, Function void
 */
void pop(stack_t **head, unsigned int num)
{
	stack_t *list = *head;

	if (*head == NULL || head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
	(*head) = list->next;
	if (list->next)
		list->next->prev = NULL;

	free(list);
}
