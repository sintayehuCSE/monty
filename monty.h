#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FLUSH_BUFFER 1
#define WRITE_BUFFER 1024
extern unsigned int line_number;
/**....List of needed data structures "Database tables, as I call them"...*/
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queue, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**.......Functions for writing an error to erro_buffer and stderr..........*/
void _eputs(const char *);
void _eput(const char);
/**....Check file open operation error....*/
void check_file_open_error(FILE *, const char *);
#endif /** MONTY_H*/
