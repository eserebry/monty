#include "monty.h"
/**
 * _add - add the top two elements of the stack
 *@head: pointer to the head of the linked list
 *@i: unused parameter
 */
void _add(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	unsigned int sum = 0;
	stack_t *tmp;

	tmp = *head;
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}
/**
 *_sub - subtract top two elements of stack
 *@head: pointer to head of the linked list
 *@i: unused parameter
 */
