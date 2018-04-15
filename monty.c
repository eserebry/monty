#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int line_num = 0;
/**
 * getopcode - function that selects the correct function
 * to perform the operation asked by the user
 *
 * @s: operator passed as argument to the program
 *
 * Return: pointer to the function that corresponds to the operator
 * given as a parameter
 */
void (*getopcode(char *s))(stack_t **, unsigned int)
{
	instruction_t o[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"nop", _nop},
		{NULL, NULL}
	};
	int i = 0;

	while (o[i].opcode != NULL)
	{
		if (strcmp(o[i].opcode, s) == 0)
		{
			return (o[i].f);
		}
		i++;
	}
	return (NULL);
}


/**
 *read_file - reads a text file (and prints it to a standart output)
 *
 *@file_name: name of the file to read
 *
 * Return: number of letters to print, 0 otherwise
 */
void read_file(const char *file_name)
{
	FILE *fd;
	int readcount;
	size_t len = 0;
	char *strinput = NULL, *token_0 = NULL, *token_1 = NULL, *delim = "\n ";
	stack_t *head;
	int tokennumber = 0;
	void (*p)(stack_t **, unsigned int);

	head = NULL;
	if (file_name == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((readcount = getline(&strinput, &len, fd)) != -1)
	{
		line_num++;

		token_0 = strtok(strinput, delim);
		token_1 = strtok(NULL, delim);
		if (!token_0 || !strinput)
			continue;


		if ((strcmp(token_0, "push") == 0) && token_1 == NULL)
		{
			printf("L%d: usage: push integer\n", line_num);
			_free(head);
			free(strinput);
			exit(EXIT_FAILURE);
		}
		if (token_1 != NULL)
		{
			tokennumber = atoi(token_1);
			if (tokennumber == 0 && (strcmp(token_1, "0") != 0))
			{
				printf("L%d: usage: push integer\n", line_num);
				_free(head);
				free(strinput);
				exit(EXIT_FAILURE);
			}
		}

		p = getopcode(token_0);
		if (p == NULL)
		{
			printf("L%d: unknown instruction %s\n",
			       line_num, token_1);
			_free(head);
			free(strinput);
			exit(EXIT_FAILURE);
		}

		p(&head, tokennumber);
	}

	fclose(fd);
	free(strinput);
	_free(head);
}

/**
 *main - calling red_file function as well as error management
 *
 *@argc: argument count
 *@argv: pointer to an adress of the argument
 *
 *Return: 0, always success
 */
int main(int argc, char *argv[])
{


	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1]);

	return (0);

}
