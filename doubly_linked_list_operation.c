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

	new_node = (stack_t *)malloc(sizeof(stack_t));
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
	new_node->next = *stack_head;
	(*stack_head)->prev = new_node;
	*stack_head = new_node;
	return (new_node);
}
/**
* add_node_end - Add new node to the end of a stack_s stract
* @stack_head: Pointer to the head node of stack_s struct
* @int_arg: The data to add to the end of the stack_s struct
*
* Return: The new node/end of stack_s struct
*/
stack_t *add_node_end(stack_t **stack_head, int int_arg)
{
	stack_t *new_node, *head;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
		malloc_error(stack_head);
	head = *stack_head;
	if (!head)
	{
		new_node->n = int_arg;
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack_head = new_node;
		return (new_node);
	}
	while (head->next)
		head = head->next;
	new_node->n = int_arg;
	new_node->next = NULL;
	new_node->prev = head;
	head->next = new_node;
	return (new_node);
}
