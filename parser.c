#include "monty.h"

/**
 * parse_instruction - extracts the opcode and value from the instruction line
 *
 * @line: the instruction line
 * @opcode: pointer to a string that will be updated with the opcode
 * @value: pointer to an int that will be updated with the value
 */
void parse_instruction(char *line, char **opcode, char **value)
{
	int i, len = 0;
	char *arg, c;

	arg = malloc(sizeof(char) * (_strlen(line) + 1));
	if (arg == NULL)
	error_malloc();

	for (i = 0; (c = line[i]) != '\0'; i++)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (len)
			{
				arg[len] = '\0';
				if (*opcode == NULL)
					*opcode = _strdup(arg);
				else
					*value = _strdup(arg);
				len = 0;
			}
		}
		else
			arg[len++] = c;
	}

	if (len)
	{
		arg[len] = '\0';
		if (*opcode == NULL)
			*opcode = _strdup(arg);
		else
			*value = _strdup(arg);
		len = 0;
	}

	free(arg);
}
