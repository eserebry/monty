#include "monty.h"
/**
 * _free - function frees all memory stored in heap
 *@head: pointer to head of linked list
 */
void _free(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
