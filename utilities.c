#include "monty.h"
/**
 *_atoi - own atoi
 *@number: number to convert
 *
 *Return: converted int
 */
/*int _atoi(char *number)
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

	}*/
int _atoi(char *s)
{
	int i;
	unsigned int in;
	int sign;

	i = 0;
	in = 0;
	sign = 0;
	while (s[i] > '9' || s[i] < '0')
	{
		if (s[i] == '-')
		{
			sign++;
		}
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		in = in * 10 + (s[i] - '0');
		i++;
	}
	if (sign % 2 != 0)
	{
		in = -1 * in;
		return (in);
	}
	if (in == 0)
		return (0);
	return  (in);
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
