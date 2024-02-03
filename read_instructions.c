#include "monty.h"
/**
* read_instructions - read each instruction from a monty bytecode file
* @line_number: The instruction line number
* @stack_head: Head node of the stack struct
*
* Return: Nothing
*/
void read_instructions(unsigned int *line_number, stack_t **stack_head)
{
	char *line_ptr = NULL;
	long check_off_set;
	long end_of_file;

	end_of_file = capture_end_of_file();
	if (!end_of_file)
		exit(EXIT_FAILURE);
	if (read_line(&line_ptr, line_number, &check_off_set, stack_head))
	{
		while (check_off_set < end_of_file)
		{
			read_line(&line_ptr, line_number, &check_off_set, stack_head);
		}
	}
}
/**
* capture_end_of_file - Set factor for determining exhaustion of all
* instruction within the monty bytecode file
*
* Return: Nothing
*/
long capture_end_of_file(void)
{
	long end_of_file;

	if (fseek(file_ptr, 0L, SEEK_END) == -1)
	{
		_eputs("Something went wrong@func capture_end_of_file");
		_eputs(", please re-run your interpreter\n");
		_eput(FLUSH_BUFFER);
		exit(EXIT_FAILURE);
	}
	end_of_file = ftell(file_ptr);
	rewind(file_ptr);/**...Same as fseek(file_ptr, 0L, SEEK_SET); ...*/
	return (end_of_file);
}
/**
* read_line - Read a single line from monty bytecode file at a time
* @line_buffer: A buffer to hold line content
* @line_number: The instruction line number
* @check_off_set: Current position in the monty bytecode file
* @stack_head: Pointer to the head node of stack struct
*
* Return: The number of bytes on a single line and it can't be zero.
*/
ssize_t read_line(char **line_buffer, unsigned int *line_number,
		  long *check_off_set, stack_t **stack_head)
{
	ssize_t i = 0;
	char eol[1] = {'\n'};
	char check_buf[1];
	char read_buffer[READ_BUFFER];

	/**Read in to a read_buffer untill you hit line feed('\n')*/
	fread(check_buf, 1, 1, file_ptr);
	read_buffer[i] = check_buf[0];
	while (eol[0] != read_buffer[i])
	{
		fread(check_buf, 1, 1, file_ptr);
		i++;
		read_buffer[i] = check_buf[0];
	}
	/** Note read_buffer[i] == '\n' at the end of this while loop*/
	read_buffer[i + 1] = '\0';
	*check_off_set = ftell(file_ptr);
	*line_number = *line_number + 1;
	*line_buffer = read_buffer;
	extract_opcode(line_buffer, line_number, stack_head);
	return (i + 1);
}
/**
* extract_opcode - Extracts opcode on a single line of the monty bytecode
* file and call the corresponding opcode execution function
* @line_buffer: A buffer containing a line content
* @line_number: The number of line being read
* @stack_head: Pointer to the head of the stack
*
* Return: Nothing
*/
int extract_opcode(char **line_buffer, unsigned int *line_number,
		   stack_t **stack_head)
{
	int i = 0;
	char *op_code = NULL;
	instruction_t av_op[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{NULL, NULL}
	};

	op_code = strtok(*line_buffer, " \n\t");
	if (!op_code)/**Check for empty or space full line + nop*/
		return (1);
	while (av_op[i].opcode)
	{
		if (strcmp(av_op[i].opcode, op_code) == 0)
		{
			av_op[i].f(stack_head, *line_number);
			return (1);
		}
		i++;
	}
	error_invalid_opcode(*line_number, op_code, stack_head);
	return (0);

}
