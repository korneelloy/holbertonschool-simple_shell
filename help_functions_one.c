#include "main.h"

/**
 * str_comparing - comparing given string with word "exit"
 * this function ignores any whitespaces that might be included
 * before in the given string
 * adn anything that might come after the given word
 *
 * @buffer: pointer to givven string
 * @comparison: pointer to string you want to compare against
 *
 * Return: 0 if strings correspond, -1 if they don't
 */

int str_comparing(char *buffer, char *comparison)
{
	int i = 0, j = 0, len = 0;
	char last;

	if (buffer == NULL || comparison == NULL)
		return (-1);

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			break;
	}

	len = strlen(comparison);

	for (j = 0; j < len; j++)
	{
		if (buffer[i] != comparison[j])
			return (-1);
		i++;
	}

	last = buffer[i];

	if (last == ' ' || last == '\0' || last == '\n')
	{
		return (0);
	}

	return (-1);
}

/**
 * counting_words - count the number of words in a sentence
 * @sentence : pointer to the sentence
 *
 * Return: the number of words
 */

int counting_words(char *sentence)
{
	int i;
	int nb_of_words = 0;

	if (sentence == NULL || sentence[0] == '\0')
		return (0);
	for (i = 0; sentence[i] != '\n'; i++)
	{
		if (sentence[i] != ' ' && nb_of_words == 0)
			nb_of_words++;
		else if (sentence[i] == ' ' && sentence[i + 1] != '\0'
		&& sentence[i + 1] != ' ' && sentence[i + 1] != '\n')
			nb_of_words++;
	}
	return (nb_of_words);
}

/**
 * free_memory - freeing the memory that was allocated
 * @arguments: double pointer to list of arguments
 *
 * Return:0 on succes
 */

int free_memory(char **arguments)
{
	int j = 0;

	if (arguments)
	{
		while (arguments[j] != NULL)
		{
			free(arguments[j]);
			arguments[j] = NULL;
			j++;
		}
		free(arguments);
		arguments = NULL;
	}

	return (0);
}

/**
 * transform_to_array - transform a sentence into an array of words
 * @buffer: sentence
 * @size_read: size of sentence
 *
 * Return: array of words
 */

char **transform_to_array(char *buffer, int size_read)
{
	int number_of_args = 0;
	char *argument, *copy_buffer;
	char **arguments;
	int i, len;
	char *sep = " \n";
	(void) size_read;

	number_of_args = counting_words(buffer);
	arguments = malloc((number_of_args + 1) * sizeof(char *));
	if (arguments == NULL)
		return (NULL);
	copy_buffer = malloc(strlen(buffer) + 1);
	if (copy_buffer == NULL)
		return (NULL);
	strcpy(copy_buffer, buffer);
	argument = strtok(copy_buffer, sep);
	for (i = 0; argument != NULL; i++)
	{
		len = strlen(argument);
		arguments[i] = malloc(len + 1);
		if (arguments[i] == NULL)
			return (NULL);
		strcpy(arguments[i], argument);
		argument = strtok(NULL, sep);
	}
	arguments[i] = NULL;
	free(copy_buffer);
	return (arguments);
}

/**
 * _getenv - get value corresponding to identifier in environment variables
 * @identifier: identifier of variable
 *
 * Return: value corresponding to identifier
 */

char *_getenv(const char *identifier)
{
	char **cpy_env = environ;
	char *env_var = NULL;
	char *env_var_var = NULL;
	char *env_var_value = NULL;
	int i, len_tot, len_first = 0, len_second;

	while (*cpy_env)
	{
		len_tot = strlen(*cpy_env);
		env_var = *cpy_env;
		len_first = 0;
		len_second = 0;

		for (i = 0; i < len_tot; i++)
		{
			if (env_var[i] == '=')
				break;
			len_first++;
		}
		len_second = len_tot - len_first;
		env_var_var = malloc(len_first + 1);
		if (env_var_var == NULL)
			return (NULL);
		strncpy(env_var_var, env_var, len_first);
		env_var_var[len_first] = '\0';
		if (strcmp(identifier, env_var_var) == 0)
		{
			env_var_value = malloc(len_second + 1);
			if (env_var_value == NULL)
				return (NULL);
			strncpy(env_var_value, env_var + len_first + 1, len_second);
			env_var_value[len_second] = '\0';
			free(env_var_var);
			return (env_var_value);
		}
		cpy_env++;
		free(env_var_var);
		free(env_var_value);
	}
	return (NULL);
}
