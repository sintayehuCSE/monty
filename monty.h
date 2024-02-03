#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define FLUSH_BUFFER 1
#define WRITE_BUFFER 1024
#define READ_BUFFER 1024
#define WRITE_BUFFER 1024
#define UNUSED(x) (void)(x)
extern FILE *file_ptr;
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
void error_invalid_opcode(unsigned int, char *, stack_t **);
void error_push_opcode(stack_t **, unsigned int);
void error_pint_opcode(unsigned int);
void error_pop_opcode(unsigned int);
void error_swap_opcode(stack_t **, unsigned int);
void error_add_opcode(stack_t **, unsigned int);
void malloc_error(stack_t **);



/**......Function for writing an output into output buffer and stdout.......*/
void _puts(const char *);
void _put(const char);


/**....Check file open operation error....*/
void check_file_open_error(const char *);


/**....Read each instruction in a monty bytecode..........................*/
void read_instructions(unsigned int *, stack_t **);
ssize_t read_line(char **, unsigned int *, long *, stack_t **);
int extract_opcode(char **, unsigned int *, stack_t **);
long capture_end_of_file(void);


/**........Stack Operations............*/
void stack_push(stack_t **, unsigned int);
void stack_pall(stack_t **, unsigned int);
void stack_pint(stack_t **, unsigned int);
void stack_pop(stack_t **, unsigned int);
void stack_swap(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void stack_nop(stack_t **, unsigned int);

/**......Function for stack node manipulation.......*/
stack_t *add_node_top(stack_t **, int);


/**........Utility/Special purpose functions.................*/
int free_memory(stack_t **);
void convert_number_to_str(int, char *, int *);
int len(char *);
void parse_arg_str(char *, stack_t **, unsigned int);
#endif /** MONTY_H*/
