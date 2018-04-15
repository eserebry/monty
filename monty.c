#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void _pall(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	while((*head)->next)
		*head = (*head)->next;

	while(*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->prev;
	}

}

void _push(stack_t **head, unsigned int pushnum)
{
	stack_t *new;
	stack_t *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);

	new->n = pushnum;

	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		new->next = NULL;
		return;
	}

	tmp = *head;

	while(tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;

	return;
}

void (*getopcode(char *s))(stack_t, unsigned int)
{
        instruction_t o[] = {
                {"push", _push},
                {"pall", _pall},
                {NULL, NULL}
        };
        int i = 0;

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
	char **token = NULL;
	char *delim = "\n ";
	stack_t **head = NULL;
	int tokennumber = 0;

	*head = NULL;

	void (*p)(stack_t, unsigned int);

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


		token = NULL;

		token = malloc(sizeof(char *) * 2);

		token[0] = strtok(strinput, delim);

		token[1] = strtok(NULL, delim);

		tokennumber = atoi(token[1]);
		line_num++;
		p = getopcode(token[0]);
		//check for p failure
		if (p == NULL)
			continue;

		p(&head, tokennumber);


		/*if (strcmp(token[0], "push") == 0)
		  {
		  numberstack = _push(tokennumber, &numberstack);
		  }
		  else if (strcmp(token[0], "pall") == 0)
		  {

		  _pall(&numberstack);
		  }
		  else
		  printf("nothingyet: %s\n", token[0]);*/
		

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
