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
 */
void error_short_stack(char *opcode)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't ");
	print_err(opcode);
	print_err(", stack too short\n");
}
