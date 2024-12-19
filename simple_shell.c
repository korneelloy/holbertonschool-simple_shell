#include "main.h"

/**
 * simple_shell - an application imitating shell
 *
 * Return: 0 on succes
 */

int simple_shell(void)
{
size_t size_read, size_to_read;
	char *buffer, *argument, **arguments, *envp[] = { NULL };
	int i, status, number_of_args = 0;
	pid_t child_process = 0;

	while (1)
	{
		size_read = 0, size_to_read = 0;
		buffer = NULL, argument = NULL, arguments = NULL;
		printf("$ ");
		size_read = getline(&buffer, &size_to_read, stdin);
		if ((int)size_read == -1)
			return (-1);
		if (str_comparing(buffer) == 0)
		{
			free_memory(arguments, i, buffer);
			kill(child_process, SIGTERM);
			break;
		}
		number_of_args = counting_words(buffer);
		if (buffer[size_read - 1] == '\n')
			buffer[size_read - 1] = '\0';
		argument = strtok(buffer, " ");
		arguments = malloc((number_of_args + 1) * sizeof(char *));
		if (arguments == NULL)
			continue;
		for (i = 0; argument != NULL; i++)
		{
			arguments[i] = strdup(argument);
			argument = strtok(NULL, " ");
		}
		arguments[i] = NULL;
		child_process = fork();
		if (child_process == 0)
			if (execve(arguments[0], arguments, envp) == -1)
				printf("No such file or directory\n");
		wait(&status);
		free_memory(arguments, i, buffer);
	}
	return (0);
}
