#include "monty.h"
/**
 * _mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 *@head: pointer to the head of the linked list
 *@line_num: line number
 */
void _mod(stack_t **head, unsigned int line_num)
{
	unsigned int mod = 0;
	stack_t *tmp;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	mod = (*head)->next->n % (*head)->n;
	(*head)->next->n = mod;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}
