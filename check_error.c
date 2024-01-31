#include "monty.h"
/**
* check_file_open_error - Check if a monty bytecode file open attempt fails
* @file_ptr: A file pointer to the opened file stream
* @filename: Monty bytecode filename
*
* Return: Nothing
*/
void check_file_open_error(FILE *file_ptr, const char *filename)
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
