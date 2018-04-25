#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 *read_file - reads a text file (and prints it to a standart output)
 *
 *@file_name: name of the file to read
 *
 * Return: number of letters to print, 0 otherwise
 */
int read_file(const char *file_name)
{
	FILE *fd;
	int readcount/*, tok = 0*/,line_num = 0;
	size_t len = 0;
	char *strinput = NULL, *token;

	if (file_name == NULL)
		return (0);
	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		return (0);
	}
	while ((readcount = getline(&strinput, &len, fd)) != -1)
	{
		if (readcount == -1)
		{
			exit(0);
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
			token = strtok(NULL, " ");
		}
		line_num ++;
	}
	printf("number of lines is %d\n", line_num);
	return (0);
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
