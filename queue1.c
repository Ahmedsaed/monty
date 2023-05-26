#include "monty.h"

/**
 * queue_back - returns the value at the back of a stack_t list
 *
 * @stack: pointer to the stack
 *
 * Return: the value at the back of the stack
*/
int queue_back(stack_t *stack)
{
	stack_t *temp;

	if (stack->n == 0)
		return (-1);

	temp = stack->next;

	while (temp->prev != NULL)
		temp = temp->prev;

	return (temp->n);
}
