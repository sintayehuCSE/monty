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
