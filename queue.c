#include "monty.h"

/* stack and queue functions */
void init_stack(stack_t *stack);
void stack_push_back(stack_t *stack, int value);
int stack_pop_back(stack_t *stack);
int stack_front(stack_t *stack);
void queue_push_back(stack_t *stack, int value);
void queue_push_front(stack_t *stack, int value);
int queue_pop_back(stack_t *stack);
int queue_pop_front(stack_t *stack);
int queue_front(stack_t *stack);
int queue_back(stack_t *stack);

/**
 * queue_push_back - adds a new node at the end of a stack_t list
 *
 * @stack: pointer to the stack
 * @value: value to be added to the stack
 *
 * Return: the address of the new element, or NULL if it failed
*/
void queue_push_back(stack_t *stack, int value)
{
	stack_push_back(stack, value);
}

/**
 * queue_push_front - adds a new node at the beginning of a stack_t list
 *
 * @stack: pointer to the stack
 * @value: value to be added to the stack
*/
void queue_push_front(stack_t *stack, int value)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	new_node->n = value;
	new_node->prev = NULL;

	if (stack->n == 0)
	{
		new_node->next = NULL;
		stack->next = new_node;
	}
	else
	{
		new_node->next = stack->next;
		stack->next->prev = new_node;
		stack->next = new_node;
	}

	stack->n++;
}

/**
 * queue_pop_back - removes the last element of a stack_t list
 *
 * @stack: pointer to the stack
 *
 * Return: the value of the removed element
*/
int queue_pop_back(stack_t *stack)
{
	return (stack_pop_back(stack));
}

/**
 * queue_pop_front - removes the first element of a stack_t list
 *
 * @stack: pointer to the stack
 *
 * Return: the value of the removed element
*/
int queue_pop_front(stack_t *stack)
{
	int value;
	stack_t *temp;

	if (stack->n == 0)
		return (-1);

	value = stack->next->n;
	temp = stack->next;

	if (stack->next->prev != NULL)
		stack->next->prev->next = NULL;

	stack->next = stack->next->prev;

	free(temp);
	stack->n--;

	return (value);
}

/**
 * queue_front - returns the value at the front of a stack_t list
 *
 * @stack: pointer to the stack
 *
 * Return: the value at the front of the stack
*/
int queue_front(stack_t *stack)
{
	return (stack_front(stack));
}
