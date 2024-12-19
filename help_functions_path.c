#include "main.h"

/**
 * get_path_array - gets the path and print it in an array
 */

void get_path_array()
{
	int i;
	int j = 1;
	int counter = 1;
	char *path = getenv("PATH");
	char **paths_array = NULL;
	char *single_path= NULL;
	char *this_path;
	int last_index;

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
	printf("%d\n", counter);

	for (i = 0; i < counter; i++)
		printf("%s\n", paths_array[i]);
	

	free(paths_array);

}

/**
 * get_path_linked_list - gets the path and print it in a linked list
 */

void get_path_linked_list()
{
	int i;
	int j = 1;
	int counter = 1;
	char *path = getenv("PATH");
	char *single_path= NULL;
	char *this_path;
	int last_index;
	path_t *root;
	path_t *current;
	path_t *printing;

	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
			counter++;
	}

	single_path = strtok(path, ":");

	root = malloc(sizeof(path_t));
	if (root == NULL)
		return;

	root->path = strdup(single_path);
	if (root->path == NULL)
	{
		free(root);
		return;
	}

	current = root;

	for (i = 0; i < (counter -2) ; i++)
	{
		current->next = malloc(sizeof(path_t));
		current = current->next;
		single_path = strtok(NULL, ":");
		current->path = strdup(single_path);
	}

	single_path = strtok(NULL, ":");
	current->path = strdup(single_path);
	current->next = NULL;

	printing = root;
 	while(printing != NULL)
    {
        printf("%s\n", printing->path);
		printing = printing->next;
    }

}
