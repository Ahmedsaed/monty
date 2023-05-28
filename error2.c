#include "monty.h"

/**
 * error_pop - print error message when stack is empty
 */
void error_pop(void)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't pop an empty stack\n");
}


/**
 * error_short_stack - print error message when stack is too short
 *
 * @opcode: opcode
 *
 * Return: -1
 */
int error_short_stack(char *opcode)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't ");
	print_err(opcode);
	if (_strcmp(opcode, "pchar") == 0)
		print_err(", stack empty\n");
	else
		print_err(", stack too short\n");

	return (-1);
}

/**
 * error_div_zero - print error message when division by zero
 *
 * Return: -1
 */
int error_div_zero(void)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": division by zero\n");

	return (-1);
}

/**
 * error_pchar - print error message when value is not in ASCII table
 *
 * Return: -1
 */
int error_pchar(void)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't pchar, value out of range\n");

	return (-1);
}
