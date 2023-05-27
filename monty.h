#ifndef MONTY_H
#define MONTY_H

#include <fcntl.h>
#include "string.h"
#include "mem.h"
#include "error.h"
#include "stack.h"

#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024
#define true 1
#define false 0
#define MAX_ARG_LEN 1000

/* global variables */
extern int line_number;

/* file functions */
int process_file(char *file, int *fd);

/* parsers */
void parse_instruction(char *line, char **opcode, char **value);

#endif
