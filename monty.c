#include "monty.h"

/* global variables*/
int line_number = 1;
stack_t *stack = NULL;

/* helper functions */
int run_instruction(char *line_buffer);

/**
 * main - entry point to monty
 *
 * @argc: argument count
 * @argv: argument list
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	int fd, rn = 0;
	size_t line_size;
	char *line_buffer = NULL;

	if (argc != 2)
	{
		print_err("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (process_file(argv[1], &fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (true)
	{
		if (_getline(&line_buffer, &line_size, fd) != -1)
		{
			if (run_instruction(line_buffer) == -1)
			{
				rn = EXIT_FAILURE;
				break;
			}
		}
		else
			break;
	}

	free(line_buffer);
	return (rn);
}

/**
 * run_instruction - parses and executes the instruction
 *
 * @line_buffer: string that contains the instruction details
 *
 * Return: 0 on success, -1 on failure
 */
int run_instruction(char *line_buffer)
{
	int rn = 0;
	char *opcode = NULL, *value = NULL;

	parse_instruction(line_buffer, &opcode, &value);

	if (opcode == NULL)
		return (0);

	if (_strcmp(opcode, "push") == 0)
		rn = op_push(value);
	else if (_strcmp(opcode, "pall") == 0)
		rn = op_pall();
	else if (_strcmp(opcode, "pint") == 0)
		rn = op_pint();
	else if (_strcmp(opcode, "pop") == 0)
		rn = op_pop();
	else if (_strcmp(opcode, "swap") == 0)
		rn = op_swap();
	else
	{
		error_instruction(opcode);
		rn = -1;
	}

	free(opcode);
	if (value != NULL)
		free(value);

	line_number++;
	return (rn);
}
