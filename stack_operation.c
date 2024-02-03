#include "monty.h"
/**
* stack_push - Push an integer on to the top of stack
* @stack: Pointer to the head node of the stack
* @line_number: Line number of monty bytecode containing
* this particuar instruction.
*
* Return: Nothing
*/
void stack_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");
	int arg_int = 0, is_negative = 0;

	if (!arg)
		error_push_opcode(stack, line_number);
	if (arg[0] == '-' && len(arg) >= 2)
	{
		arg = &arg[1];
		is_negative = 1;
	}
	parse_arg_str(arg, stack, line_number);
	if (arg[0] != '0')
		arg_int = atoi(arg);
	if (is_negative)
		arg_int *= -1;
	add_node_top(stack, arg_int);
}
/**
* stack_pall - Print all the values of stack, starting from top
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
/**
* stack_pint - Prints the value at the top of the stack
* @stack: Pointer to the head node of stack
* @line_number: Line number of monty bytecode file where
* pint opcode is located
*
* Return: Nothing
*/
void stack_pint(stack_t **stack, unsigned int line_number)
{
	int index = WRITE_BUFFER - 1;
	char buf[WRITE_BUFFER];

	if (!*stack)
		error_pint_opcode(line_number);
	convert_number_to_str((*stack)->n, &buf[index], &index);
	_puts(&buf[index]);
	_puts("\n");
	_put(FLUSH_BUFFER);
}
