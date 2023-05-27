#ifndef STRING_H
#define STRING_H

#include <unistd.h>
#include <stdlib.h>
#include "error.h"

/* string functions */
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, int ch);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_substr(char *src, int m, int n);
int _atoi(char *str);
char *_itoa(int num);
int is_numeric(char *s);
int is_digit(char c);

/* print functions */
void print_str(char *s);
void print_err(char *s);

/* getline functions */
int _getline(char **lineptr, size_t *n, int stream);

#endif /* STRING_H */
