#include "monty.h"

/**
 * add_error - if stack contains less than two elements print error.
 * @line: represents the line
 *
 * Return: void
 */
void add_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * sub_error - error if the sack contains less than two elemts.
 * @line: shows the line
 *
 * Return: void.
 */
void sub_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * swap_error - if the stack contains less than two elements
 * it prints error message.
 * @line: reps the line.
 *
 * Return: void.
 */
void swap_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * div_error - if the stack contains less than two elements print error.
 * @line: reps the line.
 *
 * Return: void.
 */
void div_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * mul_error - if the stack contains less than two elments print error.
 * @line: reps the line.
 *
 * Return: void.
 */
void mul_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}
