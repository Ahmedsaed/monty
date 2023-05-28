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
