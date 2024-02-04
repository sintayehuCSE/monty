#include "monty.h"
/**
* error_div_by_zero - Checks for an attempt to divide int by zero
* @stack_head: Pointer to the head of the stack struct
* @line_number: Line number where div opcode for div by zero is found
*
* Return: Nothing
*/
void error_div_by_zero(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": division by zero\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* error_mul_opcode - Handles error for mul opcode
* @stack_head: Pointer to the head node of the stack struct
* @line_number: The line number where mul opcode for too short stack is found
*
* Return: Nothing
*/
void error_mul_opcode(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't mul, stack too short\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* error_mod_opcode - Handles error for mod opcode
* @stack_head: Pointer to the head node of the stack struct
* @line_number: The line number where mod opcode for too short stack is found
*
* Return: Nothing
*/
void error_mod_opcode(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't mod, stack too short\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* error_pchar_opcode - Check error for pcharing empty stack
* @line_number: Line number within monty bytecode file where
* pchar opcode for empty stack is found
*
* Return: Nothing
*/
void error_pchar_opcode(unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't pchar, stack empty\n");
	_eput(FLUSH_BUFFER);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* error_ascii_overflow - Check error for ascii value out of range
* @stack_head: Pointer to the head node of the stack struct
* @line_number: Line number within monty bytecode file where
* pchar opcode for out of range ascii value of character is found
*
* Return: Nothing
*/
void error_ascii_overflow(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't pchar, value out of range\n");
	_eput(FLUSH_BUFFER);
	fclose(file_ptr);
	free_memory(stack_head);
	exit(EXIT_FAILURE);
}

