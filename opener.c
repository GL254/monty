#include "monty.h"
#include "num.h"

/**
 * control - controls operations
 * @file: file descriptor
 * @func: list of functions
 * @func_size: number of commands on list
 *
 * Return: nothing
 */
void control(FILE *file, instruction_t *func, size_t func_size)
{
	char *delim = " , \n, \t, $", *opcode = NULL, *integer = NULL;
	char *line = NULL;
	size_t size = 0, i = 0;
	ssize_t read = 0;
	stack_t *head = NULL;
	unsigned int line_no = 0;
	int cmp = 1;

	read = getline(&line, &size, file);
		if (read != -1)
		line_no = 1;
	while (read != -1)
	{
		opcode = strtok(line, delim);
		if (opcode != NULL)
		{
			integer = strtok(NULL, delim);
			format(opcode, integer, line_no, &num);
		}
		for (; i < func_size; ++i)
		{
			if (opcode == NULL)
				break;
			cmp = _strcmp(func[i].opcode, opcode);
			if (cmp == 0)
			{
				func[i].f(&head, line_no);
				break;
			}
		}
		i = 0;
		read = getline(&line, &size, file);
		if (read != -1)
			line_no++;
	}
	free_single(line);
	free_stack(head);
}

/**
 * push - adds an integer to stack
 * @head: stack
 * @line_no: line with opcode
 *
 * Return: nothing
 */
void push(stack_t **head, unsigned int line_no)
{
	stack_t *new_ptr = NULL, *ptr = NULL;

	(void)line_no;
	new_ptr = (stack_t *) malloc(sizeof(stack_t));
	mallerror(new_ptr);
	new_ptr->n = num;
	new_ptr->next = NULL;
	new_ptr->prev = NULL;
	if (*head == NULL)
	{
		*head = new_ptr;
		return;
	}
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_ptr;
	new_ptr->prev = ptr;
}

/**
 * pall - prints all elements in stack
 * @head: stack
 * @line_no: line number in file
 *
 * Return: nothing
 */
void pall(stack_t **head, unsigned int line_no)
{
	stack_t *ptr = NULL;

	(void)line_no;
	if (*head == NULL)
	{}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->prev;
		}
	}
}

/**
 * pint - prints element at the top of stack
 * @head: stack
 * @line_no: line number of opcode
 *
 * Return: nothing
 */
void pint(stack_t **head, unsigned int line_no)
{
	char msg[] = ": can't pint, stack empty";
	stack_t *ptr = NULL;

	if (*head == NULL)
		error_msg(line_no, msg);
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	printf("%d\n", ptr->n);
}

/**
 * pop - removes element on top of stack
 * @head: stack
 * @line_no: line number of opcode
 *
 * Return: nothing
 */
void pop(stack_t **head, unsigned int line_no)
{
	char msg[] = ": can't pop an empty stack";
	stack_t *ptr = NULL;

	if (*head == NULL)
		error_msg(line_no, msg);
	ptr = *head;
	if (ptr->next == NULL)
	{
		*head = NULL;
		return;
	}
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	free(ptr->next);
	ptr->next = NULL;
}

