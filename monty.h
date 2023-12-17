#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void control(FILE *file, instruction_t *func, size_t size);
void push(stack_t **head, unsigned int line_no);
size_t print_dlistint(const stack_t *h);
void pall(stack_t **head, unsigned int line_no);
int _strcmp(char *s1, char *s2);
void free_stack(stack_t *head);
void pint(stack_t **head, unsigned int line_no);
void pop(stack_t **head, unsigned int line_no);
void mallerror(stack_t *ptr);
void open_error(char *argv, char *err_msg, size_t len_err, size_t len_argv);
void free_single(char *ptr);
void _mul(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _swap(stack_t **top, unsigned int line_number);
void swap_error(unsigned int line);
void add_error(unsigned int line);
void sub_error(unsigned int line);
void div_error(unsigned int line);
void mul_error(unsigned int line);
void invalid_func(unsigned int line_no, char *opcode);
void rotr(stack_t **head, unsigned int line_no);
void queue(stack_t **head, unsigned int line_no);
int is_in(char *opcode, char *integer, unsigned int line_no, char *msg);
void error_msg(unsigned int line_no, char *msg);
void format(char *opcode, char *integer, unsigned int line_no, int *num);
void div_error2(unsigned int line);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif
