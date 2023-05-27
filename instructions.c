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

	stack.push_back(&stack, n);

	return (0);
}

/**
 * op_pall - prints all the values on the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pall(void)
{
	while (stack.front(&stack) != -1)
	{
		char *s = _itoa(stack.front(&stack));

		print_str(s);
		print_str("\n");
		stack.pop_front(&stack);

		free(s);
	}

	return (0);
}
