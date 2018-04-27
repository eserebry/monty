#include "monty.h"
/**
 * _add - add the top two elements of the stack
 *@head: pointer to the head of the linked list
 *@line_num: line number
 */
void _add(stack_t **head, unsigned int line_num)
{
	unsigned int sum = 0;
	stack_t *tmp;

	tmp = *head;
	if ((*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}
/**
 *_sub - subtract top two elements of stack
 *@head: pointer to head of the linked list
 *@line_num: keeps track of line count
 */
void _sub(stack_t **head, unsigned int line_num)
{
	unsigned int sub = 0;
	stack_t *tmp;

	tmp = *head;
	if ((*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
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
 *@line_num: keeps track of line count
 */
void _div(stack_t **head, unsigned int line_num)
{
	unsigned int sub = 0;
	stack_t *tmp;

	tmp = *head;
	if ((*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sub = (*head)->next->n / (*head)->n;
	(*head)->next->n = sub;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 *_mul - multiplies the second top element of the stack with the top
 *@head: pointer to head of the linked list
 *@line_num: keeps track of line count
 */
void _mul(stack_t **head, unsigned int line_num)
{
	unsigned int sub = 0;
	stack_t *tmp;

	tmp = *head;
	if ((*head = NULL) || (*head)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sub = (*head)->next->n * (*head)->n;
	(*head)->next->n = sub;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 * _nop - doesnt do anything
 *
 *@head: unused parameter
 *@i: unused
 *
 */
void _nop(stack_t **head, unsigned int i)
{
	(void)head;
	(void)i;
}
