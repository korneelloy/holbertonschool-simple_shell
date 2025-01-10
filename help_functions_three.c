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

/**
 * check_special - handle special characters
 * @buffer : what the user typed
 */

void check_special(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '"' || buffer[i] == '\'' || buffer[i] == '`' || buffer[i] == '\\' 
		|| buffer[i] == '*' || buffer[i] == '&' || buffer[i] == '#') 
		{
			printf("code to finish\n");
		}
	}
}
