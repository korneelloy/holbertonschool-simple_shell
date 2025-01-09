#include "main.h"
/**
* free_as_a_bird - frees memory
* @commannd: the command
* @buffer: adds the buffer
* @arguments: the arguments

* Return: Nothing
*/

void free_as_a_bird(char *command, char *buffer, char **arguments)
{
	free(command);
	free(buffer);
	free_memory(arguments);
}
