#include "monty.h"
unsigned int line_number = 1;
/**
* main - Entry to the monty bytecode interpreter
* @ac: Count of cmd argument to the interpreter
* @argv: Pointer to the cmd argument of the interpreter
*
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int ac, char **argv)
{
	FILE *file_ptr = NULL;

	if (ac != 2)
	{
		_eputs("USAGE: monty file\n");
		_eput(FLUSH_BUFFER);
		exit(EXIT_FAILURE);
	}
	else
	{
		file_ptr = fopen(argv[1], "r");
		check_file_open_error(file_ptr, argv[1]);
	}
	return (0);
}
