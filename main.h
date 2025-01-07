#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>


/**
 * struct path_struct - strucrue de singly liked list of paths
 * @path: the path
 * @next: the next path
 */

typedef struct path_struct
{
	char *path;
	struct path_struct *next;
} path_t;

extern char **environ;

int str_comparing(char *buffer, char *comparison);
int counting_words(char *sentence);
int free_memory(char **arguments);
char *_which(char *argv);
void simple_shell(void);
char **transform_to_array(char *buffer, int size_read);
char *_getenv(const char *identifier);
int check_empty(char *buffer);
void free_path(char *path, char **paths_array);
int count_paths(char *path);

#endif
