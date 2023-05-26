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
 */
void error_instruction(char *opcode)
{
	print_err("L");
	print_err(_itoa(line_number));
	print_err(": unknown instruction ");
	print_err(opcode);
	print_err("\n");
}

/**
 * error_malloc - print error message when malloc can't allocate memory anymore
 */
void error_malloc(void)
{
	print_err("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}