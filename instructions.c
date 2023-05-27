#include "monty.h"

/**
 * op_push - pushes an element to the stack
 *
 * @value: value to push
 *
 * Return: 0 on success, -1 on failure
 */
int op_push(char *value)
{
	int n;

	if (is_numeric(value) == 0)
	{
		error_push_value();
		return (-1);
	}

	n = _atoi(value);

	push_front(&stack, n);

	return (0);
}

/**
 * op_pall - prints all the values on the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pall(void)
{
	stack_t *current = stack;

	while (front(&current) != -1)
	{
		char *str = _itoa(front(&current));

		print_str(str);
		print_str("\n");
		current = current->next;
		free(str);
	}

	return (0);
}
