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

// Stack push_back operation
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

// Stack pop_back operation
int stack_pop_back(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    int value = stack->next->n;
    stack_t *temp = stack->next;
    stack->next = stack->next->prev;

    if (stack->next != NULL)
        stack->next->next = NULL;

    free(temp);
    stack->n--;

    return value;
}

// Stack front operation
int stack_front(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->next->n;
}

// Initialize the stack/queue object
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