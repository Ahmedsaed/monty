#include "monty.h"

// Queue push_back operation
void queue_push_back(stack_t *stack, int value)
{
    stack_push_back(stack, value);
}

// Queue push_front operation
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

// Queue pop_back operation
int queue_pop_back(stack_t *stack)
{
    return stack_pop_back(stack);
}

// Queue pop_front operation
int queue_pop_front(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = stack->next->n;
    stack_t *temp = stack->next;

    if (stack->next->prev != NULL)
        stack->next->prev->next = NULL;

    stack->next = stack->next->prev;

    free(temp);
    stack->n--;

    return value;
}

// Queue front operation
int queue_front(stack_t *stack)
{
    return stack_front(stack);
}

// Queue back operation
int queue_back(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    stack_t *temp = stack->next;

    while (temp->prev != NULL)
        temp = temp->prev;

    return temp->n;
}