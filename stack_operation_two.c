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
/**
* stack_sub - Substracts the top element of the stack from the second
* top element of the stack
* @stack: Pointer to the head node of the stack struct
* @line_number: Line where sub opcode is located
*
* Return: Nothing
*/
void stack_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sub;

	if (!*stack || !(*stack)->next)
		error_sub_opcode(stack, line_number);
	sub = ((*stack)->next->n) - ((*stack)->n);
	(*stack)->next->n = sub;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	free_memory(&temp);
}
/**
* stack_div - Divides the second top element of the stack by the top
* element of the stack
* @stack: Pointer to the head node of the stack
* @line_number: The line where div opcode is located
*
* Return: Nothing
*/
void stack_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int div;

	if (!*stack || !(*stack)->next)
		error_div_opcode(stack, line_number);
	if ((*stack)->n == 0)
		error_div_by_zero(stack, line_number);
	div = ((*stack)->next->n) / ((*stack)->n);
	(*stack)->next->n = div;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	free_memory(&temp);
}
