#include "shell.h"

/**
 * length_of_command - find the number of commands in a string
 * @string: string that have the commands
 * Return: number of commands
*/

unsigned int length_of_command(char *string)
{
	unsigned int i = 0, command = 0, flag = 0;

	while (string[i] != '\0')
	{
		if (string[i] != ' ')
			flag = 1;
		if ((flag && string[i + 1] == ' ')
			|| (flag && string[i + 1] == '\0'))
		{
			++command;
			flag = 0;
		}
		i++;
	}
	return (command);
}

/**
 * array_strtok - create a double pointer array that point to each string
 * from the command line
 * @str: command from the terminal
 * Return: array of pointers that are commands to interpret or execute
*/
char **array_strtok(char *str)
{
	char *token, **holder;
	unsigned int length;
	int i = 0;

	str[_strlen(str) - 1] = '\0'; /**replace the new line by null*/
	length = length_of_command(str);
	if (length == 0)
		return (NULL);
	holder = malloc((sizeof(char *) * (length + 1)));
	if (holder == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		holder[i] = malloc(_strlen(token) + 1);
		if (holder[i] == NULL)
		{
			free_all_dp(holder);
			return (NULL);
		}
		_strncpy(holder[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		i++;
	}
	holder[i] = NULL;
	return (holder);
}

