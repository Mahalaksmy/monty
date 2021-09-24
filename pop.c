#include "monty.h"
/**
 * pop - function that removes the top element of the stack.
 * @head: pointer to the variable
 * @times: Number of line.
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
