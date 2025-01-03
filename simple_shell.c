#include "main.h"

/**
 * simple_shell - an application imitating shell
 */

void simple_shell(void)
{
	size_t size_read, size_to_read;
	char *buffer, **arguments;
	extern char **environ;
	int status;
	pid_t child_process = 0;

	while (1)
	{
		size_read = 0, size_to_read = 0;
		buffer = NULL, arguments = NULL;
		printf("$ ");
		size_read = getline(&buffer, &size_to_read, stdin);
		if ((int)size_read == -1)
		{
			if (buffer)
				free(buffer);
			printf("\nlogout\n");
			exit(0);
		}
		if ((int)size_read == 1)
			continue;
		if (str_comparing(buffer, "exit") == 0)
		{
			free_memory(arguments, buffer);
			exit(0);
		}
		arguments = transform_to_array(buffer, size_read);
		child_process = fork();
		if (child_process == 0)
		{
			if (execve(arguments[0], arguments, environ) == -1)
			{
				printf("No such file or directory\n");
				free_memory(arguments, buffer);
			}
		}
		wait(&status);
		free_memory(arguments, buffer);
	}
}
