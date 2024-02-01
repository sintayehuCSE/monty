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
	size_t line_size;
	long check_off_set;
	long eof;

	capture_end_of_file(&eof);
	if (read_line(&line_ptr, &line_size, line_number, &check_off_set, stack_head))
	{
		while (check_off_set != eof)
		{
			read_line(&line_ptr, &line_size, line_number, &check_off_set, stack_head);
		}
	}
}
/**
* capture_end_of_file - Set factor for determining exhaustion of all
* instruction within the monty bytecode file
* @eof: Pointer to Off_set value for end of file
*
* Return: Nothing
*/
void capture_end_of_file(long *eof)
{
	fseek(file_ptr, 0L, SEEK_END);
	*eof = ftell(file_ptr);
	fseek(file_ptr, 0L, SEEK_SET);
}
/**
* read_line - Read a single line from monty bytecode file at a time
* @line_buffer: A buffer to hold line content
* @buffer_size: Size of the line_buffer
* @line_number: The instruction line number
* @check_off_set: Current position in the monty bytecode file
* @stack_head: Pointer to the head node of stack struct
*
* Return: The number of instruction bytes on a line
*/
ssize_t read_line(char **line_buffer, size_t *buffer_size,
		  unsigned int *line_number, long *check_off_set, stack_t **stack_head)
{
	ssize_t read_byte = 0, i = 0;
	static long off_set;
	char eol[1] = {'\n'};
	char read_buffer[READ_BUFFER];
	int not_empty = 1;

	if (!off_set && not_empty && is_empty(&off_set))
		return (read_byte);
	if (not_empty)
	{
		fseek(file_ptr, 0L, SEEK_SET);
		off_set = ftell(file_ptr);
		not_empty = 0;
	}
	if (off_set)
		fseek(file_ptr, off_set, SEEK_SET);
	/**Read in to a buffer untill you hit line feed*/
	fread(read_buffer, 1, 1, file_ptr);
	while (eol[0] != read_buffer[i])
	{
		fread(read_buffer, 1, 1, file_ptr);
		i++;
	}
	off_set = i + 1;
	*check_off_set = off_set;
	*line_number = *line_number + 1;
	*line_buffer = read_buffer;
	*buffer_size = (size_t)i + 1;
	extract_opcode(line_buffer, line_number, stack_head);
	return (i);
}
/**
* is_empty - Check if a monty byte code file is empty file or not
* @off_set: Pointer to current off_set of the file
*
* Return: the file status. if true 1 otherwise 0
*/
int is_empty(long *off_set)
{
	fseek(file_ptr, 0L, SEEK_END);
	*off_set = ftell(file_ptr);
	if (!*off_set)
		return (1);
	return (0);
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
		{NULL, NULL}
	};

	op_code = strtok(*line_buffer, " \n\t");
	if (!op_code)/**Check for empty or space full line*/
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
