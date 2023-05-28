#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

int op_push(char *value);
int op_pall(void);
int op_pint(void);
int op_pop(void);
int op_swap(void);

int math_operations(char *opcode);
int op_pchar(void);
int op_pstr(void);
int print_operations(char *opcode);

#endif /* INSTRUCTIONS_H */
