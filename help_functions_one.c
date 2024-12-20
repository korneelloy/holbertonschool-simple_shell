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

	if (buffer == NULL)
		return (-1);

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			break;
	}


	for (len = 0; comparison[len] != '\n' && comparison[len] != '\0'; len++)
		continue;


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

	for (i = 0; sentence[i] != '\n'; i++)
	{
		if (sentence[i] != ' ' && nb_of_words == 0)
			nb_of_words++;
		else if (sentence[i] == ' ' && sentence[i + 1] != ' '
		&& sentence[i + 1] != '\n')
			nb_of_words++;
	}
	return (nb_of_words);
}

/**
 * free_memory - freeing the memory that was allocated
 * @arguments: double pointer to list of arguments
 * @buffer: the pointer to the buffer created by getline function
 *
 * Return:0 on succes
 */

int free_memory(char **arguments, char *buffer)
{
	int j = 0;


	while (arguments && arguments[j] != NULL)
	{
		free(arguments[j]);
		j++;
	}

	if (arguments)
		free(arguments);

	if (buffer)
		free(buffer);

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
	char *argument;
	char **arguments;
	int i;

	number_of_args = counting_words(buffer);

	if (buffer[size_read - 1] == '\n')
	{
		buffer[size_read - 1] = '\0';
	}
	argument = strtok(buffer, " ");

	arguments = malloc((number_of_args + 1) * sizeof(char *));
	if (arguments == NULL)
		return (NULL);

	for (i = 0; argument != NULL; i++)
	{
		arguments[i] = strdup(argument);
		if (arguments[i] == NULL)
			return (NULL);
		argument = strtok(NULL, " ");
	}

	arguments[i] = NULL;

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
	extern char **environ;
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
		strncpy(env_var_var, env_var, len_first);
		env_var_var[len_first] = '\0';
		if (strcmp(identifier, env_var_var) == 0)
		{
			strncpy(env_var_value, env_var + len_first + 1, len_second);
			env_var_value[len_second] = '\0';
			printf("before:%s\n", env_var_var);
			printf("after:%s\n", env_var_value);
			break;
		}
		cpy_env++;
		return (env_var_value);
	}
	return (NULL);
}

