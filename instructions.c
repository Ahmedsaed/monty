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

	n = atoi(value);

	if (format == STACK)
		push_front(n);
	else if (format == QUEUE)
		push_back(n);

	return (0);
}

/**
 * op_pall - prints all the values on the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pall(void)
{
	stack_t *current = list_head;

	while (current != NULL)
	{
		char *str = _itoa(current->n);

		print_str(str);
		print_str("\n");
		current = current->next;
		free(str);
	}

	return (0);
}

/**
 * op_pint - prints the value at the top of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pint(void)
{
	char *str;

	if (list_head == NULL)
	{
		error_pint();
		return (-1);
	}

	str = _itoa(front());
	print_str(str);
	print_str("\n");

	free(str);
	return (0);
}

/**
 * op_pop - removes the top element of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pop(void)
{
	if (list_head == NULL)
	{
		error_pop();
		return (-1);
	}

	pop_front();

	return (0);
}

/**
 * op_swap - swaps the top two elements of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_swap(void)
{
	int n1, n2;

	if (list_head == NULL || list_head->next == NULL)
	{
		error_short_stack("swap");
		return (-1);
	}

	n1 = front();
	pop_front();
	n2 = front();
	pop_front();

	push_front(n1);
	push_front(n2);

	return (0);
}
