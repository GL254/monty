#include "monty.h"

/**
 * is_in - checks for digits
 * @opcode: input string
 * @integer: operand
 * @line_no: line number of opcode
 * @msg: error message
 *
 * Return: 0 for success, 1 for fail
 */
int is_in(char *opcode, char *integer, unsigned int line_no, char *msg)
{
	char array_int[] = {"0123456789"}, neg[] = "-";
	unsigned int ret_val = 1, i = 0, j = 0;

	if (_strcmp(opcode, "push") == 0)
	{
		if (integer == NULL)
			error_msg(line_no, msg);
		if (integer[0] == neg[0])
			i++;
		while (i < strlen(integer))
		{
			while (j < strlen(array_int))
			{
				if (integer[i] == array_int[j])
				{
					ret_val = 0;
					j = 0;
					break;
				}
				else
					ret_val = 1;
				j++;
			}
			if (ret_val == 1)
				break;
			i++;
		}
	}
	return (ret_val);
}
/**
 * error_msg - error message
 * @line_no: line_no of opcode
 * @msg: error message for opcode
 *
 * Return: nothing
 */
void error_msg(unsigned int line_no, char *msg)
{
	ssize_t n = 0;
	unsigned int len = 0;
	char buf[10] = {0};

	len = sprintf(buf, "%u", line_no);
	n = write(STDERR_FILENO, "L", 1);
	n = write(STDERR_FILENO, buf, len);
	n = write(STDERR_FILENO, msg, strlen(msg));
	n = write(STDERR_FILENO, "\n", 1);
	if (n == 0)
		++n;
	exit(EXIT_FAILURE);
}

/**
 * format - checks format of functions
 * @opcode: operation
 * @integer: operand
 * @line_no: line number of opcode
 * @num: integer given
 *
 * Return: nothing
 */
void format(char *opcode, char *integer, unsigned int line_no, int *num)
{
	char *funcs[] = {"push", "pall", "pop", "add", "sub", "mul",
		"rotr", "pint", "div", "swap"};
	char msg[30] = {0};
	unsigned int i = 0, same = 0;

	strcpy(msg, ": usage: ");
	while (i < sizeof(funcs) / sizeof(funcs[0]))
	{
		if (_strcmp(opcode, funcs[i]) == 0)
		{
			same = 1;
			strcat(msg, funcs[i]);
			if (_strcmp(funcs[i], "push") == 0)
				strcat(msg, " integer");
			break;
		}
		i++;
	}
	if (same == 0)/*not found in funcs*/
		invalid_func(line_no, opcode);
	if (_strcmp(opcode, "push") == 0)
	{
		if (integer == NULL)
			error_msg(line_no, msg);
		if (is_in(opcode, integer, line_no, msg) == 1)
			error_msg(line_no, msg);
		*num = atoi(integer);
	}
	if (integer != NULL && _strcmp(opcode, "push") != 0)
		error_msg(line_no, msg);
}
