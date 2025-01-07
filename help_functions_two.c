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
	char *path = NULL, **paths_array = NULL, *single_path = NULL, *this_path;
	struct stat st;

	if (stat(typed_path, &st) == 0)
	{
		this_path = malloc(strlen(typed_path) + 1);
		if (this_path == NULL)
			return (NULL);
		strcpy(this_path, typed_path);
		return (this_path);
	}
	path = _getenv("PATH");
	counter = count_paths(path);
	paths_array = malloc(counter * sizeof(char *));
	if (paths_array == NULL)
		return (NULL);
	single_path = strtok(path, ":");
	for (i = 0; i < counter; i++)
	{
		paths_array[i] = single_path;
		single_path = strtok(NULL, ":");
	}
	for (i = 0; i < counter; i++)
	{
		this_path = malloc(strlen(paths_array[i]) + strlen(typed_path) + 2);
		if (this_path == NULL)
			return (NULL);
		strcpy(this_path, paths_array[i]);
		strcat(strcat(this_path, "/"), typed_path);
		if (stat(this_path, &st) == 0)
		{
			free_path(path, paths_array);
			return (this_path);
		}
		free(this_path);
	}
	free_path(path, paths_array);
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
	unsigned long int i;

	if (buffer == NULL)
		return (0);
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n')
			return (1);
	}
	return (0);
}

/**
 * free_path - frees the memeory allocated for the path
 * @path: the path
 * @path_array: the array of paths
 *
 * Return: void
 */

void free_path(char *path, char **paths_array)
{
	free(paths_array);
	free(path);
}

/**
 * count_paths - counth the numebr of elements in the path
 * @path: the path
 *
 * Return: the number of elements
 */

int count_paths(char *path)
{
	int counter = 0, i = 0;

	for (i = 0; path[i] != '\0'; i++)
		if (path[i] == ':')
			counter++;
	return (counter);
}
