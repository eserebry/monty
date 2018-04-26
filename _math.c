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
void _sub(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	unsigned int sub = 0;
	stack_t *tmp;

	tmp = *head;
	sub = (*head)->next->n - (*head)->n;
	(*head)->next->n = sub;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 *_div - divides the second top element of the stack
 * by the top element of the stack.
 *@head: pointer to head of the linked list
 *@i: unused parameter
 */
void _div(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	unsigned int sub = 0;
	stack_t *tmp;

	tmp = *head;
	sub = (*head)->next->n / (*head)->n;
	(*head)->next->n = sub;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 *_mul - multiplies the second top element of the stack with the top
 *@head: pointer to head of the linked list
 *@i: unused parameter
 */
void _mul(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	unsigned int sub = 0;
	stack_t *tmp;

	tmp = *head;
	sub = (*head)->next->n * (*head)->n;
	(*head)->next->n = sub;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}
