#ifndef ERROR_H
#define ERROR_H

/* error handlers */
void error_file(char *file);
int error_instruction(char *opcode);
void error_malloc(void);
void error_push_value(void);
void error_pint(void);

void error_pop(void);
int error_short_stack(char *opcode);
int error_div_zero(void);
int error_pchar(void);

#endif /* ERROR_H */
