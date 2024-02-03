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
