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
		error_short_stack(opcode);
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

/**
 * op_pchar - prints the char at the top of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pchar(void)
{
	char *c;

	if (stack == NULL)
	{
		error_short_stack("pchar");
		return (-1);
	}

	if (stack->n < 0 || stack->n > 127)
	{
		error_pchar();
		return (-1);
	}

	c = malloc(sizeof(char) * 3);
	c[0] = stack->n;
	c[1] = '\n';
	c[2] = '\0';

	print_str(c);

	free(c);
	return (0);
}
