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
 * stack_push_back - adds a new node at the end of a stack_t list
 *
 * @stack: pointer to the stack
 * @value: value to be added to the stack
 */
void stack_push_back(stack_t *stack, int value)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	new_node->n = value;
	new_node->next = NULL;

	if (stack->n == 0)
	{
		new_node->prev = NULL;
		stack->next = new_node;
	}
	else
	{
		new_node->prev = stack->next;
		stack->next->next = new_node;
		stack->next = new_node;
	}

	stack->n++;
}

/**
 * stack_pop_back - removes the last element of a stack_t list
 *
 * @stack: pointer to the stack
 *
 * Return: the value of the removed element
*/
int stack_pop_back(stack_t *stack)
{
	int value;
	stack_t *temp;

	if (stack->n == 0)
		return (-1);

	value = stack->next->n;
	temp = stack->next;
	stack->next = stack->next->prev;

	if (stack->next != NULL)
		stack->next->next = NULL;

	free(temp);
	stack->n--;

	return (value);
}

/**
 * stack_front - returns the value of the first element of a stack_t list
 *
 * @stack: pointer to the stack
 *
 * Return: the value of the first element
*/
int stack_front(stack_t *stack)
{
	if (stack->n == 0)
		return (-1);

	return (stack->next->n);
}

/**
 * init_stack - initializes a stack_t structure
 *
 * @stack: pointer to the stack
*/
void init_stack(stack_t *stack)
{
	stack->n = 0;
	stack->prev = NULL;
	stack->next = NULL;
	stack->push_back = &stack_push_back;
	stack->push_front = &queue_push_front;
	stack->pop_back = &stack_pop_back;
	stack->pop_front = &queue_pop_front;
	stack->front = &queue_front;
	stack->back = &queue_back;
}
