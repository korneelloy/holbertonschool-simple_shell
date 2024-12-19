#include "main.h"

/**
 * _which - return acces path in PATH variable of command
 * @argc: nb of arguments
 * @argv: arguments
 *
 * Return: access path
 */

int _which(int argc, char **argv)
{
	int i, j = 1, counter = 1;
	char *path = getenv("PATH");
	char **paths_array = NULL;
	char *single_path = NULL;
	struct stat st;
	char *this_path;
	(void)argc;

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
	while (argv[j])
	{
		for (i = 0; i < counter; i++)
		{
			this_path = malloc(strlen(paths_array[i]) + strlen(argv[j]) + 1);
			this_path = strcpy(this_path, paths_array[i]);
			this_path = strcat(this_path, "/");
			this_path = strcat(this_path, argv[j]);
			if (stat(this_path, &st) == 0)
			{
				printf("%s\n", this_path);
				free(this_path);
				break;
			}
			free(this_path);
		}
		j++;
	}
	free(paths_array);
	return (0);
}
