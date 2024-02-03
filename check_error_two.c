#include "monty.h"
/**
* error_pop_opcode - Check error for poping empty stack
* @line_number: Line number within monty bytecode file where
* pop opcode for empty stack is found
*
* Return: Nothing
*/
void error_pop_opcode(unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't pop an empty stack\n");
	_eput(FLUSH_BUFFER);
	exit(EXIT_FAILURE);
}
/**
* error_swap_opcode - Check error for swaping too short stack
* @stack_head: Pointer to the head node of the stack
* @line_number: Line number within monty bytecode file where
* swap opcode for too short stack is found
*
* Return: Nothing
*/
void error_swap_opcode(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't swap, stack too short\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	exit(EXIT_FAILURE);
}
/**
* error_add_opcode - Check error for adding too short stack
* @stack_head: Pointer to the head node of the stack struct
* @line_number: Line number within monty bytecode file where
* add opcode for too short stack is called
*
* Return: Nothing
*/
void error_add_opcode(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't add, stack too short\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	exit(EXIT_FAILURE);
}
