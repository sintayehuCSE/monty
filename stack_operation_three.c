#include "monty.h"
/**
* stack_mod - Computes the remainderr of the second top element of the stack
* by the top element of the stack
* @stack: Pointer to the head node of the stack struct
* @line_number: The line where mod opcode is located
*
* Return: Nothing
*/
void stack_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mod;

	if (!*stack || !(*stack)->next)
		error_mod_opcode(stack, line_number);
	if ((*stack)->n == 0)
		error_div_by_zero(stack, line_number);
	mod = ((*stack)->next->n) % ((*stack)->n);
	(*stack)->next->n = mod;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	free_memory(&temp);
}
/**
* stack_pchar - Prints the char at the top of the stack
* @stack: Pointer to the head node of the stack
* @line_number: The line where pchar opcode is located
*
* Return: Nothing
*/
void stack_pchar(stack_t **stack, unsigned int line_number)
{
	char top;

	if (!*stack)
		error_pchar_opcode(line_number);
	if ((*stack)->n < 32 || (*stack)->n > 126)
		error_ascii_overflow(stack, line_number);
	top = (*stack)->n;
	_put(top);
	_put(10);
	_put(FLUSH_BUFFER);
}
/**
* stack_pstr - Prints the string starting at the top of the stack
* @stack: Pointer to the head node of stack struct
* @line_number: Line number where pstr opcode is located
*
* Return: Nothing
*/
void stack_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	UNUSED(line_number);
	if (!head)
	{
		_put(10);
		_put(FLUSH_BUFFER);
	}
	else
	{
		while (head)
		{
			if (head->n > 31 && head->n < 127)
			{
				_put(head->n);
				_put(FLUSH_BUFFER);
				head = head->next;
			}
			else
			{
				break;
			}
		}
		/**if ((*stack)->n > 31 && (*stack)->n < 127)*/
		_put(10);
		_put(FLUSH_BUFFER);
	}
}
