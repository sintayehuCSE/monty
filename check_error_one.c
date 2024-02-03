#include "monty.h"
/**
* check_file_open_error - Check if a monty bytecode file open attempt fails
* @filename: Monty bytecode filename
*
* Return: Nothing
*/
void check_file_open_error(const char *filename)
{
	if (!file_ptr)
	{
		_eputs("Error: Can't open file ");
		_eputs(filename);
		_eputs("\n");
		_eput(FLUSH_BUFFER);
		exit(EXIT_FAILURE);
	}
}
/**
* error_invalid_opcode - handle invalid opcode error
* @line_number: Line number within monty bytecode file
* where the invalid opcode located
* @op_code: The invalid opcode
* @stack_head: The head of stack node structure
*
* Return: Nothing
*/
void error_invalid_opcode(unsigned int line_number, char *op_code,
	stack_t **stack_head)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": unknown instruction ");
	_eputs(op_code);
	_eputs("\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* error_push_opcode - Handle error for argument less push opcode
* @stack_head: The head node of stack structure
* @line_number: The line within monty bytecod file where push
* opcode with no arg is located
*
* Return: Nothing
*/
void error_push_opcode(stack_t **stack_head, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": usage: push integer\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* malloc_error - Handle malloc failure
* @stack_head: The head node of stack structure
*
* Return: Nothing
*/
void malloc_error(stack_t **stack_head)
{
	_eputs("Error: malloc failed\n");
	_eput(FLUSH_BUFFER);
	free_memory(stack_head);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}
/**
* error_pint_opcode - Check error for pinting empty stack
* @line_number: Line number within monty bytecode file where
* pint opcode for empty stack is found
*
* Return: Nothing
*/
void error_pint_opcode(unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	line_number = (int)line_number;
	convert_number_to_str(line_number, &buf[index], &index);
	_eputs("L");
	_eputs(&buf[index]);
	_eputs(": can't pint, stack empty\n");
	_eput(FLUSH_BUFFER);
	exit(EXIT_FAILURE);
}
