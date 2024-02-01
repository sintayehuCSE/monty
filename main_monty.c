#include "monty.h"
FILE *file_ptr = NULL;
/**
* main - Entry to the monty bytecode interpreter
* @ac: Count of cmd argument to the interpreter
* @argv: Pointer to the cmd argument of the interpreter
*
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int ac, char **argv)
{
	unsigned int line_number = 0;
	stack_t *stack_head = NULL;

	if (ac != 2)
	{
		_eputs("USAGE: monty file\n");
		_eput(FLUSH_BUFFER);
		exit(EXIT_FAILURE);
	}
	else
	{
		file_ptr = fopen(argv[1], "r");
		check_file_open_error(argv[1]);
		read_instructions(&line_number, &stack_head);
	}
	fclose(file_ptr);
	free_memory(&stack_head);
	return (EXIT_SUCCESS);
}
