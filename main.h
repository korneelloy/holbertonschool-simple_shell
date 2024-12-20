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

int str_comparing(char *buffer, char *comparison);
int counting_words(char *sentence);
int free_memory(char **arguments, char *buffer);
void get_path_linked_list(void);
void get_path_array(void);
int _which(int argc, char **argv);
void simple_shell(void);
char **transform_to_array(char *buffer, int size_read);
char *_getenv(const char *identifier);

#endif
