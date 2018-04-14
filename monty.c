#include "monty.h"
/**
 *
 *
 *
 */
int main(int argc __attribute__((unused)), char *argv[]  __attribute__((unused)))
{
	unsigned int readcount = 0;
	char *strinput = NULL;
	size_t len = 0;
	char delim = ' '



		while((readcount = getline(&strinput, &len, stdin)) != -1)
		{
			if (readcount == -1)
			{
				exit();
			}
			token = strtok(strinput, delim);
		}

	return (0);
}
