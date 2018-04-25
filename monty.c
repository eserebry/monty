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
	int readcount/*, tok = 0*/, i = 0;
	size_t len = 0;
	char *strinput = NULL, *token;

	if (file_name == NULL)
		return (0);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		return (0);
	while ((readcount = getline(&strinput, &len, fd)) != -1)
	{
		if (readcount == -1)
		{
			exit(0);
		}
		token = strtok(strinput, " ");
		while (token != NULL)
		{
			printf("%s", token);
			token = strtok(NULL, " ");
		}
	}
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
