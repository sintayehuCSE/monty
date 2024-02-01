#include "monty.h"
/**
* push_stack - Push an integer on to the top of stack
* @stack: Pointer to the head node of the stack
* @line_number: Line number of monty bytecode containing
* this particuar instruction.
*
* Return: Nothing
*/
void stack_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");
	int arg_int;

	if (!arg)
		error_push_opcode(stack, line_number);
	arg_int = atoi(arg);
	if (!arg_int && arg[0] != '0')
		error_push_opcode(stack, line_number);
	/**To be continued from here*/
	add_node_top(stack, arg_int);
}
/**
* pall_stack - Print all the values of stack, starting from top
* @stack: Pointer to the head node or top node of the stack
* @line_number: Line number indicating position of pall operation
* within the monty bytecode file
*
* Return: Nothing
*/
void stack_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	UNUSED(line_number);
	if (head)
	{
		if (head->next)
		{
			while (head)
			{
				temp = head->next;
				convert_number_to_str(head->n, &buf[index], &index);
				_puts(&buf[index]);
				_puts("\n");
				_put(FLUSH_BUFFER);
				head = temp;
			}
		}
		else
		{
			convert_number_to_str(head->n, &buf[index], &index);
			_puts(&buf[index]);
			_puts("\n");
			_put(FLUSH_BUFFER);
		}
	}
}
