#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_add(void)
{
	int sum = 0;

	if (stack == NULL || stack->next == NULL)
	{
		error_short_stack("add");
		return (-1);
	}

	sum = stack->n + stack->next->n;
	pop_front(&stack);
	pop_front(&stack);
	push_front(&stack, sum);

	return (0);
}
