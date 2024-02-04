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
	int is_negative = 0;

	if (num < 0)
	{
		num *= -1;
		is_negative = 1;
	}
	*str = '\0';
	if (!num)
	{
		str--;
		*str = '0';
		*idx = *idx - 1;
	}
	while (num)
	{
		str--;
		*str = (num % 10) + '0';
		*idx = *idx - 1;
		num = num / 10;
	}
	if (is_negative)
	{
		*idx = *idx - 1;
		str--;
		*str = '-';
	}
}
/**
* len - Calculate number of byte/bytes in a string
* @str: The string whose byte number is to be calculated
*
* Return: The number of bytes in a string
*/
int len(char *str)
{
	int ln = 0;

	while (*str)
	{
		ln++;
		str++;
	}
	return (ln);
}
/**
* parse_arg_str - Parse for non digit character in argument passed to
* stack_push and other stack functions as atoi may be undefined for this case
* @str: The argument string to be parsed
* @stack_head: Pointer to the head of a stack
* @line_number: Line number of operation with invalid argument
*
* Return: Nothing
*/
void parse_arg_str(char *str, stack_t **stack_head, unsigned int line_number)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
			error_push_opcode(stack_head, line_number);
		else
			str++;
	}
}
/**
* check_comment - Check if a line is comment line or not
* @str: The line's string content
*
* Return: 1 if true 0 otherwise
*/
ssize_t check_comment(const char *str)
{
	while (*str)
	{
		if (*str != 32 && *str != 35)
			return (0);
		else if (*str == 32)
			str++;
		else if (*str == 35)
			return (1);
	}
	return (0);
}
