#include "monty.h"

/**
 * op_rotl - rotates the stack to the bottom
 *
 * Return: 0 on success, -1 on failure
 */
int op_rotl(void)
{
	stack_t *tmp = list;

	if (tmp == NULL || tmp->next == NULL)
		return (0);

	push_back(&list, tmp->n);
	pop_front(&list);

	return (0);
}

/**
 * op_rotr - rotates the stack to the top
 *
 * Return: 0 on success, -1 on failure
 */
int op_rotr(void)
{
	stack_t *tmp = list;
	int n;

	if (tmp == NULL || tmp->next == NULL)
		return (0);

	while (tmp->next != NULL)
		tmp = tmp->next;

	n = tmp->n;
	pop_back(&list);
	push_front(&list, n);

	return (0);
}
