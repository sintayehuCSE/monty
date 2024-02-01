#include "monty.h"
/**
* free_memory - Deallocate memory of the stack
* @stack_head: Pointer to the head of the stack node
*
* Return: 1 on success
*/
int free_memory(stack_t **stack_head)
{
	stack_t *temp = NULL;
	stack_t *head = *stack_head;

	if (!head)
		return (1);
	if (!head->next)
	{
		free(head);
		return (1);
	}
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	return (1);
}
/**
* convert_number_to_str - Convert number to a str of its char value
* @num: Number to be converted
* @str: Pointer to buffer that store the number character
* @idx: Pointer to the index of the buffer
*
* Return: Nothing
*/
void convert_number_to_str(int num, char *str, int *idx)
{
	*str = '\0';
	while (num)
	{
		str--;
		*str = (num % 10) + '0';
		*idx = *idx - 1;
		num = num / 10;
	}
}
