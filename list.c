#include "list.h"

/**
 * empty - checks if the list is empty
 *
 * @head: pointer to the head of the list
 *
 * Return: 1 if empty, 0 if not
 */
int empty(stack_t **head)
{
	return (*head == NULL);
}

/**
 * push_back - adds a new node at the end of the list
 *
 * @head: pointer to the head of the list
 * @data: value to add to the list
 */
void push_back(stack_t **head, int data)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
		return;

	new_node->n = data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		stack_t *temp = *head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * push_front - adds a new node at the beginning of the list
 *
 * @head: pointer to the head of the list
 * @data: value to add to the list
 */
void push_front(stack_t **head, int data)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
		return;

	new_node->n = data;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

/**
 * pop_back - removes the last element of the list
 *
 * @head: pointer to the head of the list
 */
void pop_back(stack_t **head)
{
	if (*head == NULL)
	{
		return;
	}

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		stack_t *temp = *head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		free(temp);
	}
}

/**
 * pop_front - removes the first element of the list
 *
 * @head: pointer to the head of the list
 */
void pop_front(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return;

	temp = *head;

	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;

	free(temp);
}
