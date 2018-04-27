#include "monty.h"
/**
 *_isdigit - decimal-digit character test
 *@str: pointer toa string to check
 *
 *Return: 1 if it"s an ineteger string, 0 if it's not
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 *_atoi - own atoi
 *@number: number to convert
 *
 *Return: converted int
 */
int _atoi(char *number)
{
	int value = 0;
	int boo = 0;
	int i = 0;

	if (number[i] == '-')
	{
		boo = 1;
		i++;
	}
	while (number[i] != '\0')
	{
		if (!isdigit(number[i]))
			return (0);

		value = value * 10 + number[i] - '0';
		i++;
	}
	if (boo == 1)
	{
		value *= -1;
	}
	return (value);

}

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
