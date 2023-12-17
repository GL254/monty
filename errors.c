#include "monty.h"

/**
 * mallerror - malloc error
 * @ptr: new pointer
 *
 * Return: nothing
 */
void mallerror(stack_t *ptr)
{
	ssize_t n = 0;

	if (ptr == NULL)
	{
		n = write(STDERR_FILENO, "Error: malloc failed", 21);
		n = write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
		if (n == 0)
			++n;
	}
}

/**
 * open_error - malloc error for instructions
 * @argv: prog name
 * @err_msg: error message
 * @len_err: length of error
 * @len_argv: length of prog name name
 *
 * Return: nothing
 */
void open_error(char *argv, char *err_msg, size_t len_err, size_t len_argv)
{
	ssize_t n = 0;

	n = write(STDERR_FILENO, err_msg, len_err);
	n = write(STDERR_FILENO, argv, len_argv);
	n = write(STDERR_FILENO, "\n", 1);
	if (n == 0)
		++n;
	exit(EXIT_FAILURE);
}
/**
 * invalid_func - prints error for invalid function
 * @line_no: line number of opcode
 * @opcode: opcode
 *
 * Return: nothing
 */
void invalid_func(unsigned int line_no, char *opcode)
{
	unsigned int len = 0;
	char buf[10] = {0};

	len = sprintf(buf, "%u", line_no);
	write(STDERR_FILENO, "L", 1);
	write(STDERR_FILENO, buf, len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "unknown instruction ", 21);
	write(STDERR_FILENO, opcode, strlen(opcode));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * rotr - rotates stack to the bottom
 * @head: stack
 * @line_no: line with opcode
 *
 * Return: nothing
 */
void rotr(stack_t **head, unsigned int line_no)
{
	stack_t *ptr = NULL;
	int num[50] = {0}, i = 0;

	(void)line_no;
	if (*head == NULL)
		return;
	ptr = *head;
	while (ptr != NULL)
	{
		num[i] = ptr->n;
		ptr = ptr->next;
		++i;
	}
	--i;
	while ((*head)->next != NULL)
	{
		(*head)->n = num[i];
		*head = (*head)->next;
		--i;
	}
	(*head)->n = num[i];
}

/**
 * queue - sets stack to FIFO
 * @head: stack
 * @line_no: line with opcode
 *
 * Return: nothing
 */
void queue(stack_t **head, unsigned int line_no)
{
	rotr(head, line_no);
}

