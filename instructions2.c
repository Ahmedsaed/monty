#include "monty.h"

/**
 * op_cal - calculates using the OPCODE of the top two elements of the stack
 *
 * @opcode: opcode to be executed
 *
 * Return: 0 on success, -1 on failure
 */
int op_cal(char *opcode)
{
	int result = 0;

	if (stack == NULL || stack->next == NULL)
	{
		error_short_stack("add");
		return (-1);
	}

	if (_strcmp(opcode, "add") == 0)
		result = stack->n + stack->next->n;
	else if (_strcmp(opcode, "sub") == 0)
		result = stack->next->n - stack->n;
	else if (_strcmp(opcode, "div") == 0)
	{
		if (stack->n == 0)
		{
			error_div_zero();
			return (-1);
		}
		result = stack->next->n / stack->n;
	}
	else if (_strcmp(opcode, "mul") == 0)
		result = stack->n * stack->next->n;
	else if (_strcmp(opcode, "mod") == 0)
	{
		if (stack->n == 0)
		{
			error_div_zero();
			return (-1);
		}
		result = stack->next->n % stack->n;
	}

	pop_front(&stack);
	pop_front(&stack);
	push_front(&stack, result);

	return (0);
}
