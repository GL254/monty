#include "monty.h"

/**
 * _add - main entry.
 * Description: adds top two elements of  stack
 * @line_number: constant int given
 * @top: head element of the stack
 *
 * Return: void.
 */
void _add(stack_t **top, unsigned int line_number)
{
	char msg[] = ": can't add, stack too short";
	stack_t *tmp = NULL;

	if (*top == NULL || (*top)->next == NULL)
		error_msg(line_number, msg);
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->n += tmp->n;
	pop(top, line_number);
}
/**
 * _sub - main entry
 * Description: sub the top element of the stack
 * from the second top element of the stack.
 * @line_number: constant int given
 * @top: top element of the stack.
 *
 * Return: void
 */
void _sub(stack_t **top, unsigned int line_number)
{
	char msg[] = ": can't sub, stack too short";
	stack_t *tmp = NULL;

	if (*top == NULL || (*top)->next == NULL)
		error_msg(line_number, msg);
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->n -= tmp->n;
	pop(top, line_number);
}
/**
 * _div - main entry
 * Description: div the top element of the stack
 * by the top element of the stack.
 * @line_number: constant int given
 * @top: top element of the stack.
 *
 * Return: void
 */
void _div(stack_t **top, unsigned int line_number)
{
	char msg[] = ": can't div, stack too short";
	stack_t *tmp = NULL;

	if (*top == NULL || (*top)->next == NULL)
		error_msg(line_number, msg);
	if ((*top)->n == 0)
		div_error2(line_number);
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->n /= tmp->n;
	pop(top, line_number);
}
/**
 * _mul - main entry
 * Description: mul the second top element of the stack
 * @top: element at the top of the stack
 * with the top element of the stack.
 * @line_number: constant innt given
 *
 * Return: void
 */
void _mul(stack_t **top, unsigned int line_number)
{
	char msg[] = ": can't mul, stack too short";
	stack_t *tmp = NULL;

	if (*top == NULL || (*top)->next == NULL)
		error_msg(line_number, msg);
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->n *= tmp->n;
	pop(top, line_number);
}
/**
 * _swap - main entry.
 * Description: swaps the top two elements of the stack.
 * @top: element at the top the stack.
 * @line_number: cont int given
 *
 * Return: void.
 */
void _swap(stack_t **top, unsigned int line_number)
{
	char msg[] = ": can't swap, stack too short";
	int num;

	if (*top == NULL || (*top)->next == NULL)
		error_msg(line_number, msg);
	num = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = num;
}
