#include "monty.h"
/**
 * _free - function frees all memory stored in heap
 *
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
