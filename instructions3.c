#include "monty.h"

/**
 * op_rotl - rotates the stack to the bottom
 *
 * Return: 0 on success, -1 on failure
 */
int op_rotl(void)
{
	stack_t *tmp = list_head;

	if (tmp == NULL || tmp->next == NULL)
		return (0);

	push_back(tmp->n);
	pop_front();

	return (0);
}

/**
 * op_rotr - rotates the stack to the top
 *
 * Return: 0 on success, -1 on failure
 */
int op_rotr(void)
{
	stack_t *tmp = list_head;
	int n;

	if (tmp == NULL || tmp->next == NULL)
		return (0);

	while (tmp->next != NULL)
		tmp = tmp->next;

	n = tmp->n;
	pop_back();
	push_front(n);

	return (0);
}

/**
 * switch_format - switches the format of the list
 *
 * @opcode: opcode to be executed
 *
 * Return: 0 on success, -1 on failure
 */
int switch_format(char *opcode)
{
	if (_strcmp(opcode, "stack") == 0)
		format = STACK;
	else if (_strcmp(opcode, "queue") == 0)
		format = QUEUE;

	return (0);
}

/**
 * op_help - prints the help message
 *
 * Return: 0 on success, -1 on failure
 */
int op_help(void)
{
	print_str("Instructions:\n");
	print_str("  push <int>:	Pushes an element to the stack.\n");
	print_str("  pop:		Removes the top element of the stack.\n");
	print_str("  pall:		Prints all the values on the stack.\n");
	print_str("  pint:		Prints the value at the top of the stack.\n");
	print_str("  swap:		Swaps the top two elements of the stack.\n");
	print_str("  nop:		Doesn't do anything.\n");
	print_str("  add:		Adds the top two elements of the stack.\n");
	print_str("  sub:		Subtracts the top element of the stack ");
	print_str("from the second top element of the stack.\n");
	print_str("  div:		Divides the second top element of the ");
	print_str("stack by the top element of the stack.\n");
	print_str("  mul:		Multiplies the second top element of ");
	print_str("the stack with the top element of the stack.\n");
	print_str("  mod:		Computes the rest of the division of ");
	print_str("the second top element of the stack by ");
	print_str("the top element of the stack.\n");
	print_str("  pchar:	Prints the char at the top of the stack.\n");
	print_str("  pstr:		Prints the string starting at the top of the stack.\n");
	print_str("  rotl:		Rotates the stack to the bottom.\n");
	print_str("  rotr:		Rotates the stack to the top.\n");
	print_str("  queue:	Sets the format of the data to a queue (FIFO).\n");
	print_str("  stack:	Sets the format of the data to a stack (LIFO).\n");
	print_str("  exit:		Exits the program.\n");

	return (0);
}
