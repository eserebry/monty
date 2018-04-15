#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void _pall(stack_t **head)
{
	stack_t tmp;

	while((*head)->next)
		*head = (*head)->next;

	while(*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->prev;
	}

}

stack_t *_push(char *tokentwo, stack_t **head)
{
	int pushnum = 0;
	stack_t *new;
	stack_t *tmp;
	stack_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	pushnum = atoi(tokentwo);

	if (pushnum == 0)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = pushnum;

	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}

	tmp = *head;

	while(tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;

	return (*head);
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
	int i;
	size_t len = 0;
	char *strinput = NULL;
	char **token = NULL;
	char *delim = "\n ";
	stack_t *numberstack;
	stack_t opcode[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	numberstack = NULL;

	int readcount, line_num = 0;
	size_t len = 0;
	char *strinput = NULL, *token;


	if (file_name == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
                exit(EXIT_FAILURE);
        }


	fd = fopen(file_name, "r");


	fd = fopen(file_name, "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((readcount = getline(&strinput, &len, fd)) != -1)
	{


		token = NULL;
		i = 0;
		token = malloc(sizeof(char *) * 2);

		token[0] = strtok(strinput, delim);

		token[1] = strtok(NULL, delim);



		while (opcode[i].f != NULL)
		{
			
		}

		if (strcmp(token[0], "push") == 0)
		{
			numberstack = _push(token[1], &numberstack);
		}
		else if (strcmp(token[0], "pall") == 0)
		{

			_pall(&numberstack);
		}
		else
			printf("nothingyet: %s\n", token[0]);

		/*	else if (strcmp(token, "pall") == 0 || strcmp(token, "pint") == 0
			 || strcmp(token, "pop") == 0 || strcmp(token, "swap") == 0
			 ||strcmp(token, "add") == 0 || strcmp(token, "nop") == 0)

		if (readcount == -1)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(strinput, " ");
		while (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " ");
				printf("%s", token);
				break;
			}
			else if (strcmp(token, "pall") == 0 || strcmp(token, "pint") == 0
			    || strcmp(token, "pop") == 0 || strcmp(token, "swap") == 0
			    ||strcmp(token, "add") == 0 || strcmp(token, "nop") == 0)
				break;

			/*if (strcmp(token, "pall") != 0 || strcmp(token, "pint") != 0
			     || strcmp(token, "pop") != 0 || strcmp(token, "swap") != 0
			     ||strcmp(token, "add") != 0 || strcmp(token, "nop") != 0) 
			{
				printf("L%d: unknown instruction %s\n", line_num, token);
				exit(EXIT_FAILURE);
			}*/

		line_num ++;
	}


			token = strtok(NULL, " ");
		}
		line_num ++;
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
