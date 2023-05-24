#include "shell.h"

/**
* null_command - Free the buffer created
*@buffer: buffer taked from getline
*Return: Nothing(void)
*/

void null_command(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
* get_out - Free the buffer and commands taken from getline
*@buffer: buffer taked from getline
*@commands: command inserted
*Return: Nothing(void)
*/

void get_out(char *buffer, char **commands)
{
	free(buffer);
	free_all_dp(commands);
	exit(EXIT_SUCCESS);
}

/**
* env_end - Function to frees the buffer and commands created in getline
*@buffer: buffer from getline
*@commands: array store commands
*@env: enviroment variables
*Return: Nothing(void)
*/

void env_end(char *buffer, char **commands, char **env)
{
	free(buffer);
	free_all_dp(commands);
	print_env(env);
	exit(EXIT_SUCCESS);
}

/**
* _path - Function to check and execute the command inserted
*@commands: array sotored commands
*@buffer: buffer from getline
*@env: enviroment variables
*@argv: argument vector
*@count: number of times runned the prompt
*/

void _path(char **commands, char *buffer, char **env, char **argv, int count)
{
	struct stat fileStat2;
	int i = 0;
	char **directories;

	directories = store_e_variables(commands[0], env);
	while (directories[i])
	{
		if (stat(directories[i], &fileStat2) == 0)
			execve(directories[i], commands, NULL);
		i++;
	}

	/*if command not found print error*/
	build_message(argv, commands[0], count);

	free(buffer);
	free_all_dp(commands);
	free_all_dp(directories);
	exit(EXIT_SUCCESS);
}
