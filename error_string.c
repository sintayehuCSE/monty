#include "monty.h"
/**
* _eputs - Parse the error string and call for its storage in the error_buffer
* @str: The error string
*
* Return: Nothing
*/
void _eputs(char *str)
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
void _eput(char chr)
{
    static char error_buffer[WRITE_BUFFER];
    static size_t i = 0;

    if (chr == FLUSH_BUFFER || i >= WRITE_BUFFER)
    {
        write(STDERR_FILENO, error_buffer, i);
        i = 0;
    }
    else
    {
        error_buffer[i] = chr;
        i++;
    }
}
