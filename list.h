#ifndef STACK_H
#define STACK_H

#include <unistd.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1

extern int format;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *list_head;
extern stack_t *list_tail;

/* stack and queue functions */
int empty(void);
void push_back(int data);
void push_front(int data);
void pop_back(void);
void pop_front(void);
int front(void);
int back(void);
void free_list(void);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif /* STACK_H */
