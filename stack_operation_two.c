#include "monty.h"
/**
* stack_add - Adds the top two elements of the stack
* @stack: Pointer to the head of the stack
* @line_number: The line within monty bytecode file that
* contain the stack add opcode
*
* Return: Nothing
*/
void stack_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (!*stack || !(*stack)->next)
		error_add_opcode(stack, line_number);
	sum = ((*stack)->n) + ((*stack)->next->n);
	(*stack)->next->n = sum;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	free_memory(&temp);
}
/**
* stack_nop - The stack nop function for doing nothing
* @stack: Pointer to head node of stack struct
* @line_number: Line where nop opcode is found within the file
*
* Return: Nothing
*/
void stack_nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
}
