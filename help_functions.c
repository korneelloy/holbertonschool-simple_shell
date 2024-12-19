#include "main.h"

/**
 * str_comparing - comparing given string with word "exit"
 * this function ignores any whitespaces that might be included
 * before in the given string
 * adn anything that might come after the given word
 *
 * @buffer: pointer to givven string
 *
 * Return: 0 if strings correspond, -1 if they don't
 */

int str_comparing(char *buffer)
{
	int i = 0, j = 0;
	char *comparison = "exit";
	char last;

	if (buffer == NULL)
		return (-1);

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			break;
	}

	for (j = 0; j < 4; j++)
	{
		if (buffer[i] != comparison[j])
			return (-1);
		i++;
	}

	last = buffer[i];

	if (last == ' ' || last == '\0' || last == '\n')
		return (0);

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
 * @i: number of arguments
 * @buffer: the pointer to the buffer created by getline function
 *
 * Return:0 on succes
 */

int free_memory(char **arguments, int i, char *buffer)
{
	int j;

	if (arguments)
	{
		for (j = 0; j <= i; j++)
			free(arguments[j]);
		free(arguments);
	}
	if (buffer)
		free(buffer);

	return (0);
}
