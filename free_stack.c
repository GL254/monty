#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: head of list
 *
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *ptr = head, *for_free = NULL;

	while (ptr != NULL)
	{
		for_free = ptr->next;
		free(ptr);
		ptr = for_free;
	}
}

/**
 * free_single - free a pointer
 * @ptr: pointer
 *
 * Return: nothing
 */
void free_single(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = 0;
	}
}
