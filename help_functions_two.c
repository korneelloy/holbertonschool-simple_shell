#include "main.h"

/**
 * _which - return acces path in PATH variable of command
 * @typed_path: the path or command typed in by user
 *
 * Return: access path
 */

char *_which(char *typed_path)
{
	int i, counter = 1;
	char *path = NULL;
	char **paths_array = NULL;
	char *single_path = NULL;
	struct stat st;
	char *this_path;

	if (stat(typed_path, &st) == 0)
		return (typed_path);

	path = _getenv("PATH");

	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
			counter++;
	}
	paths_array = malloc(counter * sizeof(char *));
	single_path = strtok(path, ":");
	for (i = 0; i < counter; i++)
	{
		paths_array[i] = single_path;
		single_path = strtok(NULL, ":");
	}

	for (i = 0; i < counter; i++)
	{
		this_path = malloc(strlen(paths_array[i]) + strlen(typed_path) + 1);
		this_path = strcpy(this_path, paths_array[i]);
		this_path = strcat(this_path, "/");
		this_path = strcat(this_path, typed_path);
		if (stat(this_path, &st) == 0)
			return (this_path);
	}
	free(this_path);
	free(paths_array);
	return (NULL);

}

/**
 * check_empty - checks if string is empty
 * @buffer: string
 *
 * Return: 0 if empty, 1 if not
 */

int check_empty(char *buffer)
{
	 long unsigned int i;

	if (buffer == NULL)
		return (0);
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n')
			return (1);
	}
	return (0);
}
