#include "main.h"

/**
 * simple_shell - an application imitating shell
 */

void simple_shell(void)
{
	size_t size_read, size_to_read;
	char *buffer, *command, **arguments;
	int status;
	pid_t child_process = 0;

	while (1)
	{
		size_read = 0, size_to_read = 0;
		buffer = NULL, arguments = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		size_read = getline(&buffer, &size_to_read, stdin);
		if ((int)size_read == -1)
			exit(0);
		if (check_empty(buffer) == 0)
			continue;
		if (str_comparing(buffer, "exit") == 0)
		{
			free_memory(arguments);
			exit(0);
		}
		arguments = transform_to_array(buffer, size_read);
		command = _which(arguments[0]);
		if (command == NULL)
			printf("No such file or directory\n");
		if (command != NULL)
		{
			child_process = fork();
			if (child_process == 0)
				if (execve(command, arguments, environ) == -1)
					printf("No such file or directory\n");
			wait(&status);
		}
		free_memory(arguments);
	}
}
