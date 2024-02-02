#include "monty.h"
/**
* add_node_top - Add a new node on top of the stack
* @stack_head: The head node of the stack structure
* @int_arg: The integer to add on top of stack
*
* Return: The new node/top of stack
*/
stack_t *add_node_top(stack_t **stack_head, int int_arg)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		malloc_error(stack_head);
	if (!*stack_head)
	{
		new_node->n = int_arg;
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack_head = new_node;
		return (new_node);
	}
	new_node->n = int_arg;
	new_node->prev = NULL;
	new_node->next = (*stack_head)->prev;
	*stack_head = new_node;
	return (new_node);
}
