#include "monty.h"

/**
 * error_file - print error message for file failures.
 *
 * @file: file name.
 */
void error_file(char *file)
{
	print_err("Error: Can't open file ");
	print_err(file);
	print_err("\n");
}

/**
 * error_instruction - print error message for unkown instruction opcode
 *
 * @opcode: the unkown opcode
 *
 * Return: -1 on failure
 */
int error_instruction(char *opcode)
{
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": unknown instruction ");
	print_err(opcode);
	print_err("\n");

	free(s);

	return (-1);
}

/**
 * error_push_value - print error message for unkown instruction opcode
 */
void error_push_value(void)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": usage: push integer\n");
}

/**
 * error_malloc - print error message when malloc can't allocate memory anymore
 */
void error_malloc(void)
{
	print_err("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * error_pint - print error message when stack is empty
 */
void error_pint(void)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't pint, stack empty\n");
}
