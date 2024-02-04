#include "monty.h"
/**
* stack_stack_mode - Sets the operation mode of the stack_s struct to normal
* which is the default behavior of this program
* @stack: Pointer to the head node of the stack
* @line_number: The line where stack opcode is located in monty bytecode file
*
* Return: Nothing
*/
void stack_stack_mode(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
}
/**
* stack_queue_mode - Sets the operation mode of the stack_s struct
* to queue mode
* @stack: Pointer to the head node of the stack_s struct
* @line_number: The line where queue opcode is located in monty bytecode file
*
* Return: Nothing
*/
void stack_queue_mode(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
	mode = 2;
}
