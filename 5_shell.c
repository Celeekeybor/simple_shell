#include "shell.h"
/**
 * free_all_dp - frees all the memory including a double pointer
 * @ptr: pointer to free
 * Return: Nothing
*/

void free_all_dp(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}

/**
 * parent_free_commands - free the buffer and the commands
 * @buffer: buffer in getline
 * @commands: double pointer that store all the commands inserted
 * Return: Nothing(void)
*/

void parent_free_commands(char *buffer, char **commands)
{
	free(buffer);
	free_all_dp(commands);
}

/**
* send_to_free - Function to send free when the child is not created
*@buffer: buffer created by getline
*@commands: array of commands
*Return: Nothing(void)
*/

void send_to_free(char *buffer, char **commands)
{
	if (commands == NULL)
		parent_free_commands(buffer, commands);
	/*on exit status*/
	else if (_strcmp("exit", commands[0]))
		get_out(buffer, commands);
	else
		parent_free_commands(buffer, commands);
}

