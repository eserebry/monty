#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void _pall(stack_t **head, unsigned int i __attribute__ ((unused)))
{

	if (*head == NULL || head == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while((*head)->next)
		*head = (*head)->next;

	printf("_pall\n");
	while(*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->prev;
	}

}

void _push(stack_t **head, unsigned int pushnum)
{
	stack_t *new;
	printf("in _push func\n");
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = pushnum;
	new->prev = NULL;
	printf("B\n");
	if (head == NULL || *head)
	{
		printf("here\n");
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = (*head);
		(*head)->prev = new;
		*head = new;
	}
}

void (*getopcode(char *s))(stack_t **, unsigned int)
{
	instruction_t o[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i = 0;
	printf("A\n");

	while (o[i].opcode != NULL)
	{
		if (strcmp(o[i].opcode, s) == 0)
		{
			return(o[i].f);
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
		printf("%d\n", line_num);
		if (p == NULL)
			continue;
		p(&head, tokennumber);
		printf("end\n");

	}


	printf("number of lines is %d\n", line_num);

	fclose(fd);
	free (strinput);
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
