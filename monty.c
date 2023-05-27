#include "monty.h"

/* global variables*/
int line_number = 1;
stack_t stack;

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
	int fd;
	size_t line_size;
	char *line_buffer = NULL;

	if (argc < 2)
	{
		print_err("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (process_file(argv[1], &fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	init_stack(&stack);
	while (true)
	{
		if (_getline(&line_buffer, &line_size, fd) != -1)
		{
			if (run_instruction(line_buffer) == -1)
				return (EXIT_FAILURE);
		}
		else
			break;
	}

	free(line_buffer);
	return (0);
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
		return (-1);

	if (_strcmp(opcode, "push") == 0)
		rn = op_push(value);
	else if (_strcmp(opcode, "pall") == 0)
		rn = op_pall();
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
