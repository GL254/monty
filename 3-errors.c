#include "monty.h"

/**
 * div_error2 - prrints error if the top element of the stack is 0
 * @line: line
 *
 * Return: void.
 */
void div_error2(unsigned int line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}
