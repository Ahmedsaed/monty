#ifndef STACK_H
#define STACK_H

/* type definations */
typedef struct stack_s stack_t;

typedef void (*push_back_fn)(stack_t *stack, int value);
typedef void (*push_front_fn)(stack_t *stack, int value);
typedef int (*pop_back_fn)(stack_t *stack);
typedef int (*pop_front_fn)(stack_t *stack);
typedef int (*front_fn)(stack_t *stack);
typedef int (*back_fn)(stack_t *stack);

/* stack functions */
void init_stack(stack_t *stack);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * @push_back: function pointer to push_back function
 * @push_front: function pointer to push_front function
 * @pop_back: function pointer to pop_back function
 * @pop_front: function pointer to pop_front function
 * @front: function pointer to front function
 * @back: function pointer to back function
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
	push_back_fn push_back;
	push_front_fn push_front;
	pop_back_fn pop_back;
	pop_front_fn pop_front;
	front_fn front;
	back_fn back;
};

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
