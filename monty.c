#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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
	int line_num = 0;
	size_t len = 0;
	char *strinput = NULL;
	char *token_0 = NULL;
	char *token_1 = NULL;
	char *delim = "\n ";
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


		token_0 = strtok(strinput, delim);

		token_1 = strtok(NULL, delim);
		if (token_1 != NULL)
			tokennumber = atoi(token_1);
		line_num++;
		p = getopcode(token_0);
		if (p == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_num, token_1);
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
