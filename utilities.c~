#include "monty.h"
/**
 *_atoi - changes characters to an integer
 *@token: number to convert
 *
 *return: converted number
 */
int _atoi(char *token)
{
	int number = 0;
	int i = 0;
	int boo = 0;

	if (token[i] == "-")
	{
		boo = 1;
		i++;
	}
	while(token[i] != '\0')
	{
		number = number*10 + token[i] - '0';
		i++;
	}
	if (boo == 1)
		number *= -1;

	return (number);
}
