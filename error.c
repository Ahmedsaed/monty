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
