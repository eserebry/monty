#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _pint(stack_t **head, unsigned int line_num);
void _pall(stack_t **head, unsigned int i __attribute__ ((unused)));
void _push(stack_t **head, unsigned int line_num __attribute__ ((unused)));
void _pop(stack_t **head, unsigned int line_num);
void _swap(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void _sub(stack_t **head, unsigned int line_num);
void _nop(stack_t **head, unsigned int i);
void _div(stack_t **head, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);
void _mod(stack_t **head, unsigned int line_num);
void _free(stack_t *head);
int _isdigit(char *str);
void _pchar(stack_t **head, unsigned int line_num);
void _pstr(stack_t **head, unsigned int i __attribute__ ((unused)));
extern char *tokennum;
#endif
