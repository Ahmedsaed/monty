#include "list.h"

/**
 * front - returns the front element of the list
 *
 * @head: pointer to the head of the list
 *
 * Return: value of the front element
 */
int front(stack_t **head)
{
	if (*head == NULL)
		return (-1);

	return ((*head)->n);
}

/**
 * back - returns the back element of the list
 *
 * @head: pointer to the head of the list
 *
 * Return: value of the back element
 */
int back(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return (-1);

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	return (temp->n);
}
