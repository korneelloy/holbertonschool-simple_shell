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


	for (len = 0; comparison[len] != '\0'; len++)
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
		argument = strtok(NULL, " ");
	}

	arguments[i] = NULL;

	return (arguments);
}
