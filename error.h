#ifndef ERROR_H
#define ERROR_H

/* error handlers */
void error_file(char *file);
void error_instruction(char *opcode);
void error_malloc(void);
void error_push_value(void);
void error_pint(void);

#endif /* ERROR_H */
