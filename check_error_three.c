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
	exit(EXIT_FAILURE);
}
