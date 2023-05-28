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
