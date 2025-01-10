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
		if ((int)size_read == -1 || str_comparing(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
		if (check_empty(buffer) == 0)
		{
			free(buffer);
			continue;
		}
		arguments = transform_to_array(buffer, size_read);
		if (str_comparing(arguments[0], "env") == 0)
		{
			_env(buffer, arguments);
			continue;
		}
		command = _which(arguments[0]);
		if (command == NULL)
			fprintf(stderr, "%s\n", strerror(errno));
		if (command != NULL)
		{
			child_process = fork();
			if (child_process == 0 && execve(command, arguments, environ) == -1)
				fprintf(stderr, "%s\n", strerror(errno));
			wait(&status);
		}
		free_as_a_bird(command, buffer, arguments);
	}
}
