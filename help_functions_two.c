#include "main.h"

/**
 * get_path_array - gets the path and print it in an array
 */

void get_path_array(void)
{
	int i;
	int counter = 1;
	char *path = _getenv("PATH");
	char **paths_array = NULL;
	char *single_path = NULL;

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
		printf("%s\n", paths_array[i]);
	free(paths_array);
}

/**
 * get_path_linked_list - gets the path and print it in a linked list
 */

void get_path_linked_list(void)
{
	int i, counter = 1;
	char *path = _getenv("PATH");
	char *single_path = NULL;
	path_t *root, *current, *printing;

	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
			counter++;
	}
	single_path = strtok(path, ":");
	root = malloc(sizeof(path_t));
	if (root == NULL)
		return;
	root->path = _strdup(single_path);
	if (root->path == NULL)
	{
		free(root);
		return;
	}
	current = root;
	for (i = 0; i < (counter - 2) ; i++)
	{
		current->next = malloc(sizeof(path_t));
		current = current->next;
		single_path = strtok(NULL, ":");
		current->path = _strdup(single_path);
	}
	single_path = strtok(NULL, ":");
	current->path = _strdup(single_path);
	current->next = NULL;
	printing = root;
	while (printing != NULL)
	{
		printf("%s\n", printing->path);
		printing = printing->next;
	}
}


/**
 * _strdup - allocates memory and creates a copy of the string
 * @words: the string to duplicate
 *
 * Return: pointer to new string
 */

char *_strdup(char *words)
{
	int len, i;
	char *new_word;

	for (len = 0; words[len] != '\0'; len++)
		continue;

	new_word = malloc((len + 1) * sizeof(char));

	for (i = 0; i < len; i++)
		words[i] = new_word[i];

	return (new_word);
}
