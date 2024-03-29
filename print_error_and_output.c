#include "monty.h"
/**
* _eputs - Parse the error string and call for its storage in the error_buffer
* @str: The error string
*
* Return: Nothing
*/
void _eputs(const char *str)
{
	while (*str)
	{
		_eput(*str);
		str++;
	}
}
/**
* _eput - Store the error character into error's buffer and output it to stderr
* @chr: The error character
*
* Return: Nothing
*/
void _eput(const char chr)
{
	static char error_buffer[WRITE_BUFFER];
	static size_t i;

	if (chr == FLUSH_BUFFER || i >= WRITE_BUFFER)
	{
		fwrite(error_buffer, 1, i, stderr);
		i = 0;
	}
	else
	{
		error_buffer[i] = chr;
		i++;
	}
}
/**
* _puts - Parse the output string and call for its storage in output bufferr
* @str: The output string
*
* Return: Nothing
*/
void _puts(const char *str)
{
	while (*str)
	{
		_put(*str);
		str++;
	}
}
/**
* _put - store the output str in to output buffer and prints it
* @chr: The output character
*
* Return: Nothing
*/
void _put(const char chr)
{
	static char output_buffer[WRITE_BUFFER];
	static size_t i;

	if (chr == FLUSH_BUFFER || i >= WRITE_BUFFER)
	{
		fwrite(output_buffer, 1, i, stdout);
		i = 0;
	}
	else
	{
		output_buffer[i] = chr;
		i++;
	}
}
